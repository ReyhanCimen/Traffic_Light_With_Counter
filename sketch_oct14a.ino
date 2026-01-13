#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void displayDigit(uint8_t num)
{
    
    PORTD |= ( (1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7) );
    PORTB |= ( (1<<PB3) | (1<<PB4) );

    switch (num) {
        case 0: PORTD &= ~((1<<PD5)|(1<<PD7)|(1<<PD3)|(1<<PD2)|(1<<PD4)); PORTB &= ~(1<<PB4); break;
        case 1: PORTD &= ~(1<<PD7); PORTB &= ~(1<<PB4); break;
        case 2: PORTD &= ~((1<<PD5)|(1<<PD7)|(1<<PD3)|(1<<PD2)|(1<<PD6)); break;
        case 3: PORTD &= ~((1<<PD5)|(1<<PD7)|(1<<PD3)|(1<<PD6)); PORTB &= ~(1<<PB4); break;
        case 4: PORTD &= ~((1<<PD7)|(1<<PD4)|(1<<PD6)); PORTB &= ~(1<<PB4); break;
        case 5: PORTD &= ~((1<<PD5)|(1<<PD3)|(1<<PD4)|(1<<PD6)); PORTB &= ~(1<<PB4); break;
        case 6: PORTD &= ~((1<<PD5)|(1<<PD3)|(1<<PD2)|(1<<PD4)|(1<<PD6)); PORTB &= ~(1<<PB4); break;
        case 7: PORTD &= ~((1<<PD5)|(1<<PD7)); PORTB &= ~(1<<PB4); break;
        case 8: PORTD &= ~((1<<PD5)|(1<<PD7)|(1<<PD3)|(1<<PD2)|(1<<PD4)|(1<<PD6)); PORTB &= ~(1<<PB4); break;
        case 9: PORTD &= ~((1<<PD5)|(1<<PD7)|(1<<PD3)|(1<<PD4)|(1<<PD6)); PORTB &= ~(1<<PB4); break;
        default: break;
    }
}

void setup()
{
    DDRD = 0b11111100;  
    DDRB = 0b00011111;  
}

void loop()
{

    for (int count = 9; count >= 0; count--)
    {
        displayDigit(count);

        if (count > 6) {                
            PORTB = 0b00000010;
        } 
        else if (count == 6) {           
            PORTB = 0b00000011;
        } 
        else if (count == 0) {           
            PORTB = 0b00000100;
            displayDigit(0);
            _delay_ms(1000);
            displayDigit(5);
            _delay_ms(1000);

            
            for (int c = 5; c >= 0; c--) {
                displayDigit(c);
                if (c == 2) PORTB = 0b00000001;      
                else if (c == 0) PORTB = 0b00000010; 
                else PORTB = 0;
                _delay_ms(1000);
            }
        }

        _delay_ms(1000);
    }
}
