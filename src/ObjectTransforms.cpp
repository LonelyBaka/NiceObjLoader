#include "ObjectTransforms.hpp"

TObjectTransforms::TObjectTransforms(TObject *obj) {
  pos = obj->GetProperty("Coordinate");
  scale = obj->GetProperty("Dimensions");
}

glm::vec3 TObjectTransforms::getPos() {
  return glm::vec3(pos->GetValues()["X"], pos->GetValues()["Y"],
                   pos->GetValues()["Z"]);
}

glm::vec3 TObjectTransforms::getScale() {
  return glm::vec3(scale->GetValues()["Width"], scale->GetValues()["Length"],
                   scale->GetValues()["Height"]);
}