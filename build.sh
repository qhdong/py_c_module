gcc -fPIC -c -I/usr/include/python2.7 -I/usr/lib/python2.7 sample.c py_sample.c
gcc -shared -o sample.so sample.o py_sample.o
