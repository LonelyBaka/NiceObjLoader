#include "WorkManager.hpp"
#include "Table.hpp"

TWorkManager::TWorkManager(TGraphicPresenter *presenter)
    : _presenter(presenter) {
  _objects.push_back(new TTable());
}

void TWorkManager::sendObjects() {
  for (auto* elem : _objects)
    _presenter->addTObject(elem);
}