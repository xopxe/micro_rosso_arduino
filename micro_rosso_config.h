#ifndef __micro_rosso_config_h
#define __micro_rosso_config_h

#define ROS2_NODE_NAME "micro_rosso_rclc"

#define DEBUG_CONSOLE Serial1
#define DEBUG_CONSOLE_PIN_RX 10
#define DEBUG_CONSOLE_PIN_TX 9
#define DEBUG_CONSOLE_BAUD 115200

#define USE_SET_TIME

#define I2C_SCL 22  // default value 22
#define I2C_SDA 21  // default value 21

#define TIMER_CONTROL_MS 50  // 20Hz
#define TIMER_REPORT_MS 200  // 5Hz

//#define TRANSPORT_SERIAL Serial

//#define TRANSPORT_WIFI
#define TRANSPORT_WIFI_SSID (char*)"robotito_ap"
#define TRANSPORT_WIFI_PASS (char*)"***REMOVED***"
#define TRANSPORT_WIFI_AGENT_IP   (char*)"192.168.1.2" 
//#define TRANSPORT_WIFI_IP   (char*)"10.42.0.1" 
#define TRANSPORT_WIFI_PORT 2024 
#define TRANSPORT_WIFI_STATIC_IP IPAddress(192,168,1,101)
#define TRANSPORT_WIFI_STATIC_GATEWAY IPAddress(192,168,1,2)
#define TRANSPORT_WIFI_STATIC_SUBNET IPAddress(255,255,255,0)


#endif  // __micro_rosso_config_h
