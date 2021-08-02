// C++ code
//
int val=0;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop()
{
  val=digitalRead(2);
  Serial.print("Motion Sensor Output: ");
  Serial.println(String(val));
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