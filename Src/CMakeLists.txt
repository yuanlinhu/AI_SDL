cmake_minimum_required(VERSION 2.8.4)
project(ChickenShooter)

set(SDL2_INCLUDE_DIR F:/study/AI_SDL/ThirdParty/SDL2-2.0.10/include)
set(SDL2_LIBRARY F:/study/AI_SDL/ThirdParty/SDL2-2.0.10/lib/x86/SDL2.lib)

set(SDL2_MAIN_LIBRARY F:/study/AI_SDL/ThirdParty/SDL2-2.0.10/lib/x86/SDL2main.lib)

set(SDL2_IMAGE_INCLUDE_DIR F:/study/AI_SDL/ThirdParty/SDL2_image-2.0.5/include)
set(SDL2_IMAGE_LIBRARY F:/study/AI_SDL/ThirdParty/SDL2_image-2.0.5/lib/x86/SDL2_image.lib)

set(SDL2_TTF_INCLUDE_DIR F:/study/AI_SDL/ThirdParty/SDL2_ttf-2.0.15/include)
set(SDL2_TTF_LIBRARY F:/study/AI_SDL/ThirdParty/SDL2_ttf-2.0.15/lib/x86/SDL2_ttf.lib)


set(SRC_INCLUDE F:/study/AI_SDL/Src/)



include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})


aux_source_directory(. SOURCE_FILES)

add_executable(ChickenShooter ${SOURCE_FILES})
target_link_libraries(ChickenShooter ${SDL2_LIBRARY})
target_link_libraries(ChickenShooter ${SDL2_MAIN_LIBRARY})
target_link_libraries(ChickenShooter ${SDL2_IMAGE_LIBRARY})
target_link_libraries(ChickenShooter ${SDL2_TTF_LIBRARY})



