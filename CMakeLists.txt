cmake_minimum_required(VERSION 3.5)

project(index VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        index_mainwindow.cpp
        index_mainwindow.h
        index_mainwindow.ui
        sonwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(index
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        mybutton.h mybutton.cpp
        index_img.qrc
        detailpage.h detailpage.cpp
        sonwindow.h sonwindow.cpp
        slidepage.h slidepage.cpp
        mydialog.h mydialog.cpp
        graphview.h graphview.cpp
        wy_vector.h wy_vector.cpp
        img2.qrc
        img3.qrc
        list_mainwindow.h list_mainwindow.cpp
        listpage.h listpage.cpp
        uidefine.h
        lnode.h lnode.cpp
        myarrowitem.h myarrowitem.cpp
        linklist.h linklist.cpp
        clinklist.h clinklist.cpp
        dlinklist.h dlinklist.cpp
        dlnode.h dlnode.cpp
        graphpage.cpp graphpage.h graphpage.ui
        stackvisualizationwidget.cpp stackvisualizationwidget.h treepage.cpp treepage.h
        treesonwindow.h treesonwindow.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET index APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(index SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(index
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(index PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.index)
endif()
set_target_properties(index PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS index
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(index)
endif()
