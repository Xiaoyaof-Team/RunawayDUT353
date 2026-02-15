target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SomeoneWithClassroom.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SomeoneWithClassroom.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
