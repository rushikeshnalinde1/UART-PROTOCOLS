HardwareSerial uart(1);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  uart.begin(9600, SERIAL_8N1, 16, 17);
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(uart.available()) {

    if(uart.read() == 0xAA) {

        while(uart.available() < 4);

        uint8_t led = uart.read();
        uint8_t state = uart.read();
        uint8_t checksum = uart.read();
        uint8_t endByte = uart.read();

        if(endByte == 0x55 &&
           checksum == (led + state)) {

            Serial.println("Valid Packet");

            if(led == 0x01) {
                digitalWrite(22, state ? HIGH : LOW);
            }
        }
    }
}
}

