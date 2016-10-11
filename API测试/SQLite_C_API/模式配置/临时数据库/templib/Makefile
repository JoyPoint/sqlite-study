OBJ=mytemp.cpp mytemp.h
TAR=mytemp
CXX=g++
CXXFLAGS=-g -I/home/liangxx/local/include/ \
         -L/home/liangxx/local/lib/ -lsqlite3 \
         -I/home/liangxx/local/include/boost/ \
         -o

$(TAR):$(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(TAR)

clean:
	rm -f $(TAR)
