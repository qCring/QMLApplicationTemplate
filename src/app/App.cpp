#include <QApplication>
#include <QtQml>

#include "App.h"
#include "AppMenu.h"
#include "AppConfig.h"
#include "AppWindow.h"
#include "AppController.h"

namespace App
{
    int Execute(int argc, char** argv)
    {
        QApplication application(argc, argv);
        RegisterTypes();
        
        App::Menu* menu = Menu::Create();
        menu->init();
        
        Config* config = Config::Create();
        config->init();
        
        Controller* controller = Controller::Create();
        controller->init();
        
        App::Window* window = App::Window::Create();
        window->init();
        window->show();
        
        return application.exec();
    }
    
    void RegisterTypes()
    {
        qmlRegisterType<::App::Config>();
    }
}