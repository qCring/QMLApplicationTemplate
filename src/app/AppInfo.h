#pragma once

#include <QString>

namespace App
{
    class Info
    {
    private:
    public:
        static const std::string appName;
        static const int versionMajor;
        static const int versionMinor;
        static const int versionPatch;
    };
}