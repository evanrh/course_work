FLAGS:=-Wall -std=c++11 -o
OUTPUT:=lab9
CC:=g++
SOURCE:=${wildcard *.cpp}

lab9: ${SOURCE}
	${CC} ${FLAGS} ${OUTPUT} ${SOURCE} -g
clean:
	rm -f ${OUTPUT} 
run: lab9
	./${OUTPUT} 
memcheck: lab9
	valgrind --leak-check=yes ./${OUTPUT}
debug: lab9
	gdb ./$(OUTPUT)
