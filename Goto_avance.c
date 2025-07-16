#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>


// VD mô phỏng led ma trận:

char first_sentence[]  = "HI";  
char second_sentence[] = "FASHION";
char third_sentence[]  = "SUITABLE";

uint8_t letter_H[8][8] =
{  
   {1,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,1},  
};

uint8_t letter_I[8][8] =
{  
   {1,1,1,1,1,1,1,1},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {0,0,0,0,1,0,0,0},
   {1,1,1,1,1,1,1,1},  
};

uint8_t letter_F[8][8] =
{  
   {1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0},
   {1,0,0,0,0,0,0,0},
   {1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0},
   {1,0,0,0,0,0,0,0},
   {1,0,0,0,0,0,0,0},
   {1,0,0,0,0,0,0,0},  
};

uint8_t letter_S[8][8] =
{  
   {0,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0},
   {1,0,0,0,0,0,0,0},
   {0,1,1,1,1,1,1,0},
   {0,0,0,0,0,0,0,1},
   {0,0,0,0,0,0,0,1},
   {0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,0},  
};

// mô phỏng nút nhấn bấm dừng chương trình
uint8_t button = 0;

// khởi tạo kiểu liệt kê đại diện cho 3 câu cần hiển thị
typedef enum
{
   FIRST,
   SECOND,
   THIRD
} Sentence;


// mô phỏng in ký tự ra led ma trận 8x8
void print_char(const uint8_t matrix[8][8])
{
   for (size_t i=0; i<8; i++)
   {
      for (size_t j=0; j<8; j++)
      {
         printf(matrix[i][j] ? "*" : " ");
      }
      printf("\n");
   }
}

// mô phỏng đọc nút nhấn dừng hiển thị led ma trận
uint8_t is_pressed_stop_key()
{
   // Kiểm tra xem có phím nào được nhấn
   if (kbhit())
   {
      char key = getch(); // phím M -> 'M'

      // Kiểm tra nếu phím M được nhấn
      if (key == 'M' || key == 'm') return 1;
   }
   return 0;
}

// hàm delay theo giây
void delay(unsigned int time)
{
   sleep(time);
   // usleep(1);
}

int main(int argc, char const *argv[])
{
   // Biến 'sentence' được khởi tạo với giá trị 'FIRST', đại diện cho câu đầu tiên cần hiển thị.
   Sentence sentence = FIRST;

   while(1)
   {  
      switch(sentence)
      {
         case FIRST:
               for (int index=0; index<sizeof(first_sentence); index++)
               {
                  if (first_sentence[index] == 'H'){
                     print_char(letter_H);
                  } else if (first_sentence[index] == 'I'){
                     print_char(letter_I);
                  }
                 
                  if ((button = is_pressed_stop_key()) == 1) goto exit_loops;
               }
               printf("First sentence is done\n");
               printf("\n");
               delay(2);
               goto logic;


         case SECOND:
               for (int index=0; index<sizeof(second_sentence); index++)
               {
                  if (second_sentence[index] == 'F'){
                     print_char(letter_F);
                  } else if (second_sentence[index] == 'A'){
                     // in ra ký tự 'A'
                  }

                  if ((button = is_pressed_stop_key()) == 1) goto exit_loops;
               }
               printf("Second sentence is done\n");
               printf("\n");
               delay(2);
               goto logic;


         case THIRD:
               for (int index=0; index<sizeof(third_sentence); index++)
               {
                  if (third_sentence[index] == 'S'){
                     print_char(letter_S);
                  } else if (third_sentence[index] == 'U'){
                     // in ra ký tự 'U'
                  }
                 
                  if ((button = is_pressed_stop_key()) == 1) goto exit_loops;
               }
               printf("Third sentence is done\n");
               printf("\n");
               delay(2);
               goto logic;
      }

      logic:
         if (sentence == FIRST)       sentence = SECOND;
         else if (sentence == SECOND) sentence = THIRD;
         else if (sentence == THIRD)  sentence = FIRST;
   }

   exit_loops:
      printf("Stop\n");

   return 0;
}
