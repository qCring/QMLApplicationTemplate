QML Application Template - Setup
===

###1. Downlaod and install prerequisites

- Download and install [Qt5](https://www.qt.io/download-open-source/)
- Downlaod and install [CMake](http://www.cmake.org/download/)

###2. Configure using CMake GUI

- Start CMake and set the project source and binary directories:

	![](img/img1.png)

- Select Xcode

	![](img/img2.png)

- Press *Configure* (...and probably receive an error)
 
	![](img/img3.png)
	
	This happens only if CMake is not able to locate the Qt installation
	
- Fixing the above error: First type 'qt' in the search to filter values

	![](img/img4.png)
	
- Set the path to **Qt5_DIR** (.../Qt/Qt5.4/clang_64_lib/cmake/Qt5):

	![](img/img5.png)
	
- Press *Configure*
	
- Specify project settings as you want (all prefixed with **TEMPLATE_**)

	![](img/img6.png)

- Press *Configure* again

- Press *Generate*

###3. Build and run

- Open the generated .xcodeproj file with Xcode

- Switch to the application target

	![](img/img7.png)
	
- Run the app

	![](img/img8.png)
