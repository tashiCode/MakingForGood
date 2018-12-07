int _ABVAR_1_Btn1_State = 0 ;
int _ABVAR_2_Btn2_State = 0 ;
int _ABVAR_3_Btn3_State = 0 ;
int _ABVAR_4_Num_Colors = 0 ;
int _ABVAR_5_randChoice1 = 0 ;
int _ABVAR_6_randChoice2 = 0 ;
int _ABVAR_7_randChoice3 = 0 ;
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


void blue1();
void button3Press();
void green3();
void button2Press();
void purple3();
void purple2();
void yellow1();
void yellow2();
void blue3();
void purple1();
void yellow3();
void blue2();
void red2();
void red1();
void green2();
void gameSetup();
void red3();
void green1();
void matchRGB3();
void matchRGB2();
void button1Press();
void matchRGB1();
void matchSequence();

void setup()
{
  Serial.begin(9600);
  _ABVAR_1_Btn1_State = 0 ;

  _ABVAR_2_Btn2_State = 0 ;

  _ABVAR_3_Btn3_State = 0 ;

  _ABVAR_4_Num_Colors = 6 ;

  gameSetup();

  Serial.print("randChoice1");
  Serial.print(" ");
  Serial.print(_ABVAR_5_randChoice1);
  Serial.print(" ");
  Serial.println();

  Serial.print("randChoice2");
  Serial.print(" ");
  Serial.print(_ABVAR_6_randChoice2);
  Serial.print(" ");
  Serial.println();

  Serial.print("randChoice3");
  Serial.print(" ");
  Serial.print(_ABVAR_7_randChoice3);
  Serial.print(" ");
  Serial.println();

}

void loop()
{
  Serial.print("btn_state1");
  Serial.print(" ");
  Serial.print(_ABVAR_1_Btn1_State);
  Serial.print(" ");
  Serial.println();
  Serial.print("btn_state2");
  Serial.print(" ");
  Serial.print(_ABVAR_2_Btn2_State);
  Serial.print(" ");
  Serial.println();
  Serial.print("btn_state3");
  Serial.print(" ");
  Serial.print(_ABVAR_3_Btn3_State);
  Serial.print(" ");
  Serial.println();
  button1Press();
  button2Press();
  button3Press();
  matchSequence();
}

void button1Press()
{
  if (( ( __ardublockDigitalReadPullup(5) ) == ( false ) ))
  {
    _ABVAR_1_Btn1_State = ( ( _ABVAR_1_Btn1_State + 1 ) % _ABVAR_4_Num_Colors ) ;
  }
  if (( ( _ABVAR_1_Btn1_State ) == ( 1 ) ))
  {
    red1();
  }
  if (( ( _ABVAR_1_Btn1_State ) == ( 2 ) ))
  {
    green1();
  }
  if (( ( _ABVAR_1_Btn1_State ) == ( 3 ) ))
  {
    blue1();
  }
  if (( ( _ABVAR_1_Btn1_State ) == ( 4 ) ))
  {
    yellow1();
  }
  if (( ( _ABVAR_1_Btn1_State ) == ( 5 ) ))
  {
    purple1();
  }
}

void red2()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 255);
  analogWrite(A5 , 255);
  delay( 300 );
}

void matchRGB2()
{
  if (( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_5_randChoice1 ) ))
  {
    __ardublockDigitalWrite(11, HIGH);
    break;
  }
  else
  {
    if (( ( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_6_randChoice2 ) ) || ( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_7_randChoice3 ) ) ))
    {
      __ardublockDigitalWrite(11, HIGH);
      delay( 100 );
      __ardublockDigitalWrite(11, LOW);
      delay( 100 );
      break;
    }
    else
    {
      __ardublockDigitalWrite(11, LOW);
    }
  }
}

void gameSetup()
{
  _ABVAR_5_randChoice1 = 	random( 1 , 5 ) ;
  _ABVAR_6_randChoice2 = 	random( 1 , 5 ) ;
  _ABVAR_7_randChoice3 = 	random( 1 , 5 ) ;
}

void green2()
{
  analogWrite(A3 , 255);
  analogWrite(A2 , 0);
  analogWrite(A5 , 255);
  delay( 300 );
}

void yellow1()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 0);
  analogWrite(A5 , 255);
  delay( 300 );
}

