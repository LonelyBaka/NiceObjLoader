#pragma once

#include "ObjectTransforms.hpp"
#include "model.h"
#include "shader.h"

class TGObject {
private:
  TObjectTransforms &_transform;
  Model &_model;
  Shader &_shader;

public:
  TGObject(TObjectTransforms &transform, Model &model, Shader &shader)
      : _transform(transform), _model(model), _shader(shader) {}
  void draw();
};