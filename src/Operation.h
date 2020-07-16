// Operation.h

#ifndef _OPERATION_h
#define _OPERATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "Plate.h"
#include "Cocktail.h"
#include "Technique.h"
#include "Pump.h"
#include <array>
#include <vector>


class Operation {
private:

public:
	// 프리셋 함수 (setup)
	vector<Cocktail> preset_cocktail();
	// 컴파일러가 알아서 레퍼런스 방식으로 해준다길래 리턴형식을 벡터로 함.
	array<Pump, 5> preset_pumps(); // 5개
	void preset_ledstrip();
	void preset_oled();
	// 근데 생략하고 직접 하나씩 해줘도 될 듯?
	void bluetooth_connect();
	// 만드는 함수 (loop)
	int make_cocktail(Cocktail ct);
	int emergency_stop();
};



#endif

