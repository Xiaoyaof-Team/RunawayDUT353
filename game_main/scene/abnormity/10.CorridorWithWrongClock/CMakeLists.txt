target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithWrongClock.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithWrongClock.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
