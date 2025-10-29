// The default entry point our linker expects is actually
// identified as '_start'. Indeed, it is an assembly label!
int _start(void){
    // We want the generated assembly to have a fixed, well
    // identified memory location, to address.
    const char hello[] = "Hello, world!\n"; // Size: 14 chars

    // We aren't using libraries, so we need to phone things in
    // ourselves. That demands some 64-bit assembly!
    // Note that this means our program will only work in an
    // UNIX OS running on an x86-64 architecture, and will
    // absolutely go up in a beautiful ball of fire in any other
    // system. It's not very portable!
    asm volatile(           // Hard coded call to puts(hello);
        "mov $1, %%rax\n\t" // print is service 1 in unix
        "mov $1, %%rdi\n\t" // fd = 1 -> stdout
        "lea %0, %%rsi\n\t" // Load effective address of hello
        "mov $14, %%rdx\n\t"// Size of hello = 14 bytes
        "syscall\n\t"       // SVC = syscall = int 0x80 (legacy UNIX)
        :
        : "m"(hello)        // Argument %0, pointer to hello
        : "%rax", "%rdi", "%rsi", "%rdx"   //List of modified registers
    );

    asm volatile(           // Hard coded exit(0)
        "mov $60, %%rax\n\t"// exit is service 60
        "mov $0, %%rdi\n\t" // exit code = 0
        "syscall\n\t"
        ::: "%rax", "%rdi"  // modified registers
    );

    // We will never reach here unless we are tinkering with GDB:
    // we will be performing exit(0) prior in normal circumstances.
    return 0;
}
