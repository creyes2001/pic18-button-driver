// === Configuration Bits for PIC18F4550 ===
// CONFIG1L
#pragma config PLLDIV = 1       // No PLL prescale (4 MHz crystal)
#pragma config CPUDIV = OSC1_PLL2 // CPU system clock divide
#pragma config USBDIV = 1       // No USB clock divide
   
// CONFIG1H
#pragma config FOSC = HS        // High-speed crystal/resonator
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor disabled
#pragma config IESO = OFF       // Internal/External Switchover disabled
  
// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer enabled
#pragma config BOR = ON         // Brown-out Reset enabled
#pragma config BORV = 3         // Brown-out Reset Voltage = 2.85V
  
// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer disabled
 
// CONFIG3H
#pragma config PBADEN = OFF     // PORTB<4:0> pins are digital
#pragma config LPT1OSC = OFF    // Timer1 configured for high power
#pragma config MCLRE = ON       // MCLR pin enabled

// CONFIG4L
#pragma config STVREN = ON      // Stack overflow reset enabled
#pragma config LVP = OFF        // Low-voltage programming disabled
#pragma config XINST = OFF      // Extended instruction set disabled
 

