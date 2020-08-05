#pragma once

#include <vector>

#include "GraphicPresenter.hpp"
#include "Object.hpp"

class TWorkManager {
  private:
    std::vector<TObject *> _objects;
    IGraphicPresenter *_presenter;
    bool _stopWork;

  public:
    explicit TWorkManager(IGraphicPresenter *presenter);
    void Start();
    void sendObjects();
    void stopWork() { _stopWork = true; }
};
    