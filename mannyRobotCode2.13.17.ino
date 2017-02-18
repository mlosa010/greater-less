#include "RelayBoard.h"  //including the header file that was made

#define WIRE 1
#define RESISTOR 2
#define CAPACITOR 3
#define INDUCTOR 4
#define DIODE 5

int unswitchedArray[5];
int switchedArray[5];
int unswitchedSort[5];
int switchedSort[5]; //array holding the buble sorted values
int x = 0;
int n = 0;
int z = 0;
int k = 0;
int j = 0;
int i = 0;
int intermidiateprint= 0;
int storingswitchedSort =0;
int gettingunswitchedSort=0;
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
  while(x<1) {
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
    Serial.println("");
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

    memcpy( switchedSort, unswitchedArray, 5*sizeof(int) );

    while (storingswitchedSort<1) {
      for(count=0;count<10;count++) {
        // repeat until i= length of list
        for (int i=0; i<5; i++) {
          if(switchedSort[i] < switchedSort[i+1]) {  //swap the two elements
            temp = switchedSort[i];
            switchedSort[i]=switchedSort[i+1];
            switchedSort[i+1] = temp;
          }
        }
        storingswitchedSort++;
      }
    }

  while(intermidiateprint<1){
    Serial.println("");  //I don't know why
    Serial.println(switchedSort[0]);
    Serial.println(switchedSort[1]);
    Serial.println(switchedSort[2]);
    Serial.println(switchedSort[3]);
    Serial.println(switchedSort[4]);

    //finding the wire in the haystack
    for (i = 0;i < 5;i++) {
      if (unswitchedArray[i] == unswitchedSort[0])
        unswitchedArray[i] = CAPACITOR;
      else if (unswitchedArray[i] == unswitchedSort[1])
        unswitchedArray[i] = RESISTOR;
      else if (unswitchedArray[i] == unswitchedSort[2])
        unswitchedArray[i] = DIODE;
      else if (unswitchedArray[i] == unswitchedSort[3])
        unswitchedArray[i] = INDUCTOR;
      else if (unswitchedArray[i] == unswitchedSort[4])
        unswitchedArray[i] = WIRE;
    }

    Serial.println("");  //I don't know why
    Serial.println(unswitchedArray[0]);
    Serial.println(unswitchedArray[1]);
    Serial.println(unswitchedArray[2]);
    Serial.println(unswitchedArray[3]);
    Serial.println(unswitchedArray[4]);

    for (i = 0;i < 5;i++) {
      if (switchedArray[i] == switchedSort[0])
        switchedArray[i] = WIRE;
      else if (switchedArray[i] == switchedSort[1])
        switchedArray[i] = INDUCTOR;
      else if (unswitchedArray[i] == switchedSort[2])
        switchedArray[i] = RESISTOR;
      else if (unswitchedArray[i] == switchedSort[3])
        switchedArray[i] = CAPACITOR;
      else if (switchedArray[i] == switchedSort[4])
        switchedArray[i] = DIODE;
    }

    Serial.println("");  //I don't know why
    Serial.println(switchedArray[0]);
    Serial.println(switchedArray[1]);
    Serial.println(switchedArray[2]);
    Serial.println(switchedArray[3]);
    Serial.println(switchedArray[4]);

        
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
