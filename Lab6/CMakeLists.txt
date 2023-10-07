# CMakeList.txt : CMake project for Lab6, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Lab6  "Lab6.h" "Entitate.h" "Entitate.cpp" "main.cpp"  "Repository.cpp" "Service.h" "Service.cpp" "UI.h" "UI.cpp" "tests.h" "tests.cpp" "Repository.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab6 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
