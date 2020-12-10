#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include "Animation.h"
#include "Viewer.h"

#include "Quadrangle.h"

#include "Point.h"


int main()
{
	//float pos[] = {
	//0, 1, 1,
	//1, 1, 1,
	//1, 0, 1,
	//0, 0, 1,
	//0, 1, 0,
	//1, 1, 0,
	//1, 0, 0,
	//0, 0, 0
	//};

	//float pos[] = {
	//	 0.5f,  0.5f, 0.0f,     1.0f, 1.0f,
	//	 0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 
	//	 -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 
	//	 -0.5f,  0.5f, 0.0f,     0.0f, 1.0f  
	//};


	float pos[] = {
		 400.f,  400.f, 0.0f,     1.0f, 0.0f,
		 400.f,  200.f, 0.0f,     1.0f, 1.0f,
		 200.f,  200.f, 0.0f,     0.0f, 1.0f,
		 200.f,  400.f, 0.0f,     0.0f, 0.0f
	};
	
	//float par = 300;
	
	//for (int i = 0; i < 4 * 5; i++)
	//{
	//	//texCoord[i] *= (par/2);
	//	pos[i] *= par;
	//}

	//int k = 3, k_o = 3;
	//int j = 5;
	//for(int i = 0; i < 2 * 4; i++)
	//{
	//	std::cout << "num:" << k << "\n";
	//	std::cout << pos[k] << "\n";
	//	k++;
	//	if(k % j == 0)
	//		k += k_o;
	//}

	std::vector<std::string> path = { "res/anim/01.gif","res/anim/02.gif", "res/anim/03.gif", "res/anim/04.gif", "res/anim/06.gif", "res/anim/07.gif" };
	
	GraphicsEngine::Viewer v(640, 480);
	//v.AddObjectToPool(new GraphicsEngine::Quadrangle(0, 0, pos));
	v.AddObjectToPool(new Animation(path, 0, 0, pos));

	while (true)
	{
		v.Clear();
		v.Draw();
	}

	return 0;
}

//
//#include <fstream>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//
//#include <iostream>
//#include <sstream>
//
//
//#include "Quadrangle.h"
//#include "vendor/stb_image/stb_image.h"
//#include "ViewObject.h"
//
//#include "Shader.h"
//#include "Texture.h"
//#include "VertexBufferLayout.h"
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//GLFWwindow* window;
//GraphicsEngine::VertexArray* va;
//GraphicsEngine::VertexBuffer* vb;
//GraphicsEngine::VertexBufferLayout* layout;
//GraphicsEngine::IndexBuffer* ib;
//
//GraphicsEngine::Shader* ourShader;
//Texture* tex;
//
//int init();
//void zip(float*, unsigned int*);
//void draw(GraphicsEngine::Renderer, float*, unsigned int*);
//
//int main()
//{
//    init();
//    auto vertices = new float[]{
//         0.5f,  0.5f, 0.0f,     1.0f, 1.0f, 
//         0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 
//        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 
//        -0.5f,  0.5f, 0.0f,     0.0f, 1.0f  
//    };
//    auto indices = new unsigned int[]{
//        0, 1, 3, 
//        1, 3, 2  
//    };
//
//    auto q = new  GraphicsEngine::Quadrangle(0,0,vertices);
//	
//    std::string path = "res/tex.png";
//    tex = new Texture(path);
//	
//    ourShader = new GraphicsEngine::Shader("Basic.shader");
//   
//    GraphicsEngine::Renderer r;
//
//
//    while (!glfwWindowShouldClose(window))
//    {
//        //draw(r, vertices, indices);
//        q->draw();
//    	
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//    glfwTerminate();
//    return 0;
//}
//
//
//int init()
//{
//    if (!glfwInit())
//    {
//        fprintf(stderr, "Failed to initialize GLFW\n");
//        getchar();
//        return -1;
//    }
//
//    glfwWindowHint(GLFW_SAMPLES, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    //glfwWindowHint(GLFW_RESIZABLE , GL_FALSE);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Window", NULL, NULL);
//    if (window == NULL)
//    {
//        fprintf(stderr,
//            "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version.\n");
//        getchar();
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//    glewExperimental = true;
//    if (glewInit() != GLEW_OK)
//    {
//        fprintf(stderr, "Failed to initialize GLEW\n");
//        getchar();
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
//
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//    return 0;
//}
//
//void zip(float* vertices, unsigned int* indices)
//{
//    va = new GraphicsEngine::VertexArray;
//    vb = new GraphicsEngine::VertexBuffer(vertices, sizeof(float) * 5 * 4);
//    layout = new GraphicsEngine::VertexBufferLayout;
//    layout->Push(GL_FLOAT, 3);
//    layout->Push(GL_FLOAT, 2);
//    va->AddBuffer(*vb, *layout);
//
//    ib = new GraphicsEngine::IndexBuffer(indices, 6);
//
//    ourShader->Bind();
//    ourShader->SetUniform1i("u_Texture", 0);
//}
//
//void draw(GraphicsEngine::Renderer r , float* vertices, unsigned int* indices)
//{
//    zip(vertices, indices);
//    tex->Bind();
//    ourShader->Bind();
//
//    r.Draw(*va, *ib, *ourShader);
//}