#include "GraphicManager.hpp"

TGraphicManager::TGraphicManager()
    : _window(new FirstPersonView(800, 600, "Sample")),
      _shader(Utils::getPath("/assets/VertexShader.vs").c_str(),
              Utils::getPath("/assets/FragmentShader.fs").c_str()),
      _tableModel(Utils::getPath("/assets/table.obj")) {}