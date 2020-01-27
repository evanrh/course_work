FLAGS:=-Wall -std=c++11 -o
OUTPUT:=lab5
CC:=g++
SOURCE:=${wildcard *.cpp}

lab5: ${SOURCE}
	${CC} ${FLAGS} ${OUTPUT} ${SOURCE}
clean:
	rm -f ${OUTPUT} 
run: lab5
	./${OUTPUT} 
memcheck: lab5
	valgrind --leak-check=yes ./${OUTPUT} input.txt output.txt
