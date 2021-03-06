# CC = arm-none-linux-gnueabi-gcc
# CC = arm-elf-gcc
CFLAGS = -Wall -W -Os -Wdeclaration-after-statement # -pedantic -ansi # -std=c89
OBJ_FILE = sdb_utility.o sdb_string.o sdb_stack_watch.o sdb_config.o sdb_bio.o\
		   sdb_vxprintf.o sdb_out.o sdb_in.o sdb_dump.o sdb_menu.o
HEAD_FILE = libsdb.h sdb_config.h sdb_internal.h

all: libsdb.a sdb_selftest

libsdb.a: $(OBJ_FILE)
	ar rc libsdb.a $^

%.o: %.c $(HEAD_FILE)
	$(CC) $(CFLAGS) -c -o $@ $<

sdb_selftest: sdb_selftest.c libsdb.a
	$(CC) $(CFLAGS) -DSDB_SELFTEST -DMAIN_ENTRY -I.\
		-c -o sdb_selftest.o sdb_selftest.c
	$(CC) $(CFLAGS) -L. -o $@ sdb_selftest.o -lsdb

.PHONY: clean
clean:
	-rm -f *.o *.d libsdb.a sdb_selftest

