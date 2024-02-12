set(target ${DICT_TESTS})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
message(STATUS "hdrs VALUES ${hdrs}")
message(STATUS "srcs VALUES ${srcs}")
message(STATUS "MP2_INCLUDE VALUES ${DICT_INCLUDE}")
add_executable(${target} ${srcs} ${hdrs})

target_link_libraries(${target} INTERFACE dictionary_lib)
target_link_libraries(${target} PRIVATE gtest)
