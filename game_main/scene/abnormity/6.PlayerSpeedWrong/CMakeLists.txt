target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerSpeedWrong.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerSpeedWrong.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
