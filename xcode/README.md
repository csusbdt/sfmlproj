# Setup instructions for an OS X Project using Xcode

## Overview

This doc explains how to set up the contents of the xcode folder,
which is used to store files needed for building for OS X targets.

## Prerequisites

- Xcode
- CMake
- Doxygen (optional; needed only to generate docs)

## Clone and build SFML 2

Clone SFML 2.

    mkdir sfml2
    cd sfml2
    git clone https://github.com/LaurentGomila/SFML.git

Configure SFML.

    mkdir build

Run the gui version of cmake and follow 
[these instructions](http://www.sfml-dev.org/tutorials/2.0/compile-with-cmake.php) 
to create the build files. I selected the following.

    BUILD_SHARED_LIBS
    SFML_BUILD_FRAMEWORKS
    SFML_BUILD_EXAMPLES
    SFML_INSTALL_XCODE4_TEMPLATES 
    SFML_BUILD_DOC                 // requires doxygen

For the source folder, use $PROJ/osx/sfml2/SFML; 
for the destination folder, use $PROJ/osx/sfml2/build.
 
Build and install.

    cd build
    make
    sudo make install

The installation will add templates to the following folder.

    /Library/Frameworks

It leaves the framework folders under $PROJ/xcode/sfml2/build.

## Create xcode project

Open xcode and create an SFML App project under $PROJ/osx.
You need to check the boxes to include the window module, audio module and
graphics modules to get the starter code to build.

I had to change the architecture to _64-bit Intel_ under Build Settings.
I don't know how to build for other architectures; it might be the way
SFML was built.

