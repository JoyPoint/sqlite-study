OBJ=libunencapsulated.cpp
TAR=libunencapsulated.so
CXX=g++
CXXFLAGS=-shared -fPIC -Wall \
	-g -I/home/liangxx/local/include/ -L/home/liangxx/local/lib/ -lsqlite3 -o

$(TAR):$(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(TAR)

clean:
	rm -f $(TAR)
