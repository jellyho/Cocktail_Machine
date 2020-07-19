// 
// 수정 필요
// 

#include "Oled.h"
Oled::Oled() {
	//idisplay(4);
	idisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	idisplay.clearDisplay();
}

void Oled::display_bluetooth() {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	idisplay.setCursor(30, 27);
	idisplay.println("Bluetooth");
	idisplay.setCursor(20, 35);
	idisplay.println("is connected");
	idisplay.display();
	delay(2000);
}


void Oled::display_complete() {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	idisplay.setCursor(30, 30);
	idisplay.println("Complete!");
	idisplay.display();
	delay(2000);
}

/*이거 여기 안에서 for문 반복시키면 안되던데 왜 안되는건지
  그래서 어쩔 수 없이 인자 숫자로 받고 main함수에서 for 문 돌리니까 됨
  ㄴ 일단 뭐를 어떻게 표시할지 다시 정하는게 좋겠어요! ㅠㅠ 저도 헷갈리네요*/
void Oled::display_process(int i) 
{
	// 잔 레이아웃을 그리는 코드
	idisplay.drawTriangle(5, 5, 55, 5, 30, 35, WHITE);
	idisplay.drawLine(30, 35, 30, 60, WHITE);
	idisplay.drawLine(15, 60, 45, 60, WHITE);

	// 단계를 표시하기 위해 계산
	int d1 = 1.2 * i - 1;
	int d2 = -1.2 * i + 63;
	idisplay.fillTriangle(i, d1, d2, d1, 30, 35, WHITE);

	// 걍 내가 추가한 코드. 이렇게 쓸거 맞지? 여기다 재료의 이름을 출력?
	char msg[] = "making cocktail...";
	this->display_cocktail(msg);
	idisplay.display();

	/* 코드의 의도를 모르겠다... 테스트용?
	  ㄴ 위에서 말했듯 무엇을 표현할지 명확하게 정하기가 1순위 목표
	delay(2000);
	idisplay.clearDisplay();
	delay(2000);*/
}

//칵테일 이름 출력(이름 긴 거는 띄어쓰기 기준으로 줄바꿈)
void Oled::display_cocktail(char* msg) {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	char* result = strtok(msg, " ");
	//i 초기 값이랑 증가값 조정 필요
	int i = 30;
	while (result != NULL) {
		idisplay.setCursor(60, i);
		idisplay.println(result);
		result = strtok(NULL, " ");
		i += 10;
	}
	idisplay.display();
	delay(2000);
}

void Oled::clear() {
	idisplay.clearDisplay();
	idisplay.display();
}
