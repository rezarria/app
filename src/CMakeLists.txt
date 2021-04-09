add_executable(app app.cpp)
target_link_libraries(app PUBLIC rezlib)
#target_include_directories(app PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/lib")
