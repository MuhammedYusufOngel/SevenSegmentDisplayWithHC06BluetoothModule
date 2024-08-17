char Incoming_value = 0;

//These letters are explained on the home page.
const int segmentG = 8;
const int segmentF = 7;
const int segmentE = 6;
const int segmentD = 5;
const int segmentC = 4;
const int segmentB = 3;
const int segmentA = 2;
const int segmentPoint = 9;

//This function provides that we don't need write these codes again to show number
void writeNumber(uint8_t g, uint8_t f, uint8_t e, uint8_t d, uint8_t c, uint8_t b, uint8_t a)
{
	digitalWrite(segmentG,g);
	digitalWrite(segmentF,f);
	digitalWrite(segmentE,e);
	digitalWrite(segmentD,d);
	digitalWrite(segmentC,c);
	digitalWrite(segmentB,b);
	digitalWrite(segmentA,a);
	digitalWrite(segmentPoint, HIGH);
}

//We give number parameter and this function display that number.
void displayNumber(int number)
{
  if(number == -1)
  {
    writeNumber(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);

  }

  if(number == 0)
  {
    writeNumber(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
  }

  if(number == 1)
  {
    writeNumber(HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH);
  }

  else if(number == 2)
  {
    writeNumber(LOW, HIGH, LOW, LOW, HIGH, LOW, LOW);
  }

  else if(number == 3)
  {
    writeNumber(LOW, HIGH, HIGH, LOW, LOW, LOW, LOW);
  }

  if(number == 4)
  {
    writeNumber(LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH);
  }

  if(number == 5)
  {
    writeNumber(LOW, LOW, HIGH, LOW, LOW, HIGH, LOW);
  }

  else if(number == 6)
  {
    writeNumber(LOW, LOW, LOW, LOW, LOW, HIGH, LOW);
  }

  else if(number == 7)
  {
    writeNumber(HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW);
  }

  else if(number == 8)
  {
    writeNumber(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
  }

  else if(number == 9)
  {
    writeNumber(LOW, LOW, HIGH, LOW, LOW, LOW, LOW);
  }
}

void setup() {
  // put your setup code  here, to run once:
  Serial.begin(9600);
	pinMode(segmentG, OUTPUT);
	pinMode(segmentF, OUTPUT);
	pinMode(segmentE, OUTPUT);
	pinMode(segmentD, OUTPUT);
	pinMode(segmentPoint, OUTPUT);
	pinMode(segmentC, OUTPUT);
	pinMode(segmentB, OUTPUT);
	pinMode(segmentA, OUTPUT);
}

void  loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
    {
      Incoming_value = Serial.read();
      Serial.print(Incoming_value);
      Serial.print("/n");
      if (Incoming_value == '1')
        displayNumber(1);
      else if(Incoming_value == '0')
        displayNumber(0);
      else if(Incoming_value == '2')
        displayNumber(2);
      else if(Incoming_value == '3')
        displayNumber(3);
      else if(Incoming_value == '4')
        displayNumber(4);
      else if(Incoming_value == '5')
        displayNumber(5);
      else if(Incoming_value == '6')
        displayNumber(6);
      else if(Incoming_value == '7')
        displayNumber(7);
      else if(Incoming_value == '8')
        displayNumber(8);
      else if(Incoming_value == '9')
        displayNumber(9);
      else if(Incoming_value == '-1')
        displayNumber(-1);
    }
}