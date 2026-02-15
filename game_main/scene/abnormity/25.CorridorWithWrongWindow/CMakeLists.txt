target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithWrongWindow.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithWrongWindow.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
