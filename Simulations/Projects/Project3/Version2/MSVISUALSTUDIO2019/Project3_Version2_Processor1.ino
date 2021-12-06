/*
 Name:		Project003.ino
 Created:	11.06.2021 2:34:43
 Author:	DANIIL KONEV
 Author:	ARDUINO-DESIGNER.RU
*/

#include <GyverTimers.h>
#include <GyverButton.h>
#include <AnalogKey.h>
#include <Segment.h> //https://github.com/BlaT2512/Segment ����������� �������� �������� ����� �������� ��������� �������. � ���� ���������� ������� ������� ����, �������� � ������� ���
#include <avr/eeprom.h> 

byte i_want_to_see_the_diagnostical_output = false;

// The library can either be declared using pins straight (sega-segg), pins straight with decimal point (sega-segdp) or with a shift register (data, clock, latch) (dp or no dp)
// See README.md for more information on how to declare the library
// Un-comment the one you are using below!

Segment Number1(2, 3, 4, 5, 6, 7, 8, true);      // Uncomment for straight wiring pins (segment a - segment g)
Segment Number2(9, 10, 11, 12, 13, 16, 17, true);      // Uncomment for straight wiring pins (segment a - segment g)
//Segment sevseg(5, 6, 7, 8, 9, 10, 11, 12, true);  // Uncomment for straight wiring pins with a decimal point (segment a - decimal point)
//Segment sevseg(5, 6, 7, -1, 7, true);             // Uncomment for shift register wiring pins (Data, Clock, Latch) (it doesn't matter if it has a decimal point or not)

int time1second = 100;   // Milliseconds to delay after each number (default 1 second)		������� � ����������� ������ ������� �� ����������� ������������ 
int displays = 1;  // Number of seven segment displays you have daisy-chained (default 1)	������ ����� ��� ����� ������� 

GButton Button1(18);
GButton Button2(19);

void setup() {
	//**************************************************************************************************************************************************************
	Serial.begin(9600);
	if (i_want_to_see_the_diagnostical_output == true)
	{
		Serial.println(" ");     // 
		Serial.println("DANIIL KONEV");     // 
		//Serial.println("ARDUINO-DESIGNER.RU");     // 
	}
	//**************************************************************************************************************************************************************
	Make_Demonstration_of_display_on_board();
	Make_First_setup_in_EEPROM();
	Make_Display_number_from_EEPROM();
	//**************************************************************************************************************************************************************
	Button1.setTickMode(AUTO); // Button1.tick();  // ������������ ������� ���������. ������ ��������� ������������
	Button2.setTickMode(AUTO); // Button1.tick();  // ������������ ������� ���������. ������ ��������� ������������
	//**************************************************************************************************************************************************************
	Timer1.setFrequency(1);               // ������������ ������ 1 ��� ������� ����������, ������� - 1 ����
	Timer1.enableISR(CHANNEL_A);          // ��������� ���������� (�� �����. ����� �)
}
void loop() 
{
	if (Button1.isSingle()) 
	{
		byte digit1 = eeprom_read_byte(1);
		byte digit2 = eeprom_read_byte(2);
		byte digit3 = eeprom_read_byte(3);

		++digit1;
		if (digit1 > 9) digit1 = 0;	// ����� ����� ����� �� ������ ��������� ����� 9, � �� ��� �� ������ ������������ �� ������������ ����������
		eeprom_write_byte(1, digit1); 
		Number1.display(ByteToChar(digit1, 2));	// � ���������� ������ ����� ����� 2 
		digit3 = digit1 * 10 + digit2;
		eeprom_write_byte(3, digit3);

		if (i_want_to_see_the_diagnostical_output == true) 
		{
			Serial.print("digit1=");     
			Serial.println(digit1);     
			Serial.print("digit2=");     
			Serial.println(digit2);     
			
			digit3 = digit1 * 10 + digit2;
			Serial.println(digit3); 
			Serial.print("digit3="); 
			Serial.println(digit3);
		}
		
	}  
	if (Button2.isSingle())
	{
		byte digit1 = eeprom_read_byte(1);
		byte digit2 = eeprom_read_byte(2);
		byte digit3 = eeprom_read_byte(3);

		++digit2;
		if (digit2 > 9) digit2 = 0;	// ����� ����� ����� �� ������ ��������� ����� 9, � �� ��� �� ������ ������������ �� ������������ ����������
		eeprom_write_byte(2, digit2);  
		Number2.display(ByteToChar(digit2, 2));	// � ���������� ������ ����� ����� 2 
		digit3 = digit1 * 10 + digit2;
		eeprom_write_byte(3, digit3);

		if (i_want_to_see_the_diagnostical_output == true)
		{
			Serial.print("digit1=");
			Serial.println(digit1);
			Serial.print("digit2=");
			Serial.println(digit2);

			digit3 = digit1 * 10 + digit2;
			Serial.println(digit3);
			Serial.print("digit3=");
			Serial.println(digit3);
		}
	}
}

