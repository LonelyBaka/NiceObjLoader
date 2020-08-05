// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#include "GraphicManager.hpp"
#include "GraphicPresenter.hpp"
#include "WorkManager.hpp"

int main(void) {
    IGraphicPresenter *presenter = new TGraphicPresenter();
    TWorkManager workManager(presenter);
    TGraphicManager *graphicManager = new TGraphicManager();
    presenter->setGraphicManager(graphicManager);
    workManager.sendObjects();

    std::thread(&TWorkManager::Start, &workManager).detach();
    graphicManager->startDraw();
    workManager.stopWork();
    return 0;
}
