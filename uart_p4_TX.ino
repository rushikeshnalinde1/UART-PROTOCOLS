HardwareSerial uart(1);
void setup(){
  Serial.begin(115200);
  uart.begin(9600, SERIAL_8N1, 16, 17);
}

void loop(){
  uint8_t  package[5];
  package[0] = 0xAA;
  package[1] = 0x01;
  package[2] = 0x01;
  package[3] = package[2]+package[3];
  package[4] = 0x55;

  uart.write(package, 5);
}