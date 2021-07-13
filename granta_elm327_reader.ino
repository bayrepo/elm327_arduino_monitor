/*
* program for communicate arduino nano with
* the elm327 adapter via bluetooth module HC05.
* Gathered data displays on the OLED 128x64
* Author: Alexey
* E-mail: bayrepo.info@gmail.com
*/

#include <stdlib.h>

#include <Arduino.h>
#include <U8g2lib.h>
#include <SoftwareSerial.h>
#include <Time.h>
#include <ELMduino.h>
#include <SPI.h>
#include <avr/pgmspace.h>
#include <Bluetooth_HC05.h>
#include <EEPROM.h>

#define DEFAULT_PIN "1234"
#define STORAGE_ADDR 0

typedef struct slave_Name__ {
  char pin[5];
  BluetoothAddress addr;
} slave_Name;

slave_Name device;

U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, 13, 11, 10, 9, 8);
SoftwareSerial BTS(4, 5);
Bluetooth_HC05 hc05(BTS);
ELM327 intELM327;

#define DRAW_BEGIN u8g2.firstPage(); do {

#define DRAW_END } while( u8g2.nextPage() );

#define MAX_PID_STATE AUX_INPUT_OUTPUT_SUPPORTED

#define LIGHT_PIN 2
#define SENSOR_PIN 3
#define LONG_PRESS 10

#define RESET_MAC 12
#define RESET_H05 6
#define COMM_HC05 7

uint8_t state = 0;

#define OLED_MAX_X 128
#define OLED_MAX_Y 64

typedef struct obdnames__d__ {
  uint8_t id;
  char *name1;
  char *name2;
  char *name3;
} obdnames__d;

//#define MAX_CACHE 128
//int8_t cachePIDs[MAX_CACHE];
char programStrings[30];

uint8_t isConnected = 0;
uint8_t BaudRate = 0;

const char string0[] PROGMEM = "Calculated engine load";
const char string0_1[] PROGMEM = "%";
const char string1[] PROGMEM = "Engine coolant temperature";
const char string1_1[] PROGMEM = "C";
const char string2[] PROGMEM = "Fuel pressure";
const char string2_1[] PROGMEM = "kPa";
const char string3_0[] PROGMEM = "Intake manifold absolute";
const char string3_1[] PROGMEM = "pressure";
const char string3_2[] PROGMEM = "kPa";
const char string4[] PROGMEM = "Engine speed";
const char string4_1[] PROGMEM = "RPM";
const char string5[] PROGMEM = "Vehicle speed";
const char string5_1[] PROGMEM = "km/h";
const char string6[] PROGMEM = "Timing advance";
const char string6_1[] PROGMEM = "grd";
const char string7[] PROGMEM = "Intake air temperature";
const char string7_1[] PROGMEM = "C"; 
const char string8[] PROGMEM = "MAF air flow rate";
const char string8_1[] PROGMEM = "g/s";
const char string9[] PROGMEM = "Throttle position";
const char string9_1[] PROGMEM = "%";  
const char string10[] PROGMEM = "Run time since engine start";
const char string10_1[] PROGMEM = "sec";
const char string11_0[] PROGMEM = "Distance traveled with mal";
const char string11_1[] PROGMEM = "function indicator lamp on";
const char string11_2[] PROGMEM = "km";
const char string12_0[] PROGMEM = "Fuel Rail Pressure (relat";
const char string12_1[] PROGMEM = "ive to manifold vacuum)";
const char string12_2[] PROGMEM = "kPa";
const char string13_0[] PROGMEM = "Fuel Rail Gauge Pressure";
const char string13_1[] PROGMEM = "gasoline direct injection";
const char string13_2[] PROGMEM = "kPa";
const char string14[] PROGMEM = "Fuel Tank Level Input";
const char string14_1[] PROGMEM = "%";  
const char string15[] PROGMEM = "Abs Barometric Pressure";
const char string15_1[] PROGMEM = "kPa";  
const char string16[] PROGMEM = "Control module voltage";
const char string16_1[] PROGMEM = "V";  
const char string17[] PROGMEM = "Absolute load value";
const char string17_1[] PROGMEM = "%";  
const char string18[] PROGMEM = "Rel throttle position";
const char string18_1[] PROGMEM = "%";
const char string19[] PROGMEM = "Ambient air temperature";
const char string19_1[] PROGMEM = "C";  
const char string20[] PROGMEM = "Ethanol fuel";
const char string20_1[] PROGMEM = "%"; 
const char string21_0[] PROGMEM = "Relative accelerator";
const char string21_1[] PROGMEM = "pedal position"; 
const char string21_2[] PROGMEM = "%"; 
const char string22[] PROGMEM = "Engine oil temperature";
const char string22_1[] PROGMEM = "C";
const char string23[] PROGMEM = "Fuel injection timing";
const char string23_1[] PROGMEM = "deg";


