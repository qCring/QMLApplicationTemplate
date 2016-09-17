#pragma once

#include <QString>
#include <QQuickView>

namespace app {

    class Instance {
    private:
        QQuickView* m_view = nullptr;
    private:
        static Instance* instance;
        Instance();
        auto init() -> void;
        auto AddFontDir(const QString&) -> void;
    public:
        static auto Execute(int, char**) -> int;
    };
}
