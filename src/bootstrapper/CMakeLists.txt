set(BOOTSTRAPPER_TARGET_NAME bootstrapper)

configure_file(bootstrapper.rc.in resources/bootstrapper.rc)

file(GLOB BOOTSTRAPPER_HEADERS LIST_DIRECTORIES=false *.h)
file(GLOB BOOTSTRAPPER_SOURCES LIST_DIRECTORIES=false *.cpp)
file(GLOB BOOTSTRAPPER_RESOURCES LIST_DIRECTORIES=false ${CMAKE_CURRENT_BINARY_DIR}/resources/*.rc)

add_executable(${BOOTSTRAPPER_TARGET_NAME}
    WIN32
    ${BOOTSTRAPPER_HEADERS}
    ${BOOTSTRAPPER_SOURCES}
    ${BOOTSTRAPPER_RESOURCES}
)

target_compile_definitions(${BOOTSTRAPPER_TARGET_NAME}
    PRIVATE
        UNICODE
)

set_target_properties(${BOOTSTRAPPER_TARGET_NAME}
    PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)

install(TARGETS ${BOOTSTRAPPER_TARGET_NAME})
