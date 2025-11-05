#include "Arduino.h"
#include "dcMotor.h"

void dcMotor::begin()
{
    dcMotor.in1 = 0;
    dcMotor.in2 = 0;
    dcMotor.in3 = 0;
    dcMotor.in4 = 0;
    dcMotor.enA = 0;
    dcMotor.enB = 0;

    dcMotor.ocLimit = 12.0;
}

int dcMotor::initSingle(int ctr1, int ctr2, int id, int pwm)
/*
   initializes a single-channel motor
   args:
    - ctr1: digital pin ID of in1/in3
    - ctr2: digital pin ID of in2/in4
    - pwm: pwm pin ID of enA/enB
    - id: operating channel of the motor (channel 1 uses pins in1/in2/enA, channel 2 uses pins in3/in4/enB)
   returns:
    - 1, if initialization is successful unto channel 1
    - 2, if initialization is successful unto channel 2
    - 0, if initialization is unsuccessful
*/
{
    switch id
    {
        case 1:
        dcMotor.in1 = ctr1;
        dcMotor.in2 = ctr2;
        dcMotor.enA = pwm;

        pinMode(dcMotor.in1, OUTPUT);
        pinMode(dcMotor.in2, OUTPUT);
        pinMode(dcMotor.enA, OUTPUT);
        
        return 1;
        break;
        
        case 2:
        dcMotor.in3 = ctr1;
        dcMotor.in4 = ctr2;
        dcMotor.enB = pwm;

        pinMode(dcMotor.in3, OUTPUT);
        pinMode(dcMotor.in4, OUTPUT);
        pinMode(dcMotor.enB, OUTPUT);

        return 2;

        default:
        return 0;
}

int dcMotor::initDual(int ctr1, int ctr2, int ctr3, int ctr4, int pwmA, int pwmB)
/*
   initializes a dual-channel
   args:
    - ctr1: digital pin ID of in1
    - ctr2: digital pin ID of in2
    - ctr3: digital pin ID of in3
    - ctr4: digital pin ID of in4
    - pwmA: pwm pin ID of enA
    - pwmB: pwm pin ID of enB
   returns:
    - 1, if initialization is successful
*/
{

    dcMotor.in1 = ctr1
    dcMotor.in2 = ctr2
    dcMotor.in3 = ctr3
    dcMotor.in4 = ctr4
    dcMotor.enA = pwmA
    dcMotor.enB = pwmB

    pinMode(dcMotor.in1, OUTPUT);
    pinMode(dcMotor.in2, OUTPUT);
    pinMode(dcMotor.in3, OUTPUT);
    pinMode(dcMotor.in4, OUTPUT);
    pinMode(dcMotor.enA, OUTPUT);
    pinMode(dcMotor.enB, OUTPUT);

    return 1;
}

int dcMotor::driveSingle(char dir, int id, float power)
/*
drives a single-channel motor
args:
- dir: direction of the motor (FORWARDS -> drives forwards | REVERSE -> drives backwards)
- id: channel id of the motor
- power: %power to run the motor at
returns:
- 1, if motor on channel 1 is found and successfully updated
- 2, if motor on channel 2 is found and successfully updated
- 0, if motor has not been found or successfully updated
*/
{
    switch id
    {
        case 1:
            if(dir == "FORWARDS")
            {
            digitalWrite(dcMotor.in1, HIGH);
            digitalWrite(dcMotor.in2, LOW);
            }
            else if(dir == "REVERSE")
            {
            digitalWrite(dcMotor.in1, LOW);
            digitalWrite(dcMotor.in2, HIGH);
            }

            analogWrite(dcMotor.enA, round(power * 2.55) )
            return 1;
            break;

        case 2:
            if(dir == "FORWARDS")
            {
            digitalWrite(dcMotor.in3, HIGH);
            digitalWrite(dcMotor.in4, LOW);
            }
            else if(dir == "REVERSE")
            {
            digitalWrite(dcMotor.in3, LOW);
            digitalWrite(dcMotor.in4, HIGH);
            }

            analogWrite(dcMotor.enB, round(power * 2.55) )
            return 2;
            break;

        default:
            return 0;
            break;

    }
}

int dcMotor::driveDual(char dir, float power)
/*
   drives a dual-channel motor
   args:
    - dir: direction of the motor (FORWARDS -> drives forwards | REVERSE -> drives backwards)
    - power: %power to run the motor at
   returns:
    - 1, if motor has been found and successfully updated
*/
{
    if(dir == "FORWARDS")
    {
    digitalWrite(dcMotor.in1, HIGH);
    digitalWrite(dcMotor.in2, LOW);
    digitalWrite(dcMotor.in3, HIGH);
    digitalWrite(dcMotor.in4, LOW);
    }
    else if(dir == "REVERSE")
    {
    digitalWrite(dcMotor.in1, LOW);
    digitalWrite(dcMotor.in2, HIGH);
    digitalWrite(dcMotor.in3, LOW);
    digitalWrite(dcMotor.in4, HIGH);
    }

    analogWrite(dcMotor.enA, round(power * 2.55) )
    return 1;
}

int dcMotor::overclock(float ocWattage)
/*
   overclocks a dual-channel motor
   args:
    - ocWattage: additional overclock wattage to apply to the motor
   returns:
    - 1, if motor has been successfully overclocked
    - 0, if overclock wattage has exceeded safe limits or failed
*/
{
    if(ocWattage <= dcMotor.ocLimit)
    {
    analogWrite(dcMotor.enB, round(ocWattage * (255/14.4) ) )
    return 1;
    }
    else
    {
    return 0;
    }
}