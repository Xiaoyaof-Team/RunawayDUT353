target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithBanClassroomDoor.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CorridorWithBanClassroomDoor.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
