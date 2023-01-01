long val = 0;
long old_val = 0;
bool volume_state = true;

int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int buttonPin = PB12;
 
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}
 
void loop() {
  val = analogRead(PA1);
  if (abs(old_val - val) > 40)
  {
    old_val = val;
    volume_state = true;
    Serial.println(val); 
  }

  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        volume_state = !volume_state;
        if (volume_state)
        {
          Serial.println(old_val); 
        }
        else
        {
          Serial.println(0);
        }
      }
    }
  }

  lastButtonState = reading;
  delay(10);
}
