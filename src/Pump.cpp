// 
// ok
// 

#include "Pump.h"


//750ml�شٰ� �ϰ� 1�ʿ� �� 10ml���´� ����
inline double Pump::cal_pump(double amount) 
{
	const int amount_per_sec_ratio = 10;
	double pump_time = amount / amount_per_sec_ratio; //��->��
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
// �� ����?? - ���͵���̺� �����Ʈ ���� �ٲ�� �� ��..!

void Pump::work_pump(double amount) {
	start_pump();
	delay(cal_pump(amount));//��ȯ �ð� �Է�
	stop_pump();
}