char ByteToChar(byte byteSt, byte num) {
	// ��� ����� ���� �������� ������� http://arduino.ru/forum/programmirovanie/preobrazovanie-byte-v-char
	// ������ �������� ��� ���������� ����� ������, ������� ���� ������� - ���� ������ ���� ������ , �� ������ ��� ������ � ���� �� �����, � ������ ������ ������ � ��� ���������� ��� ����.
	const byte offset = 48;
	if (num == 1) return char(offset + byteSt / 10); // 48 + 73/10 = 48+7=55
	if (num == 2) return char(offset + byteSt - byteSt / 10 * 10);  // 48+73-(73/10)*10 = 48+73-70=51

}
void Make_Demonstration_of_display_on_board(void) 
{
	Number1.clear(); // Clear the number of displays you have
	Number2.clear(); // Clear the number of displays you have

	Number1.display(ByteToChar(9, 2)); // Display the number 0 
	Number2.display(ByteToChar(9, 2)); // Display the number 0
	delay(time1second);    // Delay for the delay time specified in the integer delayTime
	Number1.display(ByteToChar(8, 2)); // ����� ����� 2 
	Number2.display(ByteToChar(8, 2));	// ����� ����� 2 
	delay(time1second);
	Number1.display('7');
	Number2.display('7');
	delay(time1second);
	Number1.display('6');
	Number2.display('6');
	delay(time1second);
	Number1.display('5');
	Number2.display('5');
	delay(time1second);
	Number1.display('4');
	Number2.display('4');
	delay(time1second);
	Number1.display('3');
	Number2.display('3');
	delay(time1second);
	Number1.display('2');
	Number2.display('2');
	delay(time1second);
	Number1.display('1');
	Number2.display('1');
	delay(time1second);
	Number1.display('0'); // Display the number 0
	Number2.display('0'); // Display the number 0
}
void Make_First_setup_in_EEPROM(void)
{
	if (eeprom_read_byte(3) > 99) // ���� ������ ������ �������� �������� ����� �� ���� ����� ������� � ����
	{
		eeprom_write_byte(1, 0);  // 1� ���� ������� 
		eeprom_write_byte(2, 0);  // 2� ���� ������� 
		eeprom_write_byte(3, 0);  // 3� ���� ������� 
	}

	if (i_want_to_see_the_diagnostical_output == true)
	{
		Serial.println(" ");
		Serial.print("eeprom_read_byte(0)=");
		Serial.println(eeprom_read_byte(0));
		Serial.print("eeprom_read_byte(1)=");
		Serial.println(eeprom_read_byte(1));
		Serial.print("eeprom_read_byte(2)=");
		Serial.println(eeprom_read_byte(2));
	}
	 
}
void Make_Display_number_from_EEPROM(void)
{
	byte d1 = eeprom_read_byte(1);
	Number1.display(ByteToChar(d1, 2));	// � ���������� ������ ����� ����� 2 

	byte d2 = eeprom_read_byte(2);
	Number2.display(ByteToChar(d2, 2));	// � ���������� ������ ����� ����� 2 

}
ISR(TIMER1_A) 
{  
	byte Number_of_this_device = eeprom_read_byte(3);
	Serial.println(Number_of_this_device); //
} // ��������� ���������� � �� ������� 1
