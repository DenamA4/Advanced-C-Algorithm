#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define tong(...)           \
    sum(__VA_ARGS__, "abc")

int sum(char* s,int count,...)
{
    va_list args;
    if(strcmp(s, "int") == 0)
    {
        va_start(args, count); // số đầu tiên bỏ qua
    }else return -1;

    int result = count;

    while (1)
    {
        char *type = va_arg(args, char*);
        if (strcmp(type, "abc") == 0) break;

        if (strcmp(type, "int") == 0)
        {
            int val = va_arg(args, int);
            result += val;
        }
        // else if (strcmp(type, "float") == 0)
        // {
        //     // float được promote thành double trong variadic
        //     double val = va_arg(args, double);
        //     result += val;
        // }
        // else if (strcmp(type, "char") == 0)
        // {
        //     int ch = va_arg(args, int); // char cũng được promote thành int
        //     result += ch;
        // }
        else
        {
            // Unknown type
            printf("Unknown type: %s\n", type);
        }
    }

    va_end(args);
    return result;
}

int main()
{
    printf("Tong: %d\n",tong(
        "int", 10,
        "int", 0,
        "int", 2,  
        "int", -5
    ));  
    return 0;
}
