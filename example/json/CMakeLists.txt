if (Boost_VERSION_STRING VERSION_GREATER_EQUAL "1.75")
    add_executable(json_create json_create.cpp)
    add_executable(json_open json_open.cpp)
    add_executable(jgraph jgraph.cpp)
endif()