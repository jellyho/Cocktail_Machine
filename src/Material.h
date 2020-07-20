// Material.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


// Note: 하드웨어 관련 코드 없음
class Material {
private:
	String name;
	int pos_x = 0, pos_y = 0;
	int remain;
	int rgb[3];
	void num_to_pos(int a_num);

public:
	Material(String aname, int a_num, int a_remain, int ar, int ag, int ab);
	String get_name() { return name; }
	int get_pos_x() { return pos_x; }
	int get_pos_y() { return pos_y; }
	int get_amount() { return remain; }
	void set_amount(int a_remain) { remain = a_remain; }
	int* get_rgb() { return rgb; }
};


// 생성자 함수
inline Material::Material(String aname, int a_num, int a_remain, int ar, int ag, int ab) {
	name = aname;
	this->num_to_pos(a_num);
	remain = a_remain;
	rgb[0] = ar;  rgb[1] = ag;  rgb[2] = ab;
}


// 생성할 때 번호를 지정해 주면 알아서 위치를 지정해줌.
void Material::num_to_pos(int a_num) {
	switch (a_num)
	{
	case 1:
		pos_x = 1;  pos_y = 2;  break;
	case 2:
		pos_x = 1;  pos_y = 2;  break;
	case 3:
		pos_x = 1;  pos_y = 2;  break;
	case 4:
		pos_x = 1;  pos_y = 2;  break;
	case 5:
		pos_x = 1;  pos_y = 2;  break;
	case 6:
		pos_x = 1;  pos_y = 2;  break;
	case 7:
		pos_x = 1;  pos_y = 2;  break;
	case 8:
		pos_x = 1;  pos_y = 2;  break;
	case 9:
		pos_x = 1;  pos_y = 2;  break;
	case 10:
		pos_x = 1;  pos_y = 2;  break;
	case 11:
		pos_x = 1;  pos_y = 2;  break;
	case 12:
		pos_x = 1;  pos_y = 2;  break;
	default:
		break;
	}
}



// ******************** 위의 Material을 상속받은 클래스 두 개 *********************
class DispenserMaterial :
	public Material
{
public:
	DispenserMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
		: Material(aname, a_num, a_remain, ar, ag, ab) { }

};

class PumpMaterial :
	public Material
{
public:
	PumpMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
		: Material(aname, a_num, a_remain, ar, ag, ab) { }

};


#endif
