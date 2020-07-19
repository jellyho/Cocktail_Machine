// Led.h

#ifndef _LED_h
#define _LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_NeoPixel.h>

class Led {
private:
	int numpixels;
	int brightness; //네오픽셀 밝기 설정 0(어두움)-255(밝음)
	int PIN_LED;
	int user_delay;

	Adafruit_NeoPixel strip;

	void colorWipe(uint32_t c, uint8_t wait);
	uint32_t Wheel(byte WheelPos);
	void rainbow();
	void rainbowCycle();

public:
	Led(int a_numpixel, int a_pin);

	void set_delay(int d);
	void set_brightness(int x);
	void off_gradually();//끄는 함수
	void off();
	void color(int* cock_color);//재료의 색을 나타내는 함수
	void random_color(); //이 함수는 의논 후 아래의 두 함수 중 하나로 결정
	void temp();
};


#endif

