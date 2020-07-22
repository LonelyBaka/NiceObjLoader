#pragma once

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

#include "Object.hpp"
#include "Properties.hpp"

class TObjectTransforms {
private:
  IProperties* pos;
  IProperties* scale;

public:
  TObjectTransforms(цTObject &obj);
  glm::vec3 getPos();
  glm::vec3 getScale();
};