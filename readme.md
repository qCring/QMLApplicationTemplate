QMLApplicationTemplate
===

![Qt](https://img.shields.io/badge/Qt-5.9.1-green.svg)

**[CMake](https://cmake.org)** project template for a simple **[QML](http://doc.qt.io/qt-5/qtqml-index.html)** desktop application.

<center>
	<img src="doc/screenshot.png" />
</center>

## About
A small template to get started with **[QML](http://doc.qt.io/qt-5/qtqml-index.html)**. You've got out-of-the-box support for some basic things like custom font handling, support for **[FontAwesome](http://fontawesome.io)** and a minimal setup regarding **[CMake](https://cmake.org)** and a basic application controller. Use **[CMake](https://cmake.org)** to quickly set up relevant project properties (they're all prefixed with **TEMPLATE_**) like application name, organization, domain, project version etc.

## Building
1. Download and launch the installer from the **[Qt download section](https://www.qt.io/download/)** and install the Qt binaries
2. Launch **[CMake](https://cmake.org)** and set the paths to **src** and **bin**
3. Press **configure** and set the path to Qt (`../lib/cmake/Qt5/`)
4. Press **configure** and **generate**

**Note:** When working with Visual Studio, make sure to set the environment in the IDE. Add the path to **[Qt](http://www.qt.io)** to the *Environment* field located in the project properties view under *Debugging*:

**PATH=**\<path-to-qt-dlls\>**;%PATH%;**

## License
![License](https://img.shields.io/badge/license-BSD--3--Clause-blue.svg)

Copyright (c) 2015, Alexander Eduard Szalo
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

