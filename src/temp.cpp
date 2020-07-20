/*
operation.cpp에 작성했었던 예전 프리셋 함수 메모
*/

/*
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
*/