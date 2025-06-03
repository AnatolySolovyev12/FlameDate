cmake_minimum_required(VERSION 3.10)

project(FlameDate)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui AxContainer Network WebSockets)

set(SOURCES 
"${CMAKE_SOURCE_DIR}/source/FlameDate.cpp"
"${CMAKE_SOURCE_DIR}/source/FlameDate.h"

"${CMAKE_SOURCE_DIR}/source/GeneralParam.cpp"
"${CMAKE_SOURCE_DIR}/source/GeneralParam.h"

"${CMAKE_SOURCE_DIR}/source/ProcessObject.cpp"
"${CMAKE_SOURCE_DIR}/source/ProcessObject.h"

"${CMAKE_SOURCE_DIR}/source/TelegramJacket.cpp"
"${CMAKE_SOURCE_DIR}/source/TelegramJacket.h"

"${CMAKE_SOURCE_DIR}/source/ui_FlameDate.h"
"${CMAKE_SOURCE_DIR}/source/ui_GeneralParam.h"

"${CMAKE_SOURCE_DIR}/source/main.cpp"
) # Добавьте сюда ваши файлы


qt6_wrap_ui(GLOB_RECURSE UI_HEADERS 
"${CMAKE_SOURCE_DIR}/source/*.ui"
)

qt6_add_resources(RESOURCES "${CMAKE_SOURCE_DIR}/source/FlameDate.qrc")

qt6_wrap_cpp(MOC_SOURCES ${SOURCES})

add_executable(FlameDate_APP ${SOURCES} ${MOC_SOURCES} ${UI_HEADERS} ${RESOURCES})

target_include_directories(FlameDate_APP PRIVATE ${CMAKE_SOURCE_DIR}/source)

target_link_libraries(FlameDate_APP PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui Qt6::AxContainer Qt6::Network Qt6::WebSockets)