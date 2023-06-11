#include <stdio.h>
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_RED 3
#define LED_GREEN 4
#define LED_BLUE 5
#define LED_YELLOW 18
#define LED_WHITE 19

void app_main(void)
{
    uint8_t ledArray[] = { LED_YELLOW, LED_WHITE};

    for (int i = 0; i < sizeof (ledArray); ++i) {
        gpio_reset_pin(ledArray[i]);
        gpio_set_pull_mode(ledArray[i],GPIO_FLOATING);
        gpio_set_drive_capability(ledArray[i], GPIO_DRIVE_CAP_0);
    }

    ledc_timer_config_t settings_timer;
    settings_timer.speed_mode = LEDC_LOW_SPEED_MODE;
    settings_timer.timer_num = LEDC_TIMER_0;
    settings_timer.freq_hz = 5000;
    settings_timer.duty_resolution = LEDC_TIMER_10_BIT;
    settings_timer.clk_cfg = LEDC_AUTO_CLK;
    ledc_timer_config(&settings_timer);

    ledc_channel_config_t settings_channel;
    settings_channel.speed_mode = LEDC_LOW_SPEED_MODE;
    settings_channel.channel = LEDC_CHANNEL_0;
    settings_channel.gpio_num = LED_RED;
    settings_channel.duty = 0;
    settings_channel.timer_sel = LEDC_TIMER_0;
    settings_channel.intr_type = LEDC_INTR_DISABLE;
    ledc_channel_config(&settings_channel);

    settings_channel.speed_mode = LEDC_LOW_SPEED_MODE;
    settings_channel.channel = LEDC_CHANNEL_1;
    settings_channel.gpio_num = LED_GREEN;
    settings_channel.duty = 0;
    settings_channel.timer_sel = LEDC_TIMER_0;
    settings_channel.intr_type = LEDC_INTR_DISABLE;
    ledc_channel_config(&settings_channel);

    settings_channel.speed_mode = LEDC_LOW_SPEED_MODE;
    settings_channel.channel = LEDC_CHANNEL_2;
    settings_channel.gpio_num = LED_BLUE;
    settings_channel.duty = 0;
    settings_channel.timer_sel = LEDC_TIMER_0;
    settings_channel.intr_type = LEDC_INTR_DISABLE;
    ledc_channel_config(&settings_channel);

    while (1){
        for (int i = 0; i < 1023; ++i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0);
            vTaskDelay(1);
        }
        for (int i = 1023; i >= 0; --i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0);
            vTaskDelay(1);
        }
        for (int i = 0; i < 1023; ++i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_1);
            vTaskDelay(1);
        }
        for (int i = 1023; i >= 0; --i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_1);
            vTaskDelay(1);
        }
        for (int i = 0; i < 1023; ++i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_2);
            vTaskDelay(1);
        }
        for (int i = 1023; i >= 0; --i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_2);
            vTaskDelay(1);
        }
        for (int i = 0; i < 1023; ++i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0);
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_2);
            vTaskDelay(1);
        }
        for (int i = 1023; i >= 0; --i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0);
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_2);
            vTaskDelay(1);
        }

        for (int i = 0; i < 1023; ++i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0);
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_1);
            vTaskDelay(1);
        }
        for (int i = 1023; i >= 0; --i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0);
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_1);
            vTaskDelay(1);
        }

        for (int i = 0; i < 1023; ++i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_1);
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_2);
            vTaskDelay(1);
        }
        for (int i = 1023; i >= 0; --i) {
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_1);
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, i);
            ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_2);
            vTaskDelay(1);
        }
//        blink();
    }
}
