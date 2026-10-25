target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/Bsp/Inc"
        "${CMAKE_CURRENT_LIST_DIR}/Devices/Inc"
        "${CMAKE_CURRENT_LIST_DIR}/EtherCAT"
        "${CMAKE_CURRENT_LIST_DIR}/Start/Inc"
)

file(GLOB_RECURSE SOURCES "Bsp/*.c" "Devices/*.c" "EtherCAT/*.c" "Start/*.c")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})