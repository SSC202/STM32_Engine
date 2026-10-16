#include "ch.h"
#include "hal.h"
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg)
{
    /* Onetime actions of Thread 1. */
    (void)arg;

    chRegSetThreadName("blinker");
    while (true)
    {
        /* Periodic actions of Thread 1. */
        palSetPad(GPIOC, GPIOC_LED);
        chThdSleepMilliseconds(500);
        palClearPad(GPIOC, GPIOC_LED);
        chThdSleepMilliseconds(500);
    }
}
/*
 * Application entry point.
 */
int main(void)
{
    /* HAL and RT initialization. */
    halInit();
    chSysInit();
    /* Creatation of the Thread 1. */
    chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO + 1, Thread1, NULL);

    /* Onetime actions of Thread main. */
    while (true)
    {

        /* Periodic actions of Thread main. */
        chThdSleepMilliseconds(50);
    }
}