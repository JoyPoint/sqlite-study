# We do not recommend using GLOB to collect a list of source files from your
# source tree. If no CMakeLists.txt file changes when a source is added or
# removed then the generated build system cannot know when to ask CMake to
# regenerate.
set(sldb_source_files
    slfdb_shell.cpp
    slmdb_shell.cpp
    slhdb.cpp
)

# Add a library to the project using the specified source files.
# BUILD_SHARED_LIBS
add_library(sldb SHARED ${sldb_source_files})
add_library(sldb_static STATIC ${sldb_source_files})

# Targets can have properties that affect how they are built.
set_target_properties(sldb PROPERTIES VERSION 12.03.12 SOVERSION 1)
set_target_properties(sldb PROPERTIES OUTPUT_NAME "sldb")

# Link a target to given libraries.
target_link_libraries(sldb)
#target_link_libraries(sldb_lib_static enc_base enc_rdb_sybase)

# Specify rules to run at install time.
# DESTINATION specify the directory on the disk to witch a file will be
# installed. 
# CMAKE_INSTALL_PREFIX
install(TARGETS sldb sldb_static DESTINATION lib)
#install(DIRECTORY ./ DESTINATION include/enc/saplib PATTERN "*.h" PATTERN "*.hpp")
# file(GLOB varible [RELATIVE path] [globbing expressions]...)
file(GLOB sldb_header_files "*.h" "*.hpp")
install(FILES ${sldb_header_files} DESTINATION include/sldb)

if(CMAKE_C_FLAGS_DEBUG)
add_subdirectory(test)
add_subdirectory(performance)
endif()

# vim: set tabstop=2 shiftwidth=2 expandtab:
