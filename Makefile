# gcc compiler
CC = gcc

# Compile-time flags
CFLAGS = -O2 -std=c99 -ggdb -Wpedantic

all: build/riscv_simulator

build/riscv_simulator: src/main.o src/simulator.o
	@mkdir $(@D) 2>/dev/null || true
	$(CC) $^ -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

tests/%: tests/%.mem build/riscv_simulator
	./build/riscv_simulator --load-file $< --verbose

tests/%.mem: tests/%.c
	./tools/c_to_mem $<

clean:
	-rm -rf src/*.o build
