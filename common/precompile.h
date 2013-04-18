// See google style guide: http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml

#include <assert.h>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
// See http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml#Copy_Constructors
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)
