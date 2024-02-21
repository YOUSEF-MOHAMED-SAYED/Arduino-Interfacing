const int firstbuttonpin = 7 ;
const int secondbuttonpin = 6 ;
const int ledpin = 10;

int firststate = 0;
int secondstate = 0;

void setup() {
  pinMode( firstbuttonpin , INPUT );
  pinMode( secondbuttonpin , INPUT ); 
  pinMode( ledpin , OUTPUT);
  digitalWrite(ledpin,LOW);
}

void loop() { 
  firststate = digitalRead(firstbuttonpin);
  secondstate = digitalRead(secondbuttonpin);
  if(firststate == HIGH)
  {
    digitalWrite( ledpin , HIGH);
  }
  else if(secondstate == HIGH)
  {
    digitalWrite( ledpin , HIGH);
  }
  else
  {
    digitalWrite( ledpin , LOW);
  }
}
