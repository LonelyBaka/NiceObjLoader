#pragma once

#include "WindowManager.hpp"
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <FirstPersonView.hpp>
#include <iostream>
#include <mesh.h>
#include <model.h>
#include <shader.h>
#include <stb_image.h>
#include <utils.hpp>

#include <Object.hpp>
#include <GObject.hpp>

class TGraphicManager {
private:
  WindowManager *_window;
  Model _tableModel;
  std::vector<TGObject> graphicObjects;
  Shader _shader;

public:
  TGraphicManager();
  void addNewObject(const TObject &obj);
  void startDraw();
};