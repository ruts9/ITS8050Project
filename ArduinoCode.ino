#define encoder1 2
#define encoder2 9
#define relay1 10
#define relay2 7
#define raspi15 6
#define raspi22 8

int pos = 0;
int currentState = 9;
int lastState = 9;
int slowOutput = 1000;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(encoder2, INPUT);
  pinMode(raspi22, INPUT);
  pinMode(raspi15, INPUT);
  pinMode(encoder1, INPUT);
  Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(encoder1), encoder, RISING);
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(raspi22) == LOW && digitalRead(raspi15) == HIGH ){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
  if(slowOutput >= 1000){
    pos--;
    }
  }
  if(digitalRead(raspi22) == HIGH && digitalRead(raspi15) == LOW ){
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    if(slowOutput >= 1000){
    pos++;
    }
  }
  if(digitalRead(raspi22) == LOW && digitalRead(raspi15) == LOW){
    //
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
  }
  if(slowOutput >= 1000){
    Serial.println(pos);
    slowOutput = 0;
  }
  slowOutput ++;
}
void encoder(){
  currentState = digitalRead(encoder2);
  if (currentState == lastState){
    pos--;
  }
  else{
    pos++;
  }
  lastState = currentState;
}
