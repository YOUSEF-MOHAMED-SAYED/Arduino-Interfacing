#include <EEPROM.h> //include EEPROM library

void setup()
{
  Serial.begin(9600); // initialize Serial monitor with boudrate 9600
}

void loop() 
{
  while(Serial.available() == 0); // wait until user send data in Serial monitor
  String alldata = Serial.readStringUntil('\n'); // read all data input and store it in alldata variable
  if(alldata.startsWith("read"))
  {
    int spaceindex = alldata.indexOf(' '); // get index of space between prefix and address
    if(spaceindex != -1 )
    {
      String addressString = alldata.substring(spaceindex+1); // get addrees and store it
      int address = addressString.toInt(); // convert address to int
      int val = EEPROM.read(address);
      Serial.print("Value of address");
      Serial.print(address);
      Serial.print(" : ");
      Serial.print(val);
    }
  }
  else if(alldata.startsWith("write"))
  {
     int firstSpace = alldata.indexOf(' '); // get index of first space between prefix and address
     int secondSpace= alldata.indexOf(' ',firstSpace+1); // get index of second space , second argument mean start search from this
     if( (firstSpace != -1) && (secondSpace != -1) )
     {
       String addString = alldata.substring(firstSpace+1 , secondSpace); // get address string
       int address = addString.toInt();
       String valString = alldata.substring(secondSpace+1);
       int val = valString.toInt();
       EEPROM.write(address , val);
       Serial.print("done");
     }
  }
}
