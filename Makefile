.PHONY: all clean

all: version createdb createtable retrieve

version: version.c
	gcc -std=c99 $^ -o $@ `mysql_config --cflags --libs`

createdb: createdb.c
	gcc -std=c99 $^ -o $@ `mysql_config --cflags --libs`

createtable: createtable.c
	gcc -std=c99 $^ -o $@ `mysql_config --cflags --libs`

retrieve: retrieve.c
	gcc -std=c99 $^ -o $@ `mysql_config --cflags --libs`

clean:
	rm -rf version
	rm -rf createdb
	rm -rf createtable
	rm -rf retrieve
