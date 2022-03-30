add_library(swd-lib INTERFACE)
target_include_directories(swd-lib INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(swd-lib INTERFACE
    pico_sync
)
target_sources(swd-lib INTERFACE swdldr.c swdldr.h)
