# Setup instructions for an OS X Project using Xcode

## Overview

This doc explains how to build SFML under OS X and
how to set up an Xcode project for the project.

## Prerequisites

- Xcode (Command line tools need to be installed; see below.)
- CMake
- Doxygen (optional; needed only to generate docs)

To install the Xcode command line tools, start Xcode and select
_Xcode ... Preferences_, then select the _Downloads_ tab, and
then install _Command Line Tools_ if not already installed.

## Clone and build SFML 2

Clone SFML 2 outside of $PROJ.

    mkdir sfml2
    cd sfml2
    git clone https://github.com/LaurentGomila/SFML.git

Configure SFML.

    mkdir build

Run cmake.

    cmake-gui

Set the source code folder by browsing to _sfml2/SFML_.

Set the destination folder by browsing to _sfml2/build_.

Click on the _Configure_ button.

For the project generator, choose _Unix Makefiles_ (not _Xcode_) and select to
use default native compilers.

Make the following settings.

    BUILD_SHARED_LIBS        checked
    CMAKE_BUILD_TYPE         Release
    CMAKE_OSX_ARCHITECTURES  i386;x86_64
    SFML_BUILD_FRAMEWORKS    unchecked

Check or uncheck other options as desired.

The CMAKE_OSX_ARCHITECTURES setting results in universal binaries.  
See [this page](http://www.mjbshaw.com/2013/02/building-sfml-2-with-c11-on-os-x.html).

See [these instructions](http://www.sfml-dev.org/tutorials/2.0/compile-with-cmake.php) 
for more information on building SFML.

Build and install.

    cd build
    make
    sudo make install

The installation will add templates to the following location.

    /Library/Developer/Xcode/Templates/SFML

The installation will add sndfile.framework and freetype.framework 
to the folder specified by CMAKE_INSTALL_FRAMEWORK_PREFIX.  
The default is the following.

    /Library/Frameworks


## Create xcode project

Open xcode and create an SFML App project under $PROJ/osx.
You need to check the boxes to include the window module, audio module and
graphics modules to get the starter code to build.

I had to change the architecture to _64-bit Intel_ under Build Settings.
I don't know how to build for other architectures; it might be the way
SFML was built.

