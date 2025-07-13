#include <stdio.h>

// Little endian  &  Big endian (endianness)


// Con trỏ void sử dụng trong C với ứng dụng: Generic function:  Vd: printDate(void *data,  ) thì ta truyền gì vô nó cũng tự xử lý được
// Trong C++ (có template), java thì có Generic(<>) để viết class
// Con trỏ void hay hàm đều dùng được với bootloader của vđk

int sum (int a, int b)
{
    return a + b;
}

/*

int main(int argc, char const* argv[])
{
    char h[] = "Hello";
    char *s = h;
    printf("%s", s);  // Vì sao thay bằng con trỏ vẫn in ra đúng, vì %s lúc bên trong trình biên dịch đọc đến '\0' thì dừng không quan trọng đó là tên con trỏ đến vùng nhớ mảng các kí tự hay là tên mảng
    printf(
        "%x", *(s + 8)
    );
}

*/


//Function Pointer

void in(int x, double y)
{
    printf("x = %d  &  y = %lf\n", x, y);
}



int main(int argc, char const* argv[])
{
    // int (*ptr)(int, int) = &sum;  // Or cho = sum luôn không cần &
    // printf(
    //     "%d\n", (*ptr)(34, 2)
    // );


    /*

    void (*ptr1)() = in;
    ptr1(2384, 234.889);   // --> Truyền đúng định dạng thì chạy đúng

    Nếu nhập phần double lệch thì sao:

    ptr1(3, 4.6); // --> phần parameter thứ 2 in sai

    */

    void (*ptr2)(int , double) = &in;
    (*ptr2)(10.93487, 3);

    // Ví dụ về mảng các con trỏ hàm: Cú pháp
    void (*ptr3[])(int, double);

}



// Mảng các con trỏ hàm:

/*



void tong(int a, int b) {
    printf("Tổng: %d\n", a + b);
}

void hieu(int a, int b) {
    printf("Hiệu: %d\n", a - b);
}

void tich(int a, int b) {
    printf("Tích: %d\n", a * b);
}

void thuong(int a, int b) {
    if (b != 0)
        printf("Thương: %f\n", (float)a / b);
    else
        printf("Lỗi: chia cho 0\n");
}

void calculate(void (*pheptoan)(int, int), int a, int b) {
    pheptoan(a, b);
}

int main()
{
    // cách 1
    void (*ptr)(int, int);
    ptr = tong;
    ptr(10, 20);

    ptr = tich;
    ptr(10, 5);

    // cách 2: mảng con trỏ hàm
    void (*ptr1[])(int, int) = {tong, hieu, tich, thuong};

    ptr1[0](10, 15);
    ptr1[1](10, 5);
    ptr1[2](5, 6);
    ptr1[3](2, 7);

    / cách 3: callback()
    calculate(tong,20, 8);

    return 0;
}



*/


// Phần Pointer to Pointer ứng dụng trong DSLK.c