const obdnames__d supportedPIDs[] PROGMEM = {
  { VEHICLE_SPEED, string5, NULL, string5_1 },
  { ENGINE_RPM, string4, NULL, string4_1 },
  { ENGINE_LOAD, string0, NULL, string0_1 },
  { ENGINE_COOLANT_TEMP, string1, NULL, string1_1 },
  { FUEL_PRESSURE, string2, NULL, string2_1 },
  { INTAKE_MANIFOLD_ABS_PRESSURE, string3_0, string3_1, string3_2 },
  { TIMING_ADVANCE, string6, NULL, string6_1 },
  { INTAKE_AIR_TEMP, string7, NULL, string7_1 },
  { MAF_FLOW_RATE, string8, NULL, string8_1 },
  { THROTTLE_POSITION, string9, NULL, string9_1 },
  { RUN_TIME_SINCE_ENGINE_START, string10, NULL, string10_1 },
  { DISTANCE_TRAVELED_WITH_MIL_ON, string11_0, string11_1, string11_2 },
  { FUEL_RAIL_PRESSURE, string12_0, string12_1, string12_2 },
  { FUEL_RAIL_GUAGE_PRESSURE, string13_0, string13_1, string13_2 },
  { FUEL_TANK_LEVEL_INPUT, string14, NULL, string14_1 },
  { ABS_BAROMETRIC_PRESSURE, string15, NULL, string15_1 },
  { CONTROL_MODULE_VOLTAGE, string16, NULL, string16_1 },
  { ABS_LOAD_VALUE , string17, NULL, string17_1 },
  { RELATIVE_THROTTLE_POSITION, string18, NULL, string18_1 },
  { AMBIENT_AIR_TEMP, string19, NULL, string19_1 },
  { ETHONOL_FUEL_PERCENT, string20, NULL, string20_1 },
  { RELATIVE_ACCELERATOR_PEDAL_POS, string21_0, string21_1, string21_2 },
  { ENGINE_OIL_TEMP, string22, NULL, string22_1 },
  { FUEL_INJECTION_TIMING, string23, NULL, string23_1 },
  { 0, NULL, NULL, NULL }
};

uint8_t messageToCenterX(uint8_t len, uint8_t letter_size_x){
  uint8_t maxXSymb = OLED_MAX_X / letter_size_x;
  if (len > maxXSymb) return letter_size_x;
  maxXSymb = len * letter_size_x;
  return (OLED_MAX_X - maxXSymb)/2;
}

typedef union OBD_ret__ {
  float u1;
  int32_t u2;
  uint16_t u3;
  uint8_t u4;
} OBD_ret;

OBD_ret retData;
uint8_t resDataStatus = 0;
uint8_t curScreen = 0;
uint8_t isLedOn = 0;

#define MAX_FILE_NUM_BUF 15
char NumBuf[MAX_FILE_NUM_BUF];

