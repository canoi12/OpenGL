#include <GLFW/glfw3.h>
#include "src/graphics/window.h"
#include <iostream>

int main()
{
    int a;

    using namespace selene;
    using namespace graphics;
    Window window("Selene!", 800, 600);
    glClearColor(0.2f, 0.3f, 0.8f, 1.f);

    std::cout << glGetString(GL_VERSION) << std::endl;

    while (!window.closed())
    {
        window.clear();
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f,  0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();
        window.update();
    }
    return 0;
}