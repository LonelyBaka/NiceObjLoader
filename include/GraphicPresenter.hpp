#pragma once

#include "GraphicManager.hpp"
#include "Object.hpp"

class IGraphicPresenter {
  virtual void addTObject(const TObject& obj) {}
  virtual void deleteTObject(const TObject& obj) {}
};

class TGraphicPresenter : public IGraphicPresenter {
private:
  TGraphicManager *_manager;

public:
  TGraphicPresenter() : _manager(nullptr) {}
  void setGraphicManager(TGraphicManager *manager) { _manager = manager; }
  virtual void addTObject(const TObject& obj) override { _manager->addNewObject(obj); }
  virtual void deleteTObject(const TObject& obj) override {}
};
