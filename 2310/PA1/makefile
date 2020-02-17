FLAGS:=-Wall -save-temps -o
OUTPUT:=PA1
CC:=gcc
SRCDIR:=src
SOURCES:=${wildcard *.c}
ARGS:= 25 20

# Compile and save temporary files
PA1: $(SOURCES)
	@${CC} ${FLAGS} ${OUTPUT} ${SOURCES}

# Clean up compiled files
clean:
	rm -f *.o *.i *.s $(OUTPUT)

# Test with values in ARGS
run: PA1
	./${OUTPUT} $(ARGS)

# Check for memory leaks
memcheck: PA1
	valgrind --leak-check=yes ./${OUTPUT} $(ARGS)
