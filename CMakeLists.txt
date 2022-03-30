add_library(swd-lib INTERFACE)
target_include_directories(swd-lib INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(swd-lib INTERFACE
    pico_sync
    hardware_clocks
)
target_sources(swd-lib INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/swdldr.c
    ${CMAKE_CURRENT_LIST_DIR}/swdldr.h
)
