cmake_minimum_required (VERSION 3.8)
cmake_minimum_required (VERSION 3.8)
project (PoeHelper)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)

# Add source to this project's executable.
add_executable (PoeHelper WIN32 "src/PoeHelper.cpp" 
"src/Core/Application.h" "src/Core/Application.cpp"
"src/Core/Window.h"
 "src/Core/Input.h" 
"src/ImGui/ImGuiLayer.h" "src/ImGui/ImGuiLayer.cpp"
"src/PoeHelper/PoeHelperApplication.h"
"src/Utils/Constants.h"
"src/Window/GLFWWindow.h" "src/Window/GLFWWindow.cpp"
"src/Utils/Constants.cpp" 
"src/ImGui/Panels/Panel.h" "src/ImGui/Panels/Panel.cpp" 
"src/ImGui/Panels/HeaderPanel.h" "src/ImGui/Panels/HeaderPanel.cpp" 
"src/Utils/FileUtils.h" "src/Utils/FileUtils.cpp" 
"src/ImGui/Panels/CentralDockingSpace.h" "src/ImGui/Panels/CentralDockingSpace.cpp"
"src/Utils/TextureUtils.h" "src/Utils/TextureUtils.cpp"
"src/ImGui/Panels/ConfigPanel.h" "src/ImGui/Panels/ConfigPanel.cpp" 
"src/Utils/WidgetUtils.h" "src/Utils/WidgetUtils.cpp"    
"src/Window/GLFWInput.h" "src/Window/GLFWInput.cpp" "src/Core/MouseCodes.h" "src/ApplicationLogic/PoeHelperCraftingConstants.h" "src/ApplicationLogic/PoeHelperCraftingConstants.cpp")

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/bin"
)

target_include_directories ( ${PROJECT_NAME}
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	)

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PoeHelper PROPERTY CXX_STANDARD 20)
endif()
