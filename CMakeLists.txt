cmake_minimum_required(VERSION 3.10)
find_package(OpenCV REQUIRED)

set(myapp_name myapp) #myapp_name must match program name in launch.json and code-runner settings.json
set(mylib_name mylib)
set(compile_mode 1) #0 for both lib and app, 1 for app, 2 for lib   
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${ROOT_DIR}/build/exe)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_DIR}/lib)
project(cv)

set(libsrc_list)
set(src_list)
set(lib_list)
set(header_list)
set(inc_list)

file(GLOB_RECURSE src_list ${ROOT_DIR}/src/*.cpp)
file(GLOB_RECURSE libsrc_list ${ROOT_DIR}/libsrc/*.cpp)
file(GLOB_RECURSE header_list ${ROOT_DIR}/inc/*.h ${ROOT_DIR}/src/*.h ${ROOT_DIR}/libsrc/*.h)
file(GLOB lib_list ${ROOT_DIR}/lib/*)

foreach(header_file ${header_list})
    get_filename_component(header_dir ${header_file} DIRECTORY)
    list(APPEND inc_list ${header_dir} " ")
endforeach(header_file ${header_list})

list(APPEND inc_list /usr/include " ")
list(APPEND inc_list /usr/local/include " ")
list(APPEND inc_list /usr/local/incluse/opencv4 " ")
list(APPEND inc_list /usr/local/incluse/opencv4/opencv2 " ")



include_directories(${inc_list})
add_compile_options("-g")

message(STATUS "*************************************")
message(STATUS "opencvlib_list:"${OpenCV_LIBS})
message(STATUS "*************************************")
message(STATUS "src_list:" ${src_list})
message(STATUS "*************************************")
message(STATUS "libsrc_list:" ${libsrc_list})
message(STATUS "*************************************")
message(STATUS "lib_list:" ${lib_list})
message(STATUS "*************************************")
message(STATUS "inc_list:" ${inc_list})
message(STATUS "*************************************")


if(compile_mode EQUAL 0)
    message(STATUS "compile all")
    message(STATUS "*************************************")

    add_executable(${myapp_name} ${src_list})
    add_library(${mylib_name} SHARED ${libsrc_list})
    target_link_libraries(${myapp_name} ${OpenCV_LIBS} ${lib_list})


elseif(compile_mode EQUAL 1)
    message(STATUS "compile myapp only")
    message(STATUS "*************************************")

    add_executable(${myapp_name} ${src_list})
    target_link_libraries(${myapp_name} ${OpenCV_LIBS} ${lib_list})
else(compile_mode EQUAL 2)
    message(STATUS "compile mylib only")
    message(STATUS "*************************************")
    add_library(${mylib_name} SHARED ${libsrc_list})
endif()