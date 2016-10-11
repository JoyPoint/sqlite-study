# Libraries:
#set(log_libs log4cxx apr-1 aprutil-1)
set(boost_libs boost_system boost_date_time boost_filesystem boost_thread)
set(sldb_libs sldb)
set(sqlite3_libs sqlite3)

# Test base:
#add_executable(test-base test-base.cpp)
#target_link_libraries(test-base ${sldb_libs} ${sqlite3_libs} ${boost_libs})

# Test class slfdb_shell:
add_executable(test-slfdb_shell test-slfdb_shell.cpp)
target_link_libraries(test-slfdb_shell ${sldb_libs} ${sqlite3_libs} ${boost_libs})

# Test class slmdb_shell:
add_executable(test-slmdb_shell test-slmdb_shell.cpp)
target_link_libraries(test-slmdb_shell ${sldb_libs} ${sqlite3_libs} ${boost_libs})

# Test class slhdb:
add_executable(test-slhdb test-slhdb.cpp)
target_link_libraries(test-slhdb ${sldb_libs} ${sqlite3_libs} ${boost_libs})
