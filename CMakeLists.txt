project(rml_task)

add_executable(main main.cpp Points.cpp Cluster.cpp KMeans.cpp)
target_include_directories(main PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))