void button3Press()
{
  if (( ( __ardublockDigitalReadPullup(9) ) == ( false ) ))
  {
    _ABVAR_3_Btn3_State = ( ( _ABVAR_3_Btn3_State + 1 ) % _ABVAR_4_Num_Colors ) ;
  }
  if (( ( _ABVAR_3_Btn3_State ) == ( 1 ) ))
  {
    red3();
  }
  if (( ( _ABVAR_3_Btn3_State ) == ( 2 ) ))
  {
    green3();
  }
  if (( ( _ABVAR_3_Btn3_State ) == ( 3 ) ))
  {
    blue3();
  }
  if (( ( _ABVAR_3_Btn3_State ) == ( 4 ) ))
  {
    yellow3();
  }
  if (( ( _ABVAR_3_Btn3_State ) == ( 5 ) ))
  {
    purple3();
  }
}

void green1()
{
  analogWrite(A3 , 255);
  analogWrite(A2 , 0);
  analogWrite(A5 , 255);
  delay( 300 );
}

void yellow2()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 0);
  analogWrite(A5 , 255);
  delay( 300 );
}

void blue1()
{
  analogWrite(A3 , 255);
  analogWrite(A2 , 255);
  analogWrite(A5 , 0);
  delay( 300 );
}

void green3()
{
  analogWrite(A3 , 255);
  analogWrite(A2 , 0);
  analogWrite(A5 , 255);
  delay( 300 );
}

void red3()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 255);
  analogWrite(A5 , 255);
  delay( 300 );
}

void purple3()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 255);
  analogWrite(A5 , 0);
  delay( 300 );
}

void purple2()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 255);
  analogWrite(A5 , 0);
  delay( 300 );
}

void matchRGB3()
{
  if (( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_5_randChoice1 ) ))
  {
    __ardublockDigitalWrite(11, HIGH);
    break;
  }
  else
  {
    if (( ( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_6_randChoice2 ) ) || ( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_7_randChoice3 ) ) ))
    {
      __ardublockDigitalWrite(11, HIGH);
      delay( 100 );
      __ardublockDigitalWrite(11, LOW);
      delay( 100 );
      break;
    }
    else
    {
      __ardublockDigitalWrite(11, LOW);
    }
  }
}

void blue2()
{
  analogWrite(A3 , 255);
  analogWrite(A2 , 255);
  analogWrite(A5 , 0);
  delay( 300 );
}

void matchSequence()
{
  if (( ( ( _ABVAR_1_Btn1_State ) != ( 0 ) ) && ( ( ( _ABVAR_2_Btn2_State ) != ( 0 ) ) && ( ( _ABVAR_3_Btn3_State ) != ( 0 ) ) ) ))
  {
    matchRGB1();
    matchRGB2();
    matchRGB3();
  }
}

void purple1()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 255);
  analogWrite(A5 , 0);
  delay( 300 );
}

void yellow3()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 0);
  analogWrite(A5 , 255);
  delay( 300 );
}

void red1()
{
  analogWrite(A3 , 0);
  analogWrite(A2 , 255);
  analogWrite(A5 , 255);
  delay( 300 );
}

void matchRGB1()
{
  if (( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_5_randChoice1 ) ))
  {
    __ardublockDigitalWrite(11, HIGH);
    break;
  }
  else
  {
    if (( ( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_6_randChoice2 ) ) || ( ( _ABVAR_1_Btn1_State ) == ( _ABVAR_7_randChoice3 ) ) ))
    {
      __ardublockDigitalWrite(11, HIGH);
      delay( 100 );
      __ardublockDigitalWrite(11, LOW);
      delay( 100 );
      break;
    }
    else
    {
      __ardublockDigitalWrite(11, LOW);
    }
  }
}

void button2Press()
{
  if (( ( __ardublockDigitalReadPullup(6) ) == ( false ) ))
  {
    _ABVAR_2_Btn2_State = ( ( _ABVAR_2_Btn2_State + 1 ) % _ABVAR_4_Num_Colors ) ;
  }
  if (( ( _ABVAR_2_Btn2_State ) == ( 1 ) ))
  {
    red2();
  }
  if (( ( _ABVAR_2_Btn2_State ) == ( 2 ) ))
  {
    green2();
  }
  if (( ( _ABVAR_2_Btn2_State ) == ( 3 ) ))
  {
    blue2();
  }
  if (( ( _ABVAR_2_Btn2_State ) == ( 4 ) ))
  {
    yellow2();
  }
  if (( ( _ABVAR_2_Btn2_State ) == ( 5 ) ))
  {
    purple2();
  }
}

void blue3()
{
  analogWrite(A3 , 255);
  analogWrite(A2 , 255);
  analogWrite(A5 , 0);
  delay( 300 );
}
