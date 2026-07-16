#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/devicetree.h>
#include <zephyr/device.h>
//#include <zephyr/drivers/uart.h>

//dobra praktyka- zabezpiecznie kodu
#if !DT_HAS_ALIAS(led0)
 #error "missing devicetree alias led0" 
#endif
    //struct gpio_dt_spec to utworzenie struktury o nazwie led- (nazwe sami wymyslamy)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(led0),gpios);


int main(void)
{
    bool led_state = false; //zmienna do przechowywania stanu diody
    //sprawdzamy czy dziala urzadzenie(tutaj led)
    if(!(gpio_is_ready_dt(&led))){ 
        return 0;
    }
    if(gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE) < 0){
        return 0;
    } //ustawienie pinu jako wyjscie i ustawienie stanu wysokiego
    led_state = !led_state;

   // gpio_pin_configure bez dt to klasyczna wersja jak z bare metal gdzie zamiast jednego aliasu podajemy juz port, pin i flage
    while(true){
        if(gpio_pin_toggle_dt(&led) < 0){
        return 0;
    }
    printf("Led state: %s ",led_state ? "On" : "off"); 
    k_msleep(1000);

    
}

    return 0;
}	
