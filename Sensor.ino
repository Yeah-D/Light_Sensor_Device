int echoPin = 12;
int trigPin = 13;
int led1=3, led2=4, led3=5, speakerpin=8;

void setup() {
  Serial.begin(9600);     
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = ((float)(340*duration)/10000)/2;
  Serial.print(distance);
  Serial.println("cm"); 
  
  if(distance<10){
  digitalWrite(led3,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
  tone(speakerpin,500,1000);
  }
  else if(distance>=10 && distance<30){
  digitalWrite(led3,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led1,LOW);
  }
  else{
  digitalWrite(led3,LOW);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  }
  
  delay(1000);
}
