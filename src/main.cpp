#include <Arduino.h>


#define INPUT_BIT0 PB8
#define INPUT_BIT1 PB7
#define INPUT_BIT2 PB6
#define INPUT_BIT3 PB5
#define INPUT_RESET PB9



#define OUTPUT_BIT0 PA4
#define OUTPUT_BIT1 PA5
#define OUTPUT_BIT2 PA6
#define OUTPUT_BIT3 PA7

int buttonState00 = LOW;
int buttonState01 = LOW;
int buttonState02 = LOW;
int buttonState03 = LOW;

int resetButtonState = LOW;

int lastButtonState00;
int currentButtonState00;
int lastButtonState01;
int currentButtonState01;
int lastButtonState02;
int currentButtonState02;
int lastButtonState03;
int currentButtonState03;

void ToggleBit0()
{
    lastButtonState00    = currentButtonState00;
    currentButtonState00 = digitalRead(INPUT_BIT0);


    if(lastButtonState00 == HIGH && currentButtonState00 == LOW)
    {
        Serial.println("Button 0 was pressed");

        // toggle state of LED
        buttonState00 = !buttonState00;

        // control LED arccoding to the toggled state
        digitalWrite(OUTPUT_BIT0, buttonState00);
    }
}

void ToggleBit1()
{
    lastButtonState01    = currentButtonState01;
    currentButtonState01 = digitalRead(INPUT_BIT1);


    if(lastButtonState01 == HIGH && currentButtonState01 == LOW)
    {
        Serial.println("Button 1 was pressed");

        // toggle state of LED
        buttonState01 = !buttonState01;

        // control LED arccoding to the toggled state
        digitalWrite(OUTPUT_BIT1, buttonState01);
    }
}

void ToggleBit2()
{
    lastButtonState02    = currentButtonState02;
    currentButtonState02 = digitalRead(INPUT_BIT2);


    if(lastButtonState02 == HIGH && currentButtonState02 == LOW)
    {
        Serial.println("Button 2 was pressed");

        // toggle state of LED
        buttonState02 = !buttonState02;

        // control LED arccoding to the toggled state
        digitalWrite(OUTPUT_BIT2, buttonState02);
    }
}

void ToggleBit3()
{
    lastButtonState03    = currentButtonState03;
    currentButtonState03 = digitalRead(INPUT_BIT3);


    if(lastButtonState03 == HIGH && currentButtonState03 == LOW)
    {
        Serial.println("Button 3 was pressed");

        // toggle state of LED
        buttonState03 = !buttonState03;

        // control LED arccoding to the toggled state
        digitalWrite(OUTPUT_BIT3, buttonState03);
    }
}

void BitsReset()
{
    resetButtonState = digitalRead(INPUT_RESET);

    if (resetButtonState == HIGH)
    {
        lastButtonState00 = LOW;
        currentButtonState00 = LOW;
        lastButtonState01 = LOW;
        currentButtonState01 = LOW;
        lastButtonState02 = LOW;
        currentButtonState02 = LOW;
        lastButtonState03 = LOW;
        currentButtonState03 = LOW;

        buttonState00 = LOW;
        buttonState01 = LOW;
        buttonState02 = LOW;
        buttonState03 = LOW;

        digitalWrite(OUTPUT_BIT0, buttonState00);
        digitalWrite(OUTPUT_BIT1, buttonState01);
        digitalWrite(OUTPUT_BIT2, buttonState02);
        digitalWrite(OUTPUT_BIT3, buttonState03);

    }
}

void ToggleInputs()
{
    ToggleBit0();
    ToggleBit1();
    ToggleBit2();
    ToggleBit3();
    BitsReset();
}


void setup() {
// write your initialization code here

    pinMode(INPUT_BIT0, INPUT);
    pinMode(INPUT_BIT1, INPUT);
    pinMode(INPUT_BIT2, INPUT);
    pinMode(INPUT_BIT3, INPUT);

    pinMode(OUTPUT_BIT0, OUTPUT);
    pinMode(OUTPUT_BIT1, OUTPUT);
    pinMode(OUTPUT_BIT2, OUTPUT);
    pinMode(OUTPUT_BIT3, OUTPUT);

    currentButtonState00 = digitalRead(INPUT_BIT0);
    currentButtonState01 = digitalRead(INPUT_BIT1);
    currentButtonState02 = digitalRead(INPUT_BIT2);
    currentButtonState03 = digitalRead(INPUT_BIT3);

    Serial.begin(9600);
}

void loop() {
// write your code here

    ToggleInputs();
}