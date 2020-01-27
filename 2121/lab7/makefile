FLAGS:=-Wall -std=c++11 -o
OUTPUT:=lab7
CC:=g++
SOURCE:=${wildcard *.cpp}

lab7: ${SOURCE}
	${CC} ${FLAGS} ${OUTPUT} ${SOURCE} -g
clean:
	rm -f ${OUTPUT} 
run: lab7
	./${OUTPUT} 
memcheck: lab7
	valgrind --leak-check=yes ./${OUTPUT}
debug: lab7
	gdb ./$(OUTPUT)
