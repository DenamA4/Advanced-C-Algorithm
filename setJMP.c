#include <stdio.h>
#include <setjmp.h>

// Điều hướng flow chương trình mạnh hơn goto ở khoản nhảy giữa nhiều hàm khác nhau, có thể ngoài main

jmp_buf buf;

int exception = 0;

void func2()
{
    printf("This is function 2\n");
    longjmp(buf, 2);
}

void func3()
{
    printf("This is function 3\n");
    longjmp(buf, 3);
}

void func1()
{
    exception = setjmp(buf);
    if (exception == 0)
    {
        printf("This is function 1\n");
        printf("exception = %d\n", exception);
        func2();
    }
    else if (exception == 2)
    {
        printf("exception = %d\n", exception);
        func3();
    }
    else if (exception == 3)
    {
        printf("exception = %d\n", exception);
    }
}

int main(int argc, char const *argv[])
{
    func1();
    return 0;
}
