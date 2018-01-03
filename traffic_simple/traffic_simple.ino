int greenled= 8;
int redled = 9;
int yellowled = 10;


void blink(int led, int dl){
  digitalWrite(led, HIGH);
  delay(dl);
  digitalWrite(led, LOW);
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(greenled, HIGH);
  digitalWrite(redled, HIGH);
  digitalWrite(yellowled, HIGH);
  digitalWrite(LED_BUILTIN, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenled, LOW);
  delay(1000);
  digitalWrite(greenled, HIGH);
  digitalWrite(yellowled, LOW);
  delay(1000);
  digitalWrite(yellowled, HIGH);
  digitalWrite(redled, LOW);
  delay(1000);
  digitalWrite(redled, HIGH);
}
