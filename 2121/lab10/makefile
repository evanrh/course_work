FLAGS:=-Wall -std=c++11 -o
OUTPUT:=lab10
CC:=g++
SOURCE:=wolfGoatCabbage.cpp

lab10: ${SOURCE}
	${CC} ${FLAGS} ${OUTPUT} ${SOURCE} -g
clean:
	rm -f ${OUTPUT} 
run: lab10
	./${OUTPUT} 
memcheck: lab10
	valgrind --leak-check=yes ./${OUTPUT}
debug: lab10
	gdb ./$(OUTPUT)
