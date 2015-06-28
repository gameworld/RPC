INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../../) 
link_directories(${CMAKE_SOURCE_DIR}/../../gen-cpp/)
add_executable(server timeservice_server.skeleton.cpp)
target_link_libraries(server  thriftTimeService thrift)