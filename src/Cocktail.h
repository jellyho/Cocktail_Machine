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
using namespace std;


class Cocktail
{
private:
	string name;
	map<DispenserMaterial, double> disp_recipe;
	map<PumpMaterial, double> pump_recipe;
	TechniqueMethod method;

	// 변환함수
	// map<Material, double> vector_to_map(vector<string> a_list);

public: // 벡터로 쭉 받은 다음 원소 끝날 때까지 map에 저장시켜.
	Cocktail(string a_name,
		TechniqueMethod a_method,
		map<DispenserMaterial, double> a_disp_recipe,
		map<PumpMaterial, double> a_pump_recipe)
	{
		name = a_name;
		method = a_method;
		disp_recipe = a_disp_recipe;
		pump_recipe = a_pump_recipe;
	}


	map<DispenserMaterial, double> get_disp_recipe() { return disp_recipe; }
	map<PumpMaterial, double> get_pump_recipe() { return pump_recipe; }
	string get_name() { return name; }
	TechniqueMethod get_craft_method() { return method; }

#endif

