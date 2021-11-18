/*
 Name:		Project3_Version3_Processor1.ino
 Created:	09.07.2021 23:13:52
 Author:	konev
*/


#include <GyverTimers.h>
#include <GyverButton.h>
#include <AnalogKey.h>

// ������ 18 - ������� � ����� ������
#define PIN_DATA1 6 // � ������ 14 ���������� 74HC595
#define PIN_LATCH1 8 // � ������ 12 ���������� 74HC595
#define PIN_CLOCK1 10 // � ������ 11 ���������� 74HC595

#define PIN_DATA2 3 // � ������ 14 ���������� 74HC595
#define PIN_LATCH2 4 // � ������ 12 ���������� 74HC595
#define PIN_CLOCK2 2 // � ������ 11 ���������� 74HC595

#define PIN_CLOCK3 5 // � ������ 11 ���������� 74HC595
#define PIN_DATA3 6 // � ������ 14 ���������� 74HC595
#define PIN_LATCH3 7 // � ������ 12 ���������� 74HC595

// ����������� ������ � ������������ ���������
// ��� ���� 0 - 9 � ���� A - F (�� ����. 6.2)
byte digits[] = { 252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142 };
byte index_of_segment1 = 0;
byte index_of_segment2 = 0;
byte index_of_segment3 = 0;

GButton Button1(17);
GButton Button2(18);
GButton Button3(19);


void setup()
{
	Serial.begin(9600);
	Serial.println(" ");     // 
	Serial.println("Author DANIIL KONEV");     // 
	Serial.println("Blog ARDUINO-DESIGNER.RU");     // 

	Button1.setTickMode(AUTO); // Button1.tick();  // ������������ ������� ���������, ��� ������ ��������� ������������
	Button2.setTickMode(AUTO); // Button2.tick();  // ������������ ������� ���������. ������ ��������� ������������
	Button3.setTickMode(AUTO); // Button3.tick();  // ������������ ������� ���������. ������ ��������� ������������
	
	pinMode(PIN_LATCH1, OUTPUT);
	pinMode(PIN_CLOCK1, OUTPUT);
	pinMode(PIN_DATA1, OUTPUT);

	pinMode(PIN_LATCH2, OUTPUT);
	pinMode(PIN_CLOCK2, OUTPUT);
	pinMode(PIN_DATA2, OUTPUT);

	pinMode(PIN_LATCH3, OUTPUT);
	pinMode(PIN_CLOCK3, OUTPUT);
	pinMode(PIN_DATA3, OUTPUT);
}

void loop()
{
		digitalWrite(PIN_LATCH1, LOW);
		shiftOut(PIN_DATA1, PIN_CLOCK1, LSBFIRST, digits[index_of_segment1] + 1); // +1, ����� �������� �����
		digitalWrite(PIN_LATCH1, HIGH);

		digitalWrite(PIN_LATCH2, LOW);
		shiftOut(PIN_DATA2, PIN_CLOCK2, LSBFIRST, digits[index_of_segment2]); // ������� ������� 0-9, A-F ��� ����� 
		digitalWrite(PIN_LATCH2, HIGH);

		digitalWrite(PIN_LATCH3, LOW);
		shiftOut(PIN_DATA3, PIN_CLOCK3, LSBFIRST, digits[index_of_segment3]); // ������� ������� 0-9, A-F ��� ����� 
		digitalWrite(PIN_LATCH3, HIGH);
		//delay(1000);

		if (Button1.isSingle())
		{
			index_of_segment1++;
			if (index_of_segment1 > 9) index_of_segment1 = 0;	// ����� ����� ����� �� ������ ��������� ����� 9, � �� ��� �� ������ ������������ �� ������������ ����������
		}

		if (Button2.isSingle())
		{
			index_of_segment2++;
			if (index_of_segment2 > 9) index_of_segment2 = 0;	// ����� ����� ����� �� ������ ��������� ����� 9, � �� ��� �� ������ ������������ �� ������������ ����������
		}

		if (Button3.isSingle())
		{
			index_of_segment3++;
			if (index_of_segment3 > 9) index_of_segment3 = 0;	// ����� ����� ����� �� ������ ��������� ����� 9, � �� ��� �� ������ ������������ �� ������������ ����������
		}
}
