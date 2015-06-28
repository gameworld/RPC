INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../../) 
link_directories(${CMAKE_SOURCE_DIR}/../../gen-cpp/)
add_executable(timeclient timeclient.cpp)
target_link_libraries(timeclient  thriftTimeService thrift)
