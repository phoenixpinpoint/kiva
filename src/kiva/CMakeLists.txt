set(kiva_src Main.cpp
             GroundPlot.cpp
             GroundPlot.hpp
             Input.cpp
             Input.hpp
             InputParser.cpp
             InputParser.hpp
             Simulator.cpp
             Simulator.hpp
             WeatherData.cpp
             WeatherData.hpp )


include_directories(${CMAKE_BINARY_DIR}/src/libkiva/)
add_executable(kiva ${kiva_src})

set(kiva_link_flags "")

if(${ENABLE_OPENMP})
  set(kiva_link_flags "${kiva_link_flags} -fopenmp")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${kiva_link_flags}")

set(links boost_date_time
          boost_program_options
          boost_filesystem
          boost_system
          yaml-cpp
          mgl-static
          lis )

target_link_libraries(kiva ${links} libkiva)
