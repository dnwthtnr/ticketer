# CMakeList.txt : CMake project for iFixAndTicket, include source and define
# project specific logic here.
#

# Add source to this project's executable.
qt_add_executable (iFixAndTicket  "core.cpp" "core.h " "iFixAndTicket.h" "iFixAndTicket.cpp" "mainwindow.cpp" "mainwindow.h"  )


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET iFixAndTicket PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
