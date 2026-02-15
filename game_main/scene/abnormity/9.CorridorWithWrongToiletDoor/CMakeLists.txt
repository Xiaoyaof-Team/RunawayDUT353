target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithWrongToiletDoor.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithWrongToiletDoor.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
