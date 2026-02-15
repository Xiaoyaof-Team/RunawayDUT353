target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/abnormity.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AllAbnormity.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/abnormity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AllAbnormity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/classroom.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/classroom_desk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/corridor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mirror.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/rule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/toilet.cpp
)

target_include_directories(game_start PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR})