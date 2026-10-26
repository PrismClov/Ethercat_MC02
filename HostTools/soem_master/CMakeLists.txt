cmake_minimum_required(VERSION 3.22)

project(ecat_soem_master LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

option(ECAT_FETCH_SOEM "Download SOEM 2.0.0 when it is not installed" OFF)

if(POLICY CMP0144)
    cmake_policy(SET CMP0144 NEW)
endif()

find_package(soem CONFIG QUIET)

if(NOT TARGET soem)
    if(DEFINED SOEM_ROOT AND EXISTS "${SOEM_ROOT}/CMakeLists.txt")
        set(SOEM_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory("${SOEM_ROOT}" "${CMAKE_CURRENT_BINARY_DIR}/soem")
    elseif(ECAT_FETCH_SOEM)
        include(FetchContent)
        set(SOEM_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
        FetchContent_Declare(
            soem_source
            GIT_REPOSITORY https://github.com/OpenEtherCATsociety/SOEM.git
            GIT_TAG        v2.0.0
            GIT_SHALLOW    TRUE
        )
        FetchContent_MakeAvailable(soem_source)
    else()
        message(FATAL_ERROR
            "未找到 SOEM。请安装 SOEM 2.0.0，或传入 "
            "-DSOEM_ROOT=/path/to/SOEM，或加 -DECAT_FETCH_SOEM=ON。")
    endif()
endif()

add_executable(ecat_soem_master src/soem_master.c)
target_link_libraries(ecat_soem_master PRIVATE soem)
target_include_directories(ecat_soem_master PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../src")

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ecat_soem_master PRIVATE -Wall -Wextra -Wpedantic)
endif()
