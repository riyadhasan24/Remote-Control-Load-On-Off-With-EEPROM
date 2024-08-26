#include <IRremote.h>
#include <EEPROM.h>

int Receive_PIN = 3;
IRrecv IR_Receive(Receive_PIN);
decode_results Results;

#define Light_1  10
#define Light_2  11
#define Light_3  12
#define Light_4  13


int State_1 = HIGH;
int State_2 = HIGH;
int State_3 = HIGH;
int State_4 = HIGH;

byte Valu_1;
byte Valu_2;
byte Valu_3;
byte Valu_4;

void setup()
  {
    IR_Receive.enableIRIn();

    pinMode(Light_1, OUTPUT);
    pinMode(Light_2, OUTPUT);
    pinMode(Light_3, OUTPUT);
    pinMode(Light_4, OUTPUT);  
  }

void loop() 
{
  if(IR_Receive.decode(&Results)) 
    {    
        IR_Receive.resume();

        if(Results.value == 0x58853BFC)
          {
            digitalWrite(Light_1, State_1);
            EEPROM.write("E_Light_1", State_1);
            State_1 = !State_1; 
          }
        
        if(Results.value == 0x58853BCE)  
          {
            digitalWrite(Light_2, State_2);
            EEPROM.write("E_Light_2", State_2);
            State_2 = !State_2; 
          }

        if(Results.value == 0x58853BCE)  
          {
            digitalWrite(Light_3, State_3);
            EEPROM.write("E_Light_3", State_3);
            State_3 = !State_3; 
          }

        if(Results.value == 0x58853BCE)  
          {
            digitalWrite(Light_4, State_4);
            EEPROM.write("E_Light_4", State_4);
            State_4 = !State_4; 
          }    
    }
        else
            {
               Valu_1 = EEPROM.read("E_Load_1");
               digitalWrite(Load_1, Valu_1);

               Valu_2 = EEPROM.read("E_Load_2");
               digitalWrite(Load_2, Valu_2);
            }     
}
