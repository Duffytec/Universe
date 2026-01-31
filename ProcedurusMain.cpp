/*******************************************************************************
* File:           ProcedurusMain.h
* Author:         Christian Alfons
* Date created:   2010-06-29
* Date modified:  2010-12-03
* Description:    The main file of the Procedurus application.
*******************************************************************************/

#include <iostream>
#include "Application/Application.h"

using std::cout;
using std::endl;

// Application variables
Application *application = nullptr;

// Window close callback
void HandleWindowClose(GLFWwindow *window) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

// Key callback function
void HandleKey(GLFWwindow *window, int key, int scancode, int action, int mods) {
    (void)scancode;
    (void)mods;
    // If a key was pressed
    if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        return;
    }

    application->HandleKey(key, action);
}

// The main entry point for the application
int main(int argc, char *argv[]) {
    // Initialize GLFW
    if (!glfwInit()) {
        // Print an error message
        cout << "glfwInit failed" << endl;

        return 1;
    }



    // Open a GLFW window
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 32);
    glfwWindowHint(GLFW_STENCIL_BITS, 0);
    GLFWwindow *window = glfwCreateWindow(1280, 800, "Procedurus", nullptr, nullptr);
    if (!window) {
        // Terminate GLFW
        glfwTerminate();
        // Print an error message
        cout << "glfwCreateWindow failed" << endl;
        return 2;
    }

    // Make the context current
    glfwMakeContextCurrent(window);

    // Enable mouse cursor
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    // Turn vsync off for benchmarking purposes
    glfwSwapInterval(0);

    // Set GLFW callback functions
    glfwSetWindowCloseCallback(window, HandleWindowClose);
    glfwSetKeyCallback(window, HandleKey);

    // Create an application instance
    application = new Application(window);

    // Get the current time
    double timeLastFrame = glfwGetTime();

    // Start the main loop
    while (!glfwWindowShouldClose(window)) {
        // Calculate the frame time
        const double currentTime = glfwGetTime();
        const double frameTime = currentTime - timeLastFrame;
        timeLastFrame = currentTime;

        // Update and render the application
        application->Update(frameTime);
        application->Render();
        glfwPollEvents();

        // Print any OpenGL error flag value
        static GLenum lastError = GL_NO_ERROR;
        while (GLenum error = glGetError() != GL_NO_ERROR) {
            if (error != lastError) {
                cout << "OpenGL error: " << error << endl;
                lastError = error;
            }
        }
    }

    // Delete pointers here to deinitialize OpenGL stuff before terminating GLFW
    delete application;

    glfwDestroyWindow(window);
    // Terminate GLFW
    glfwTerminate();

    return 0;
}
