target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/DoNotGoBack.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DoNotGoBack.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})
