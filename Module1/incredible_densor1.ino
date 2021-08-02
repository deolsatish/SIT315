// C++ code
//
int val=0;
const uint8_t LED_PIN = 13;
const uint8_t Senosr_Pin = 2;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(Senosr_Pin,INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(Senosr_Pin), button_ISR, CHANGE);
}

void loop()
{
  val=digitalRead(Senosr_Pin);
  Serial.print("Motion Sensor Output: ");
  Serial.println(String(val));
  delay(500);
  
  
}
void button_ISR()
{
  val=digitalRead(Senosr_Pin);
  Serial.println("Interrupt Working");
  if(val==HIGH)
  {
    digitalWrite(13, HIGH);  	
  }
  else
  {
    digitalWrite(13, LOW);
  }
  delay(10);
}