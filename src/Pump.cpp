// 
// ok
// 

#if 0

#include "Pump.h"


//750ml준다고 하고 1초에 물 10ml나온다 가정
inline double Pump::cal_pump(double amount) 
{
	const int amount_per_sec_ratio = 10;
	double pump_time = amount / amount_per_sec_ratio; //양->초
	return pump_time;
}


void Pump::start_pump() 
{
	digitalWrite(PIN_PUMP_1, HIGH);
	digitalWrite(PIN_PUMP_2, LOW);
	
}


void Pump::stop_pump() 
{
	digitalWrite(PIN_PUMP_1, HIGH);
	digitalWrite(PIN_PUMP_2, LOW);
	
}
// 왜 같지?? - 모터드라이브 스펙시트 보고 바꿔야 할 듯..!

void Pump::work_pump(double amount) {
	start_pump();
	delay(cal_pump(amount));//변환 시간 입력
	stop_pump();
}


#endif