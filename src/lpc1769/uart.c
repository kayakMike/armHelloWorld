#include "micro_types.h"
#include "hwdef_gpio.h"
#include "hwdef_pinsel.h"
#include "hwdef_uart.h"
#include "system.h"


//icky....
void uart0_send(char *msg){
    uint32_t i;
    for(i=0;msg[i]!='\0';i++){
        if(UART0_LINE_STATUS.tx_hold_empty==1){
            //spin until UART0 is not busy anymore
            UART0_THR.buffer=msg[i];
        }
    }    
}

//better
void send_message(uint8_t *message, uint32_t count){
    uint32_t index=0;
    while(index<count){
        if(UART0_LINE_STATUS.tx_hold_empty==1){
            UART0_THR.buffer=message[index];
            index++;
        }
    }
}

void uart0_initialize(void){
    PINSEL0.p002=1;
    PINSEL0.p003=1;
    PINMODE0.p002=3;  //pulldown
    PINMODE0.p003=3;  //pulldown

    //PERIPHERAL_CLOCK_SEL0.uart0=0;
    //uart clock is SYSTEM_CORE_CLOCK/4.
    //120MHz/4 is 30Mhz
    //Calculation from Data Sheets 
    //DLest is 10
    //DivAddVal is 5
    //MulVal is 8
    UART0_TRANSMIT_ENABLE.tx_enable=0;

    UART0_FIFO_CTL.enable=1;
    UART0_FIFO_CTL.rx_reset=1;
    UART0_FIFO_CTL.tx_reset=1;
    UART0_FIFO_CTL.rx_trigger_lvl=0;
    UART0_FIFO_CTL.dma=0;
    UART0_LINE_CTL.word_length=3;    //8
    UART0_LINE_CTL.parity_enable=0;  //N
    UART0_LINE_CTL.stop_bits=0;      //1

    UART0_LINE_CTL.divisor_latch=1;  //unlock divisors
    UART0_FRACTIONAL_DIVIDER.divaddval=5;
    UART0_FRACTIONAL_DIVIDER.mulval=8;

    UART0_DLL.buffer=10;
    UART0_DLM.buffer=0;

    UART0_LINE_CTL.divisor_latch=0;  //relock divisors
    UART0_TRANSMIT_ENABLE.tx_enable=1;
}


