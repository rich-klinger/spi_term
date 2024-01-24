/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"

/*
SPI spi(); 
spi.spi_frequency(spi_t *obj, int hz)
// main() runs in its own thread in the OS
int main()
{
    while (true) {

    }
}*/

// Define SPI pins
SPI spi(D11, D12, D13);  // MOSI, MISO, SCLK
DigitalOut cs(D9);      // Chip Select

int main() {
    // Initialize SPI with a 1 MHz clock frequency
    spi.format(8, 0);  // 8 bits per frame, SPI mode 0
    spi.frequency(1000000);  // 1 MHz

    while (1) {
        cs = 0;  // Select the device

        // Perform SPI communication here
        // e.g., spi.write(data);

        cs = 1;  // Deselect the device

        ThisThread::sleep_for(1s);  // Sleep for 1 second
    }
}
/*#include "mbed.h"

#define WAIT_TIME_MS 500 
DigitalOut led1(LED1);

int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    while (true)
    {
        led1 = !led1;
        thread_sleep_for(WAIT_TIME_MS);
    }
}
*/