CC = gcc
OGFLAGS = -Og
O1FLAGS = -O1
CFLAGS = $(OFLAGS) -Wall -g

CINC =
F64 =-m64


files: mstore-exe.d assembly

assembly:  ms_main.c mstore.c mult2.c mult2.h mstore.h
	$(CC) $(CFLAGS) $(CINC) $(F64) -S mult2.c mstore.c ms_main.c
mstore-exe.d: mstore.c mult2.c ms_main.c mult2.h mstore.h
	$(CC) $(CFLAGS) $(CINC) $(F64) mult2.c mstore.c ms_main.c -o mstore
	objdump -d mstore > mstore-exe.d
#	rm -f mstore

clean:
	rm -f *~
	rm -f *.s *.d
	rm -f mstore