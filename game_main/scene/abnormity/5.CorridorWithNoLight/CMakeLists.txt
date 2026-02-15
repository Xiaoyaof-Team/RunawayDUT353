target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithNoLight.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithNoLight.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
