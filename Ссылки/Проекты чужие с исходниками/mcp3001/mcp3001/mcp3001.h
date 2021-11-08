#define DDR_SPI DDRB
#define DD_SS 2
#define DD_MOSI 3
#define DD_MISO 4
#define DD_SCK 5
#define SPE 6
#define MSTR 4
#define SPR0 0
#define SPIF 7

void SPI_MasterInit()
{
DDR_SPI |= (1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS);//����������� �� �����
SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);//��� SPI, �������, ������� fck/16
}

//������� �������� �����
void SPI_MasterTransmit(char cData)
{
SPDR = cData;//�������� ��������
while(!(SPSR & (1<<SPIF)));//���� ���� �������� ����������
}

unsigned int ReceiveADC()
{
	unsigned char adcMSB=0;
	unsigned char adcLSB=0;
	unsigned int adc=0;

	PORTB &= ~(1<<DD_SS);
	SPI_MasterTransmit(0x00);
	adcMSB=SPDR;
	SPI_MasterTransmit(0x00);
	adcLSB=SPDR;
	PORTB |= (1<<DD_SS);
	//�������� �������� ���������� ���� ������	
	adcMSB &= 0b00011111;
	adc = adcMSB;
	adc<<=5;
	adcLSB>>=3;
	adc |= adcLSB;
	return adc;
}
