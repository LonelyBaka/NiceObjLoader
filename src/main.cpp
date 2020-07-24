// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include "GraphicPresenter.hpp"
#include "WorkManager.hpp"
#include "GraphicManager.hpp"

int main(void) {
  TGraphicPresenter* presenter = new TGraphicPresenter();
  TWorkManager workManager(presenter);
  TGraphicManager* graphicManager = new TGraphicManager();
  presenter->setGraphicManager(graphicManager);
  workManager.sendObjects();

  

  graphicManager->startDraw();



  // auto window = new FirstPersonView(800, 600, "Sample");

  // // говорим stb_image.h чтобы он перевернул загруженные текстуры относительно
  // // y-оси (до загрузки модели).

  // // Create and compile our GLSL program from the shaders
  // Shader myShade(Utils::getPath("/assets/VertexShader.vs").c_str(),
  //                Utils::getPath("/assets/FragmentShader.fs").c_str());

  // Model Cyborg(Utils::getPath("/assets/cyborg/cyborg.obj"));
  // Model Table(Utils::getPath("/assets/table.obj"));
  // Model Nanosuit(Utils::getPath("/assets/nanosuit/nanosuit.obj"));
  // stbi_set_flip_vertically_on_load(true);
  // Model Backpack(Utils::getPath("/assets/backpack/backpack.obj"));
  // stbi_set_flip_vertically_on_load(false);

  return 0;
}
