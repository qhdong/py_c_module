all: sample.so
.PHONY: all

sample.o: sample.c sample.h
	gcc -fPIC -c -I/usr/include/python2.7 -I/usr/lib/python2.7 sample.c

sample.o: py_sample.c sample.o
	gcc -fPIC -c -I/usr/include/python2.7 -I/usr/lib/python2.7 sample.c

sample.so: sample.c sample.h py_sample.c
	gcc -g -Wall -shared -fPIC -o sample.so sample.c py_sample.c
