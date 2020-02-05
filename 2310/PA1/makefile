FLAGS:=-Wall -o
OUTPUT:=PA1
CC:=gcc
SOURCE:=${wildcard *.c}
ARGS:= 255 37

PA1: ${SOURCE}
	@${CC} ${FLAGS} ${OUTPUT} ${SOURCE}
clean:
	rm -f ${OUTPUT} 
run: PA1
	./${OUTPUT} $(ARGS)
memcheck: PA1
	valgrind --leak-check=yes ./${OUTPUT} $(ARGS)
