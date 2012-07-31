project(FCDControl)
set(FCDControl_sources main.c)

include_directories(../FCDlib/)
add_executable(FCDControl main.c)
target_link_libraries(FCDControl FCD hidapi argtable2)

install(TARGETS FCDControl RUNTIME DESTINATION bin COMPONENT runtime)

