#include <DallasTemperature.h>
#include "HX711.h"

#ifndef SUPLA_SETTINGS_H
#define SUPLA_SETTINGS_H


#define  SUPLA_DEVICE_NAME     "SUPLA TESTY"
#define  CONFIG_WIFI_LOGIN     "MODUL SUPLA"
#define  CONFIG_WIFI_PASSWORD  ""

#define  DEFAULT_LOGIN         "admin"
#define  DEFAULT_PASSWORD      "password"
#define  DEFAULT_HOSTNAME      "Primary v2"

#define  UPDATE_PATH           "/firmware"

//DHT ****************************************************************************************************
#define  DHTPIN                0
#define  DHTTYPE               DHT22
#define  MAX_DHT               8

//DS18B20 ************************************************************************************************
#define  MAX_DS18B20            4
#define  TEMPERATURE_PRECISION  10  // rozdzielczość czujnika DS 9 -12 bit
//LED CONFIG *********************************************************************************************
#define LED_CONFIG_PIN         2
//CONFIG PIN *********************************************************************************************
#define CONFIG_PIN             0 //D3     // triger config

//EEPROM *************************************************************************************************
#define EEPROM_SIZE           4096/4

#define  MAX_SSID            32
#define  MAX_PASSWORD        64
#define  MAX_MLOGIN          32
#define  MAX_MPASSWORD       64
#define  MIN_PASSWORD        8
#define  MAX_SUPLA_SERVER    SUPLA_SERVER_NAME_MAXSIZE
#define  MAX_SUPLA_ID        32
#define  MAX_SUPLA_PASS      SUPLA_LOCATION_PWD_MAXSIZE
#define  MAX_HOSTNAME        32
#define  MAX_BUTTON          16
#define  MAX_RELAY           16
#define  MAX_DS18B20_SIZE    16

#define  GUI_BLUE              "#005c96"
#define  GUI_GREEN             "#00D151"

#define CHOICE_TYPE  -1

extern DallasTemperature sensor[];
typedef struct {
  int pin;
  int channel;
  String address;
  int type; //0-single 1-multi
  DeviceAddress deviceAddress;
  long lastTemperatureRequest;
  bool TemperatureRequestInProgress;

} _ds18b20_t;
extern _ds18b20_t ds18b20[];
extern char GUID[SUPLA_GUID_SIZE];
String read_rssi(void);
void supla_led_blinking(int led, int time);
void supla_led_blinking_stop(void);


void add_Sensor(int sensor);
void add_Roller_Shutter_Buttons(int channel, int button1, int button2);
void add_Roller_Shutter_Relays(int relay1, int relay2);
void add_Led_Config(int led);
void add_Config(int pin);
void add_Relay(int relay);
void add_Relay_Invert(int relay);
void add_DHT11_Thermometer(int thermpin);
void add_DHT22_Thermometer(int thermpin);
void add_DS18B20_Thermometer(int thermpin);
void add_Relay_Button(int relay, int button, int type);
void add_Relay_Button_Invert(int relay, int button, int type);
void add_Relay_Button(int relay, int button, int type, int DurationMS);
void add_Relay_Button_Invert(int relay, int button, int type, int DurationMS);
void add_DS18B20Multi_Thermometer(int thermpin);

double get_temperature(int channelNumber, double last_val);
void get_temperature_and_humidity(int channelNumber, double *temp, double *humidity);
String GetAddressToString(DeviceAddress deviceAddress);
extern double temp_html;
extern double humidity_html;

// HX711*************************************************************************************
#define DOUT  5
#define CLK  4
#define MAX_CALIBRATION     10
//double calibration_factor = -7050; //-7050 worked for my 440lb max scale setup
extern double calibration_factor; // = -26230; //-7050 worked for my 440lb max scale setup
//                              -26230 = 104.4 kg 
extern HX711 scale;
extern double butla_pusta; // = 10.2;
extern double butla_pelna;  //= 21.2;

#endif //SUPLA_SETTINGS_H
