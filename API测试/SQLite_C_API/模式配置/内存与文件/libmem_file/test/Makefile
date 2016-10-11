OBJ=test-mem_file.c
TAR=test-mem_file
C=gcc
CFLAGS=-g -L../ -lmem_file -L/home/liangxx/local/lib/ -lsqlite3 -o

$(TAR):$(OBJ)
	$(C) $(OBJ) $(CFLAGS) $(TAR)

clean:
	rm -f $(TAR)
