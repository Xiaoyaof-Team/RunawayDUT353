target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithWrongBackground.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithWrongBackground.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
