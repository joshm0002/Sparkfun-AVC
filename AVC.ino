void setup() {
  Serial.begin (115200);

}

String Command;

void loop() {

  if (Serial.available()>0){
    char c = Serial.read();
    Serial.println(Command); //Used for debug
   if(c == "/n") {
     parseCommand(Command);
     Command = "";
     }
   else {
    Command += c;
   }
  }
  
}

void parseCommand(String com) {
String motor;
String direct;
String power;
int powerint;
int pin;

//Example input string
// a,f,%50
// motor a selected
// Forward direction
// Power 50

motor = com.substring(0, com.indexOf(","));
direct = com.substring(com.indexOf(",")+1, com.indexOf(",%")); 
power = com.substring(com.indexOf(",%")+1);

if(motor.equalsIgnoreCase("a") && direct.equalsIgnoreCase("f")) {
  pin = 4;
}
if(motor.equalsIgnoreCase("a") && direct.equalsIgnoreCase("r")) {
  pin = 6;
}
if(motor.equalsIgnoreCase("b") && direct.equalsIgnoreCase("f")) {
  pin = 7;
}
if(motor.equalsIgnoreCase("b") && direct.equalsIgnoreCase("r")) {
  pin = 16;
}

powerint = power.toInt();
powerint = map(powerint, 0, 100, 0, 255);

analogWrite(pin, powerint);
  
}

