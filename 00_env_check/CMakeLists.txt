cmake_minimum_required(VERSION 3.22)

project(stm32_no_board_demo C ASM)

add_executable(${PROJECT_NAME}.elf
    main.c
)

target_compile_options(${PROJECT_NAME}.elf PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -ffunction-sections
    -fdata-sections
    -Wall
    $<$<CONFIG:Debug>:-Og -g3 -gdwarf-2>
    $<$<CONFIG:Release>:-Os>
)

target_link_options(${PROJECT_NAME}.elf PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -specs=nosys.specs
    -nostartfiles
    -Wl,-e,main
    -Wl,--gc-sections
)
