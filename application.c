/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on October 16, 2020, 7:53 PM
 */

#include "application.h"

led_t led1 = {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN0, .led_status = LED_OFF};
led_t led2 = {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN1, .led_status = LED_OFF};
led_t led3 = {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN2, .led_status = LED_OFF};

button_t btn2 = {.port_name = PORTD_INDEX, .pin = PIN1, .button_status = BUTTON_NOT_PRESSED};
uint8_t btn2_status = ZERO_INIT;
/*
led_t led_array[LED_SEQ_NUMBER] = {
    {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN0, .led_status = LED_OFF},
    {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN1, .led_status = LED_OFF},
    {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN2, .led_status = LED_OFF},
    {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN3, .led_status = LED_OFF},
    {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN4, .led_status = LED_OFF},
    {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN5, .led_status = LED_OFF},
    {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN6, .led_status = LED_OFF},
    {.port_info.port_name = PORTC_INDEX, .port_info.pin = PIN7, .led_status = LED_OFF}
};

uint8_t led_seq[][LED_SEQ_NUMBER] = {{1, 0, 0, 0, 0, 0, 0, 1},
                                     {1, 1, 0, 0, 0, 0, 1, 1},
                                     {1, 1, 1, 0, 0, 1, 1, 1},
                                     {1, 1, 1, 1, 1, 1, 1, 1}
                                    };

void perform_led_seq(led_t led_Arr[], uint8_t led_pat[][LED_SEQ_NUMBER], uint8_t seq_len);
*/
int main() {
    
    uint8_t counter =0;
    led_initialize(&led1);
    led_initialize(&led2);
    led_initialize(&led3);
    button_initialize(&btn2);
    
    while(TRUE){
        
        button_get_status(&btn2, &btn2_status);
        
        if(btn2_status == BUTTON_PRESSED){
            if(counter == 0 ){
                led_turn_on(&led1);
                __delay_ms(450);
                led_turn_off((&led1));
                counter = (counter++)%5;
            }
            else if(counter == 1){
                led_turn_on(&led2);
                 __delay_ms(450);
                 led_turn_off((&led2));
                __delay_ms(450);
                led_turn_on(&led2);
                __delay_ms(450);
                led_turn_off((&led2));
                counter = (counter++)%5;
            }
            else if(counter == 2){
                led_turn_on(&led3);
                    __delay_ms(450);
                    led_turn_off((&led3));
                    __delay_ms(450);
                    led_turn_on(&led3);
                    __delay_ms(450);
                    led_turn_off((&led3));
                    __delay_ms(450);
                    led_turn_on(&led3);
                    __delay_ms(450);
                    led_turn_off((&led3)); 
                    counter = (counter++)%5;
            }
            else if(counter == 3){
                led_turn_on(&led1);
                led_turn_on(&led2);
                led_turn_on(&led3);
                __delay_ms(450);
                counter = (counter++)%5;
            }
            else{
                led_turn_off(&led1);
                led_turn_off(&led2);
                led_turn_off(&led3);
                __delay_ms(450);
                counter = 0;
                    
            }
        }
        else { }
    }
    
    return (EXIT_SUCCESS);
}
/*
void perform_led_seq(led_t led_Arr[], uint8_t led_pat[][LED_SEQ_NUMBER], uint8_t seq_len){
    uint8_t l_led_counter = ZERO_INIT, l_led_pos = ZERO_INIT;
    for(l_led_counter = ZERO_INIT; l_led_counter<seq_len; l_led_counter++){
        led_initialize(&led_Arr[l_led_counter]);
    }
    for(l_led_counter = ZERO_INIT; l_led_counter<seq_len; l_led_counter++){
        for(l_led_pos = ZERO_INIT; l_led_pos<LED_SEQ_NUMBER; l_led_pos++){
            if(led_pat[l_led_counter][l_led_pos] == LED_ON){
                led_turn_on(&led_Arr[l_led_pos]);
            }
            else{
                led_turn_off(&led_Arr[l_led_pos]);
            }
        }
        __delay_ms(250);
    }
}
*/