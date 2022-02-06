
// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#include<ctime>
#define DHTPIN 4     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11    // DHT 11 

DHT dht(DHTPIN, DHTTYPE);
// ------------
// Tanya
// ------------
const int buttonPin2 = D2;    // the number of the pushbutton pin
int ledPin = D3;  // pin for our LED signal
// int photoresistor = A5;  // pin for our photoresistor analog input
int analogValue = 0; // a variable so we can store readings from our sensor
int buzzer = A3;  

int lightThreshold = 105; // a threshold value so we know when the lights are on or off.

int ledPin_pulse = D7;
int sensorPin_pulse = A0;
double alpha = 0.75;
int period = 20;
double change = 0.0;    

void setup() {
    //Serial.begin(9600); 
  Serial.println("DHTxx test!");
  dht.begin();
    pinMode(buttonPin2, INPUT_PULLUP);
    Particle.subscribe("touch002", myHandler);
    pinMode(ledPin, OUTPUT);  // our LED is our output, therefore we need to configure the pin to output voltage.
    digitalWrite(ledPin, LOW);
    noTone(buzzer);
    
    pinMode(ledPin_pulse, OUTPUT);
    Serial.begin(115200);

//   pinMode(photoresistor, INPUT);  // our sensor is an input, therefore we need to configure the pin to read voltage coming in.
    

}

void loop() {
    
    int reading2 = digitalRead(buttonPin2);
//   int reading2 = digitalRead(buttonPin2);
    
  
  
  // Wait a few seconds between measurements.
  

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a 
// very slow sensor)
  float h = dht.getHumidity();
// Read temperature as Celsius
  float t = dht.getTempCelcius();
// Read temperature as Farenheit
  float f = dht.getTempFarenheit();
    //Particle.publish("temperature", String(f));
// Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

// Compute heat index
// Must send in temp in Fahrenheit!
  float hi = dht.getHeatIndex();
  float dp = dht.getDewPoint();
  float k = dht.getTempKelvin();

  Serial.print("Humid: "); 
  Serial.print(h);
  Serial.print("% - ");
  Serial.print("Temp: "); 
  Serial.print(t);
  Serial.print("*C ");
  Serial.print(f);
  Serial.print("*F ");
  Serial.print(k);
  Serial.print("*K - ");
  Serial.print("DewP: ");
  Serial.print(dp);
  Serial.print("*C - ");
  Serial.print("HeatI: ");
  Serial.print(hi);
  Serial.println("*C");
  //Serial.println(Time.timeStr().c_str()-5);
  
  if(reading2 == LOW){
      Particle.publish("touch001","green",PRIVATE);
      delay(2000);
  }
//   delay(6000);
    static double oldValue = 0;
    static double oldChange = 0;
    int rawValue = analogRead(sensorPin_pulse);
    double value = alpha * oldValue + (1 - alpha) * rawValue;
    Serial.print(rawValue);
    Serial.print(",");
    Serial.println(value);
    oldValue = value;
    delay(period);
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

  if (strcmp(data,"red")==0) {
    tone(buzzer, 200, 4000);
    digitalWrite(ledPin,HIGH);
    delay(300);
    digitalWrite(ledPin,LOW);
    delay(300);
    digitalWrite(ledPin,HIGH);
    delay(300);
    digitalWrite(ledPin,LOW);
    delay(300);
    digitalWrite(ledPin,HIGH);
    delay(300);
    digitalWrite(ledPin,LOW);
    delay(300);
    digitalWrite(ledPin,HIGH);
    delay(300);
    digitalWrite(ledPin,LOW);
    delay(300);
    digitalWrite(ledPin,HIGH);
    delay(300);
    digitalWrite(ledPin,LOW);
    delay(300);
    digitalWrite(ledPin,HIGH);
    delay(300);
    digitalWrite(ledPin,LOW);
    delay(300);
    digitalWrite(ledPin,HIGH);
    delay(300);
    digitalWrite(ledPin,LOW);
    delay(300);
    digitalWrite(ledPin,HIGH);
    delay(300);
    digitalWrite(ledPin,LOW);
    
  }
    
//   if (strcmp(data,"notpushed")==0) {
//     noTone(buzzer); 
//   }
}
