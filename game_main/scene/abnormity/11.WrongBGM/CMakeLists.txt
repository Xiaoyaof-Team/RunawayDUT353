target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/WrongBGM.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WrongBGM.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
