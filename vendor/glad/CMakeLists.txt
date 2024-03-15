# glad/src/gl.c is the source file for glad library
add_library(glad STATIC src/gl.c)

# Include directory for glad headers
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
