project(peak)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_COMPILER "g++")
set(CXX=g++-10.2)

set(CMAKE_CXX_COMPILER_ID GNU)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(impl)
add_subdirectory(test)

find_package(Doxygen OPTIONAL_COMPONENTS dot)
if (DOXYGEN_FOUND)
  set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${CMAKE_SOURCE_DIR}/README.md")
  doxygen_add_docs(doc
    ${CMAKE_SOURCE_DIR}
  )
endif(DOXYGEN_FOUND)

add_custom_target(ALL COMMAND make run
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/impl
)


# https://valelab4.ucsf.edu/svn/3rdpartypublic/boost/libs/bimap/doc/html/boost_bimap/one_minute_tutorial.html
# https://www.boost.org/doc/libs/1_67_0/libs/bimap/doc/html/boost_bimap/bimap_and_boost/boost_libraries_that_work_well_with_boost_bimap.html
# https://scicomp.ethz.ch/public/manual/Boost/1.55.0/bimap.pdf
