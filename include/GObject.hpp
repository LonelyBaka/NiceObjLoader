#pragma once

#include "model.h"
#include "shader.h"

class TGObject {
private:
  glm::vec3 &_pos;
  glm::vec3 &_scale;
  Model &_model;
  Shader &_shader;

public:
  TGObject(glm::vec3 &pos, glm::vec3 &scale, Model &model, Shader &shader)
      : _pos(pos), _scale(scale), _model(model), _shader(shader) {}
  void draw();
};