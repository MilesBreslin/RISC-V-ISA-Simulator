# gcc compiler
CC = gcc

# Compile-time flags
CFLAGS = -O2 -std=c99 -ggdb

all: build/riscv_simulator

build/riscv_simulator: src/main.o
	@mkdir $(@D) 2>/dev/null || true
	$(CC) $^ -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -rf src/*.o build
