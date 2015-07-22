set( fregistersrc Register.cpp)
add_library(fregister ${fregistersrc})

link_directories(${CMAKE_BINARY_DIR})

set(fregistertesrsrc register_test.cpp)
add_executable(registertest ${fregistertesrsrc})
target_link_libraries(registertest fregister zookeeper_mt glog)