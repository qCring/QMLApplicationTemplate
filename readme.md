QML Application Template
===

![](doc/img/logo.png)

A CMake project template for a simple QML desktop application. This project should give a brief overview and orientation and also provide a robust starting point for applications based on Qt QML.

**Currently only configured for Mac OS X**

What you get
---
- Basic setup for a working app using [QtQuick/QML](http://doc.qt.io/qt-5/qmlapplications.html) technology
- Easy project generation using [CMake](http://www.cmake.org/)
- An Install target that generates a deployable .app for Mac OS X
- Built-in support for [FontAwesome](http://fortawesome.github.io/Font-Awesome/)
- Basically, a good starting point to check out QML

What you need
---
- [CMake](http://www.cmake.org/)
- [Qt 5.5](https://www.qt.io/download-open-source/)

How to set it up
---
Follow [these](doc/setup.md) steps to set up the project for Mac OS X via CMake.

Project structure
---
- root
	- build *(generated, store application builds)*
	- install *(generated, store ready-to-deploy application builds)*
	- cmake *(cmake related stuff)*
	- doc
	- res
		- asset
		- font
		- icons
		- qml
	- src
		- app

Notes
---
- All folders in the *res* directory are copied into the application bundle. You should only edit resources (like .qml files and assets for example) here instead of the resources inside *build* or *install* folders. 

- As of now, only *.js*, *.json*, *.ttf*, *.png* and *.qml* files are considered as resources. Resource-types can be defined in the AddRes function inside **cmake/Functions.cmake**).

- The application name and version are defined in CMake (see **cmake/info.in.cpp**).

- The Qt version can also be defined in CMake via the **TEMPLATE_QT_VERSION** variable to easily switch between different Qt versions installed on the system.

- When adding new source directories inside *src*, the CMakeLists.txt has to be edited. See the *AddSrc* function used in CMakeLists.txt.

- For installation, switch to the *install* target.


Next steps
---
- Fix CMake for other platforms and generators
- Setup for installation on different platforms (CPack etc.)
- Integrate libs for for:
	- Testing
	- Logging
- Make the app a little bit more comprehensive
- Include iOS and Android toolchains

These steps aim towards creating a fully equipped project template for a cross-platform application that can be used as a basis for creating UI applications using QML.

License
-------------
This project is under the [MIT License](http://opensource.org/licenses/MIT)

Copyright (C) 2015 A. E. Szalo