void restoreState(){
  if (state < 2 || state > 3) {
    digitalWrite(LIGHT_PIN, LOW);
    isLedOn = 0;
  } else {
    digitalWrite(LIGHT_PIN, HIGH);
    isLedOn = 1;
  }
}

void setState(uint8_t data){
  state = data;
  restoreState();
}

/*void clearCache(){
  uint8_t ind = 0;
  while(ind<MAX_CACHE){
    cachePIDs[ind]=-1;
    ind++;
  }
}

void setCache(int8_t data, uint8_t pid){
  if (pid < MAX_CACHE){
    if (cachePIDs[pid]!=-1) cachePIDs[pid]=data;
  }
}*/

uint8_t setupLight = 1;

uint16_t getBaud(){
  if (BaudRate>=7) BaudRate = 0;
  switch(BaudRate){
    case 1:
      return 9600;
    case 2:
      return 14400;
    case 3:
      return 19200;
    case 4:
      return 28800;
    case 5:
      return 38400;
    case 6:
      return 4800; 
    default:
      return 9600;
  }
  return 9600;
}

uint16_t bd = 0;
#define NOCURSCREEN 255
uint8_t savedData = NOCURSCREEN;

void setCurrentScreen(){
  EEPROM.get(STORAGE_ADDR+sizeof(device)+sizeof(bd), savedData);
  if (savedData != NOCURSCREEN){
    uint8_t pd_c = 1;
    uint8_t index = 0;
    while(pd_c){
      pd_c = (uint8_t)pgm_read_byte(&supportedPIDs[index].id);
      index++;
    }
    if (index>savedData){
      curScreen = savedData;
    }
  }
}

