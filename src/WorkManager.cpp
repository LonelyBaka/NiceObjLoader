#include "WorkManager.hpp"
#include "Table.hpp"
#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>

TWorkManager::TWorkManager(IGraphicPresenter *presenter)
    : _presenter(presenter), _stopWork(false) {
    _objects.push_back(new TTable());
}

void TWorkManager::sendObjects() {
    for (auto *elem : _objects)
        _presenter->addTObject(elem);
}

void TWorkManager::Start() {
    std::srand(std::time(nullptr));
    while (!_stopWork) {
        for (auto &elem : _objects) {
            auto prop = elem->GetProperty("Coordinate");
            int x = std::rand() % 4;
            switch (x) {
            case 0:
                prop->SetValue("Z", prop->GetValue("Z") - 10);
                break;
            case 1:
                prop->SetValue("Z", prop->GetValue("Z") + 10);
                break;
            case 2:
                prop->SetValue("X", prop->GetValue("X") + 10);
                break;
            case 3:
                prop->SetValue("X", prop->GetValue("X") - 10);
                break;
            }
            // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        _objects.push_back(new TTable());
        _presenter->addTObject(*(_objects.end() - 1));
        std::cout << "TABLE COUNT " << _objects.size() << std::endl;
    }
}