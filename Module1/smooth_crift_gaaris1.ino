// C++ code
//
volatile byte r,g,b=0;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(43, INPUT);
  
  Serial.begin(9600);
  
  PCICR |= 0b00000111;
  PCMSK2 |= 0b000011100;
  
  
  noInterrupts();
  //Clear Sequence
  TCCR1A=0;
  TCCR1B=0;
  TCNT1=0;
  // We want the led 9 to blink every 4 seconds
  // 0.25Hz =(16000000/((62499+1)*1024))
  //Thus we need to set timer as 64299
  
  //setting timer compare
  OCR1A=64299;
  
  //Prescaler 1024
  TCCR1B |= (1 << CS12) | (1 <<CS10);
  
  TIMSK1 |= (1<<OCIE1A);
  
  TCCR1B |= (1<<WGM12);
  interrupts();	
  
  
  
  
}

void loop()
{
  digitalWrite(12, r);
  digitalWrite(10, g);
  digitalWrite(11, b);
}

ISR(PCINT2_vect){
  Serial.println("Motion Sensor Interrupt trigerred");
  g= PIND & B00010000;
  r= PIND & B00000100;
  b= PIND & B00001000;
}

ISR(TIMER1_COMPA_vect){
  Serial.println("Timer event triggered");
  digitalWrite(9,digitalRead(9)^1);
}
