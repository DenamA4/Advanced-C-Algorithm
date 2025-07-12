#include <stdio.h>
#include <stdint.h>

// VD1:
// Việc quy định từng bit mang những thông tin cụ thể gì dùng #define để gán mác

#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)

// Tự thêm tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4

// Set bit
void enableFeature(uint8_t *features, uint8_t feature)
{
    *features |= feature;
}

// Clear bit
void disableFeature(uint8_t *features, uint8_t feature)
{
    *features &= ~feature;
}


// Check bit
int isFeatureEnabled(uint8_t features, uint8_t feature)
{
    return (features & feature) != 0;
}

/*

Giả sử check nhiều bit:
    Kiểm tra 3 bit(5,6,7): 

        0bx0xx xx01   &   0b1110 0000   !=    0  ---> Chỉ kết luận được 1 trong 3 bit này được bật thôi 
                                        =    0 ---> thì 3 bit đều tắt
*/

void listSelectedFeatures(uint8_t features)
{
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("feature selected: %d\n", (features >> i) & 1);
    }
   
    // Thêm các điều kiện kiểm tra cho các tính năng khác
}

int main()
{
    uint8_t options = 0;

    // Thêm tính năng
    enableFeature(&options, GENDER | TSHIRT | HAT);

    // Xóa tính năng
    disableFeature(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
   
    return 0;
}









// VD2: 

/*

#define LED1 1 << 0 // 0001
#define LED2 1 << 1 // 0010
#define LED3 1 << 2 // 0100
#define LED4 1 << 3 // 1000

void enableLED(unsigned int *GPIO_PORT, unsigned int LED)
{
    *GPIO_PORT |= LED;
}

void disableLED(unsigned int *GPIO_PORT, unsigned int LED)
{
    *GPIO_PORT &= ~LED;
}


int main()
{
    unsigned int GPIO_PORT = 0; // Giả sử là biến điều khiển cổng GPIO

    // Bật LED1 và LED3
    enableLED(&GPIO_PORT, LED1 | LED3);
    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }
   
    // Tắt LED1 và bật LED2
    disableLED(&GPIO_PORT, LED1);
    enableLED(&GPIO_PORT, LED2);

    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }

    // Cập nhật trạng thái của GPIO_PORT tương ứng với hardware

    return 0;
}


*/



// VD3: với struct


/*



#define COLOR_RED 0
#define COLOR_BLUE 1
#define COLOR_BLACK 2
#define COLOR_WHITE 3

#define POWER_100HP 0
#define POWER_150HP 1
#define POWER_200HP 2

#define ENGINE_1_5L 0
#define ENGINE_2_0L 1

typedef uint8_t CarColor;
typedef uint8_t CarPower;
typedef uint8_t CarEngine;

#define SUNROOF_MASK 1 << 0     // 0001
#define PREMIUM_AUDIO_MASK 1 << 1 // 0010
#define SPORTS_PACKAGE_MASK 1 << 2 // 0100
// Thêm các bit masks khác tùy thuộc vào tùy chọn

typedef struct
{
    uint8_t additionalOptions : 3; // 3 bits cho các tùy chọn bổ sung
    CarColor color : 2;
    CarPower power : 2;
    CarEngine engine : 1;
} CarOptions;


void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options)
{
    car->color = color;
    car->power = power;
    car->engine = engine;
    car->additionalOptions = options;
}

void setOption(CarOptions *car, uint8_t optionMask)
{
    car->additionalOptions |= optionMask;
}

void unsetOption(CarOptions *car, uint8_t optionMask)
{
    car->additionalOptions &= ~optionMask;
}

void displayCarOptions(const CarOptions car)
{
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.color]);
    printf("Power: %s\n", powers[car.power]);
    printf("Engine: %s\n", engines[car.engine]);
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No");
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
}

int main()
{
    CarOptions myCar;
    configureCar(&myCar, COLOR_BLACK, POWER_150HP, ENGINE_2_0L, 0);
   

    setOption(&myCar, SUNROOF_MASK);
    setOption(&myCar, PREMIUM_AUDIO_MASK);
   
    displayCarOptions(myCar);

    unsetOption(&myCar, PREMIUM_AUDIO_MASK);
    displayCarOptions(myCar);

    printf("size of my car: %d\n", sizeof(CarOptions));
    return 0;
}


*/



// VD4: struct bật tắt LED

/*


#define ENABLE 1
#define DISABLE 0

typedef struct
{
    uint8_t LED1 : 1;  
    uint8_t LED2 : 1;
    uint8_t LED3 : 1;
    uint8_t LED4 : 1;
    uint8_t LED5 : 1;
    uint8_t LED6 : 1;
    uint8_t LED7 : 1;
    uint8_t LED8 : 1;
} LEDStatus;

void displayAllStatusLed(LEDStatus status)
{
    uint8_t* statusPtr = (uint8_t*)&status;
    for (int j = 0; j < 8; j++)
    {
        printf("LED%d: %d\n", j+1, (*statusPtr >> j) & 1);
    }
}


int main()
{
    LEDStatus ledStatus = {.LED7 = ENABLE, .LED5 = ENABLE};

    // Bật LED 1 và 3
    ledStatus.LED1 = ENABLE;
    ledStatus.LED3 = ENABLE;
    displayAllStatusLed(ledStatus);
    return 0;
}


*/




