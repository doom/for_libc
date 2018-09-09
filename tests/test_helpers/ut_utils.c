/*
** Created by doom on 08/09/18.
*/

long ut_write(int fd, const void *data, unsigned long size)
{
    long ret;

    asm("movq $1, %%rax;"
        "movq %1, %%rdi;"
        "movq %2, %%rsi;"
        "movq %3, %%rdx;"
        "syscall;"
        "mov %%rax, %0;"
    : "=r"(ret)
    : "r"((unsigned long)fd), "r"(data), "r"(size)
    : "%rax", "%rdi", "%rsi", "%rdx");
    return ret;
}

void ut_exit(int status)
{
    asm("mov $60, %%rax;"
        "mov %0, %%rdi;"
        "syscall;"
    : /* no output registers */
    : "r"((long)status)
    : "%rax", "%rdi"
    );
}
