#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define STARS 5000
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int init(GLFWwindow *window) {
    
    if (!glfwInit())
        return 0;
    
    glfwWindowHint(GLFW_SAMPLES, 16);
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_WIDTH, 
        "Star-fields", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        return 0;

    glEnable(GL_MULTISAMPLE);
}

void loop(GLFWwindow *window) {

    float vertices[] = {
        -0.5f,  0.5f,
         0.5f,  0.5f,
        -0.5f, -0.5f,
         0.5f, -0.5f
    };

    unsigned int vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertex_buffer, GL_STATIC_DRAW);

    unsigned int transform_buffer;
    glGenBuffers(1, &transform_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, transform_buffer);
    glBufferData(GL_ARRAY_BUFFER, STARS * 4 * 4 * sizeof(float), NULL, GL_STREAM_DRAW);

    while (!glfwWindowShouldCLose(window)) {

        glCear(GL_COLOR_BUFFER_BIT);

        // update transforms
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        //glBufferSubData(GL_ARRAY_BUFFER, 0, size, subdata);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void shutdown() {
    glfwTerminate();
}

int main() {

    GLFWwindow *window;
    init(window);
    loop(window);
    shutdown();

    return EXIT_SUCCESS;
}