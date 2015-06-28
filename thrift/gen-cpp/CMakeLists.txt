set(timelibsrc timeService_constants.cpp timeService_types.cpp timeservice.cpp)
add_library( thriftTimeService  STATIC ${timelibsrc})