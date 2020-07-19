/*
 Name:		Project_Cocktail_Machine.ino
 Created:	2020-07-15 오전 2:20:54
 Author:	USER
*/



// ========= user-installed headers ==========
// 여기 있는 것들 옮겨 ㅅㅂ

#include <Stepper.h>
#include <ArduinoSTL.h>

#include <splash.h>
#include <Adafruit_SSD1306.h>

#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_MonoOLED.h>
#include <Adafruit_GFX.h>


// ========= user-defined headers =========

// #include "Operation.h"
#include "Pump.h"

#define _TECHNIQUE_h
#define _PLATE_h
#define _OPERATION_h
#define _OLED_h
#define _MATERIAL_h
#define _LED_h
#define _COCKTAIL_h
// #define _PUMP_h

// ========================================


void setup() {
	Pump p(1, 2);
	
	p.work_pump(50);

}


void loop() {
  
}
