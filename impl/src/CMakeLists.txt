include_directories(${peak_SOURCE_DIR}/impl/inc)

add_library(event_generator event_generator.cpp)
add_library(peak_analyzer peak_analyzer.cpp)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.49.0)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(peak main.cpp event_generator.cpp peak_analyzer.cpp)
    target_link_libraries(peak ${Boost_LIBRARIES})
endif()
