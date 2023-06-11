#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_RED 3
#define LED_GREEN 4
#define LED_BLUE 5
#define LED_YELLOW 18
#define LED_WHITE 19
#define delay 500

void app_main(void)
{
    uint8_t ledArray[] = {LED_RED, LED_GREEN,LED_BLUE,LED_YELLOW,LED_WHITE};

    for (int i = 0; i < sizeof (ledArray); ++i) {
        gpio_reset_pin(ledArray[i]);
        gpio_set_direction(ledArray[i],GPIO_MODE_OUTPUT);
        gpio_set_pull_mode(ledArray[i],GPIO_FLOATING);
        gpio_set_drive_capability(ledArray[i], GPIO_DRIVE_CAP_0);
    }

    while (1)
    {
        for (int i = 0; i < sizeof (ledArray); ++i) {
            gpio_set_level(ledArray[i], 1);
            vTaskDelay(pdMS_TO_TICKS(delay));
            gpio_set_level(ledArray[i], 0);
            vTaskDelay(pdMS_TO_TICKS(delay/3));
        }
    }
}
