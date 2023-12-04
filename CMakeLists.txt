cmake_minimum_required(VERSION 3.16)
project(SIMPLE_GAME LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(SIMPLE_GAME 
    src/lib/Buckets.cpp
    src/lib/Buckets.h

    src/lib/Plant.h 
    src/lib/Plant.cpp

    src/lib/Resource.cpp
    src/lib/Resource.h

    src/lib/State.h
    src/lib/State.cpp

    src/lib/BackGround.cpp
    src/lib/BackGround.h

    src/lib/Encyclopedia.cpp
    src/lib/Encyclopedia.h

    src/lib/MainSlot.cpp
    src/lib/MainSlot.h

    src/lib/Minigame.cpp
    src/lib/Minigame.h

    src/lib/Setting.h
    src/lib/Setting.cpp

    src/lib/Shop.h
    src/lib/Shop.cpp

    src/lib/Slot.cpp
    src/lib/Slot.h

    src/lib/mini_game_JS.cpp

    src/main/main.cpp 

    

)
target_link_libraries(SIMPLE_GAME PRIVATE 
sfml-graphics
sfml-audio
)
target_compile_features(SIMPLE_GAME PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET SIMPLE_GAME
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SIMPLE_GAME>
        VERBATIM)
endif()

install(TARGETS SIMPLE_GAME)
