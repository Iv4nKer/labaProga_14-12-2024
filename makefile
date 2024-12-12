all:
	gcc main.c reaf.c -o smeta
	./smeta
clean:
	rm -f smeta
