
// tinkercad project link: https://www.tinkercad.com/things/auM0qSTMN1p

#include <Servo.h>

const char unsigned led[5] = { 3, 4, 5, 6, 7 };
class Servo serv[4];

char unsigned index;

void setup( void )
{
    Serial.begin(9600);

    index = 0;

    while (4 > index)
    {
        pinMode(led[index], OUTPUT);

        serv[index].attach(12 - index++, 500, 2500);
    }

    return;
}

void loop( void )
{
    if (! Serial.available())
        return;

    index = Serial.read() - '0';

    if (8 < index) {
        digitalWrite(led[4], HIGH), delay(10);
        digitalWrite(led[4], LOW );

    } else if (0 == index) {
        while(4 > index)
            digitalWrite(led[index++], LOW);

    } else if (5 > index) {
        --index;

        digitalWrite(led[index], !digitalRead(led[index]));

    } else if (9 > index) {
        index -= 5;

        serv[index].write( 0), delay(1000);
        serv[index].write(90);
    }

    return;
}

