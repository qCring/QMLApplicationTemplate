#pragma once

#include "appQmlRegister.hpp"

#include <QObject>

namespace app {

    class Info : public QObject {
        Q_OBJECT
        Q_PROPERTY(bool debugBuild READ isDebugBuild CONSTANT);
        Q_PROPERTY(QString version READ getVersion CONSTANT);
    private:
        static Qml::Register::Type<Info> Register;
        Info() = default;
    public:
        static Info* instance;
        static auto Create() -> void;
        auto getVersion() -> QString;
        auto isDebugBuild() -> bool;
    };
}
