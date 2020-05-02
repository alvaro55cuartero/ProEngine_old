#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main(void) {
	
	if (!glfwInit())
		return -1;
	
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "ERROR: GLEW fail init" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{ 
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(-0.5, -0.5);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

