#include <stdio.h>

//Biên dịch từ .c, .h ---->  .i: gõ lệnh này trên terminal :   gcc -E file.c(file.h) -o file_name.i

/*

Toán tử Variadic: sử dụng cho các trường hợp không biết số lượng tham số truyền vào, bao gồm 2 thành phần:
    +)...: Đại diện cho số lượng đối số truyền vào(các đối số không xác định)
    +)__VA_ARGS__: chứa danh sách các đối số(phần tử thay thế ...) 
*/

// Giả sử #define print(...) __VA_ARGS__
//Vd trong main() ghi print(1,2,3,4,5); hoặc  print("hello World", 'c', 1,2.6, 's'); rồi chạy gcc -E file.c -o file.i để xem file.i


/*

VD: về hàm bằng toán tử variadic không cần hàm variadic của thư viện stdarg.h

#define sum(...)                                                \
int arr[] = {__VA_ARGS__};                                      \
int result = 0;                                                 \
for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)          \
{                                                               \
    result += arr[i];                                           \
}                                                                

int main(void)
{
    sum(1,2,3,3,25,5);
    printf("Tong bang: %d", result);
}

*/

//Cú pháp biên dịch từ file.i ra file.s(compiler):  gcc -S file.i -o file_name.s

//Cú pháp biên dịch từ file.s ra file.o(assembler): gcc -c file.s -o file_name.o