void setup(void) {
  //Serial.begin(9600);
  pinMode(RESET_MAC, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  if (digitalRead(RESET_MAC) == LOW){
    device.pin[0] = 0;
    device.pin[1] = 0;
    device.pin[2] = 0;
    device.pin[3] = 0;
    device.pin[4] = 0;
    device.addr[0] = 255;
    device.addr[1] = 255;
    device.addr[2] = 255;
    device.addr[3] = 255;
    device.addr[4] = 255;
    device.addr[5] = 255;
    EEPROM.put(STORAGE_ADDR, device);
    bd = 0;
    EEPROM.put(STORAGE_ADDR+sizeof(device), bd);
    savedData = NOCURSCREEN;
    EEPROM.put(STORAGE_ADDR+sizeof(device)+sizeof(bd), savedData);
    while(1){
      if (setupLight) {
        digitalWrite(LIGHT_PIN, HIGH);
        setupLight = 0;
      } else {
        digitalWrite(LIGHT_PIN, LOW);
        setupLight = 1;
      }
      delay(300);
    }
  }
  u8g2.begin();
  delay(500);
  //clearCache();
  pinMode(SENSOR_PIN, INPUT);
  EEPROM.get(STORAGE_ADDR, device);
  if ((device.addr[0]==255) &&
      (device.addr[1]==255) &&
      (device.addr[2]==255) &&
      (device.addr[3]==255) &&
      (device.addr[4]==255) &&
      (device.addr[5]==255)) {
        BTS.begin(38400);
        setState(4);
  } else {
    EEPROM.get(STORAGE_ADDR+sizeof(device), bd);
    if (!bd || bd == 65535){
      bd = getBaud();
    }
    BTS.begin(bd);
    hc05.begin(bd, RESET_H05, COMM_HC05, HC05_MODE_DATA);
    delay(1000);
  }
}

/*uint8_t isPIDSupported(uint8_t pidType){
  if (pidType < MAX_CACHE){
    if (cachePIDs[pidType]!=-1) {
      return cachePIDs[pidType];
    }
  }
  if (pidType>SUPPORTED_PIDS_1_20 && pidType < SUPPORTED_PIDS_21_40){
    retData.u2 = intELM327.supportedPIDs_1_20();d
    return (retData.u2 & (((uint32_t)1)<<(pidType - SUPPORTED_PIDS_1_20)))?1:0;
  } else if (pidType>SUPPORTED_PIDS_21_40 && pidType < SUPPORTED_PIDS_41_60){
    retData.u2 = intELM327.supportedPIDs_21_40();
    return (retData.u2 & (((uint32_t)1)<<(pidType - SUPPORTED_PIDS_21_40)))?1:0;
  } else if (pidType>SUPPORTED_PIDS_41_60 && pidType < SUPPORTED_PIDS_61_80){
    retData.u2 = intELM327.supportedPIDs_41_60();
    return (retData.u2 & (((uint32_t)1)<<(pidType - SUPPORTED_PIDS_41_60)))?1:0;
  } else if (pidType > SUPPORTED_PIDS_61_80){
    retData.u2 = intELM327.supportedPIDs_61_80();
    return (retData.u2 & (((uint32_t)1)<<(pidType - SUPPORTED_PIDS_61_80)))?1:0;
  }
  return 0;
}*/

void getAllDataFromOBD(uint8_t pidType){
  if (intELM327.status == ELM_SUCCESS || intELM327.status == ELM_NO_DATA){
    /*if (!isPIDSupported(pidType)){
      resDataStatus=1;
      setCache(0, pidType);
      return;
    }
    setCache(1, pidType);*/
    switch(pidType){
      case VEHICLE_SPEED:
        //int32_t
        retData.u2 = intELM327.kph();
        break;
      case ENGINE_LOAD:
        //float
        retData.u1 = intELM327.engineLoad();
        break;
      case ENGINE_COOLANT_TEMP:
        //float
        retData.u1 = intELM327.engineCoolantTemp();
        break;
      case FUEL_PRESSURE:
        //float
        retData.u1 = intELM327.fuelPressure();
        break;
      case INTAKE_MANIFOLD_ABS_PRESSURE:
        //uint8_t
        retData.u4 = intELM327.manifoldPressure();
        break;
      case ENGINE_RPM:
        //float
        retData.u1 = intELM327.rpm();
        break;
      case TIMING_ADVANCE:
        //float
        retData.u1 = intELM327.timingAdvance();
        break;
      case INTAKE_AIR_TEMP:
        //float
        retData.u1 = intELM327.intakeAirTemp();
        break;
      case MAF_FLOW_RATE:
        //float
        retData.u1 = intELM327.mafRate();
        break;
      case THROTTLE_POSITION:
        //float
        retData.u1 = intELM327.throttle();
        break;
      case RUN_TIME_SINCE_ENGINE_START:
        //uint16_t
        retData.u3 = intELM327.runTime();
        break;
      case DISTANCE_TRAVELED_WITH_MIL_ON:
        //uint16_t
        retData.u3 = intELM327.distTravelWithMIL();
        break;
      case FUEL_RAIL_PRESSURE:
        //float
        retData.u1 = intELM327.fuelRailPressure();
        break;
      case FUEL_RAIL_GUAGE_PRESSURE:
        //float
        retData.u1 = intELM327.fuelRailGuagePressure();
        break;
      case FUEL_TANK_LEVEL_INPUT:
        //float
        retData.u1 = intELM327.fuelLevel();
        break;
      case ABS_BAROMETRIC_PRESSURE:
        //uint8_t
        retData.u4 = intELM327.absBaroPressure();
        break;
      case CONTROL_MODULE_VOLTAGE:
        //float
        retData.u1 = intELM327.ctrlModVoltage();
        break;
      case ABS_LOAD_VALUE:
        //float
        retData.u1 = intELM327.absLoad();
        break;
      case RELATIVE_THROTTLE_POSITION:
        //float
        retData.u1 = intELM327.relativeThrottle();
        break;
      case AMBIENT_AIR_TEMP:
        //float
        retData.u1 = intELM327.ambientAirTemp();
        break;
      case ETHONOL_FUEL_PERCENT:
        //float
        retData.u1 = intELM327.ethonolPercent();
        break;
      case RELATIVE_ACCELERATOR_PEDAL_POS:
        //float
        retData.u1 = intELM327.relativePedalPos();
        break;
      case ENGINE_OIL_TEMP:
        //float
        retData.u1 = intELM327.oilTemp();
        break;
      case FUEL_INJECTION_TIMING:
        //float
        retData.u1 = intELM327.fuelInjectTiming();
        break;
      default: {
          resDataStatus=1;
          return;
        }
    }
    if (intELM327.status == ELM_NO_DATA) {
      resDataStatus=2;
    } else {
      resDataStatus=0;
    }
  } else if (intELM327.status == ELM_NO_DATA) {
    resDataStatus=2;
  } else {
    setState(1);
  }
  
}

bool debg = false;

void printConnect(){
  ltoa((uint32_t)bd, NumBuf, 10);
  DRAW_BEGIN
  u8g2.setFont(u8g2_font_5x7_t_cyrillic);
  u8g2.drawStr(0, 10, "Set connection to device..");
  u8g2.drawStr(messageToCenterX(strlen(NumBuf), 5),20, NumBuf); 
  u8g2.drawStr(messageToCenterX(7, 5),30,"made by"); 
  u8g2.drawStr(messageToCenterX(15, 5),40,"Alexey Berezhok"); 
  u8g2.drawStr(messageToCenterX(8, 5),50,"(c) 2021");
  DRAW_END
  //clearCache();
  if (!intELM327.begin(BTS, debg))
  {
    if (!isConnected) {
      BaudRate++;
      bd = getBaud();
      BTS.begin(bd);
    }
    setState(1);
  } else {
    isConnected = 1;
    bd = getBaud();
    EEPROM.put(STORAGE_ADDR+sizeof(device), bd);
    setCurrentScreen();
    setState(2);
  }
}

void printCanntConnect(){
  DRAW_BEGIN
  u8g2.setFont(u8g2_font_5x7_t_cyrillic);
  u8g2.drawStr(messageToCenterX(20, 5), 10, "Can't connect to OBD");
  u8g2.drawStr(messageToCenterX(14, 5),28,"turn on ELM327"); 
  u8g2.drawStr(messageToCenterX(14, 5),36,"and push reset"); 
  DRAW_END
  delay(3000);
  setState(0);
}

void printPIDPage(){
  uint8_t pd_c = (uint8_t)pgm_read_byte(&supportedPIDs[curScreen].id);
  getAllDataFromOBD(pd_c);
  if (state==1){
    return;
  } else {
    if (resDataStatus==1){
      curScreen++;
      pd_c = (uint8_t)pgm_read_byte(&supportedPIDs[curScreen].id);
      if (pd_c == 0){
        setState(1);
        resDataStatus=0;
        curScreen = 0;
        EEPROM.put(STORAGE_ADDR+sizeof(device)+sizeof(bd), curScreen);
        return;
      }
      EEPROM.put(STORAGE_ADDR+sizeof(device)+sizeof(bd), curScreen);
      return;
    } else if (resDataStatus==0) {
    switch(pd_c){
      case VEHICLE_SPEED:
        itoa(retData.u2, NumBuf, 10);
        break;
      case ENGINE_LOAD:
      case ENGINE_COOLANT_TEMP:
      case FUEL_PRESSURE:
      case TIMING_ADVANCE:
      case INTAKE_AIR_TEMP:
      case MAF_FLOW_RATE:
      case THROTTLE_POSITION:
      case FUEL_RAIL_PRESSURE:
      case FUEL_RAIL_GUAGE_PRESSURE:
      case FUEL_TANK_LEVEL_INPUT:
      case CONTROL_MODULE_VOLTAGE:
      case AMBIENT_AIR_TEMP:
      case ABS_LOAD_VALUE:
      case RELATIVE_THROTTLE_POSITION:
      case ETHONOL_FUEL_PERCENT:
      case RELATIVE_ACCELERATOR_PEDAL_POS:
      case ENGINE_OIL_TEMP:
      case FUEL_INJECTION_TIMING:
        dtostrf(retData.u1, 6, 1, NumBuf);
        break;
      case INTAKE_MANIFOLD_ABS_PRESSURE:
      case ABS_BAROMETRIC_PRESSURE:
        itoa(retData.u4, NumBuf, 10);
        break;
      case RUN_TIME_SINCE_ENGINE_START:
      case DISTANCE_TRAVELED_WITH_MIL_ON:
        ltoa((uint32_t)retData.u3, NumBuf, 10);
        break;
      case ENGINE_RPM:
        itoa((uint32_t)retData.u1, NumBuf, 10);
        break;
      default:{
      NumBuf[0]='N';
      NumBuf[1]='D';
      NumBuf[2]=0;
        }
    }
    } else {
      NumBuf[0]='N';
      NumBuf[1]='D';
      NumBuf[2]=0;
    }
  }
  DRAW_BEGIN
  u8g2.setFont(u8g2_font_5x7_t_cyrillic);
  strcpy_P(programStrings, (char *)pgm_read_word(&supportedPIDs[curScreen].name1));
  u8g2.drawStr(messageToCenterX(strlen(programStrings), 5), 10, programStrings);
  if ((char *)pgm_read_word(&supportedPIDs[curScreen].name2)) {
    strcpy_P(programStrings, (char *)pgm_read_word(&supportedPIDs[curScreen].name2));
    u8g2.drawStr(messageToCenterX(strlen(programStrings), 5), 20, programStrings);
  }
  if (NumBuf[0]=='N' && NumBuf[1]=='D') {
    u8g2.setFont(u8g2_font_5x7_t_cyrillic);
    u8g2.drawStr(messageToCenterX(strlen(NumBuf), 5), 30, NumBuf);
  } else {
    u8g2.setFont(u8g2_font_luBS18_tn);
    u8g2.drawStr(messageToCenterX(strlen(NumBuf), 18), 50, NumBuf);
  }
  u8g2.setFont(u8g2_font_5x7_t_cyrillic);
  strcpy_P(programStrings, (char *)pgm_read_word(&supportedPIDs[curScreen].name3));
  u8g2.drawStr(messageToCenterX(strlen(programStrings), 5), 60, programStrings);
  DRAW_END
}

#define MAX_LINES 5

void printSelect(){
  uint8_t top = curScreen;
  uint8_t bottom = top;
  uint8_t ind = top;
  while(1){
   if ((uint8_t)pgm_read_byte(&supportedPIDs[ind].id)==0){
     ind--;
     break;
   }
   if ( (ind - top) >= MAX_LINES ){
     break;
   }
   ind++;
  }
  if ((ind - top) < MAX_LINES){
    top = ind - MAX_LINES;
  }
  bottom = ind;
  
  DRAW_BEGIN
  u8g2.setFont(u8g2_font_5x7_t_cyrillic);
  for(ind=top; ind<=bottom; ind++){
    strcpy_P(programStrings, (char *)pgm_read_word(&supportedPIDs[ind].name1));
    if (ind == curScreen) {
      u8g2.drawStr(0, ((ind - top)+1) * 10, ">");
    }
    u8g2.drawStr(5, ((ind - top)+1) * 10, programStrings);
  }
  DRAW_END
}

#define LED_ON_TIMEOUT 4

uint8_t touchState = 0;
uint8_t touchCounter = 0;
uint8_t isTouched = 0;
uint8_t ledCounter = LED_ON_TIMEOUT;

#define MAX_MAC_STR 25

char MAC_buff[MAX_MAC_STR+1];

const char hexConv[17]="0123456789ABCDEF";

void prepareMAC(uint8_t *address){
    MAC_buff[0]=hexConv[address[0]>>4];
    MAC_buff[1]=hexConv[address[0]&0xF];
    MAC_buff[2]=':';
    MAC_buff[3]=hexConv[address[1]>>4];
    MAC_buff[4]=hexConv[address[1]&0xF];
    MAC_buff[5]=':';
    MAC_buff[6]=hexConv[address[2]>>4];
    MAC_buff[7]=hexConv[address[2]&0xF];
    MAC_buff[8]=hexConv[address[3]>>4];
    MAC_buff[9]=hexConv[address[3]&0xF];
    MAC_buff[10]=':';
    MAC_buff[11]=hexConv[address[4]>>4];
    MAC_buff[12]=hexConv[address[4]&0xF];
    MAC_buff[13]=':';
    MAC_buff[14]=hexConv[address[5]>>4];
    MAC_buff[15]=hexConv[address[5]&0xF];
    MAC_buff[16]=0;
}

uint8_t startScan = 0;

#define MAX_DEVICES 6 
BluetoothAddress scanned[MAX_DEVICES];
uint8_t nDevs = 0;
uint8_t DevIndexer = 0;

void BTCallbk(const BluetoothAddress &address){
  if (nDevs < MAX_DEVICES) {
    scanned[nDevs][0] = address[0];
    scanned[nDevs][1] = address[1];
    scanned[nDevs][2] = address[2];
    scanned[nDevs][3] = address[3];
    scanned[nDevs][4] = address[4];
    scanned[nDevs][5] = address[5];
    nDevs++;
  }
  startScan=2;
}

uint8_t PrntMACSCR(BluetoothAddress &address, uint8_t ind, uint8_t from){
  uint8_t isSet = 0;
  uint8_t deviceCounter = 30;
  while (deviceCounter){
    DRAW_BEGIN
    u8g2.setFont(u8g2_font_5x7_t_cyrillic);
    prepareMAC((uint8_t *)&address);
    u8g2.drawStr(messageToCenterX(strlen(MAC_buff), 5), 10, MAC_buff);
    sprintf(MAC_buff, "To the next devise %d", deviceCounter);
    u8g2.drawStr(messageToCenterX(strlen(MAC_buff), 5), 20, MAC_buff);
    sprintf(MAC_buff, "Current %d", ind);
    u8g2.drawStr(messageToCenterX(strlen(MAC_buff), 5), 30, MAC_buff);
    sprintf(MAC_buff, "From %d", from);
    u8g2.drawStr(messageToCenterX(strlen(MAC_buff), 5), 40, MAC_buff);
    DRAW_END
    touchState = digitalRead(SENSOR_PIN);
    if(touchState == HIGH){
      isSet = 1;
      break;
    }
    deviceCounter--;
    delay(100);
  }
  if (isSet) {
    if(hc05.cancelInquiry(10000)==false){
        printATError();
        return 255;
    }
    hc05.softReset(10000);
    delay(1000);
    if (hc05.initSerialPortProfile()==false){
        printATError();
        return;
    }
    if(hc05.setPassword(DEFAULT_PIN, 10000)==false){
        printATError();
        return 255;
    }
    if (hc05.setConnectionMode(HC05_CONNECT_BOUND, 10000)==false){
        printATError();
        return 255;
    }
    if(hc05.softReset(2000)==false){
        printATError();
        return 255;
    }
    delay(5000);
    if (hc05.initSerialPortProfile()==false){
        printATError();
        return;
    }
    hc05.pair(address, 30000);
    delay(5000);
    hc05.bind(address, 10000);
    hc05.connect(address);
    strcpy(device.pin, DEFAULT_PIN);
    device.addr[0] = address[0];
    device.addr[1] = address[1];
    device.addr[2] = address[2];
    device.addr[3] = address[3];
    device.addr[4] = address[4];
    device.addr[5] = address[5];
    EEPROM.put(STORAGE_ADDR, device);
    delay(1000);
    setState(0);
    return 1;
  }
  return 0;  
}

void printATError(){
  DRAW_BEGIN
  u8g2.setFont(u8g2_font_5x7_t_cyrillic);
  u8g2.drawStr(messageToCenterX(16, 5), 10, "AT command error");
  DRAW_END
  delay(1000);
}

void printSelectDevice(){
    uint8_t res = 0;
    if (!startScan){
      DRAW_BEGIN
      u8g2.setFont(u8g2_font_5x7_t_cyrillic);
      u8g2.drawStr(messageToCenterX(16, 5), 10, "Try to find devs");
      DRAW_END
      hc05.begin(38400, RESET_H05, COMM_HC05, HC05_MODE_COMMAND);
      delay(1500);
      if (hc05.initSerialPortProfile()==false){
        printATError();
        return;
      }
      if (hc05.restoreDefaults(10000)==false){
        printATError();
        return;
      }
      if (hc05.setRole(HC05_ROLE_MASTER)==false){
        printATError();
        return;
      };
      hc05.softReset(10000);
      delay(1000);
      if (hc05.initSerialPortProfile()==false){
        printATError();
        return;
      }
      if (hc05.deleteAllDevicesFromList()==false){
        printATError();
        return;
      }
      if (hc05.setConnectionMode(HC05_CONNECT_ANY, 10000)==false){
        printATError();
        return;
      }
      if (hc05.setInquiryMode(HC05_INQUIRY_STANDARD, MAX_DEVICES, 20)==false){
        printATError();
        return;
      }
      if (hc05.setDeviceClass(0, 10000)==false){
        printATError();
        return;
      }
      startScan = 1;
      hc05.inquire(BTCallbk, 30000);
    } else {
      if (startScan == 1){
          DRAW_BEGIN
          u8g2.setFont(u8g2_font_5x7_t_cyrillic);
          u8g2.drawStr(messageToCenterX(17, 5), 10, "Not found devices");
          DRAW_END
      } else {
        if (DevIndexer < nDevs) {
          res = PrntMACSCR(scanned[DevIndexer], DevIndexer, nDevs);
          if (!res){
            DevIndexer++;
          }
        } else {
          startScan = 0;
          nDevs = 0;
          DevIndexer = 0;
        }
      }
    }
    delay(100);
}

void machineState(){
  switch (state){
    case 1: {
      printCanntConnect();
      break;
      }
    case 2: {
      printPIDPage();
      break;
      }
    case 3: {
      printSelect();
      break;
      }
    case 4: {
      printSelectDevice();
      break;
      }
    default:{
      printConnect();
    }
  }
}

void loop(void) {
  machineState();
  touchState = digitalRead(SENSOR_PIN);
  if(touchState == HIGH)
  {
    touchCounter++;
    if (!isTouched) isTouched = 1;
    if (touchCounter > LONG_PRESS){
      if (ledCounter == LED_ON_TIMEOUT){
        if (isLedOn==1) {
          digitalWrite(LIGHT_PIN, LOW);
          isLedOn = 0;
        } else {
          digitalWrite(LIGHT_PIN, HIGH);
          isLedOn = 1;
        }
      }
      ledCounter--;
      if (ledCounter == 255) ledCounter = LED_ON_TIMEOUT;
    }
  }
  else
  {
    ledCounter = LED_ON_TIMEOUT;
    restoreState();
    if (isTouched == 1) {
      if (touchCounter < LONG_PRESS){
        curScreen++;
        if ((uint8_t)pgm_read_byte(&supportedPIDs[curScreen].id)==0){
          curScreen = 0;
        }
        EEPROM.put(STORAGE_ADDR+sizeof(device)+sizeof(bd), curScreen);
      } else if (touchCounter > LONG_PRESS) {
        if (state == 2) setState(3);
        else if (state == 3) setState(2);
      }
      isTouched = 0;
    }
    touchCounter = 0;
  }
  delay(100);  
}
