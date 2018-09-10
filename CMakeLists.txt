cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME scrolling-text)
project(${PROJECT_NAME})


set(${CMAKE_PROJECT_NAME}_SKETCH scrolling-text.ino)

#### Uncomment below additional settings as needed.
set(${CMAKE_PROJECT_NAME}_BOARD uno)
set(${CMAKE_PROJECT_NAME}_PORT COM5)
# set(mega.build.mcu atmega2560)
# set(mega.upload.protocol wiring)
# set(mega.upload.speed 115200)

generate_arduino_firmware(${CMAKE_PROJECT_NAME})
