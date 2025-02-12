
// Arduino.hが存在する場合は include する
#if __has_include(<Arduino.h>)
 #include <Arduino.h>
#else
 #include <freertos/FreeRTOS.h>
 #include <freertos/task.h>
 
__attribute__((weak))
void delay(uint32_t ms)
{
  vTaskDelay(ms / portTICK_PERIOD_MS);
}
#endif

void setup(void)
{
}

void loop(void)
{
  printf("Hello World.\n");
  delay(1000);
}

extern "C" {
  // weak属性を付与することで、ArduinoESP32では無効化し、ESP-IDFの場合は有効化する。
  __attribute__((weak))
  void app_main()
  { // Arduino環境と同じ挙動になるようsetupとloopを呼び出す
    setup();
    for (;;) {
      loop();
    }
  }
}

