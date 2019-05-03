SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c, %.o, $(SRC))
output.exe: $(OBJ)
	gcc -o $@ $(OBJ) -Wall
clean:
	rm *.o *.exe
