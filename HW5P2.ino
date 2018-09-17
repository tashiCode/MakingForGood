int _ABVAR_1_a;
void __ardublockDigitalWrite(int pinNumber, boolean status)
{
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, status);
}


void led_blink();
void led_seq();
void tone_deaf();

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  tone_deaf();
  noTone(5);
  led_seq();
  for (_ABVAR_1_a=1; _ABVAR_1_a<= ( 2 ); ++_ABVAR_1_a )
  {
    led_blink();
  }
}

void led_blink()
{
  __ardublockDigitalWrite(6, HIGH);
  __ardublockDigitalWrite(9, HIGH);
  __ardublockDigitalWrite(10, HIGH);
  __ardublockDigitalWrite(11, HIGH);
  delay( 2000 );
  __ardublockDigitalWrite(6, LOW);
  __ardublockDigitalWrite(9, LOW);
  __ardublockDigitalWrite(10, LOW);
  __ardublockDigitalWrite(11, LOW);
  delay( 2000 );
}

void led_seq()
{
  Serial.print("LED turns on for pin");
  Serial.print(" ");
  Serial.print(6);
  Serial.print(" ");
  Serial.println();
  __ardublockDigitalWrite(6, HIGH);
  delay( 2000 );
  __ardublockDigitalWrite(6, LOW);
  Serial.print("LED turns on for pin");
  Serial.print(" ");
  Serial.print(9);
  Serial.print(" ");
  Serial.println();
  __ardublockDigitalWrite(9, HIGH);
  delay( 2000 );
  __ardublockDigitalWrite(9, LOW);
  Serial.print("LED turns on for pin");
  Serial.print(" ");
  Serial.print(10);
  Serial.print(" ");
  Serial.println();
  __ardublockDigitalWrite(10, HIGH);
  delay( 2000 );
  __ardublockDigitalWrite(10, LOW);
  Serial.print("LED turns on for pin");
  Serial.print(" ");
  Serial.print(11);
  Serial.print(" ");
  Serial.println();
  __ardublockDigitalWrite(11, HIGH);
  delay( 2000 );
  __ardublockDigitalWrite(11, LOW);
}

void tone_deaf()
{
  tone(5, 300, 1000);
  tone(5, 550, 1000);
  tone(5, 400, 1000);
  delay( 500 );
  tone(5, 250, 1000);
  tone(8, 440, 1000);
}
