target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SomeoneWithToilet.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SomeoneWithToilet.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
