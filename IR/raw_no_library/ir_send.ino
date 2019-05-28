// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
int IRledPin =  2  ;    // LED connected to digital pin 13
int ledPin=1;
 int data;
// The setup() method runs once, when the sketch starts

void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);
   digitalWrite(ledPin, HIGH);
   delayMicroseconds(7);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   digitalWrite(ledPin, LOW);
   delayMicroseconds(7);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendOK() {
mustafa(33460,9740);
mustafa(4620,660);
mustafa(520,660);
mustafa(540,640);
mustafa(560,620);
mustafa(560,620);
mustafa(580,620);
mustafa(560,620);
mustafa(1740,620);
mustafa(580,600);
mustafa(580,600);
mustafa(600,580);
mustafa(600,600);
mustafa(600,580);
mustafa(600,580);
mustafa(600,600);
mustafa(1760,600);
mustafa(600,580);
mustafa(1780,600);
mustafa(1760,600);
mustafa(580,600);
mustafa(1760,600);
mustafa(600,580);
mustafa(600,600);
mustafa(580,600);
mustafa(600,580);
mustafa(600,600);
mustafa(580,600);
mustafa(1760,600);
mustafa(600,580);
mustafa(1780,600);
mustafa(1760,600);
mustafa(1760,600);
mustafa(1760,600);
mustafa(48020,9600);
mustafa(2360,580);


}
void power(){
mustafa(40728,2480);
mustafa(14328,9420);
mustafa(4460,840);
mustafa(300,840);
mustafa(300,820);
mustafa(300,840);
mustafa(300,840);
mustafa(320,720);
mustafa(420,700);
mustafa(1620,720);
mustafa(420,700);
mustafa(1620,700);
mustafa(1640,680);
mustafa(1640,680);
mustafa(1660,680);
mustafa(1640,680);
mustafa(1660,660);
mustafa(480,640);
mustafa(1680,640);
mustafa(520,620);
mustafa(1700,620);
mustafa(520,600);
mustafa(520,620);
mustafa(1720,600);
mustafa(540,600);
mustafa(520,620);
mustafa(520,600);
mustafa(1720,620);
mustafa(520,600);
mustafa(1720,620);
mustafa(1720,600);
mustafa(540,600);
mustafa(1720,600);
mustafa(1740,600);
mustafa(1720,620);
mustafa(41760,9260);
mustafa(2260,600);
mustafa(34204,9240);
mustafa(2320,560);
}
void UP(){
mustafa(35404,9400);
mustafa(4680,560);
mustafa(600,560);
mustafa(600,580);
mustafa(600,560);
mustafa(600,580);
mustafa(600,560);
mustafa(600,560);
mustafa(1780,560);
mustafa(600,580);
mustafa(600,560);
mustafa(600,580);
mustafa(600,560);
mustafa(600,560);
mustafa(620,540);
mustafa(620,560);
mustafa(1780,560);
mustafa(600,560);
mustafa(1780,560);
mustafa(1780,560);
mustafa(620,540);
mustafa(1800,540);
mustafa(620,560);
mustafa(600,560);
mustafa(620,560);
mustafa(600,560);
mustafa(620,560);
mustafa(600,560);
mustafa(1780,560);
mustafa(600,560);
mustafa(1780,560);
mustafa(1780,560);
mustafa(1780,560);
mustafa(1780,560);
mustafa(47860,9320);
mustafa(2380,540);
}
int mustafa(int a,int b){
    delayMicroseconds(a);
    pulseIR(b);
}
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT); 
  pinMode(ledPin,OUTPUT); 
    
 
  //Serial.begin(9600);
}
 
void loop()                     
{ 
  //Serial.println("Sending IR signal");

 UP();
 delay(500);

}
  


 
