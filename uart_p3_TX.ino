HardwareSerial uart(1);
const uint8_t pot = 34;

void setup(){
  Serial.begin(115200);
  uart.begin(9600, SERIAL_8N1, 16, 17);
  pinMode(pot, INPUT);
}

void loop(){
  int adc = analogRead(pot);
 
    uart.print(" adc value is: ");
    uart.println(adc);
    Serial.println("message sent ");
  delay(1000);
}