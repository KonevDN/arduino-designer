/*
 Name:		Project1_Processor2.ino
 Created:	17.06.2021 22:24:24
 Author:	Konev
*/


/*
  ������ ��� ��������� ������� ������, ������ �� �����, � ������ (String) ��� "�������"
*/
String String1 = "";
boolean recieved_with_success_flag;
void setup() 
{
    Serial.begin(9600);
    Serial.println("PROCESSOR2");               // �������
}
void loop() 
{
    while (Serial.available() > 0) // ���� ���� ��� �� �� �����    
    {         
        String1 = String1 + (char)Serial.read();        // �������� ������ ��������� �������
        recieved_with_success_flag = true;                   // ������� ���� ��� �������� ������
        delay(10);                              // ����� ������ ��������! ��� �� �������� �����������!
    }
    if (recieved_with_success_flag == true)     // ���� ������ ��������
    {                      
        Serial.print("RX: ");               // �������
        Serial.print(String1);               // �������
        String1 = "";                          // ��������
        recieved_with_success_flag = false;                  // �������� ����
    }
}
