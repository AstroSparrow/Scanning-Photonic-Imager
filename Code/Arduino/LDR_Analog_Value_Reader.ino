const int LDR = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR, INPUT);
}

void loop() {
  long AVGSum = 0;

  for (int i = 0; i < 20; i++) {
    AVGSum += analogRead(LDR);
    delay(40);
  };

  int AVG = AVGSum / 20; 

  Serial.print("LDR Value: ");
  Serial.println(AVG); 
  
  delay(600); 
}
