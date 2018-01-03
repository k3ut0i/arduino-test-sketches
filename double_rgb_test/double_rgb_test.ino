int green1 = 8;
int blue1= 9;
int red1 = 10;

int green2 = 5;
int blue2 = 6;
int red2 = 7;

void blink(int led, int dl){
  // I'm using common anode rgb led's wired so LOW turns it on.
  digitalWrite(led, LOW);
  delay(dl);
  digitalWrite(led, HIGH);
  }

void setup() {
  // put your setup code here, to run once:

  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  digitalWrite(green1, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(blue1, HIGH);
  
  digitalWrite(green2, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(blue2, HIGH);
  
  digitalWrite(LED_BUILTIN, LOW);

}

void blink_test(unsigned int dl){
  blink(green1, dl);
  blink(blue1, dl);
  blink(red1, dl);
  blink(green2, dl);
  blink(blue2, dl);
  blink(red2, dl);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long delay_ms = 1000;
  blink_test(delay_ms);
  
}
