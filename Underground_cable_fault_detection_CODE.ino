#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#define RX 12
#define TX 11
String AP = "bhavya”;
            // AP NAME
            String PASS = "bhavyabhatia123";  // AP PASSWORD
            String API = "TALU6IGV086XT3EN";  // Write API KEY
            String HOST = "api.thingspeak.com";
            String PORT = "80";
            String field = "field1";
            int countTrueCommand;
            int countTimeCommand;
            boolean found = false;
            SoftwareSerial esp8266(RX, TX);
            int sensorPin = A0;   // select the input pin for ldr
            int sensorValue = 0;  // variable to store the value coming from the sensor
            int red = 0;
            int yellow = 0;
            int blue = 0;
            18 | P a g e
            void setup() {
            Serial.begin(9600);
            esp8266.begin(9600);
            sendCommand("AT", 5, "OK");
            sendCommand("AT + CWMODE = 1", 5, "OK");
                                       sendCommand("AT + CWJAP = \"" + AP + "\",\"" + PASS + "\"", 20, "OK");
pinMode(8, OUTPUT);   // Relay 1
pinMode(9, OUTPUT);   // Relay 2
pinMode(10, OUTPUT);  // Relay 3
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
lcd.begin(16, 2);
lcd.print("UNDERGROUND CABLE");
lcd.setCursor(0, 1);
lcd.print("FAULT LOCATOR");
delay(1000);
delay(1000);
}
void loop() {
  lcd.clear();
  digitalWrite(8, LOW);  // Low means relay on
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);

  delay(350);
  lcd.setCursor(1, 0);
  lcd.print("R");
  lcd.write(1);
  lcd.setCursor(7, 0);
  lcd.print("Y");
  lcd.write(1);
  lcd.setCursor(13, 0);
  lcd.print("B");
  lcd.write(1);
  sensorValue = analogRead(sensorPin);    // read the value from the sensor
  Serial.println(sensorValue);
  screen
  //prints the values coming from the sensor on the
  if ((sensorValue >= 1000)) {
    lcd.setCursor(0, 1);
    lcd.print("NF");
    Serial.print("R -  NF,");
    red = 0;
  }
  else if ((sensorValue >= 890) && (sensorValue <= 920)) {
    Serial.print("R - 8KM,");
    lcd.setCursor(0, 1);
    lcd.print("8KM");
    int red = 8;

  }
  else if ((sensorValue >= 870) && (sensorValue <= 880)) {
    Serial.print("R - 6KM,");
    lcd.setCursor(0, 1);
    lcd.print("6KM");
    red = 6;
  }
  else if ((sensorValue >= 800) && (sensorValue <= 825)) {
    Serial.print("R - 4KM,");
    lcd.setCursor(0, 1);
    lcd.print("4KM");
    red = 4;
  }
  else if ((sensorValue >= 670) && (sensorValue <= 688)) {
    Serial.print("R - 2KM,");
    lcd.setCursor(0, 1);
    lcd.print("2KM");
    red = 2;
  }
  delay(1500);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(350);
  sensorValue = analogRead(sensorPin);  // read the value from the sensor

  Serial.println(sensorValue);
  screen
  if ((sensorValue >= 1000)) {
    Serial.print("Y -  NF");
    lcd.setCursor(6, 1);
    lcd.print("NF");
    yellow = 0;
    //prints the values coming from the sensor on the
  }
  else if ((sensorValue >= 890) && (sensorValue <= 920)) {
    lcd.setCursor(6, 1);
    Serial.print("Y - 8KM,");
    lcd.print("8KM");
    yellow = 8;
  }
  else if ((sensorValue >= 870) && (sensorValue <= 880)) {
    Serial.print("Y - 6KM,");
    lcd.setCursor(6, 1);
    lcd.print("6KM");
    yellow = 6;
  }
  else if ((sensorValue >= 800) && (sensorValue <= 825)) {
    Serial.print("Y - 4KM,");
    lcd.setCursor(6, 1);
    lcd.print("4KM");
    yellow = 4;
  }

  else if ((sensorValue >= 670) && (sensorValue <= 688)) {
    Serial.print("Y - 2KM,");
    lcd.setCursor(6, 1);
    lcd.print("2KM");
    yellow = 2;
  }
  delay(1500);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(350);
  sensorValue = analogRead(sensorPin);  // read the value from the sensor
  Serial.println(sensorValue);
  //prints the values coming from the sensor on the
  screen
  if ((sensorValue >= 1000)) {
    lcd.setCursor(12, 1);
    Serial.println("B -  NF");
    lcd.print("NF");
    blue = 0;
  }
  else if ((sensorValue >= 890) && (sensorValue <= 920)) {
    Serial.println("B - 8KM");
    lcd.setCursor(12, 1);
    lcd.print("8KM");
    blue = 8;
    23 | P a g e
  }
  else if ((sensorValue >= 870) && (sensorValue <= 880)) {
    Serial.println("B - 6KM");
    lcd.setCursor(12, 1);
    lcd.print("6KM");
    blue = 6;
  }
  else if ((sensorValue >= 800) && (sensorValue <= 825)) {
    Serial.println("B - 4KM");
    lcd.setCursor(12, 1);
    lcd.print("4KM");
    blue = 4;
  }
  else if ((sensorValue >= 670) && (sensorValue <= 688)) {
    Serial.println("B - 2KM");
    lcd.setCursor(12, 1);
    lcd.print("2KM");
    blue = 2;
  }
  delay(1500);
  String getData = "GET /update?api_key=" + API + "&" + field + "=" + String(red) +
                   "&field2=" + String(yellow) + "&field3=" + String(blue);
  sendCommand("AT+CIPMUX=1", 5, "OK");
  sendCommand("AT+CIPSTART=0,\"TCP\",\"" + HOST + "\"," + PORT, 15, "OK");
  sendCommand("AT+CIPSEND=0," + String(getData.length() + 4), 4, ">");
  esp8266.println(getData);
  delay(1500);
  countTrueCommand++;

  sendCommand("AT+CIPCLOSE=0", 5, "OK");
  delay(5000);
}
void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while (countTimeCommand < (maxTime * 1)) {
    esp8266.println(command);
    //at+cipsend
    if (esp8266.find(readReplay))  //ok
    {
      found = true;
      break;
    }
    countTimeCommand++;
  }
  if (found == true) {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  if (found == false) {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  found = false;
}
