cmake_minimum_required(VERSION 3.5)

project (FlameSteelCore)
set(CMAKE_BUILD_TYPE Debug)

if (MINGW32)
set(CMAKE_SYSTEM_NAME Windows)
SET(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
SET(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
SET(CMAKE_RC_COMPILER i686-w64-mingw32-windres)
set(CMAKE_RANLIB i686-w64-mingw32-ranlib)
endif()

if (OSXCROSS)
SET(CMAKE_SYSTEM_NAME Darwin)
SET(CMAKE_C_COMPILER o64-clang)
SET(CMAKE_CXX_COMPILER o64-clang++)
SET(CMAKE_C_COMPILER_AR x86_64-apple-darwin19-ar)
SET(CMAKE_CXX_COMPILER_AR x86_64-apple-darwin19-ar)
SET(CMAKE_LINKER x86_64-apple-darwin19-ld)
SET(ENV{OSXCROSS_MP_INC} 1)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCE_FILES
    "src/FlameSteelCore/*.cpp"
)

if (EMSCRIPTEN)
add_library(FlameSteelCore STATIC ${SOURCE_FILES})
elseif (MINGW32)
add_library(FlameSteelCore.dll SHARED ${SOURCE_FILES})
elseif (OSXCROSS)
add_library(FlameSteelCore STATIC ${SOURCE_FILES})
else()
add_library(FlameSteelCore SHARED ${SOURCE_FILES})
endif()

if (MINGW32)
set_target_properties(FlameSteelCore.dll PROPERTIES
        PREFIX ""
        SUFFIX ""
        LINK_FLAGS "-Wl,--add-stdcall-alias"
        POSITION_INDEPENDENT_CODE 0 # this is to avoid MinGW warning; 
        # MinGW generates position-independent-code for DLL by default
)
target_link_libraries(
                        FlameSteelCore.dll
                        -static-libgcc
                        -static-libstdc++
                        )
else()
install(DIRECTORY "${CMAKE_SOURCE_DIR}/src/FlameSteelCore"
        DESTINATION include/FlameSteelFramework
        FILES_MATCHING
        PATTERN "*.h"
)

install(TARGETS FlameSteelCore DESTINATION lib)
endif()
