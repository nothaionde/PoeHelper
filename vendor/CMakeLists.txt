add_subdirectory(spdlog)
add_subdirectory(glfw)
add_subdirectory(glad)

add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE spdlog)
target_link_libraries(vendor INTERFACE glfw)
target_link_libraries(vendor INTERFACE glad)
target_link_libraries(vendor INTERFACE imgui-docking)

target_include_directories(vendor INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include
        ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
        ${CMAKE_CURRENT_SOURCE_DIR}/imgui-docking
        ${CMAKE_CURRENT_SOURCE_DIR}/IconFontCppHeaders
        ${CMAKE_CURRENT_SOURCE_DIR}/stb_image
        )

# -------------- IMGUI static library creation`
#
set(IMGUI_PATH ${CMAKE_CURRENT_LIST_DIR}/imgui-docking)
file(GLOB IMGUI_GLOB
        ${IMGUI_PATH}/imgui.h
        ${IMGUI_PATH}/imgui.cpp
        ${IMGUI_PATH}/imconfig.h
        ${IMGUI_PATH}/imgui_demo.cpp
        ${IMGUI_PATH}/imgui_draw.cpp
        ${IMGUI_PATH}/imgui_internal.h
        ${IMGUI_PATH}/imstb_rectpack.h
        ${IMGUI_PATH}/imstb_textedit.h
        ${IMGUI_PATH}/imstb_truetype.h
        ${IMGUI_PATH}/imgui_tables.cpp
        ${IMGUI_PATH}/imgui_widgets.cpp

        # specific bindings...
        ${IMGUI_PATH}/backends/imgui_impl_glfw.h
        ${IMGUI_PATH}/backends/imgui_impl_glfw.cpp
        ${IMGUI_PATH}/backends/imgui_impl_opengl3.h
        ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_PATH}/backends/imgui_impl_opengl3_loader.cpp)
add_library("imgui-docking" STATIC ${IMGUI_GLOB})
target_include_directories("imgui-docking" PUBLIC ${IMGUI_PATH})
target_link_libraries("imgui-docking" PRIVATE glfw)
# ----------------------------------------------------------------------