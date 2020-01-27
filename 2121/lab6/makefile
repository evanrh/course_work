FLAGS:=-Wall -std=c++11 -o
OUTPUT:=lab6
CC:=g++
SOURCE:=${wildcard *.cpp}

lab6: ${SOURCE}
	${CC} ${FLAGS} ${OUTPUT} ${SOURCE}
clean:
	rm -f ${OUTPUT} 
run: lab6
	./${OUTPUT} 
memcheck: lab6
	valgrind --leak-check=yes ./${OUTPUT} input.txt output.txt
