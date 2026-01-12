cmake_minimum_required(VERSION 3.16)

project(ChatFinalProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    tcpclient.h
    tcpclient.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    # Используем qt_add_executable без MANUAL_FINALIZATION — проще и надёжнее
    qt_add_executable(ChatFinalProject
        ${PROJECT_SOURCES}
        loginwindow.h loginwindow.cpp loginwindow.ui
        registerwindow.h registerwindow.cpp registerwindow.ui



    )
else()
    if(ANDROID)
        add_library(ChatFinalProject SHARED ${PROJECT_SOURCES})
    else()
        add_executable(ChatFinalProject ${PROJECT_SOURCES})
    endif()
endif()

target_link_libraries(ChatFinalProject PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(WIN32)
    target_link_libraries(ChatFinalProject PRIVATE ws2_32)
endif()

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ChatFinalProject)
endif()

set_target_properties(ChatFinalProject PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ChatFinalProject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
