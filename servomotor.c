#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22   
#define PWM_FREQUENCY 50  
#define PWM_WRAP 20000  // Período do PWM em microssegundos (20ms)

// Função para configurar o ciclo ativo (duty cycle)
void set_pwm_duty_cicle(uint slice, uint channel, uint pulse_width) {
    // Define a largura do pulso PWM
    pwm_set_chan_level(slice, channel, pulse_width);
}

void setup_pwm ()  {
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);
    uint channel = pwm_gpio_to_channel(PWM_PIN);
}

int main() {
    stdio_init_all();
    setup_pwm();

    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);
    uint channel = pwm_gpio_to_channel(PWM_PIN);
    
    pwm_set_wrap(slice_num, PWM_WRAP);  
    pwm_set_clkdiv(slice_num, 125.0);   
    pwm_set_enabled(slice_num, true); 

    // Movendo o servo para 180°, 90° e 0° com intervalo de 5 segundos
    printf("Posição inicial do servomotor em 180° (2.400µs)\n");
    set_pwm_duty_cicle(slice_num, channel, 2400);
    sleep_ms(5000);

    printf("Posição do servomotor em 90° (1.470µs)\n");
    set_pwm_duty_cicle(slice_num, channel, 1470);
    sleep_ms(5000);

    printf("Posição do servomotor em 0° (500µs)\n");
    set_pwm_duty_cicle(slice_num, channel, 500);
    sleep_ms(5000);

    // Movimentação contínua entre 0° e 180°
    printf("Movimentação periódica do servomotor entre 0° e 180°\n");

    while (1) {
        // Subindo de 0° para 180°
        for (uint pulse = 500; pulse <= 2400; pulse += 5) {
            set_pwm_duty_cicle(slice_num, channel, pulse); // Ajusta o ciclo ativo
            sleep_ms(10); // Atraso de 10ms para um movimento suave
        }
        // Descendo de 180° para 0°
        for (uint pulse = 2400; pulse >= 500; pulse -= 5) {
            set_pwm_duty_cicle(slice_num, channel, pulse); // Ajusta o ciclo ativo
            sleep_ms(10); // Atraso de 10ms para um movimento suave
        }
    }

    return 0;
}