OBJ=test-unencapsulated.cpp
TAR=test-unencapsulated
CXX=g++
CXXFLAGS=-g -I../ -L../ -lunencapsulated -L/home/liangxx/local/lib/ -lsqlite3 -o

$(TAR):$(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(TAR)

clean:
	rm -f $(TAR)
