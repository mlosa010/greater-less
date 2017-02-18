#include "RelayBoard.h" // including the header file that was made

#define WIRE 1
#define RESISTOR 2
#define CAPACITOR 3
#define INDUCTOR 4
#define DIODE 5

void bubSort(int arrToSort[5]);
void gettingValues(int aquiredArray[5]);

int unswitchedArray[5];
int switchedArray[5];
int unswitchedSort[5];
int switchedSort[5]; // array holding the buble sorted value
int i = 0;
int done = 0;

RelayBoard relays(3, 4, 5, 6, 7, 8); // what relay numbers will be used

struct values {    // a group of variables asigned to one block of memory
  uint8_t pins[5]; // asigns pins in an array [] to have a width of 8 bits and
                   // be positive only
  uint16_t values[5]; // asigns pins in an array [] to have a width of 16 bits
  // and be positive only
  uint8_t code[5];
} readings = {
    .pins = {A0, A1, A2, A3, A4}}; // defines what pins are used for readings

void read_value(uint8_t pin, struct values *v,
                RelayBoard *r); // setting what will be read?

void setup() // the setup for the program
{
  Serial.begin(9600); // denotes what data rate in bits per second
}

void loop() // the infinite loop
{
  while (done != 1) {
    gettingValues(unswitchedArray);
    Serial.println("");
    Serial.println("Switching polarity.");
    Serial.println("");
    relays.switchpolarity();
    gettingValues(switchedArray);

    Serial.println("");

    Serial.println("Printing the unswitched array:");
    for (i = 0; i < 5; i++) {
      Serial.println(unswitchedArray[i]);
    }

    Serial.println("");

    Serial.println("Printing the switched array:");
    for (i = 0; i < 5; i++) {
      Serial.println(switchedArray[i]);
    }

    Serial.println("");

    memcpy(unswitchedSort, unswitchedArray, 5 * sizeof(int));

    Serial.println("Printing the to be sorted unswitched array:");
    for (i = 0; i < 5; i++) {
      Serial.println(unswitchedSort[i]);
    }

    Serial.println("");

    bubSort(unswitchedSort);

    memcpy(switchedSort, switchedArray, 5 * sizeof(int));

    Serial.println("Printing the to be sorted switched array:");
    for (i = 0; i < 5; i++) {
      Serial.println(switchedSort[i]);
    }

    Serial.println("");

    bubSort(switchedSort);

    Serial.println("Printing the sorted unswitched array:");
    for (i = 0; i < 5; i++) {
      Serial.println(unswitchedSort[i]);
    }

    Serial.println("");

    Serial.println("Printing the sorted switched array:");
    for (i = 0; i < 5; i++) {
      Serial.println(switchedSort[i]);
    }

    Serial.println("");

    // finding the wire in the haystack
    for (i = 0; i < 5; i++) {
      if (unswitchedArray[i] == unswitchedSort[0])
        unswitchedArray[i] = WIRE;
      if (unswitchedArray[i] == unswitchedSort[1])
        unswitchedArray[i] = CAPACITOR;
      if (unswitchedArray[i] == unswitchedSort[2])
        unswitchedArray[i] = INDUCTOR;
      if (unswitchedArray[i] == unswitchedSort[3])
        unswitchedArray[i] = RESISTOR;
      if (unswitchedArray[i] == unswitchedSort[4])
        unswitchedArray[i] = DIODE;
    }

    Serial.println("Printing out the final unswitched array:");
    for (i = 0; i < 5; i++) {
      Serial.println(unswitchedArray[i]);
    }

    Serial.println("");

    for (i = 0; i < 5; i++) {
      if (switchedArray[i] == switchedSort[0])
        switchedArray[i] = RESISTOR;
      if (switchedArray[i] == switchedSort[1])
        switchedArray[i] = DIODE;
      if (switchedArray[i] == switchedSort[2])
        switchedArray[i] = INDUCTOR;
      if (switchedArray[i] == switchedSort[3])
        switchedArray[i] = CAPACITOR;
      if (switchedArray[i] == switchedSort[4])
        switchedArray[i] = WIRE;
    }

    Serial.println("Printing out the final switched array:");
    for (i = 0; i < 5; i++) {
      Serial.println(switchedArray[i]);
    }

    Serial.println("");

    done = 1;
  }
}

void bubSort(int arrToSort[5]) {
  int count, temp;

  for (count = 0; count < 4; count++) {
    for (i = 0; i < 5 - count - 1; i++) {
      if (arrToSort[i] < arrToSort[i + 1]) { // swap the two elements
        temp = arrToSort[i];
        arrToSort[i] = arrToSort[i + 1];
        arrToSort[i + 1] = temp;
      }
    }
  }
}

void gettingValues(int aquiredArray[5]) {
  for (i = 0; i < RelayBoard::PINS;
       i++) { // the begining of the for loop dets i to n integer
    relays.select(
        i); // select the relays that are enabled( does it cycle threw here?)
    delay(3000);                       // pauses code for 3 seconds
    read_value(i, &readings, &relays); // enter the value from the pins struct?
    Serial.print("Reading from "); // prints the comment in serial data printout
    Serial.print(i);
    Serial.print(":");
    Serial.println(readings.values[i] * (5.0 / 1023.0)); // Prints the valueof
                                                         // the reading from a
                                                         // pin then changes
                                                         // it to volts
    aquiredArray[i] = readings.values[i];
  }
}

void read_value(uint8_t pin, struct values *v,
                RelayBoard *r) // reads the values again?
{
  r->select(pin); // selects pins
  v->values[pin] = analogRead(v->pins[pin]);
}

// Diode = 1.38  code 5
// Resistor = 3.5  code 2
// Inductor = 1.27  code 4
// Capasitor = 5    code 3
// wire = .87    code 1
