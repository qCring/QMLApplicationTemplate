#include "appController.hpp"
#include "appInfo.hpp"
#include "meta.hpp"

namespace app {

    Controller* Controller::instance = nullptr;

    Controller::Controller() {
        if (instance) {
            throw std::runtime_error("instance already existing");
        }
    }

    auto Controller::Create() -> Controller* {
        instance = new Controller();
        Info::Create();
        return instance;
    }

    auto Controller::getInfo() -> Info* {
        return Info::instance;
    }
}
