FLAGS:=-Wall -std=c++11 -o
OUTPUT:=lab3
CC:=g++
SOURCE:=${wildcard *.cpp}

lab3: ${SOURCE}
	${CC} ${FLAGS} ${OUTPUT} ${SOURCE}
clean:
	rm -f ${OUTPUT}
run: lab3
	./${OUTPUT}
memcheck: lab10
	valgrind --leak-check=yes ./${OUTPUT}
