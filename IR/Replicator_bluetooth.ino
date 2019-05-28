#include <IRremote.h>
#include "SoftwareSerial.h"
int RECV_PIN = 2;
int STATUS_PIN = 13;
unsigned long  data;
String BluetoothData;
char recieve;
IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;



// Storage for the recorded code
int codeType = -1; // The type of code
unsigned long codeValue; // The code value if not raw
unsigned int rawCodes[RAWBUF]; // The durations if raw
int codeLen; // The length of the code
int toggle = 0; // The RC5/6 toggle state
SoftwareSerial HC05(A4,A5);//tx,rx

void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome to IR mapper!");
  HC05.begin(9600);

  irrecv.enableIRIn(); // Start the receiver
  pinMode(STATUS_PIN, OUTPUT);
}


// Stores the code for later playback
// Most of this code is just logging
void storeCode(decode_results *results, long int *Value, int *Len) {
  codeType = results->decode_type;
  int count = results->rawlen;
  if (codeType == UNKNOWN) {
    Serial.println("Unknown code");


  }
  else {
    if (codeType == NEC) {
      Serial.print("Received NEC: ");
          
          


      if (results->value == REPEAT) {
        // Don't record a NEC repeat value as that's useless.
        Serial.println("repeat; ignoring.");
        return;
      }
    }
    else {
      Serial.print("Unexpected codeType ");Serial.print(codeType, DEC);Serial.println("");

    }
    Serial.println(results->value,HEX);
    HC05.print(String(results->value,HEX));
    *Value = results->value;
    *Len = results->bits;
  }
}




void sendCode(long int Value, int Len) {
  if (codeType == NEC) {
    if(Value==0){Serial.println("empty!");
    }
    else{
    Serial.println("Pressed, sending");
    digitalWrite(STATUS_PIN, HIGH);
    irsend.sendNEC(Value, Len);
    Serial.print("Sent NEC ");
    Serial.println(Value, HEX);
    digitalWrite(STATUS_PIN, LOW);
    delay(50);}}
  

  else if (codeType == UNKNOWN /* i.e. raw */) {
    // Assume 38 KHz
    irsend.sendRaw(rawCodes, codeLen, 38);
    Serial.println("Unknown code!");
    recieve='k';
  }
    irrecv.enableIRIn(); // Start the receiver

}

void loop() {

if (HC05.available()){
  HC05.setTimeout(200);

  BluetoothData=HC05.readString();
  data=convert(BluetoothData);
  Serial.println(BluetoothData);
  Serial.println(data);
  if(data>10000){ irsend.sendNEC(data, 32);delay(40);
  Serial.println("sent");
 irrecv.enableIRIn();  }
 
  //if(data>0){Serial.println(data);}
  if (data == 96) {
    //irrecv.enableIRIn();
    Serial.write(27);       // ESC command
    Serial.print("[2J");    // clear screen command
    Serial.write(27);
    Serial.print("[H");     // cursor to home command
    Serial.println("configuration mode:");
    Serial.println("point your remote to the reciever and press a button then select a corresponding button on your keyboard");
  }

  if (data == 1) {
    digitalWrite(STATUS_PIN, HIGH);
    if (irrecv.decode(&results)) {
      digitalWrite(STATUS_PIN, HIGH);
      storeCode(&results, &codeValue, &codeLen);
      irrecv.resume(); // resume receiver
      digitalWrite(STATUS_PIN, LOW);
    }


  } 
}
}


unsigned long power(int number){
  unsigned long result=1;
  for(int i=0;i<number;i++)
  result*=16;
  return result;
}

unsigned long convert(String data){
  int count2=data.length()-1;
  unsigned long result=0;
char letter;
int number;
for (int i=0;i<=count2;i++){
      letter=data[i];
      if(letter=='0')number=0;
      else if(letter=='1')number=1;
      else if(letter=='2')number=2;
      else if(letter=='3')number=3;
      else if(letter=='4')number=4;
      else if(letter=='5')number=5;
      else if(letter=='6')number=6;
      else if(letter=='7')number=7;
      else if(letter=='8')number=8;
      else if(letter=='9')number=9;
      else if(letter=='a'||letter=='A')number=10;
      else if(letter=='b'||letter=='B')number=11;
      else if(letter=='c'||letter=='C')number=12;
      else if(letter=='d'||letter=='D')number=13;
      else if(letter=='e'||letter=='E')number=14;
      else if(letter=='f'||letter=='F')number=15;
      //Serial.print("number");Serial.println(number);
      result+=number*(power(count2-i));
      //Serial.print("count ");
      //Serial.print(count2-i);
      //Serial.print("number  ");
      //Serial.println(power(count2-i));
      //Serial.println(result);
      
    }
    //Serial.println(result);
    //Serial.println(data);
    return result;
    }
