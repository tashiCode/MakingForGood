int _ABVAR_1_SensorOutput = 0 ;
int __ardublockAnalogRead(int pinNumber)
{
  pinMode(pinNumber, INPUT);
  return analogRead(pinNumber);
}


boolean __ardublockDigitalReadPullup(int pinNumber)
{
  pinMode(pinNumber, INPUT_PULLUP);
  return digitalRead(pinNumber);
}


void __ardublockDigitalWrite(int pinNumber, boolean status)
{
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, status);
}


void Theremin();
void TouchAndHold();
void LightSensitive();

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  _ABVAR_1_SensorOutput = __ardublockAnalogRead(11) ;
  LightSensitive();
  TouchAndHold();
}

void LightSensitive()
{
  Serial.print("Light Output");
  Serial.print(" ");
  Serial.print(__ardublockDigitalReadPullup(11));
  Serial.print(" ");
  Serial.println();
  if (( ( _ABVAR_1_SensorOutput ) < ( 70 ) ))
  {
    __ardublockDigitalWrite(6, HIGH);
  }
  else
  {
    __ardublockDigitalWrite(6, LOW);
  }
}

void TouchAndHold()
{
  Serial.print("ButtonState");
  Serial.print(" ");
  Serial.print(__ardublockDigitalReadPullup(19));
  Serial.print(" ");
  Serial.println();
  if (( ( __ardublockAnalogRead(19) ) == ( 1 ) ))
  {
    __ardublockDigitalWrite(9, HIGH);
  }
  else
  {
    __ardublockDigitalWrite(9, LOW);
  }
}

void Theremin()
{
  Serial.print("Light Output");
  Serial.print(" ");
  Serial.print(__ardublockDigitalReadPullup(11));
  Serial.print(" ");
  Serial.println();
}
