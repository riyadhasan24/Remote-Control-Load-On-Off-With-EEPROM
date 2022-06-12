#include <IRremote.h>
#include <EEPROM.h>

int Receive_PIN = 2;
IRrecv IR_Receive(Receive_PIN);
decode_results Results;

int State_1 = HIGH;
int State_2 = HIGH;
int Load_1 = 8;
int Load_2 = 9;
byte Valu_1;
byte Valu_2;

void setup()
  {
    IR_Receive.enableIRIn();
    pinMode(Load_1, OUTPUT);
    pinMode(Load_2, OUTPUT);  
  }

void loop() 
{
  if(IR_Receive.decode(&Results)) 
    {    
        IR_Receive.resume();
        if(Results.value == 0x58853BFC)
          {
            digitalWrite(Load_1, State_1);
            EEPROM.write("E_Load_1", State_1);
            State_1 = !State_1; 
          }
        
        if(Results.value == 0x58853BCE)  
          {
            digitalWrite(Load_2, State_2);
            EEPROM.write("E_Load_2", State_2);
            State_2 = !State_2; 
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
