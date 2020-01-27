FLAGS:=-Wall -std=c++11 -o
OUTPUT:=lab8
CC:=g++
SOURCE:=${wildcard *.cpp}

lab8: ${SOURCE}
	${CC} ${FLAGS} ${OUTPUT} ${SOURCE} -g
clean:
	rm -f ${OUTPUT} 
run: lab8
	./${OUTPUT} 
memcheck: lab8
	valgrind --leak-check=yes ./${OUTPUT}
debug: lab8
	gdb ./$(OUTPUT)
