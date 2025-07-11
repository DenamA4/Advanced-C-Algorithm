#include <stdio.h>
#include <stdarg.h>

//Library stdarg cung cấp ta các phương thức(hàm hoặc macro) để làm việc với các hàm có số lượng input parameter không cố định
/*

@) Lưu ý: hàm variadic bắt buộc phải có tối thiểu một parameter rồi mới điền '...'

Lib stdarg gồm:

    1. va_list: Là kiểu dữ liệu đại diện cho danh sách các đối số biến đổi
    2. va_start: Bắt đầu một danh sách đối số biến đổi, được gọi trước khi truy cập vào từng đối số biến đổi qua va_arg, chỉ lấy cái đối số trong ... chứ đối số cố định không cần
    3. va_arg: Truy cập một đối số trong danh sách, nhận một đối số của kiểu được xác định bởi tham số thứ 2 là l(va_arg(v,l))
    4. va_end: Kết thúc việc thao tác với danh sách, hay là thu hồi lại con trỏ 

*/

/*

^)va_start(v,l):

    +) v là value chỉ danh sách các đối số biến đổi khai báo từ va_list(bao gồm cả thành phần tham số cố định bắt buộc có)
    +) l là label chỉ tham số cố định để mà nó tách ra chỉ lấy phần trong ... đưa lại vô v

    Cách tách: Ví dụ có
    // typedef char* va_list;
    // char* args;
    // args = "int count, 1,2,6";
    //va_start(arg, count);

    --> Nó so sánh từng kí tự của count với các kí tự của args, ví dụ 'c' trong count so sánh với 'i' trong int trong chuỗi args

*/

//VD hàm test:

/*

void test(int count, ...)
{
    va_list args;   //khi trỏ chuột vào từ khóa va_list nó hiện typedef struct __va_list_tag va_list[1]
    // cái va_list trong chuẩn ngôn ngữ C là không cố định, nó tùy vào trình biên dịch cung cấp nên ta có thể hiểu như // bên dưới
    // typedef char* va_list;
    // char* args;
    // args = "int count, 1,2,6"

    va_start(args, count);      // args = "1,2,6"   /hoặc trình biên dịch lưu dưới dạng mảng: args = {"\001", "\002", "\006"}  

    printf("value 1: %d\n", va_arg(args, int));     // (int)"\001" = 1    // (int)'1'  = 49
    printf("value 2: %d\n", va_arg(args, int));     // (int)"\002" = 2
    printf("value 3: %d\n", va_arg(args, int));
    printf("value 4: %f\n", va_arg(args, double));
    printf("value 5: %s\n", va_arg(args, char*));
    printf("value 6: %s\n", va_arg(args, char*));

    va_end(args);
}

*/

//VD2: hàm sum

/*

int sum(int count, ...)
{
    va_list args;
    va_start(args, count);
    int result = 0;

    for(int i = 0; i < count; i++)
    {
        result += va_arg(args, int);
    }

    va_end(args);

    return result;
}

*/

//VD3: với struct:

/*/

#include <stdio.h>
#include <stdarg.h>

typedef struct
{
    int x;
    double y;
} Data;

void display(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        Data tmp = va_arg(args, Data);
        printf("Data.x at %d is: %d\n", i, tmp.x);
        printf("Data.y at %d is: %f\n", i, tmp.y);
    }

    va_end(args);
}

int main(int argc, char const *argv[])
{
    display(3, (Data){2, 5.0}, (Data){10, 57.0}, (Data){29, 36.0});
    return 0;
}


*/

void test(int count, ...)
{
    va_list args;   //khi trỏ chuột vào từ khóa va_list nó hiện typedef struct __va_list_tag va_list[1]
    // cái va_list trong chuẩn ngôn ngữ C là không cố định, nó tùy vào trình biên dịch cung cấp nên ta có thể hiểu như // bên dưới
    // typedef char* va_list;
    // char* args;
    // args = "int count, 1,2,6"

    va_start(args, count);      // args = "1,2,6"   /hoặc trình biên dịch lưu dưới dạng mảng: args = {"\001", "\002", "\006"}  


    printf("value 1: %s\n", va_arg(args, char*));     // (int)"\001" = 1    
    printf("value 2: %d\n", va_arg(args, int));     // (int)"\002" = 2
    printf("value 3: %d\n", va_arg(args, char*));
    // printf("value 4: %f\n", va_arg(args, double));
     printf("value 5: %s\n", va_arg(args, char*));
    // printf("value 6: %s\n", va_arg(args, char*));

    va_end(args);
}


int main(int argc, char const* argv[])
{
    int x = 65;
    long long a = (long long)&x;
    test(4,a,2,'A', "Hello");
}



//VD về nhiều cảm biến cho vô cùng một file, không cần viết chương trình xử lý riêng cho từng loại cảm biến:

/*

#include <stdio.h>
#include <stdarg.h>

typedef enum
{
    TEMPERATURE_SENSOR,
    PRESSURE_SENSOR
} SensorType;

void processSensorData(SensorType type, ...)
{
    va_list args;
    va_start(args, type);

    switch (type)
    {
        case TEMPERATURE_SENSOR:
        {
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            double temperature = va_arg(args, double);

            printf("Temperature Sensor ID: %d, Reading: %.2f degrees\n", sensorId, temperature);

            if (numArgs > 2)
            {
                // Xử lý thêm tham số nếu có
                char *additionalInfo = va_arg(args, char *);
                printf("Additional Info: %s\n", additionalInfo);
            }
            break;
        }

        case PRESSURE_SENSOR:
        {
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            int pressure = va_arg(args, int);

            printf("Pressure Sensor ID: %d, Reading: %d Pa\n", sensorId, pressure);

            if (numArgs > 2)
            {
                // Xử lý thêm tham số nếu có, có thể là chuỗi
                char *unit = va_arg(args, char *);
                printf("Unit: %s\n", unit);
            }
            break;
        }

        default:
            printf("Unknown sensor type.\n");
    }

    va_end(args);
}

int main(int argc, char const *argv[])
{
    processSensorData(TEMPERATURE_SENSOR, 2, 1, 36.5);
    processSensorData(PRESSURE_SENSOR, 3, 2, 101325, "pa");
    return 0;
}


*/