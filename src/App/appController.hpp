#pragma once

#include <QObject>

namespace app {

    class Controller : public QObject {
        Q_OBJECT
        Q_PROPERTY(bool debugBuild READ isDebugBuild CONSTANT);
        Q_PROPERTY(QString version READ getVersion CONSTANT);
    private:
        Controller();
    public:
        static Controller* instance;
        static auto Create() -> Controller*;
        auto getVersion() -> QString;
        auto isDebugBuild() -> bool;
    };
}
