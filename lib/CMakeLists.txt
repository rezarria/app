add_library(rezlib rezlib.cpp)

target_include_directories(rezlib PUBLIC "${PROJECT_CURRENT_SOURCE_DIR}")

target_link_libraries(rezlib PUBLIC sfml-graphics sfml-system sfml-window sfml-audio)
