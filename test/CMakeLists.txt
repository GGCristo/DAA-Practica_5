cmake_minimum_required(VERSION "3.9.2")

project(RAM)

# file(GLOB SOURCES ../src/*.cpp)

# list(REMOVE_ITEM SOURCES "../src/main.cpp")

set(SOURCES
  ../src/m_dyv.cpp
  ../src/times.cpp
  ../src/monomio.cpp
  ../src/polinomio.cpp
  ../src/m_clasico.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(my_test ${SOURCES}
               test.cpp)
add_test(NAME my_test COMMAND my_test)
