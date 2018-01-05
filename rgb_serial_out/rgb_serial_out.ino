struct rgb_led{
  boolean active_on_high; // LED active on high or low?
  int rp, gp, bp;         // Pin numbers for red, green and blue LEDs.
  boolean rs, gs, bs;     // Status of red, green and blue LEDs.
}l1, l2;

// status variables
l1 = {false, 5, 6, 7, false, false, false};
l2 = {false, 8, 9, 10, false, false, false};

static inline boolean xnor(boolean a, boolean b)
{
  return (a && b) || (!a && !b);
}

static void update_led(int pin_no, boolean pin_status, boolean active_on_high)
{
  if(xnor(pin_status, active_on_high))
    digitalWrite(pin_no, active_on_high ? HIGH : LOW);
  else
    digitalWrite(pin_no, active_on_high ? LOW : HIGH);
}

// update a output pins of a rgb_led 
static void update_rgb_led(struct rgb_led * l)
{
  update_led(l->rp, l->rs, l->active_on_high);
  update_led(l->gp, l->gs, l->active_on_high);
  update_led(l->bp, l->bs, l->active_on_high);
}

static void set_rgb_output(int o)
{
  // Convert the input byte into the form to be represented.
  // Set the rgb LED variables to their required values
  // Call update_rgb_led for both variables.
}
void loop(){
  // Serial communication
  Serial.begin(9600);
  
  // setup rgb LED pins
  pinMode(l1->rp, OUTPUT);
  pinMode(l1->gp, OUTPUT);
  pinMode(l1->bp, OUTPUT);
  pinMode(l2->rp, OUTPUT);
  pinMode(l2->gp, OUTPUT);
  pinMode(l2->bp, OUTPUT);
  update_rgb_led(&l1);
  update_rgb_led(&l2);
}

void setup()
{
  int in_byte = 0;
  // Logic to control LED's with serial communication.
  if(Serial.available() > 0){
    in_byte = Serial.read();
    if(isAlphaNumeric(in_byte))
      set_rgb_output(in_byte);
  }
}