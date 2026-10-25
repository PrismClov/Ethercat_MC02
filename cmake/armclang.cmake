# 设置CMake最低支持版本
cmake_minimum_required(VERSION 3.17)
cmake_policy(SET CMP0123 NEW)

# 交叉编译：设置目标机器类型
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m7)

# 设置编译器
# set(TOLLCHAIN_PATH "C:/Keil_v5/ARM/ARMCLANG/bin")
# set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/armclang.exe)
# set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/armclang.exe)
# set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PATH}/armclang.exe)
set(CMAKE_C_COMPILER armclang.exe)
set(CMAKE_CXX_COMPILER armclang.exe)
set(CMAKE_ASM_COMPILER armclang.exe)

set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_ASM_COMPILER_WORKS TRUE)

# 设置链接器
set(CMAKE_C_LINK_EXECUTABLE armlink.exe)
set(CMAKE_CXX_LINK_EXECUTABLE armlink.exe)
set(CMAKE_ASM_LINK_EXECUTABLE armlink.exe)

# 接口：设置Sections脚本
function(CMSIS_SetSectionsScriptPath path)
    set(SECTIONS_SCRIPT_PATH ${path} CACHE STRING "global")
endfunction()

# 接口：配置交叉编译
function(CMSIS_CrossCompilingConfiguration)
    # 设置变量
    set(C_TARGET_FLAG --target=arm-arm-none-eabi)
    set(ASM_TARGET_FLAG --target=arm-arm-none-eabi)
    set(LINKER_TARGET_FLAG --cpu=cortex-m7)

    set(FPU_FLAG)

    # 设置通用编译参数
    set(COMPILE_RULE_FLAG "-mcpu=${CMAKE_SYSTEM_PROCESSOR} ${FPU_FLAG}")

    set(C_NO_WARN "-Wno-unused-macros")

    # 设置C编译器选项
    set(CMAKE_C_FLAGS_INIT "${C_TARGET_FLAG} ${COMPILE_RULE_FLAG} ${C_NO_WARN} -fno-rtti -c -ffunction-sections -O1 -w" CACHE STRING "global")

    # 设置C++编译器选项
    set(CMAKE_CXX_FLAGS_INIT ${CMAKE_C_FLAGS_INIT} CACHE STRING "global")

    # 设置ASM编译器选项
    set(CMAKE_ASM_FLAGS_INIT " ${ASM_TARGET_FLAG} ${COMPILE_RULE_FLAG} -masm=auto -c -gdwarf-3 " CACHE STRING "global")

    # 判断链接脚本是否存在
    if(NOT SECTIONS_SCRIPT_PATH)
        message(FATAL_ERROR "You not set SECTIONS_SCRIPT_PATH!")
    endif()

    # TODO：打印.map文件版本
    # #设置链接选项
    # set(CMAKE_EXE_LINKER_FLAGS_INIT "\
    # ${LINKER_TARGET_FLAG} \
    # --library_type=microlib \
    # --strict \
    # --scatter ${SECTIONS_SCRIPT_PATH} \
    # --summary_stderr \
    # --info summarysizes \
    # --map --load_addr_map_info --xref --callgraph --symbols \
    # --info sizes --info totals --info unused --info veneers \
    # " CACHE STRING "global")

    # TODO：不打印.map文件版本
    # 设置链接选项
    set(CMAKE_EXE_LINKER_FLAGS_INIT "\
        ${LINKER_TARGET_FLAG} \
        --library_type=microlib \
        --strict \
        --scatter ${SECTIONS_SCRIPT_PATH} \
        --summary_stderr \
        --info summarysizes \
    " CACHE STRING "global")

    # 使能汇编
    # enable_language(ASM)
endfunction()
