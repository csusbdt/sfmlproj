# Setup instructions for a Visual Studio Project using Xcode

## Overview

This doc explains how to set up the contents of the vs2010 folder,
which is used to store files needed for building for Windows targets.

## Prerequisites

- Visual Studio 2010 Express
- CMake
- Doxygen (optional; needed only to generate docs)

I used the windows installer to install cmake and I selected to have cmake added to the system path.

## Clone and build SFML 2

Clone SFML 2.

    mkdir sfml2
    cd sfml2
    git clone https://github.com/LaurentGomila/SFML.git

The following instructions should be done in a regular console window
(not Git Bash).
	
Configure SFML.

    mkdir build

Run the vcvars32.bat to set up the environment for building with Visual C++.  
On my system, I ran the following; you might need to use a different path.

    "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\vcvars32.bat"
	
Start the GUI version of cmake.

    cmake-gui

For the source folder, use $PROJ/vs2010/sfml2/SFML; 
for the destination folder, use $PROJ/vs2010/sfml2/build.
Press _Configure_.

In the first screen, select _NMake makefiles_ for the type of compilation.

In the next screen, select the following build options.

    BUILD_SHARED_LIBS
    SFML_BUILD_DOC                 // requires doxygen

See [these instruction](http://www.sfml-dev.org/tutorials/2.0/compile-with-cmake.php) 
for more explanation.

Press _Configure_ again.
 
Press _Generate_.
 
Build.

    cd build
    nmake
	
Run a command prompt as administrator, make the build folder
the current directory, set up environment to build with
visual studio, and then install.
	
	"C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\vcvars32.bat"
    nmake install

The installation will add the following folder.

    C:\Program Files (x86)\SFML

	
## Create Visual Studio project

The following instructions are for dynamic linking with SFML.

Open Visual Studio Express and create an SFML App project under $PROJ/vs2010.

See [this tutorial](http://sfml-dev.org/tutorials/2.0/start-vc.php) for instructions on how to
create a project.  Here is how I did it.

Create a C++ Win32 project called _sam_.  I specified a location of _$PROJ/cv2010_
and I selected to not create a folder for the solution.
	
Set the following include path.

    $(ProjectDir)..\sfml2\SFML\include

Set the following libraries:

    sfml-graphics.lib
	sfml-window.lib
	sfml-system.lib
	sfml-main.lib

Set the following library path.
	
	$(ProjectDir)..\sfml2\build\lib

Add the following to Environment under Debugging.

    PATH=$(PATH);$(ProjectDir)..\sfml2\build\lib
	
Replace ain.cpp with the following.

''''
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
''''

