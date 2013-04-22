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
If that setting is not specified, then the default is the following.

    /Library/Frameworks


## Create xcode project

THIS DOES NOT WORK

Open xcode and create an SFML App project under $PROJ/mac.

Fill out the product name, organization name and company identifier fields.

Leave the C++ Compiler and Standard Library field at the default
setting of _C++98 with Clang and libstdc++_.

Leave the architectures field set to the default setting of _Universal_.

Set the SFML Binarys to _Dylibs_.  The default value of _Frameworks_ will

Leave the checked modules checked to include support for everything.
Alternatively, uncheck modules as desired.

Create folder $PROJ/sfml2.
Copy the include and Frameworks folders from the sfml build process into $PROJ/sfml2.
These will be added to version control so that other developers don't need to 
get or build SFML.

In the Xcode project, go to Build Phases and add the sndfile and freetype Frameworks
under the section _Link Binaries with Libraries_.



