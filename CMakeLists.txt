# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.25)

project("iFixAndTicket")

list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.5.3/msvc2019_64")
list(APPEND CMAKE_PREFIX_PATH "C:/User/ifix/source/repos/json-develop/single_include")

message(STATUS ${CMAKE_PREFIX_PATH})

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(DQT6_DIR "C:/Qt/6.5.3/msvc2019_64/lib/cmake/Qt6")
# project ("iFixAndTicket")

set(CMAKE_CXX_STANDARD 16)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-D Qt6_DIR=C:/Qt/6.5.3/msvc2019_64/lib/cmake/Qt6 -D QT_ADDITIONAL_PACKAGES_PREFIX_PATH=C:/Qt/6.8.2/mingw_64 -Zc:rvalueCast -Zc:inline -Zc:strictStrings -Zc:throwingNew -permissive- -Zc:__cplusplus -Zc:externConstexpr -utf-8 -w34100 -w34189 -w44996 -w44456 -w44457 -w44458")

message(STATUS ${CMAKE_PREFIX_PATH})
# Include sub-projects.

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

include_directories("${CMAKE_SOURCE_DIR}/external")


add_subdirectory ("ticketer")


target_link_libraries(iFixAndTicket PRIVATE Qt6::Widgets Qt6::Core)
