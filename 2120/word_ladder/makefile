FLAGS:=-Wall -std=c++11 -g -o 
OUTPUT:=word_ladder
CC:=g++
SOURCE:=${wildcard *.cpp}

lab5: ${SOURCE}
	${CC} ${FLAGS} ${OUTPUT} ${SOURCE}
clean:
	rm -f ${OUTPUT} 
run: ${OUTPUT}
	./${OUTPUT} 
debug: lab5
	gdb ./$(OUTPUT)
memcheck: ${OUTPUT}
	valgrind --leak-check=yes ./${OUTPUT} input.txt output.txt
