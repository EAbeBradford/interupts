#define LED_PIN 8
#define BUTTON_PIN 2

int LEDState = LOW;
volatile bool buttonReleases = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  //whereever we are in the program, when the button is released the 
  //buttonReleasedInterupt function is called
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), 
                  buttonReleasedInterupt,
                  FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(buttonReleases){
    buttonReleases = false;
    toggleLED();
  }

}

//what happend when falling from high to low interupt
//AKA falling
//interrupt functions must have void and no params
void buttonReleasedInterupt(){
  buttonReleases = true;
}

void toggleLED(){
  if(LEDState==LOW){
    LEDState = HIGH;
  }
  else{
    LEDState = LOW;
  }
  digitalWrite(LED_PIN, LEDState);
}