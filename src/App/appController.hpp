#pragma once

#include <QObject>

namespace app {

    class Info;

    class Controller : public QObject {
        Q_OBJECT
        Q_PROPERTY(app::Info* info READ getInfo CONSTANT);
    private:
        Controller();
    public:
        static Controller* instance;
        static auto Create() -> Controller*;
        auto getInfo() -> Info*;
    };
}
