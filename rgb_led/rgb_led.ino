struct led{
  int pinno;
  boolean active;
  boolean active_on_high;
}red1, green1, blue1, red2, green2, blue2;

static struct led
leds[] = {
    {5, false, false}, //red1
	  {6, false, false}, //green1
	  {7, false, false}, //blue1,
	  {8, false, false}, //red2,
	  {9, false, false}, //green2,
	  {10, false, false}, //blue2
};

static const unsigned long change_period = 1000; //millisecs

static void update_led(struct led * l){
  boolean led_on = (l->active && l->active_on_high) ||
    !(l->active || l->active_on_high);
  if(led_on)
    digitalWrite(l->pinno, l->active_on_high ? HIGH : LOW);
  else
    digitalWrite(l->pinno, l->active_on_high ? LOW : HIGH);
}

static void update_leds(){
  for(unsigned int i = 0; i < sizeof(leds)/sizeof(leds[0]); i++)
    update_led(&leds[i]);
}

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED_BUILTIN, OUTPUT);  
  digitalWrite(LED_BUILTIN, LOW);
  for(unsigned int i = 0; i < sizeof(leds)/sizeof(leds[0]); i++)
    pinMode(leds[i].pinno, OUTPUT);
  update_leds();
}

void loop() {
  //Fade from one color to the next.
  const unsigned int num_leds = sizeof(leds)/sizeof(leds[0]);
  const unsigned int num_states = 2 << (num_leds - 1);
  for(unsigned int i = 0; i < num_states; i++){
    for(unsigned int j = 0; j < num_leds; j++)
      leds[j].active = ((1 << j) & i) == 0;
    delay(change_period);
    update_leds();
    }
}
