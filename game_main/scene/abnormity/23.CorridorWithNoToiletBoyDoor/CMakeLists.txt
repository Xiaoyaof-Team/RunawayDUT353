target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithNoToiletBoyDoor.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithNoToiletBoyDoor.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
