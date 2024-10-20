
// Needed on ESP32 Thing boards, Arduino ESP32 libs>=v3. Safe with v2.
// https://github.com/espressif/arduino-esp32/issues/9837
// If does not work, use Arduino ESP32 libs v2.017
//#define ESP32_THING_XTAL_FIX
#ifdef ESP32_THING_XTAL_FIX
#include "soc/rtc.h"
#endif

#include "micro_rosso.h"

#include "src/ticker.h"
Ticker ticker;

#include "src/sync_time.h"
SyncTime sync_time;

#include "src/ros_status.h"
RosStatus ros_status;

void setup() {

  delay(2000);

  #ifdef ESP32_THING_XTAL_FIX
  rtc_clk_xtal_freq_update((rtc_xtal_freq_t)26);
  rtc_clk_cpu_freq_set_xtal();
  setCpuFrequencyMhz(240);
  #endif

  D_SerialBegin(DEBUG_CONSOLE_BAUD, SERIAL_8N1, DEBUG_CONSOLE_PIN_RX, DEBUG_CONSOLE_PIN_TX);

  D_println("Booting...");

  if (!micro_rosso::setup()) {
    D_println("FAIL micro_rosso.setup()");
  }

  if (!ticker.setup()) {
    D_println("FAIL ticker.setup()");
  };
  
  if (!sync_time.setup()) {
    D_println("FAIL sync_time.setup()");
  };

  if (!ros_status.setup()) {
    D_println("FAIL ros_status.setup()");
  };

  D_println("Boot completed.");
}

void loop() {
  micro_rosso::loop();
}