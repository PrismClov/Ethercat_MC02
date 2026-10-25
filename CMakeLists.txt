cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME EcatDemoMC02)

# Include toolchain file
if(NOT DEFINED armclang)
    set(armclang ON)
endif()

if (armclang)
    include("cmake/armclang.cmake")
    #设置Sections脚本路径
    CMSIS_SetSectionsScriptPath(${CMAKE_HOME_DIRECTORY}/MDK-ARM/${CMAKE_PROJECT_NAME}/${CMAKE_PROJECT_NAME}.sct)
    #配置交叉编译
    CMSIS_CrossCompilingConfiguration()

    set(mustfile ${CMAKE_HOME_DIRECTORY}/MDK-ARM/startup_stm32h723xx.s)
else ()
    include("cmake/gcc-arm-none-eabi.cmake")

    set(mustfile ${CMAKE_HOME_DIRECTORY}/startup_stm32h723xx.s ${CMAKE_HOME_DIRECTORY}/Core/Src/sysmem.c ${CMAKE_HOME_DIRECTORY}/Core/Src/syscalls.c)
endif ()


# Core project settings
project(${CMAKE_PROJECT_NAME} C ASM)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)
add_subdirectory(User)
add_subdirectory(Middlewares/DSP_math)
add_subdirectory(Middlewares/SEGGER_RTT)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
        ${mustfile}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
        -DLAN9252
        -D__MICROLIB
        -DUSE_FULL_LL_DRIVER
        -DUser_Debug

)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
