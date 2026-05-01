abc:=$(patsubst %.c,%.o,$(wildcard *.c))
apc.exe:$(abc)
	gcc -o $@ $^
clean:
	rm *.o *.exe
