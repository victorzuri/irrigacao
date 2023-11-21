#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

/* A complete list of supported boards with WiFi is available here:
 * https://github.com/arduino-libraries/ArduinoIoTCloud/#what
 */
#if defined(BOARD_HAS_WIFI)
  #define SECRET_SSID "TISAFE-LAB"
  #define SECRET_PASS "Tisafe23@#"
#endif

/* ESP8266 ESP32*/
#if defined(BOARD_HAS_SECRET_KEY)
  #define SECRET_DEVICE_KEY "TQAQGX7CCDMJEAJVNUWL"
#endif





