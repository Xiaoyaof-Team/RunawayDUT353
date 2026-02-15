target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SomeoneWithCorridor.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SomeoneWithCorridor.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
