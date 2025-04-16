#include<stdio.h>

int gcd;

void Extended(int a, int b, int* x, int* y){
    if(b == 0){
        *x = 1;
        *y = 0;
        gcd = a;
        return;
    }
    Extended(b, a % b, x, y);
    int tmp = *x;
    *x = *y;
    *y = tmp - a/b * (*y);
}

int main(void){
    int a, b, x, y;
    scanf("%d%d", &a, &b);
    Extended(a,b,&x,&y);
    printf("UCLN bang: %d\n", gcd);
    printf("He so x = %d va He so y = %d", x, y);
}




















// #include <stdio.h>

// int extendedEuclid(int a, int b, int *x, int *y) {
//     int x1, y1;  
//     int gcd;    

//     *x = 1, *y = 0;  
//     x1 = 0, y1 = 1;  

//     while (b != 0) {
//         int q = a / b;           
//         int r = a % b;
//         a = b;
//         b = r;

//         int temp = x1;
//         x1 = *x - q * x1;
//         *x = temp;

//         temp = y1;
//         y1 = *y - q * y1;
//         *y = temp;
//     }

//     gcd = a;  // Khi b = 0, gcd là a
//     return gcd;
// }

// int main() {
//     int a, b, x, y;
//     scanf("%d %d", &a, &b);
//     int gcd = extendedEuclid(a, b, &x, &y);
//     printf("GCD(%d, %d) = %d\n", a, b, gcd);
//     printf("Các hệ số x = %d, y = %d\n", x, y);

//     return 0;
// }