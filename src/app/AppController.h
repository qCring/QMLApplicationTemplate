#pragma once

#include <QObject>

namespace App
{
    class Config;
    
    class Controller : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(App::Config* config READ getConfig CONSTANT);
    private:
        Controller() = default;
    public:
        static Controller* instance;
        static Controller* Create();
        void init();
        Config* getConfig();
        ~Controller() = default;
    };
}