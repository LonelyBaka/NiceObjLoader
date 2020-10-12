#include "GObject.hpp"
#include "utils.hpp"

void TGObject::draw() {
  _shader.use();
  _shader.setMat4("projection", Utils::getCamera()->getProjectionMatrix());
  _shader.setMat4("view", Utils::getCamera()->getViewMatrix());

  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(model, _pos);
  model = glm::scale(model, _scale);
  // model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
  _shader.setMat4("model", model);
  _model.Draw(_shader);
}