target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ToiletWithSomeone.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ToiletWithSomeone.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
