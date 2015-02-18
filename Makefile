all: lib electrotest
	rm -rf ./lib/
	mkdir ./lib/
	cp -t ./lib/ libresistance.so libpower.so libcomponent.so
	
electrotest: main.o
	gcc -L./lib -Wall -o electrotest main.o -lresistance -lpower -lcomponent

main.o: main.c main.h
	gcc -c main.c

lib: libresistance.so libpower.so libcomponent.so
 

install:
	cp -f electrotest /usr/bin/
	cp -f -t /usr/lib/ libresistance.so libpower.so libcomponent.so 

libresistance.o: libresistance.c libresistance.h
	gcc -c -fPIC libresistance.c
libresistance.so: libresistance.o
	gcc -shared -fPIC -o libresistance.so libresistance.o
libpower.o: libpower.c libpower.h
	gcc -c -fPIC libpower.c
libpower.so: libpower.o
	gcc -shared -fPIC -o libpower.so libpower.o
libcomponent.o: libcomponent.c libcomponent.h
	gcc -c -fPIC libcomponent.c
libcomponent.so: libcomponent.o
	gcc -shared -fPIC -o libcomponent.so libcomponent.o

