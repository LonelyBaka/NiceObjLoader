#pragma once

#include "GraphicManager.hpp"
#include "Object.hpp"

class IGraphicPresenter {
  public:
    virtual void addTObject(TObject *obj) {}
    virtual void deleteTObject(const TObject *obj) {}
    virtual void setGraphicManager(TGraphicManager *manager) {}
};

class TGraphicPresenter : public IGraphicPresenter {
  private:
    TGraphicManager *_manager;

  public:
    TGraphicPresenter() : _manager(nullptr) {}
    virtual void setGraphicManager(TGraphicManager *manager) override {
        _manager = manager;
    }
    virtual void addTObject(TObject *obj) override {
        _manager->addNewObject(obj);
    }
    virtual void deleteTObject(const TObject *obj) override {}
};
