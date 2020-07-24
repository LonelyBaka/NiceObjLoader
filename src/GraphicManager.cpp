#include "GraphicManager.hpp"

TGraphicManager::TGraphicManager()
    : _window(new FirstPersonView(800, 600, "Sample")),
      _shader(Utils::getPath("/assets/VertexShader.vs").c_str(),
              Utils::getPath("/assets/FragmentShader.fs").c_str()),
      _tableModel(Utils::getPath("/assets/table.obj")) {}

void TGraphicManager::addNewObject(TObject *obj) {
  TObjectTransforms *objectTransform = new TObjectTransforms(obj);
  TGObject *object = new TGObject(objectTransform, _tableModel, _shader);
  graphicObjects.push_back(object);
}

void TGraphicManager::startDraw() {
  do {

    _window->runWindow(0.01f, [&]() {
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (auto *elem : graphicObjects)
        elem->draw();
    });

  } // Check if the ESC key was pressed or the window was closed
  while (glfwWindowShouldClose(_window->getWindow()) == 0);

  glfwTerminate();
}