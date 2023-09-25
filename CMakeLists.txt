cmake_minimum_required(VERSION 3.26)
project(unitconverter)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_executable(${PROJECT_NAME} src/main.cpp
        src/models/Convertor.cpp
        src/models/Convertor.h
        src/controllers/Controller.cpp
        src/controllers/Controller.h
        src/views/ConsoleView.cpp
        src/views/ConsoleView.h
)

add_test(Test_0, "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}" "0")