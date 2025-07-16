#ifndef MOTOR_H
#define MOTOR_H

typedef struct
{
   void (*start)(int gpio);
   void (*stop)(int gpio);
   void (*changeSpeed)(int gpio, int speed);
} MotorController;

typedef int PIN;

static void startMotor(PIN pin);
static void stopMotor(PIN pin);
static void changeSpeedMotor(PIN pin, int speed);

void init_motor(MotorController *motorName);

#endif   // MOTOR_H
