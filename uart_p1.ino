const uint8_t led = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String input = Serial.readStringUntil('\n');
    input.trim();

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
