#include "micro_rosso.h"

#include "src/ticker.h"
Ticker ticker;

#include "src/sync_time.h"
SyncTime sync_time;

#include "src/ros_status.h"
RosStatus ros_status;

void setup() {

  delay(2000);

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