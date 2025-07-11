#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// #define tong(...)           \
//     sum(__VA_ARGS__, 0)

// #define tong(...)           \
//     sum2(__VA_ARGS__, '\n')

#define tong(...)           \
    sum2(__VA_ARGS__, "abc")

// tong(3,1,4,5,-1,-2) -> sum(3,1,4,5,-1,-2,0)

int sum(int count, ...)
{
    va_list args;
    va_list check;

    va_start(args, count);
    va_copy(check, args);

    int result = count;
    int value;

    while ((value = va_arg(args, int)) != 0)
    {
        result += value;
    }

    va_end(args);

    return result;
}

// Sửa để so sánh với '\n':

int sum2(int count, ...)
{
    va_list args;
    va_list check;

    va_start(args, count);
    va_copy(check, args);

    int result = count;

    // while ((va_arg(args, char*)) != (char*)'\n')         //(va_arg(args, char*)) != (char*)'\n' để hết warning
    // {
    //     result += va_arg(check, int);
    // }
    
    while() {
        result += va_arg(check,int);
    }

    va_end(args); //chỉ cần thu hồi một trong 2

    return result;
}

//Lý do dùng value lưu va_arg(args, int) vì nếu condition trong () của while gọi 1 lần xong trong{} của while lại gọi một lần nữa thì nó bị mất đi một thằng khi cộng

//Giả sử va_arg(args, char*)   (char*)"\015"(giả sử đây là cách lưu 'a')  --> "a" mà ta lại (int)"a" là sai
/*

#define tong(...) sum3(__VA_ARGS__, NULL)

int sum3(int count, ...)
{
    va_list args;
    va_start(args, count);

    int result = count;
    char* val;

    while ((val = va_arg(args, char*)) != NULL) {
        result += atoi(val); // ép chuỗi sang số (nếu dùng chuỗi)
    }

    va_end(args);
    return result;
}


*/

int main()
{
    // printf("Tong: %d\n", tong(3, -1, 1, 2, 3, 15, 1000));
    printf("Tong: %d\n", tong(1,2,10,10,3));
    // char *s = "12";
    // printf("%d", (int)*(s+1));
}
