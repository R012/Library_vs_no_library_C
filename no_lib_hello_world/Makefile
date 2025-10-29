.PHONY: clean
all: hello_world hello_world.o # By default, generate all 

hello_world: hello_world.c # standalone code generation (no libs, no anything)
	gcc -nostdlib -static hello_world.c -o hello_world

debug: hello_world.c # Code generation with debug symbols
	gcc -nostdlib -static -g hello_world.c -o hello_world

hello_world.o: hello_world.s # object code generation (pre-linking, not executable)
	gcc -c hello_world.s -o hello_world.o

hello_world.s: hello_world.i # assembly code generation from preprocessed C
	gcc -S hello_world.i -o hello_world.s

hello_world.i: hello_world.c # Preprocess C file (expand macros, parse directives...)
	gcc -E hello_world.c -o hello_world.i

clean: # Phony clean rule (no object)
	rm *.o *.s *.i hello_world
