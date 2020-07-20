// Material.h

#if 0
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// headers
#include <string>
using namespace std;

// Note: 하드웨어 관련 코드 없음
class Material {
private:
	string name;
	int pos_x, pos_y;
	double remain;
	int rgb[3];
public:
	Material(string aname, int ax, int ay, double a_remain, int ar, int ag, int ab);
	string get_name() { return name; }
	int get_pos_x() { return pos_x; }
	int get_pos_y() { return pos_y; }
	double get_amount() { return remain; }
	void set_amount(double a_remain) { remain = a_remain; }
	int* get_rgb() { return rgb; }
};

inline Material::Material(string aname, int ax, int ay, double a_remain, int ar, int ag, int ab) {
	name = aname;
	pos_x = ax;
	pos_y = ay;
	remain = a_remain;
	rgb[0] = ar, rgb[1] = ag, rgb[2] = ab;
}

class DispenserMaterial :
	public Material
{
public:
	DispenserMaterial(string aname, int ax, int ay, double a_remain, int ar, int ag, int ab)
		: Material(aname, ax, ay, a_remain, ar, ag, ab) { }

};

class PumpMaterial :
	public Material
{
public:
	PumpMaterial(string aname, int ax, int ay, double a_remain, int ar, int ag, int ab)
		: Material(aname, ax, ay, a_remain, ar, ag, ab) { }

};


#endif


