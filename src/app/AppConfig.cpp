#include <QDir>
#include <QGuiApplication>

#include "AppConfig.h"
#include "AppInfo.h"

#include <iostream>

namespace App
{
    Config* Config::instance = nullptr;
    QString Config::resourceDir = "./";
    
#ifdef NDEBUG
    bool Config::releaseBuild = true;
#else
    bool Config::releaseBuild = false;
#endif
    
    Config* Config::Create()
    {
        instance = new Config();
        
        return instance;
    }
    
    void Config::init()
    {
        QDir path = QGuiApplication::applicationDirPath();
        path.cdUp();
        
        resourceDir = path.absolutePath() + "/Resources";
    }
    
    QString Config::getVersion()
    {
        return QString::number(Info::versionMajor) + "." + QString::number(Info::versionMinor) + "." + QString::number(Info::versionPatch);
    }
    
    bool Config::getIsRelease()
    {
        return releaseBuild;
    }
}
