#include <stdio.h>
#include <assert.h>

/*

Thư viện assert

    +) Cung cấp macro assert.

    +) Macro này được sử dụng để kiểm tra một điều kiện.

    +) Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.

    +) Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.

    +) Dùng trong debug, dùng #define NDEBUG để tắt debug.

--> Thường ta debug bằng if, else để nó in đoạn mã thông báo gì đó có in hay không, nhưng nó có nhược điểm nhỡ đoạn code quá dài hay nằm trong file khác trong nhiều file
thì khó tìm, thậm chí một số lỗi không phát hiện ra được ---------------> Dùng assert, nó đưa ra vị trí chính xác nằm ở dòng nào trong file hay trong file nào, đưa ra điều
kiện đúng để lệnh đó thực thi được.(Kiểu đoạn code logic theo lối suy nghĩ mình sai, nếu sai cú pháp compiler sẽ thông báo dòng nào rồi)



*/

//VD1: assert (thay if):

/*

double divide(int a, int b)
{
    if (b == 0){
        printf("Chia cho 0\n");
    } else {
        return (double)a / b;
    }
}

int main(int argc, char const *argv[])
{
    int x = 6;

    // if (x == 5) printf("x = %d\n", x);
    assert(x == 5 && "x have to be equals to 5");

    printf("x = %d\n", x);

    int a = 2, b = 0;

    printf("Kết quả: %f\n", divide(a, b));

    return 0;
}

*/
