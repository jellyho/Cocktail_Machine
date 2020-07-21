// Cocktail.h

#if 0
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#include "Material.h"
#include "Technique.h"


class Cocktail
{
private:
	


	/* pseudo code

	name
	disp material : amount (array)
	pump material : amount (array)
	technique method

	*/

	// TechniqueMethod method; // 지금은 빨간 줄 이지만 Technique 헤더 인클루드 하면 됨 ㅇㅇ



public:

	/*************레시피*****************/
	//칵테일 갯수가 왜 다 다를까_수정필요
	//칵테일 순서: 애플마티니,바카디,블루하와이,블루로망스,코스모폴리탄,다키리,준벅,아일랜드,마가리타,멜론쿨러,모히또,피치크러시,스크류드라이브,시브리즈,솔티도그,데낄라선라이즈,타이틀스플래시,톰콜린스
	//disp 순서: 보드카,진,화이트럼,데낄라,쿠앵트로,스미노프그린애플,그린멜론,피치,블루큐라소,카시스,모히또,잭다니엘허니
	Material m_disp[15][10] = { {20,30,40,0,0,0},{},{},{},{},{},{},{} };
	//15가지 칵테일, 7가지 재료(pump)_갯수수정필요
	//pump 순서: 라즈베리,레몬,라임주스,스윗앤샤워,오렌지주스,자몽주스,토닉워터
	int m_pump[15][7] = { {},{} };
	
	//칵테일 이름 배열
	char* cocktail_name = { "applemartini" };
	//disp_material 이름 배열
	char* disp_material_name = { "sdf" };
	//pump_material 이름 배열
	char* pump_material_name = { "sdfsdf" }


	/* pseudo code

	constructor
	get disp recipe
	get pump recipe
	get name
	get technique

	*/

};

#endif