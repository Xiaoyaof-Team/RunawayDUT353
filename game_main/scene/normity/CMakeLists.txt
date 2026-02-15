target_sources(game_start PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/classroom_desk.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/classroom.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/classroom.hpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/corridor.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/corridor.hpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/mirror.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/rule.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/scene.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/scene.hpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/toilet.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/toilet.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/corridor_clock.cpp
)

target_include_directories(game_start PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})