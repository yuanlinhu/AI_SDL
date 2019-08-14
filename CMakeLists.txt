cmake_minimum_required(VERSION 2.8.4)
project(ChickenShooter)

set(SDL2_INCLUDE_DIR F:/study/AI_SDL/ThirdParty/SDL2-2.0.10/include)
set(SDL2_LIBRARY F:/study/AI_SDL/ThirdParty/SDL2-2.0.10/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
set(SOURCE_FILES F:/study/AI_SDL/Src/main.cpp)

add_executable(ChickenShooter ${SOURCE_FILES})
target_link_libraries(ChickenShooter ${SDL2_LIBRARY})