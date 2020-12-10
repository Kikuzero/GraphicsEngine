//#define _USE_MATH_DEFINES 
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#include <GL/glew.h>
//
//#include <GLFW/glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//
//#include "VertexBuffer.h"
//#include "IndexBuffer.h"
//#include "VertexArray.h"
//#include "VertexBufferLayout.h"
//#include "Shader.h"
//#include "Renderer.h"
//
//#include "Triangle.h"
//#include "Circle.h"
//#include "Rectangle.h"
//
//#include "Point.h"
//
//#define SCREEN_WIDTH 640
//#define SCREEN_HEIGHT 480
//
//int main()
//{
//	GLFWwindow* window;
//
//
//	if (!glfwInit())
//	{
//		fprintf(stderr, "Failed to initialize GLFW\n");
//		getchar();
//		return -1;
//	}
//
//	glfwWindowHint(GLFW_SAMPLES, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tutorial 03 - Matrices", NULL, NULL);
//	if (window == NULL) 
//	{
//		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version.\n");
//		getchar();
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//
//	glewExperimental = true;
//	if (glewInit() != GLEW_OK) {
//		fprintf(stderr, "Failed to initialize GLEW\n");
//		getchar();
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
//
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); 
//	glMatrixMode(GL_PROJECTION); 
//	glLoadIdentity(); 
//	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); 
//	glMatrixMode(GL_MODELVIEW); 
//	glLoadIdentity();
//	
//	GLfloat g_vertex_buffer_data_1[] = {
//		-1.0f, -1.0f,
//		 1.0f, -1.0f,
//		 0.0f,  1.0f,
//	};
//	
//	Triangle tr_1(2);
//	tr_1.setVertexPoints(g_vertex_buffer_data_1);
//	tr_1.setColor(new float[3]{ 0.5, 0.5, 0.5 });
//
//	float pos[] = {
//		-0.2, -0.2, 0,
//		 0.2, -0.2, 0,
//		 0.2,  0.2, 0,
//		-0.2,  0.2, 0,
//	};
//
//	Rectangle rec(3);
//	rec.setVertexPoints(pos);
//	rec.setColor(new float[3]{ 1.0, 0.2, 0.2 });
//
//	Rectangle rec_1(3);
//	rec_1.setVertexPoints(pos);
//	rec_1.setColor(new float[3]{ 1.0, 0.5, 0.8 });
//
//	Circle cir(0, 0, 0, 0.3, 128);
//	Circle cir_1(0, 0, 0, 0.3, 128);
//	cir_1.setColor(new float[3]{1.0, 0.5, 0.8});
//
//	do {
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		rec_1.setRotation(1.f, glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.7071607f, 0.7071607f, 0.f));
//		rec_1.draw();
//	
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//	} 
//	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
//		glfwWindowShouldClose(window) == 0);
//
//
//	glfwTerminate();
//
//	return 0;
//}