add_library(dictionary_lib INTERFACE)
target_sources(dictionary_lib INTERFACE dictionary_head.h)

target_include_directories(dictionary_lib INTERFACE "${DICT_INCLUDE}")

if(MSVC)
    add_custom_target(dictionary_lib.headers SOURCES "${DICT_INCLUDE}/dictionary_head.h")
endif()

add_executable(sample_dict sample_dict.cpp)
target_link_libraries(sample_dict INTERFACE dictionary_lib)

#https://stackoverflow.com/questions/39887352/how-to-create-a-cmake-header-only-library-that-depends-on-external-header-files/39889958