#include "appController.hpp"
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
        return instance;
    }

    auto Controller::getVersion() -> QString {
        return Meta::versionString;
    }

    auto Controller::isDebugBuild() -> bool {
#ifdef NDEBUG
        return false;
#else
        return true;
#endif
    }
}
