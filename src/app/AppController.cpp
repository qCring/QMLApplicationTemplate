#include "AppController.h"
#include "AppConfig.h"

namespace App
{
    Controller* Controller::instance = nullptr;
    
    Controller* Controller::Create()
    {
        instance = new Controller();
        
        return instance;
    }
    
    void Controller::init()
    {
    }
    
    Config* Controller::getConfig()
    {
        return Config::instance;
    }
}