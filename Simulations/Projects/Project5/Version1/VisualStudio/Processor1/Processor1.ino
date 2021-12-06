/*
 Name:		Processor1.ino
 Created:	04.07.2021 17:59:04
 Author:	Konev
*/

// ��� MASTER CPU �� ���� I2C
#include <Wire.h>
byte data_received_from_I2C_bus;					// data_received_from_I2C_bus

void setup()
{
	Wire.begin();									// join I2C bus as Master ���� ��������� ����������� � ���� I2C � �������� ������, ������� � ������� �� ��� ������ ������� ����� 
	Serial.begin(9600);
	Serial.println(" ");			// ������� 
	Serial.println("Author Konev");		// ������� 
	Serial.println("i am i2c transmitter");		// ������� 
	data_received_from_I2C_bus = 255;				// initialize global variables - ��������������� ���������� ���������� 
}

void loop()
{
	//// �������� ������	����� ���������� �������� � ���� A0 � ���������� value_pot, �� ����� ��������� �������� �� I2C.�������� ������ �� I2C �������� � ���� ��� �������.
	Wire.beginTransmission(0x08); // ����������� ���� � ���, ��� �� ����� �������� ������ to slave device 8 (0x08)
	Wire.write("K");        // ���� �������� �����
	Wire.endTransmission();       // ����� �������� ������ ��� ���������� ���������� ����, ����� ��������� ������ ����������� �������� �� ����. ��� �������� � ������� ������� Wire.endTransmission().
	Serial.println("K");
	delay(500);
}
