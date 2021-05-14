set(CLI_TARGET_NAME cli)

configure_file(cli.rc.in resources/cli.rc)

file(GLOB CLI_HEADERS LIST_DIRECTORIES=false *.h)
file(GLOB CLI_SOURCES LIST_DIRECTORIES=false *.cpp)
file(GLOB CLI_RESOURCES LIST_DIRECTORIES=false ${CMAKE_CURRENT_BINARY_DIR}/resources/*.rc)

add_executable(${CLI_TARGET_NAME}
    ${CLI_HEADERS}
    ${CLI_SOURCES}
    ${CLI_RESOURCES}
)

target_compile_features(${CLI_TARGET_NAME}
    PRIVATE
        cxx_std_17
)

target_compile_definitions(${CLI_TARGET_NAME}
    PRIVATE
        UNICODE
)

install(TARGETS ${CLI_TARGET_NAME}
	RUNTIME DESTINATION bin
)
