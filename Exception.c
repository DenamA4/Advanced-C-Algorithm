#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception = 0;
int mauso = 0;
int tuso = 0;



// C1:
/*


float divide(int mauso, int tuso)
{
    if(mauso == 0 && tuso == 0)
    {
        //printf("phep toán không hợp lệ\n");
        longjmp(buf, 1);
    } else if(mauso == 0)
    {
        //printf("Lỗi chia cho 0\n");
        longjmp(buf, 2);
    } else {
        return (float)tuso/mauso;
    }
}

int main(int argc, char const* argv[]) 
{
    exception = setjmp(buf);
    if(exception == 0) 
    {
        float result = divide(mauso, tuso);
        printf("result = %.2f", result);
    } else if(exception == 1) {
        printf("phep toán không hợp lệ\n");
    } else if(exception == 2) {
        printf("Lỗi chia cho 0\n");
    }

    return 0;
}


*/



// C2:


#define TRY if((exception = setjmp(buf)) == 0)
#define CATCH(x) else if(exception == x)
#define THROW(x) longjmp(buf, x);

float divide(int mauso, int tuso)
{
    if(mauso == 0 && tuso == 0)
    {
        //printf("phep toán không hợp lệ\n");
        THROW(1)
    } else if(mauso == 0)
    {
        //printf("Lỗi chia cho 0\n");
        THROW(2);
    } else {
        return (float)tuso/mauso;
    }
}

int main(int argc, char const* argv[]) 
{
    exception = setjmp(buf);
   TRY 
    {
        float result = divide(mauso, tuso);
        printf("result = %.2f", result);
    } 
    CATCH(1) {
        printf("phep toán không hợp lệ\n");
    } 
    CATCH(2) {
        printf("Lỗi chia cho 0\n");
    }

    return 0;
}