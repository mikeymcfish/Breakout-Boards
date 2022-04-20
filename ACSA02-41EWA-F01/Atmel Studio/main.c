#include <atmel_start.h>
#include <util/delay.h>

#define ENABLE 0b00001000
#define A0 0b00000100
#define A1 0b00000010
#define A2 0b00000001

#define A 0b00000000
#define B 0b00000100
#define C 0b00000010
#define D 0b00000110
#define E 0b00000001
#define F 0b00000101
#define G 0b00000011
#define P 0b00000111

#define NUM0 0x3F
#define NUM1 0x06
#define NUM2 0x5B
#define NUM3 0x4F
#define NUM4 0x66
#define NUM5 0x6D
#define NUM6 0x7D
#define NUM7 0x07
#define NUM8 0x7F
#define NUM9 0x6F 

#define DEL 50

#define LOOP_COUNT 1200

bool hold_display = 1;

int main(void)
{
	atmel_start_init();

	DDRC = 0b1111;

	while (1) {

		displayNumber(NUM0);
		displayNumber(NUM1);
		displayNumber(NUM2);
		displayNumber(NUM3);
		displayNumber(NUM4);
		displayNumber(NUM5);
		displayNumber(NUM6);
		displayNumber(NUM7);
		displayNumber(NUM8);
		displayNumber(NUM9);
	}

}

void displayNumber(int NUM) {
	for (int i = 0; i < LOOP_COUNT; i++) {
		
		NUM & 1 << 0 ? PORTC = ENABLE | A: 1;
		_delay_us(DEL);
		NUM & 1 << 1 ? PORTC = ENABLE | B: 1;
		_delay_us(DEL);
		NUM & 1 << 2 ? PORTC = ENABLE | C: 1;
		_delay_us(DEL);
		NUM & 1 << 3 ? PORTC = ENABLE | D: 1;
		_delay_us(DEL);
		NUM & 1 << 4 ? PORTC = ENABLE | E: 1;
		_delay_us(DEL);
		NUM & 1 << 5 ? PORTC = ENABLE | F: 1;
		_delay_us(DEL);
		NUM & 1 << 6 ? PORTC = ENABLE | G: 1;
		_delay_us(DEL);
	}
	PORTC = 0;
}
