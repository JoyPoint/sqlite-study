OBJ=mem_file.c
TAR=libmem_file.so
C=gcc
CFLAGS=-shared -fPIC -Wall -g -L/home/liangxx/local/lib/ -lsqlite3 -o

$(TAR):$(OBJ)
	$(C) $(OBJ) $(CFLAGS) $(TAR)

clean:
	rm -f $(TAR)
