#include "RelayBoard.h"  //including the header file that was made

int unswitchedArray[5];
int switchedArray[5];
int finalArray[5];
int intermidiatearray[5]; //array holding the buble sorted values
int x=0;
int n=0;
int z=0;
int k=0;
int j=0;
int intermidiateprint= 0;
int storingIntermidiateArray =0;
int gettingFinalArray=0;
int count;
int temp;

RelayBoard relays(3, 4, 5, 6, 7,8);  // what relay numbers will be used

struct values {          //a group of variables asigned to one block of memory
    uint8_t pins[5];     //asigns pins in an array [] to have a width of 8 bits and be positive only
    uint16_t values[5];  ////asigns pins in an array [] to have a width of 16 bits and be positive only
    uint8_t code[5];
} readings = { .pins = { A0, A1, A2, A3, A4 }};  //defines what pins are used for readings

void read_value(uint8_t pin, struct values *v, RelayBoard *r);  //setting what will be read?

void setup()  //the setup for the program
{
    Serial.begin(9600);  // denotes what data rate in bits per second
}

void loop()  //the infinite loop 
{
  while(x<1){
    for (int i = 0; i < RelayBoard::PINS; i++) {  //the begining of the for loop dets i to n integer
        relays.select(i); //select the relays that are enabled( does it cycle threw here?)
        delay(3000);  //pauses code for 3 seconds
        read_value(i, &readings, &relays); //(enter the value from the pins struct?)
        Serial.print("Reading from ");  //prints the comment in serial data printout
        Serial.print(i);   //prints what i it is currently on from the struct
        Serial.print(": ");  //prints the ":" for the reading
        Serial.println(readings.values[i] * (5.0/1023.0));  //Prints the valueof the reading from a pin then changes it to volts
        unswitchedArray[i]=readings.values[i];
        x=1;
    }
    
    }
    while(n<1){
    Serial.println("");  //I don't know why
    Serial.println(unswitchedArray[0]);
    Serial.println(unswitchedArray[1]);
    Serial.println(unswitchedArray[2]);
    Serial.println(unswitchedArray[3]);
    Serial.println(unswitchedArray[4]);
    n=1;
    }
relays.switchpolarity();
while(z<1){
    for (int i = 0; i < RelayBoard::PINS; i++) {  //the begining of the for loop dets i to n integer
        relays.select(i); //select the relays that are enabled( does it cycle threw here?)
        delay(3000);  //pauses code for 3 seconds
        read_value(i, &readings, &relays); //(enter the value from the pins struct?)
        Serial.print("Reading from ");  //prints the comment in serial data printout
        Serial.print(i);   //prints what i it is currently on from the struct
        Serial.print(": ");  //prints the ":" for the reading
        Serial.println(readings.values[i] * (5.0/1023.0));  //Prints the valueof the reading from a pin then changes it to volts
        switchedArray[i]=readings.values[i];
        z=1;
    }

    while(k<1){
    Serial.println("");  //I don't know why
    Serial.println(switchedArray[0]);
    Serial.println(switchedArray[1]);
    Serial.println(switchedArray[2]);
    Serial.println(switchedArray[3]);
    Serial.println(switchedArray[4]);
    k=1;
    }

memcpy( intermidiatearray, unswitchedArray, 5*sizeof(int) );


  while (storingIntermidiateArray<1){
    
for(count=0;count<10;count++){
        // repeat until i= length of list
        for (int i=0; i<5; i++)
        {
            if(intermidiatearray[i] < intermidiatearray[i+1])
            {  //swap the two elements
                temp = intermidiatearray[i];
                intermidiatearray[i]=intermidiatearray[i+1];
                intermidiatearray[i+1] = temp;
            }
        }
    storingIntermidiateArray++;
  }
 }
  while(intermidiateprint<1){
    Serial.println("");  //I don't know why
    Serial.println(intermidiatearray[0]);
    Serial.println(intermidiatearray[1]);
    Serial.println(intermidiatearray[2]);
    Serial.println(intermidiatearray[3]);
    Serial.println(intermidiatearray[4]);


//finding the wire in the haystack
      if (intermidiatearray[0]=unswitchedArray[0]){
        unswitchedArray[0]=1;
      }
      if (intermidiatearray[0]=unswitchedArray[1]){
        unswitchedArray[1]=1;
      }
      if (intermidiatearray[0]=unswitchedArray[2]){
        unswitchedArray[2]=1;
      }
      if (intermidiatearray[0]=unswitchedArray[3]){
        unswitchedArray[3]=1;
      }
      if (intermidiatearray[0]=unswitchedArray[4]){
        unswitchedArray[4]=1;
      }


      /*finding the inductor in the haystack
      if (intermidiatearray[1]=unswitchedArray[0]){
        unswitchedArray[0]=4;
      }
      if (intermidiatearray[1]=unswitchedArray[1]){
        unswitchedArray[1]=4;
      }
      if (intermidiatearray[1]=unswitchedArray[2]){
        unswitchedArray[2]=4;
      }
      if (intermidiatearray[1]=unswitchedArray[3]){
        unswitchedArray[3]=4;
      }
      if (intermidiatearray[1]=unswitchedArray[4]){
        unswitchedArray[4]=4;
      }

      //finding the resistor in the haystack 
      if (intermidiatearray[2]=unswitchedArray[0]){
        unswitchedArray[0]=2;
      }
      if (intermidiatearray[2]=unswitchedArray[1]){
        unswitchedArray[1]=2;
      }
      if (intermidiatearray[2]=unswitchedArray[2]){
        unswitchedArray[2]=2;
      }
      if (intermidiatearray[2]=unswitchedArray[3]){
        unswitchedArray[3]=2;
      }
      if (intermidiatearray[2]=unswitchedArray[4]){
        unswitchedArray[4]=2;
      }


//finding capacitor in the haystack
      if (intermidiatearray[3]=unswitchedArray[0]){
        unswitchedArray[0]=3;
      }
      if (intermidiatearray[3]=unswitchedArray[1]){
        unswitchedArray[1]=3;
      }
      if (intermidiatearray[3]=unswitchedArray[2]){
        unswitchedArray[2]=3;
      }
      if (intermidiatearray[3]=unswitchedArray[3]){
        unswitchedArray[3]=3;
      }
      if (intermidiatearray[3]=unswitchedArray[4]){
        unswitchedArray[4]=3;
      }


//finding the diode in the haystack
      if (intermidiatearray[4]=unswitchedArray[0]){
        unswitchedArray[0]=5;
      }
      if (intermidiatearray[4]=unswitchedArray[1]){
        unswitchedArray[1]=5;
      }
      if (intermidiatearray[4]=unswitchedArray[2]){
        unswitchedArray[2]=5;
      }
      if (intermidiatearray[4]=unswitchedArray[3]){
        unswitchedArray[3]=5;
      }
      if (intermidiatearray[4]=unswitchedArray[4]){
        unswitchedArray[4]=5;
      }*/

    Serial.println("");  //I don't know why
    Serial.println(unswitchedArray[0]);
    Serial.println(unswitchedArray[1]);
    Serial.println(unswitchedArray[2]);
    Serial.println(unswitchedArray[3]);
    Serial.println(unswitchedArray[4]);

    
    intermidiateprint=1;
    }


  
    
 }


}

void read_value(uint8_t pin, struct values *v, RelayBoard *r)  //reads the values again?
{
    r->select(pin); //selects pins 
    v->values[pin] = analogRead(v->pins[pin]); 
}


  //Diode = 1.38  code 5
  //Resistor = 3.5  code 2
  //Inductor = 1.27  code 4
  //Capasitor = 5    code 3
  //wire = .87    code 1
