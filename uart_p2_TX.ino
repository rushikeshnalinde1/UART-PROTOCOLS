HardwareSerial uart(1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  uart.begin(9600, SERIAL_8N1, 16, 17);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String msg = Serial.readStringUntil('\n');
    msg.trim();
    uart.println(msg);
    Serial.print("sent: ");
    Serial.println(msg);
  }

}
