const uint8_t led = 2;
HardwareSerial uart(1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  uart.begin(9600, SERIAL_8N1, 16, 17);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(uart.available()){
    String input = uart.readStringUntil('\n');
    input.trim();
    Serial.print("revieved: ");
    Serial.println(input);

    if(input == "on"){
      digitalWrite(led, HIGH);
    }
    else if(input == "off"){
      digitalWrite(led, LOW);
    }
    else if(input == "blink"){
      for(int i=0; i<5; i++){
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
      }
    }
  }

}
