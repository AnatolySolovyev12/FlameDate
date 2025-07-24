cmake_minimum_required(VERSION 3.10)

project(FlameDate)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core  Network Gui)

# Указываем путь к библиотеке QXlsx
set(QXLSX_LIB_DIR "/home/solovev/Desktop/respos/123/QXlsx/build-QXlsx-Desktop-Debug")
set(QXLSX_INCLUDE_DIR "/home/solovev/Desktop/respos/123/QXlsx/QXlsx/header")  # Укажите правильный путь к заголовочным файлам QXlsx

# Добавляем библиотеку
add_library(QXlsx STATIC IMPORTED)
set_target_properties(QXlsx PROPERTIES
    IMPORTED_LOCATION "${QXLSX_LIB_DIR}/libQXlsx.a"
    INTERFACE_INCLUDE_DIRECTORIES "${QXLSX_INCLUDE_DIR}"
)


set(SOURCES 
"${CMAKE_SOURCE_DIR}/source/FlameDate.cpp"
"${CMAKE_SOURCE_DIR}/source/FlameDate.h"

"${CMAKE_SOURCE_DIR}/source/GeneralParam.cpp"
"${CMAKE_SOURCE_DIR}/source/GeneralParam.h"

"${CMAKE_SOURCE_DIR}/source/ProcessObject.cpp"
"${CMAKE_SOURCE_DIR}/source/ProcessObject.h"

"${CMAKE_SOURCE_DIR}/source/TelegramJacket.cpp"
"${CMAKE_SOURCE_DIR}/source/TelegramJacket.h"

"${CMAKE_SOURCE_DIR}/source/main.cpp"
) # Добавьте сюда ваши файлы

qt5_wrap_cpp(MOC_SOURCES ${SOURCES})

add_executable(FlameDate_APP ${SOURCES} ${MOC_SOURCES} ${UI_HEADERS})

target_include_directories(FlameDate_APP PRIVATE
${CMAKE_SOURCE_DIR}/source
${QXLSX_INCLUDE_DIR}
)

target_link_libraries(FlameDate_APP PRIVATE QXlsx  Qt5::Core Qt5::Network Qt5::Gui)

