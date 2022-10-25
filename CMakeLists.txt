project(rml_task)

add_executable(main main.cpp src/Points.cpp src/Cluster.cpp src/KMeans.cpp)
target_include_directories(main PUBLIC $(CMAKE_CURRENT_SOURCE_DIR)/include)