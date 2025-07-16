#include "calculation.h"

// Mô phỏng quá trình tính toán bên trong không show ra dùng static chỉ nhìn được kết quả và nhập không thấy quá trình

void input_coefficients(double *a, double *b, double *c)
{
    printf("Nhap cac he so a, b, c: ");
    scanf("%lf %lf %lf", a, b, c);
}

static double calculate_Delta(double a, double b, double c)
{
    return pow(b, 2) - 4 * a * c;
}

static Type solve(double a, double b, double c, double *x1, double *x2)
{
    double delta = calculate_Delta(a, b, c);

    if (delta > 0)
    {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
        return HAI_NGHIEM;
    }
    else if (delta == 0)
    {
        *x1 = *x2 = (double)(-b) / (2 * a);
        return NGHIEM_KEP;
    }
    else
    {
        *x1 = *x2 = NAN;
        return VO_NGHIEM;
    }
}

void display_result(double a, double b, double c)
{
    double x1 = 0, x2 = 0;
    Type type = solve(a, b, c, &x1, &x2);

    switch (type)
    {
        case VO_NGHIEM:
            printf("Phuong trinh vo nghiem!\n");
            break;

        case HAI_NGHIEM:
            printf("Phuong trinh co 2 nghiem phan biet:\n");
            printf("x1 = %f\n", x1);
            printf("x2 = %f\n", x2);
            break;

        case NGHIEM_KEP:
            printf("Phuong trinh co nghiem kep:\n");
            printf("x1 = x2 = %f\n", x1);
            break;
    }
}
