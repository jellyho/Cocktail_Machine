// 
// 임포트 한 클래스들이 많이 바뀌어서, 어차피 얘도 많이 바꿔야함.
// 

#if 0


#include "Operation.h"
#include <SoftwareSerial.h>


// ******************** main의 전역 포인터 가져오기 ******************
extern Led* p_ledstrip1;  extern Led* p_ledstrip2;  
extern Led* p_ledpanel;
extern Pump* p_pump1;  extern Pump* p_pump2;  
extern Pump* p_pump3;  extern Pump* p_pump4;
extern Pump* p_pump5;  extern Pump* p_pump6;  
extern Pump* p_pump7;



// *************************** 프리셋 함수들 *************************
void Operation::preset_led_instances()
{
	Led ledstrip1(50, 31); // led 개수, 핀넘버
	Led ledstrip2(50, 32);
	Led ledpanel(256, 33);

	p_ledstrip1 = (Led*)malloc(sizeof(ledstrip1));
	p_ledstrip2 = (Led*)malloc(sizeof(ledstrip2));
	p_ledpanel = (Led*)malloc(sizeof(ledpanel));

	*(p_ledstrip1) = ledstrip1;
	*(p_ledstrip2) = ledstrip2;
	*(p_ledpanel) = ledpanel;
}

void Operation::preset_pump_instances() 
{
	Pump pump1(23, 24); // 핀A, 핀B
	Pump pump2(25, 26);
	Pump pump3(27, 28);
	Pump pump4(29, 30);
	Pump pump5(31, 32);
	Pump pump6(33, 34);
	Pump pump7(35, 36);

	p_pump1 = (Pump*)malloc(sizeof(pump1));
	p_pump2 = (Pump*)malloc(sizeof(pump2));
	p_pump3 = (Pump*)malloc(sizeof(pump3));
	p_pump4 = (Pump*)malloc(sizeof(pump4));
	p_pump5 = (Pump*)malloc(sizeof(pump5));
	p_pump6 = (Pump*)malloc(sizeof(pump6));
	p_pump7 = (Pump*)malloc(sizeof(pump7));


	*(p_pump1) = pump1;
	*(p_pump2) = pump2;
	*(p_pump3) = pump3;
	*(p_pump4) = pump4;
	*(p_pump5) = pump5;
	*(p_pump6) = pump6;
	*(p_pump7) = pump7;
}

// 정보 셋업하기 (재료들의 위치, 칵테일 레시피)
void Operation::preset_dispenser_materials() 
{

}

void Operation::preset_pump_materials()
{

}

void Operation::preset_cocktail_recipes()
{

}



// ************************* 소멸자 함수 **************************
Operation::~Operation() // 동적으로 할당해준 주소들을 해제해 준다.
{
	free(p_ledstrip1);
	free(p_ledstrip2);
	free(p_ledpanel);
	free(p_pump1);
	free(p_pump2);
	free(p_pump3);
	free(p_pump4);
	free(p_pump5);
	free(p_pump6);
	free(p_pump7);
}



// ********************** 작동을 위한 함수들 *********************
void Operation::bluetooth_connect()//preset_bluetooth()로 할까
{
	if (blueToothSerial.available()) {
		char message = blueToothSerial.read();
		if (message <= '0' && message <= '15') {//어플에서 char형으로 보내야됨
			//OLED 문자 출력 "Bluetooth is connected"
			delay(3000);
			//LED 스트립 on
			delay(3000);
		}
	}
}


// 함수 여러개로 분할할까...-> 분할하는게 좋을거라 생각했는데 좀 애매하네..(인스턴스 생성함수/디스펜서+펌프/
int Operation::make_cocktail(Cocktail ct)
{
	// creating temp instances
	// 얘네들을 어떻게 처리할까? 
	// 그냥 인스턴스 생성해서 쓰는거면 프리셋도 필요 없겠는데...->led,oled 프리셋 함수는 화면 비우는 걸 생각하신건가요??
	Oled oled_instance;
	LedStrip led_instance;
	Coord coord_instance;
	Plate plate_instance;
	Pump pump_instance;


	// checking remains...


	// OLED display name of the cocktail
	string name = ct.get_name();
	oled_instance.display_character(name); // 함수 이름은 바뀔 수 있음.


	/*
	중간에 몇 초 동안 기다리는 함수 아직 안 넣음!!
	*/
	// loop; num of alcohol; 디스펜서 개수만큼 반복...
	auto disp_recipe = ct.get_disp_recipe();
	for (auto it = disp_recipe.begin(); it != disp_recipe.end(); it++)
	{
		DispenserMaterial material = it->first;

		// OLED display alcohol
		oled_instance.display_charcater(material.get_name());

		// LedStrip set color
		int* p_rgb = material.get_rgb();
		led_instance.set_color(p_rgb[0], p_rgb[1], p_rgb[2]); // 함수 이름 달라질 수 있음

		// move plate
		coord_instance.set(material.get_pos_x(), material.get_pos_y());
		plate_instance.move_horizontally(coord_instance);

		// move plate z-axis (push dispenser)
		plate_instance.push_dispenser(it->second);
	}


	// loop; num of non-alcohol material; 디스펜서 개수만큼 반복...
	auto pump_recipe = ct.get_pump_recipe();
	for (auto it = pump_recipe.begin(); it != pump_recipe.end(); it++)
	{
		PumpMaterial material = it->first;

		// OLED display non-alcohol material
		oled_instance.display_charcater(material.get_name());

		// LedStrip set color
		int* p_rgb = material.get_rgb();
		led_instance.set_color(p_rgb[0], p_rgb[1], p_rgb[2]); // 함수 이름 달라질 수 있음

		// move plate
		coord_instance.set(material.get_pos_x(), material.get_pos_y());
		plate_instance.move_horizontally(coord_instance);

		// activate pump
		pump_instance.work_pump(it->second); // 이것 역시 함수 이름 달라질 수 있음
	}


	// 주조 기법에 따라 주조하기
	Technique ct_technique;
	ct_technique.f(ct.get_craft_method());


	// move to init pos
	plate_instance.move_to_initial_position();

	// OLED display 'complete'
	oled_instance.display_character("complete!"); // 완료 문구 달라질 수 있음

	return 0;
}


int Operation::emergency_stop()
{
	print("emergency stop!");
	exit;
	return 0;
}


#endif