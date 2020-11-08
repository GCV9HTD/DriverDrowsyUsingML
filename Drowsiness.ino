#define ir1 2
#define ir2 3
#define ir3 4
#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define buzz 7
#define gas 5


void setup() {
  Serial.begin(9600);
  Serial.println("Driver drowsiness");
  // put your setup code here, to run once:
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(ir3,INPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(gas,INPUT);
pinMode(buzz,OUTPUT);
}



void loop() {
  
  // put your main code here, to run repeatedly:
  int IR1=digitalRead(ir1);
  int IR2=digitalRead(ir2);
  int IR3=digitalRead(ir3);
  serialEvent();
  if(IR1==LOW && IR2==LOW && IR3==HIGH)
  {
    RIGHT();
  }

  else if(IR1==LOW && IR2==HIGH && IR3==LOW)
  {
    LEFT();
  }

  else if (IR1==HIGH && IR2==HIGH && IR3==HIGH)
  {
    FORWARD();
  }

  else if(IR1==LOW && IR2==LOW && IR3==LOW)
  {
    REVERSE();
  }

  else if(IR1==LOW)
  {
    REVERSE();
  }
  else{
   FORWARD();
   serialEvent();
  }

  
}
void IR1()
{
 if(digitalRead(ir1)==LOW){
    Serial.println("Front object detected");
    delay(100);
    serialEvent();
  }
  else
  {
    Serial.println("Front object not detected");
    delay(100);
    serialEvent();
  
  }

 
}

void IR2()
{
 if(digitalRead(ir2)==LOW){
    Serial.println("Left object detected");
    delay(100);
    serialEvent();
  }
  else
  {
    Serial.println("Left object not detected");
    delay(100);
    serialEvent();
  }
}


void IR3()
{
 if(digitalRead(ir3)==LOW){
    Serial.println("Right object detected");
    delay(100);
    serialEvent();
  }
}

void GAS()
{
 if(digitalRead(gas)==LOW){
    Serial.println("Alcohol intoxocated");
    delay(100);
    digitalWrite(buzz,HIGH);
    delay(100);
    digitalWrite(buzz,LOW);
    delay(100);
  }
}

void FORWARD()
{
  //For forward in1,in3-LOW in2,in4-HIGH
  //OP-AMP1
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  //OP-AMP2
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  serialEvent();
}

void REVERSE()
{
  //For reverse 1-HIGH 2-LOW 3-HIGH 4-LOW
  //OP-AMP1
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  //OP-AMP2
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  serialEvent();
}

void STOP()
{
  //For stop0 1,2,3,4=LOW
  //OP-AMP1
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  //OP-AMP2
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void LEFT()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void RIGHT()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void serialEvent()
{
  if(Serial.available()>0)
  {
    char ch;
    ch=Serial.read();
    if(ch=='$')
    {
    Serial.print("drowsiness detected");
    LEFT();
    delay(2000);
    STOP();
    delay(2000);
  }
}
}
