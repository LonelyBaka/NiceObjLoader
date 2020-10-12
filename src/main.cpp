// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include "FirstPersonView.hpp"

#include <shader.h>
#include <stb_image.h>
#include <utils.hpp>

#include "GObject.hpp"

int main(void) {
  FirstPersonView* window(new FirstPersonView(800, 600, "Sample"));
  Shader shader(Utils::getPath("/assets/VertexShader.vs").c_str(),
              Utils::getPath("/assets/FragmentShader.fs").c_str());
            
  std::vector<TGObject> graphicObjects;

  Model tableModel(Utils::getPath("/assets/table.obj"));
  TGObject table = TGObject(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), tableModel, shader);
  graphicObjects.push_back(table);

  Model cyborgModel(Utils::getPath("/assets/cyborg/cyborg.obj"));
  TGObject cyborg = TGObject(glm::vec3(-5, 0, 0), glm::vec3(1, 1, 1), cyborgModel, shader);
  graphicObjects.push_back(cyborg);

  Model nanosuitModel(Utils::getPath("/assets/nanosuit/nanosuit.obj"));
  TGObject nanosuit = TGObject(glm::vec3(6, 0, 0), glm::vec3(1, 1, 1), nanosuitModel, shader);
  graphicObjects.push_back(nanosuit);

  do {
    window->runWindow(0.001f, [&]() {
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (auto elem : graphicObjects)
        elem.draw();
    });
  } // Check if the ESC key was pressed or the window was closed
  while (glfwWindowShouldClose(window->getWindow()) == 0);

  glfwTerminate();
  return 0;
}
