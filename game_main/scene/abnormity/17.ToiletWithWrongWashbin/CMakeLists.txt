target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ToiletWithWrongWashbin.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ToiletWithWrongWashbin.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
