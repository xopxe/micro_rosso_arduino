#ifndef __micro_rosso_config_h
#define __micro_rosso_config_h

#define ROS2_NODE_NAME "micro_rosso_rclc"


/*
 Serial console used for debug output. If commented, no output is prdouced.
 To send to USB serial, set DEBUG_CONSOLE ro Serial and PINs to -1.
*/
#define DEBUG_CONSOLE Serial1
#define DEBUG_CONSOLE_PIN_RX 10
#define DEBUG_CONSOLE_PIN_TX 9
#define DEBUG_CONSOLE_BAUD 115200

/*
 Set the time on the microconroller from ROS, useful 
 for non-ROS code that might whant to know the time.
*/
#define USE_SET_TIME

/*
 I2C configration
*/
#define I2C_SCL 22
#define I2C_SDA 21

/*
 The two default timers created, one for control tasks
 (e.g. pid), and another for reporting (e.g. odom)
*/
#define TIMER_CONTROL_MS 50  // 20Hz
#define TIMER_REPORT_MS 200  // 5Hz


/*
 Select the transport to use to connect to the agent. If none
 of TRANSPORT_SERIAL or TRANSPORT_WIFI are defined, then
 the first Serial (typically the USB) is used.
*/

// Select specific serial to use
//#define TRANSPORT_SERIAL Serial

// Select Wifi transport
//#define TRANSPORT_WIFI

#define TRANSPORT_WIFI_SSID (char*)"essid"
#define TRANSPORT_WIFI_PASS (char*)"password"
#define TRANSPORT_WIFI_AGENT_IP   (char*)"192.168.1.2" 
#define TRANSPORT_WIFI_PORT 2024 
// If TRANSPORT_WIFI_STATIC_IP is undefined, DHCP is used
#define TRANSPORT_WIFI_STATIC_IP IPAddress(192,168,1,101)
#define TRANSPORT_WIFI_STATIC_GATEWAY IPAddress(192,168,1,2)
#define TRANSPORT_WIFI_STATIC_SUBNET IPAddress(255,255,255,0)


#endif  // __micro_rosso_config_h
