#pragma once

#include <vector>

#include "GraphicPresenter.hpp"
#include "Object.hpp"

class TWorkManager {
private:
  std::vector<TObject *> _objects;
  TGraphicPresenter *_presenter;

public:
  explicit TWorkManager(TGraphicPresenter *presenter);
  void Start();
  void sendObjects();
};