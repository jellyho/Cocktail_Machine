// 
// ok
// 

#include "Technique.h"

extern Led* ledstrip1;
extern Led* ledstrip2;
extern Led* ledpanel;


// 스터:
void Technique::stir() 
{
	// LED색깔
	int purple[3] = { 137, 119, 173 };
	ledstrip1->color(purple);
	ledstrip2->color(purple);
	ledpanel->random_color();

	// OLED 표시
	char* msg = "STIRRING...";
	Oled oled;
	oled.display_cocktail(msg);

	// 이동: 여러번 해야함
	Plate p;
	p.move_to(1, 2);
	p.move_to(3, 4);
	p.move_to(5, 6);

	// 거품기 작동
	Actuator a(21, 22); // 거품기 액츄에이터 핀 번호
	a.down();
	
	pinMode(30, OUTPUT); // DC모터 출력 핀
	analogWrite(30, 200); // 0~255 속도조절 원래 12V지만 5V해도 ㄱㅊ

	a.up();
	delay(5000); // 다 올라가기까지 기다려
	a.idle();

	// 사용자에게 전달
	p.move_to(10, 10);
}


// 빌드: LED 색깔과 OLED 표시 설정 필요
void Technique::build() 
{
	// LED색깔
	int purple[3] = { 137, 119, 173 };
	ledstrip1->color(purple);
	ledstrip2->color(purple);
	ledpanel->random_color();
	
	// OLED 표시
	char* msg = "BUILDING...";
	Oled oled;
	oled.display_cocktail(msg);

	// 딱히 별 다른 행동 없이 정해진 위치 (final_pos)로 이동
	Plate p;
	p.move_to(10,10);// 사용자에게 건네 줄 마지막 좌표
}

void Technique::f(TechniqueMethod method) {

	switch (method) {
	case TechniqueMethod::BUILD:
		build();
	case TechniqueMethod::STIR:
		stir();
	}

}

