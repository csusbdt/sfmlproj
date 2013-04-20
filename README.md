sfmlproj
========

Illustration on how to organize a project using SFML to build executables
for Windows and Mac desktops.

This approach does not use Cmake; instead, it requires developers
to manually synchronize the build files for Visual Studio and Xcode.

This approach builds SFML from source on Windows and Mac, and then adds
the dynamic link libraries to the project repository.
Not all developers need to build SFML; all libraries needed by project
developers are placed in version control.

In these notes, $PROJ refers to the top level folder in this repository.

Here is the folder organiztion.

    $PROJ
        win        Windows-specific source code and libraries
        mac        Mac-specific source code and libraries
        sfml2      SFML header files
        resources  Files loaded by program at runtime

NOTE: in Xcode, these instructions only build for the 64-bit Intel architecture.

## Future

Maybe I will redo using Cmake.  See:

http://stackoverflow.com/questions/7108234/building-for-x86-and-x64-platform-with-cmake-with-xcode-and-visual-studio

https://github.com/LaurentGomila/SFML/wiki/Tutorial%3A-Build-your-SFML-project-with-CMake


