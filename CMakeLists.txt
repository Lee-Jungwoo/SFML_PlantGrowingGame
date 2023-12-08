# cmake_minimum_required(VERSION 3.16)
# project(SIMPLE_GAME LANGUAGES CXX)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# include(FetchContent)
# FetchContent_Declare(SFML
#     GIT_REPOSITORY https://github.com/SFML/SFML.git
#     GIT_TAG 2.6.x)
# FetchContent_MakeAvailable(SFML)

# add_executable(SIMPLE_GAME 
#     src/lib/Buckets.cpp
#     src/lib/Buckets.h

#     src/lib/Plant.h 
#     src/lib/Plant.cpp

#     src/lib/Resource.cpp
#     src/lib/Resource.h

#     src/lib/State.h
#     src/lib/State.cpp

#     src/lib/BackGround.cpp
#     src/lib/BackGround.h

#     src/lib/Encyclopedia.cpp
#     src/lib/Encyclopedia.h

#     src/lib/Ency_Info.h
#     src/lib/Ency_Info.cpp

#     src/lib/MainSlot.cpp
#     src/lib/MainSlot.h

#     src/lib/Minigame.cpp
#     src/lib/Minigame.h

#     src/lib/Setting.h
#     src/lib/Setting.cpp

#     src/lib/Shop.h
#     src/lib/Shop.cpp

#     src/lib/Slot.cpp
#     src/lib/Slot.h



#     src/lib/mini_game_JS.cpp

#     src/lib/mini_game_HM_1.h
#     src/lib/mini_game_HM_1.cpp
#     src/lib/mini_game_HM_2.h
#     src/lib/mini_game_HM_2.cpp

#     src/main/main.cpp 

     

# )
# target_link_libraries(SIMPLE_GAME PRIVATE 
# sfml-graphics
# sfml-audio
# )
# target_compile_features(SIMPLE_GAME PRIVATE cxx_std_17)

# if(WIN32)
#     add_custom_command(
#         TARGET SIMPLE_GAME
#         COMMENT "Copy OpenAL DLL"
#         PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SIMPLE_GAME>
#         VERBATIM)
# endif()

# install(TARGETS SIMPLE_GAME)

cmake_minimum_required(VERSION 3.16)
project(SIMPLE_GAME LANGUAGES CXX)

# Set the output directory for the build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Option to build shared libraries (set to OFF for static)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Fetch and make available SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Define the source files for the project
set(SOURCE_FILES
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

    src/lib/Ency_Info.h
    src/lib/Ency_Info.cpp

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

    src/lib/mini_game_HM_1.h
    src/lib/mini_game_HM_1.cpp
    src/lib/mini_game_HM_2.h
    src/lib/mini_game_HM_2.cpp

    src/main/main.cpp 

     
)

# Create the executable target
add_executable(SIMPLE_GAME ${SOURCE_FILES})

# Link SFML libraries
target_link_libraries(SIMPLE_GAME PRIVATE 
    sfml-graphics
    sfml-audio
)

# Set C++ standard
target_compile_features(SIMPLE_GAME PRIVATE cxx_std_17)

# For Windows, copy OpenAL DLL
if(WIN32)
    add_custom_command(
        TARGET SIMPLE_GAME
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SIMPLE_GAME>
        VERBATIM)
endif()

# Create a bundle on macOS
if(APPLE)
    set_target_properties(SIMPLE_GAME PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_BUNDLE_NAME "SimpleGame"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.SimpleGame"
        OUTPUT_NAME "SimpleGame"
    )

    # Include the entire folder of assets
    file(GLOB_RECURSE ASSET_FILES 
        "${CMAKE_CURRENT_SOURCE_DIR}/*.png"
        )
    set_target_properties(SIMPLE_GAME PROPERTIES
        RESOURCE "${ASSET_FILES}"
    )

    # Install the bundle
    install(TARGETS SIMPLE_GAME
        BUNDLE DESTINATION ./bundle
        RUNTIME DESTINATION bin
    )

    # Configure the bundle
    install(CODE "
        include(BundleUtilities)
        fixup_bundle(\"${CMAKE_INSTALL_PREFIX}/SimpleGame.app\" \"\" \"\")"
    )
endif()
