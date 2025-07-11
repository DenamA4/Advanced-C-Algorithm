#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>

int count(int a) {
    int cnt = 0;
    while(a) {
        cnt++;
        a /= 10;
    }
    return cnt - 1;
}

void print(const char *s, ...) {
    va_list args;
    va_start(args, s);
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '%') {
            if(s[i + 1] == 'c') {
                putchar(va_arg(args, int));
            }else if(s[i + 1] == 'd') {
                int temp = va_arg(args, int);
                int dem = count(temp);
                while(temp) {
                    putchar(((temp / (int)(pow(10, dem))) + 48));
                    temp %= (int)pow(10, dem);      
                    dem--;
                }
            }
            i++;
        }else {
            putchar(s[i]);
        }
    }
    va_end(args);
}

int main(void) 
{
    int d = 10292;
    print("Hay in ra %d", d);
}
