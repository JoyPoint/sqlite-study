OBJ=delete_test.cpp
TAR=delete_test
CXX=g++
CXXFLAGS=-g \
         -I/home/liangxx/local/include/boost/ \
         -I/home/liangxx/local/include/ \
         -L/home/liangxx/local/lib/ \
         -lsqlite3 -o

$(TAR):$(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(TAR)

clean:
	rm -f $(TAR)
