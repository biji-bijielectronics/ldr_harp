
int led_pin = 13;
int sound_pin = 3;
int initial_read = 0;

int threshold = 50;

int state = 0; 

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(led_pin, OUTPUT); // Set LED Pin as output
  pinMode(sound_pin, OUTPUT); // Set Sound Pin as output

  //Create an average reading
  int num_readings = 10;
  long total = 0;
  for(int i  = 0; i < num_readings; i++){
    total = total + analogRead(A0);
     
    delay(100); // Wait 100ms between readings
  }
  initial_read = total / num_readings;
  Serial.print("Initial Reading: ");
  Serial.println(initial_read);
  delay(500);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  //Serial.println(sensorValue);
  if(sensorValue < initial_read - threshold){
    digitalWrite(led_pin, HIGH);
    if(state == 0){
      state =1;
      digitalWrite(sound_pin, LOW);
    
      Serial.println("ON");
      
    }
  }else{
    digitalWrite(led_pin, LOW);
    if(state == 1){
      state = 0;
      Serial.println("OFF");
      digitalWrite(sound_pin, HIGH);
    
    }
  }
  delay(10);        // delay in between reads for stability
  
}
