#include "appInfo.hpp"
#include "meta.hpp"

namespace app {

    Info* Info::instance = nullptr;
    Qml::Register::Type<Info> Info::Register;

    auto Info::getVersion() -> QString {
        return Meta::versionString;
    }

    auto Info::Create() -> void {
        if (!instance) {
            instance = new Info();
        }
    }

    auto Info::isDebugBuild() -> bool {
#ifdef NDEBUG
        return false;
#else
        return true;
#endif
    }
}
