#include <stdio.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t Task1Handle = NULL;
TaskHandle_t Task2Handle = NULL;
TaskHandle_t Task3Handle = NULL;

void Task1(void *p) {
	uint8_t count = 0;

	while (1) {
		printf("Task1 is running %d \r \n", count++);
		vTaskDelay(1000); /* 1 second delay */
	}
}


void Task2(void *p) {
	while (1) {
		vTaskDelay(5000 * configTICK_RATE_HZ / 1000);
		vTaskSuspend(Task1Handle);
		vTaskDelay(5000 * configTICK_RATE_HZ / 1000);
		vTaskSuspend(Task2Handle);
	}

}

void functionnorelock(void);




int main(void) {


	/* Tasks creation*/
	xTaskCreate(Task1,
				"task1",
				1024,
				(void*)0,
				1,
				&Task1Handle				
		);

	xTaskCreate(Task2,
				"task2",
				1024,
				(void*)0,
				1,
				&Task2Handle
		);



	vTaskStartScheduler();

	while(1){
	
	
	}

}



void functionnorelock(void){
  
  }
