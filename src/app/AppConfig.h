#pragma once

#include <QObject>

namespace App
{
    class Config : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(bool isRelease READ getIsRelease CONSTANT);
        Q_PROPERTY(QString version READ getVersion CONSTANT);
    private:
        QString m_version;
    public:
        static QString resourceDir;
        static bool releaseBuild;
    private:
        Config() = default;
    public:
        static Config* instance;
        static Config* Create();
        void init();
        bool getIsRelease();
        QString getVersion();
        ~Config() = default;
    };
}