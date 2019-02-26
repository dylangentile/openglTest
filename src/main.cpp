#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;



void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(){


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
    	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "SimpleGL", NULL, NULL);
    if(window == NULL){
    	std::cout << "glfw failed to createWindow\n";
    	glfwTerminate();
    	return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));{
    	std::cout << "Glad failed to initialize";
    	return -1;
    }

    while(!glfwWindowShouldClose(window)){
    	//input
    	processInput(window);
    	//render
    	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    	glClear(GL_COLOR_BUFFER_BIT);

    	glfwSwapBuffers(window);
    	glfwPollEvents();

    }



    glfwTerminate();
	return 0;
}
