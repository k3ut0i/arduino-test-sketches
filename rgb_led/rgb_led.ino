int red_pin2 = 2;
int green_pin2 = 3;
int blue_pin2 = 4;

boolean red2 = false;
boolean green2 = false;
boolean blue2 = false;

int red_pin1 = 8;
int green_pin1 = 9;
int blue_pin1 = 10;

boolean red1 = false;
boolean green1 = false;
boolean blue1 = false;


unsigned int red_brightness = 0;
unsigned int green_brightness = 0;
unsigned int blue_brightness = 0;

unsigned long change_period = 1000; //millisecs

void update_led(){
    digitalWrite(red_pin1, red1 ?LOW:HIGH);
    digitalWrite(green_pin1, green1 ?LOW:HIGH);
    digitalWrite(blue_pin1, blue1 ?LOW:HIGH);

    digitalWrite(red_pin2, red2?LOW:HIGH);
    digitalWrite(green_pin2, green2?LOW:HIGH);
    digitalWrite(blue_pin2, blue2?LOW:HIGH);
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(red_pin1, OUTPUT);
  pinMode(green_pin1, OUTPUT);
  pinMode(blue_pin1, OUTPUT);

  pinMode(red_pin2, OUTPUT);
  pinMode(green_pin2, OUTPUT);
  pinMode(blue_pin2, OUTPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  digitalWrite(LED_BUILTIN, LOW);
  update_led();
}

void loop() {

  //Fade from one color to the next.
  for(int i = 0; i < 8; i++){
    red1 = (i & 1<<0) == 0 ? true : false;
    green1 = (i & 1<<1) == 0 ? true : false;
    blue1 = (i & 1<<2) == 0 ? true :false;
    delay(change_period);
    update_led();
    }
}
