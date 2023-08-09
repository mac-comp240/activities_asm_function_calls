CC = gcc
OGFLAGS = -Og
O1FLAGS = -O1
CFLAGS = $(OFLAGS) -Wall -g

CINC =
F64 =-m64


%.s: %.c
	$(CC) $(OGFLAGS) $(CINC) -S $(F64) $<

%_opt01.s: %.c
	$(CC) $(O1FLAGS) $(CINC) -S $(F64) $< -o $*_optO1.s

# %_opt00.s: %.c
# 	$(CC) $(OGFLAGS) $(CINC) -S $(F64) $< -o $*_opt00.s


all: files

files:	basic_files boolean_files absdiff_files
basic_files: basic_condits.s
boolean_files: boolean_funcs.s
absdiff_files: absdiff.c

clean:
	rm -f *.s *.opt00_s *.opt01_s
