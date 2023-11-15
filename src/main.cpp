#include<iostream>
#include"../glad/glad.h"
#include<GLFW/glfw3.h>
#include <math.h>
#include <vector>

#include "../include/shaderClass.h"
#include "../include/VAO.h"
#include "../include/VBO.h"
#include "../include/Circle.h"
#include "../include/Vector2f.h"
#include "../include/GravityEngine.h"


int main(){
    glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "Geometry", NULL, NULL);
	if (window == NULL){
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}
    
	glfwMakeContextCurrent(window);

    double lastTime = glfwGetTime();
    double currentTime, deltaTime;

	gladLoadGL();

	glViewport(0, 0, 1000, 1000);
    Shader shaderProgram("../shaders/default.vert", "../shaders/default.frag");

    Circle circle(1000, Vector2f(0.f, 0.f));
    Circle circleTwo(1500, Vector2f(1.f, 1.f));
    circle.Update();
    circleTwo.Update();

	while (!glfwWindowShouldClose(window)){
		glClearColor(0.0588235f, 0.0588235f, 0.0627451f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();
        currentTime = glfwGetTime();
        std::vector<Circle> objects = {circle, circleTwo};
        deltaTime = currentTime - lastTime;
        GEN::CalculateGravityForce(objects, deltaTime);
        lastTime = currentTime;
        circle.Draw();
        circleTwo.Draw();
        glfwSwapBuffers(window);
		glfwPollEvents();
	}
    circleTwo.Delete();
    circle.Delete();
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
