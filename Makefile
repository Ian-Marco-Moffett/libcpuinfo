CFILES = $(wildcard src/*.c)
CFLAGS = -Werror-implicit-function-declaration -Iinclude -c

.PHONY: install test clean

lib/libcpuinfo.a: *.o
	@mkdir -p lib/
	ar rcs $@ *.o
	rm *.o

*.o: $(CFILES)
	gcc -c $^ -Iinclude

install:
	mkdir -p /usr/local/include/cpuinfo
	cp include/* /usr/local/include/cpuinfo/
	sudo install lib/* /usr/local/lib/

test:
	@mkdir -p bin/
	gcc tests/*.c -o bin/test -L/usr/local/lib -lcpuinfo 

clean:
	rm -rf lib
	rm -rf bin
