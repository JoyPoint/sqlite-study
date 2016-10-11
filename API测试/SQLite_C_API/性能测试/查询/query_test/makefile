OBJ=query_test_mem.cpp
TAR=query_test_mem
CXX=g++
CXXFLAGS=-g -lsqlite3 -o

$(TAR):$(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(TAR)

clean:
	rm -f $(TAR)
