/* FreeRTOS queue demonstration */
/* Author: Aussman IDDIR */

#if CONFIG_FREERTOS_UNICORE
  static const BaseType_t app_cpu = 0;
#else
  static const BaseType_t app_cpu = 1;
#endif

#define ENABLE_FREERTOS 1

// Settings
static const uint8_t msg_queue_len = 5; // Maximum items that the queue can holdx

// Globals (queue as a global variable so that all tasks can access it)
// Creation of the queue
static QueueHandle_t msg_queue;

static QueueHandle_t msg_queueRx;

// Tasks
void printMessages(void *parameter){
      int item; // where we store the value we read from the queue

      while(1){
        // See if there's a message in the queue (do not block)
        if(xQueueReceive(msg_queue, (void*)&item, 0) == pdTRUE){
          // the second parameter above is is the address of the local variable where the queue item will be copied to
          // The third parameter is the timeout in number of ticks
          // The function returns pdTRUE if thing was read from the queue or pdFALSE if not
          // If we got something we'll print it to the console
          Serial.println(item);        
          }
          vTaskDelay(1000/portTICK_PERIOD_MS);
        
        }
  
  }



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  vTaskDelay(1000/portTICK_PERIOD_MS);
  Serial.println();
  Serial.println("---FreeRTOS Queue Demo---");

  // Create queue
  msg_queue = xQueueCreate(msg_queue_len, sizeof(int));

  // Start print task
  xTaskCreatePinnedToCore(printMessages,
                          "Print Messages",
                          1024,
                          NULL,
                          1,
                          NULL,
                          app_cpu);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  static int num = 1;
  static uint8_t num2 = 0;
  static uint8_t num3 = 0;

  static uint8_t num4 = 0;
  static uint8_t num5 = 2;
  static uint8_t num6 = 3;
  static uint8_t num7 = 4;
  

  // Try to add item to queue for 10 ticks, fail if queue is full
  if(xQueueSend(msg_queue, (void*)&num, 10) != pdTRUE){
    Serial.printn("Queue full");
    }
  num++;

  vTaskDelay(500 / portTICK_PERIOD_MS);

  


}
