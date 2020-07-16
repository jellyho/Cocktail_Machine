// 
// 임포트 한 클래스들이 많이 바뀌어서, 어차피 얘도 많이 바꿔야함.
// 

#include "Operation.h"
#include <SoftwareSerial.h>


vector<Cocktail> Operation::preset_cocktail()
{
	vector<Cocktail> lists;
	map<DispenserMaterial, double> disp_temp;
	map<PumpMaterial, double> pump_temp;


	// 디스펜서 재료 아래에 추가하기;
	DispenserMaterial vodka("vodka", 30, 30, 750, 50, 50, 200);

	// 펌프 재료 아래에 추가하기;
	PumpMaterial orange_juice("orange_juice", 500, 30, 450, 230, 120, 0);

	// 칵테일 인스턴스 만들기 (4줄단위); 
	// (근데 안에있는 정보까지 복사되나?) - ???? (테스트 해보고 안되면 포인터로 해야됨 ㅠㅠ)
	// 차라리 enum으로 번호 지정해서 포인터연산 쓰는건 어떰?
	disp_temp = { {vodka, 70}, };
	pump_temp = { {orange_juice, 50}, };
	Cocktail skrew_driver("skrew_driver", TechniqueMethod::BUILD, disp_temp, pump_temp);
	lists.push_back(skrew_driver);


	return lists;
}



// 펌프 프리셋 함수; ok
array<Pump, 5> Operation::preset_pumps()
{
	array<Pump, 5> temp;

	// 이 값들은 수동으로 입력해 줄 것.
	temp[0] = Pump(1, 2);
	temp[1] = Pump(3, 4);
	temp[2] = Pump(5, 6);
	temp[3] = Pump(7, 8);
	temp[4] = Pump(9, 10);

	return temp;
}


// LED STRIP 프리셋 함수;
void Operation::preset_ledstrip()
{

}

// OLED 프리셋 함수
void Operation::preset_oled()
{

}


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
