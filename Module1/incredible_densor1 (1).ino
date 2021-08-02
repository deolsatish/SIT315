// C++ code
//
int val=0;
const uint8_t LED_PIN1 = 8;
const uint8_t Senosr_Pin1 = 2;
const uint8_t LED_PIN2 = 9;
const uint8_t Senosr_Pin2 = 3;


void setup()
{
  pinMode(LED_PIN1, OUTPUT);
  pinMode(Senosr_Pin1,INPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(Senosr_Pin2,INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(Senosr_Pin1), button_ISR1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Senosr_Pin2), button_ISR2, CHANGE);
}

void loop()
{
  
  delay(500);
  
  
}
void button_ISR1()
{
  val=digitalRead(Senosr_Pin1);
  Serial.println("Interrupt 1 Working");
  Serial.println("Motion Detected in Sensor 1");
  if(val==HIGH)
  {
    digitalWrite(LED_PIN1, HIGH);  	
  }
  else
  {
    digitalWrite(LED_PIN1, LOW);
  }
  delay(10);
}
void button_ISR2()
{
  val=digitalRead(Senosr_Pin2);
  Serial.println("Interrupt 2 Working");
  Serial.println("Motion Detected in Sensor 2");
  if(val==HIGH)
  {
    digitalWrite(LED_PIN2, HIGH);  	
  }
  else
  {
    digitalWrite(LED_PIN2, LOW);
  }
  delay(10);
}