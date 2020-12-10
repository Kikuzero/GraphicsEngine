#include "Shader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glew.h> 

#include <GLFW/glfw3.h>

namespace GraphicsEngine
{
    Shader::Shader(const std::string &_filename)
            : m_FilePath(_filename), m_RendererID(0)
    {
        ShaderProgramSource source = ParseShader();

        m_RendererID = Createshader(source.VertexSource, source.FragmentSource);
    }

    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
        : m_FilePath_v(vertexPath), m_FilePath_f(fragmentPath), m_RendererID(0)
    {
        ShaderProgramSource source = ParseShader_1();

        m_RendererID = Createshader(source.VertexSource, source.FragmentSource);
    }
	
    Shader::~Shader()
    {
        glDeleteProgram(m_RendererID);
    }

    ShaderProgramSource Shader::ParseShader()
    {
        std::ifstream stream(m_FilePath);
        
        if (!stream)
        {
            //throw std::runtime_error("Bad file path!");
            std::cerr << "Bad file path!";
        }
        
        enum class ShaderType
        {
            NONE = -1,
            VERTEX = 0,
            FRAGMENT = 1
        };
        
        std::stringstream ss[2];
        ShaderType type = ShaderType::NONE;
        
        std::string line;
        while (getline(stream, line))
        {
            if (line.find("#shader") != std::string::npos)
            {
                if (line.find("vertex") != std::string::npos)
                    type = ShaderType::VERTEX;
                else if (line.find("fragment") != std::string::npos)
                    type = ShaderType::FRAGMENT;
            }
            else
            {
                ss[(int) type] << line << "\n";
            }
        }

        return {ss[0].str(), ss[1].str()};
    }

    ShaderProgramSource Shader::ParseShader_1()
    {
        std::string vertexCode;
        std::string fragmentCode;
        std::string geometryCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        std::ifstream gShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open files
            vShaderFile.open(m_FilePath_v);
            fShaderFile.open(m_FilePath_f);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string

            // if geometry shader path is present, also load a geometry shader
            /*if (geometryPath != nullptr)
            {
                gShaderFile.open(geometryPath);
                std::stringstream gShaderStream;
                gShaderStream << gShaderFile.rdbuf();
                gShaderFile.close();
                geometryCode = gShaderStream.str();
            }*/

            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        

        return { vertexCode, fragmentCode };
    }
	
    unsigned int Shader::CompileShader(unsigned int _type, const std::string &_source)
    {
        unsigned int id = glCreateShader(_type);
        const char *src = _source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char *message = (char *) alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            std::cout << message << std::endl;
            glDeleteShader(id);

            return 0;
        }

        return id;
    }

    unsigned int Shader::Createshader(const std::string &_vertexShader, const std::string &_fragmentShader)
    {
        unsigned int program = glCreateProgram();
        unsigned int vs = CompileShader(GL_VERTEX_SHADER, _vertexShader);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, _fragmentShader);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }

    void Shader::Bind() const
    {
        glUseProgram(m_RendererID);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    void Shader::SetUniform1i(const std::string& _name, const int _value)
    {
        glUniform1i(GetUniformLocation(_name), _value);
    }

    void Shader::SetUniformMat4f(const std::string &_name, const glm::mat4 &_matrix)
    {
        glUniformMatrix4fv(GetUniformLocation(_name), 1, GL_FALSE, &_matrix[0][0]);
    }

    void Shader::SetUniform4f(const std::string &_name, float _v0, float _v1, float _v2, float _v3)
    {
        glUniform4f(GetUniformLocation(_name), _v0, _v1, _v2, _v3);
    }

    void Shader::SetUniformVec3f(const std::string &_name, const glm::vec3 &_vec)
    {
        glUniform3f(GetUniformLocation(_name), _vec[0], _vec[1], _vec[2]);
    }

    void Shader::SetUniformVec4f(const std::string &_name, const glm::vec4 &_vec)
    {
        glUniform4f(GetUniformLocation(_name), _vec[0], _vec[1], _vec[2], _vec[3]);
    }

    void Shader::SetUniform2f(const std::string &_name, const glm::vec2 &_vec)
    {
        glUniform2f(GetUniformLocation(_name), _vec[0], _vec[1]);
    }
	
    unsigned int Shader::GetUniformLocation(const std::string &_name)
    {
        if (m_UniformLocationCache.find(_name) != m_UniformLocationCache.end())
            return m_UniformLocationCache[_name];

        int location = glGetUniformLocation(m_RendererID, _name.c_str());
        if (location == -1)
            std::cout << "Warning! uniform " << _name << " doesn't exist!" << std::endl;
        else
            m_UniformLocationCache[_name] = location;

        return location;
    }
}