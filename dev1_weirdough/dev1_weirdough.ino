// Pairing Example _device 2
const int buttonPin1 = D2;    // the number of the pushbutton pin
// const int buttonPin2 = D3;    // the number of the pushbutton pin
const int ledPin = D3;      // the number of the LED pin


void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  Particle.subscribe("touch001", myHandler);
//   pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, LOW);
  
}

void loop() {

  int reading1 = digitalRead(buttonPin1);
//   int reading2 = digitalRead(buttonPin2);
    
  
  if(reading1 == LOW){
      Particle.publish("touch002","red",60,PUBLIC);
      delay(2000);
  }
  
//   if(reading2 == LOW){
//       digitalWrite(ledPin,HIGH);
//       Particle.publish("touch002","enter",60,PUBLIC);
//       delay(2000);
//       digitalWrite(ledPin,LOW);
//   }
  
}

void myHandler(const char *event, const char *data)
{
  /* Particle.subscribe handlers are void functions, which means they don't return anything.
  They take two variables-- the name of your event, and any data that goes along with your event.
  In this case, the event will be "buddy_unique_event_name" and the data will be "intact" or "broken"

  Since the input here is a char, we can't do
     data=="intact"
    or
     data=="broken"

  chars just don't play that way. Instead we're going to strcmp(), which compares two chars.
  If they are the same, strcmp will return 0.
  */

  if (strcmp(data,"green")==0) {
    digitalWrite(ledPin,HIGH);
  }
    
//   if (strcmp(data,"notpushed")==0) {
//     noTone(buzzer); 
//   }
}
