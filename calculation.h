// Bảo vệ khỏi đụng độ khi include nhiều lần
#ifndef CALCULATION_H
#define CALCULATION_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef enum
{
    VO_NGHIEM,
    NGHIEM_KEP,
    HAI_NGHIEM
} Type;

// Nhập hệ số
void input_coefficients(double *a, double *b, double *c);

// Hiển thị kết quả
void display_result(double a, double b, double c);

#endif
