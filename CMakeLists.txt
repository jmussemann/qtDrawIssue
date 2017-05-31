cmake_minimum_required(VERSION 2.8)

project("QT_issue")
set(target_name QTISSUE)

#include the common stuff
#include( ./includecommon.cmake REQUIRED )

set(USE_QT5 1)

# Qt
if( USE_QT5 )
  find_package( Qt5 REQUIRED Widgets Gui)
  include_directories(SYSTEM ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} )
  #add_definitions(-DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -D_REENTRANT)
else()
  find_package( Qt4 REQUIRED )   # might need to add specifics like QtCore QtGui
  include(${QT_USE_FILE})
endif()

# generate the moc source
set( qt_moc_files
    src/mainwindow.h
    # other files you might have go here...
    )
if( USE_QT5 )
  qt5_wrap_cpp(cpp_qt ${qt_moc_files})
else()
  qt4_wrap_cpp(cpp_qt ${qt_moc_files})
endif()

# generate the ui headers
file(GLOB qt_ui_files  src/*.ui )
if( USE_QT5 )
  qt5_wrap_ui(h_qt ${qt_ui_files})
else()
  qt4_wrap_ui(h_qt ${qt_ui_files})
endif()

# include the ui header files directory...
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_definitions(
    -DWIN32_LEAN_AND_MEAN
    -D_THREAD_SAFE
    )


# find the sources, set them into an executable
include_directories(src)
file(GLOB cpp_ src/*.cpp)
file(GLOB h_   src/*.h)
add_executable(${target_name}  ${cpp_} ${h_}  ${cpp_qt}  ${h_qt} ${ICELIB_SOURCE} ${qrc_qt})

# Use C++11 standard
set_property(TARGET ${target_name} PROPERTY CXX_STANDARD 11)


# group certain source files (for IDE display purposes)
source_group( source FILES ${cpp_} ${h_})
source_group( source\\Qt_autogen FILES ${cpp_qt} ${h_qt} ${qrc_qt})
source_group( source\\Qt_resource FILES ${qt_qrc_files} ${qt_ui_files})


# libraries to link in
if( WIN32 )
    set(Extra_Libs Ws2_32 Kernel32 Psapi)
else()
    set(Extra_Libs pthread rt dl)
endif()
target_link_libraries(${target_name}
    ${QT_LIBRARIES} # Qt libs
    ${Extra_Libs}
)
if( USE_QT5 )
  qt5_use_modules( ${target_name} Gui Widgets )
endif()


# special properties
if(MSVC)
    set_target_properties( ${target_name} PROPERTIES WIN32_EXECUTABLE TRUE )
endif()
if(APPLE)
    set_target_properties( ${target_name} PROPERTIES MACOSX_BUNDLE TRUE )
endif()
