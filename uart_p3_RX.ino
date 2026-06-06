HardwareSerial uart(1);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  uart.begin(9600, SERIAL_8N1, 16, 17);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(uart.available()){
    String msg = uart.readStringUntil('\n');
    Serial.println(msg);
  }

}
