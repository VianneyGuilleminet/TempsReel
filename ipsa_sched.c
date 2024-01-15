/* Library includes. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* Local includes. */
#include "console.h"

/* Priorities at which the tasks are created. */
#define TASK_PRIORITY1    ( tskIDLE_PRIORITY + 1 ) //Highest priority
#define TASK_PRIORITY2    ( tskIDLE_PRIORITY + 2 ) 
#define TASK_PRIORITY3    ( tskIDLE_PRIORITY + 3 )
#define TASK_PRIORITY4    ( tskIDLE_PRIORITY + 4 ) // Lowest priority

/* The rate at which data is sent to the queue.  The times are converted from
 * milliseconds to ticks using the pdMS_TO_TICKS() macro. */
#define FREQUENCY_MS1      pdMS_TO_TICKS( 1000UL ) // 1 second
#define FREQUENCY_MS2      pdMS_TO_TICKS( 2000UL ) // 2 seconds
#define FREQUENCY_MS3      pdMS_TO_TICKS( 3000UL ) // 3 seconds
#define FREQUENCY_MS4      pdMS_TO_TICKS( 4000UL ) // 4 seconds

/* The number of items the queue can hold at once. */
#define mainQUEUE_LENGTH                   ( 4 )

/*-----------------------------------------------------------*/

// Task functions
static void prvQueueSendTask1(void *pvParameters);
static void prvQueueSendTask2(void *pvParameters);
static void prvQueueSendTask3(void *pvParameters);
static void prvQueueSendTask4(void *pvParameters);

/*-----------------------------------------------------------*/

/* The queue used by all four tasks. */
static QueueHandle_t xQueue = NULL;

/*-----------------------------------------------------------*/

// Entry point of the application
void ipsa_sched(void) {

    // Create a queue with a specific length for communication between tasks
    xQueue = xQueueCreate(mainQUEUE_LENGTH, sizeof(uint32_t));

    if (xQueue != NULL) {
        // Create tasks with different priorities
        xTaskCreate(prvQueueSendTask1, "TX1", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY1, NULL);
        xTaskCreate(prvQueueSendTask2, "TX2", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY2, NULL);
        xTaskCreate(prvQueueSendTask3, "TX3", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY3, NULL);
        xTaskCreate(prvQueueSendTask4, "TX4", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY4, NULL);

        // Start the FreeRTOS scheduler
        vTaskStartScheduler();
    }

    for (;;) {
    }
}

/*-----------------------------------------------------------*/

// Task to send a Working message

static void prvQueueSendTask1(void *pvParameters) {
    const TickType_t xBlockTime = FREQUENCY_MS1;

    (void)pvParameters;

    for (;;) {

 		// Print function
        console_print("The system is working properly.\n");
        
        
        // Function used to simulate exec time for this function
        vTaskDelay( xBlockTime );
    }
}

/*-----------------------------------------------------------*/

// Task to convert a fixed fahrenheit temperature in celsius

static void prvQueueSendTask2(void *pvParameters) {
    const TickType_t xBlockTime = FREQUENCY_MS2;

    (void)pvParameters;

    for (;;) {

        float Tcel;
        float Tfar = 120;
        Tcel = (Tfar - 32.0) * 5.0 / 9.0;
        printf("In Fahrenheit the temperature is %.2f°F, wich converted to Celsius is: %.2f°C \n", Tfar, Tcel);
        
        // Function used to simulate exec time for this function
        vTaskDelay( xBlockTime );
    }
}

/*-----------------------------------------------------------*/

// Task to multiply two long numbers
static void prvQueueSendTask3(void *pvParameters) {
    const TickType_t xBlockTime = FREQUENCY_MS3;

    (void)pvParameters;

    for (;;) {
        
		long int a = 14827539067821;
        long int b = 38208667297237;
        long int c = a*b;

        printf("The result of the multiplication of %.2ld by %.2ld is %.2ld \n", a, b, c);


        // Function used to simulate exec time for this function
        vTaskDelay( xBlockTime );
    }
}

/*-----------------------------------------------------------*/

// Task to do a binary search in a randomly created array

static void prvQueueSendTask4(void *pvParameters) {
    const TickType_t xBlockTime = FREQUENCY_MS4;

    (void)pvParameters;

    for (;;) {
        	
        int a_list[] = {59, 29, 69, 99, 23, 92, 43, 99, 96, 25, 69, 28, 31, 85, 77, 28, 85, 21, 54, 81, 71, 100, 18, 52, 54, 76, 49, 6, 85, 60, 11, 98, 17, 11, 61, 45, 13, 52, 66, 80, 22, 3, 80, 27, 2, 7, 56, 64, 75, 70};

        int SeekedNumber = 75;
        int find = 0;
        int min = 0;
        int max = 49;
        int mid = (min + max) / 2;
        while (min <= max)
        {
            if (a_list[mid] < SeekedNumber)
            {
                min = mid + 1;
            }
            else if (a_list[mid] == SeekedNumber)
            {
                printf("Found it !! he is located at index %d\n", mid);
                find = 1;
                break;
            }
            else
            {
                max = mid - 1;
            }
            mid = (min + max) / 2;
        }
        if (find == 0)
        {
            printf("The element was not in the array\n");
        }

        // Function used to simulate exec time for this function
        vTaskDelay( xBlockTime );
    }
}
