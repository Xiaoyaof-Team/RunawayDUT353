target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithNoClassroomDoor.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithNoClassroomDoor.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
