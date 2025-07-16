#include <stdio.h>

// Ưu điểm của goto hơn break là thoát khỏi vòng lặp nhiều cấp, tại break chỉ thoát được 1 cấp thôi


/*

void delay(double second)
{
   double start = 0;
   while (start < second * 6000000) start++;
}

// Khai báo các trạng thái đèn giao thông
typedef enum
{
   RED,
   YELLOW,
   GREEN
} TrafficLightState;

int main()
{
   // Ban đầu, đèn giao thông ở trạng thái đỏ
   TrafficLightState state = RED;

   // Vòng lặp vô hạn để mô phỏng đèn giao thông
   while (1)
   {
      switch (state)
      {
         case RED:
               printf("RED Light\n");
               delay(50);        // Giữ trạng thái đèn đỏ trong x giây
               state = GREEN;    // Chuyển đến trạng thái đèn vàng
               goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
         
         case YELLOW:
               printf("YELLOW Light\n");
               delay(20);        // Giữ trạng thái đèn vàng trong y giây
               state = RED;      // Chuyển đến trạng thái đèn xanh
               goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái

         case GREEN:
               printf("GREEN Light\n");
               delay(100);       // Giữ trạng thái đèn xanh trong z giây
               state = YELLOW;   // Chuyển đến trạng thái đèn đỏ
               goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
      }

      // Nhãn để nhảy qua sleep() khi chuyển trạng thái
      skip_sleep:;  // Chú ý sau label không có gì phải ;
   }

   return 0;
}

*/







// int main()
// {
//    int i = 0;

//    // Đặt nhãn
//    start:
//       if (i >= 5)
//       {
//          goto end;  // Chuyển control đến nhãn "end"
//       }

//       printf("%d ", i);
//       i++;

//       goto start;  // Chuyển control đến nhãn "start"

//    // Nhãn "end"
//    end:
//       printf("\n");
//    return 0;
// }
