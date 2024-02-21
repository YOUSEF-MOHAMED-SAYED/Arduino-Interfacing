void setup() {
  pinMode( 13 , OUTPUT );
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() == 0);// wait until sending
  int DataSent = Serial.read();
  if(DataSent == '1')
  {
    digitalWrite( 13 , HIGH );
  }
  else if(DataSent == '0')
  {
    digitalWrite( 13 , LOW );
  }
}
