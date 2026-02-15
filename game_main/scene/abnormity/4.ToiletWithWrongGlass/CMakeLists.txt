target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ToiletWithWrongGlass.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ToiletWithWrongGlass.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
