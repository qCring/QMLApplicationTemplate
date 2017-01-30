#pragma once

#include <functional>

#include <QtQml>
#include <QList>

namespace app {

    namespace Qml {

        namespace Register {

            auto Init() -> void;
#ifdef _MSC_VER
            struct Queue {
                static auto GetList()->QList<std::function<void(void)>>&;
            };
#endif

            template <class T>
            struct Type {
                Type() {
                    auto initializer = []() {
                        qmlRegisterType<T>();
                    };
#ifdef _MSC_VER
                    Queue::GetList().append(initializer);
#else
                    initializer();
#endif
                }
            };
        }
    }
}
