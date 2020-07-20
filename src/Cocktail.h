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


	/* pseudo code

	constructor
	get disp recipe
	get pump recipe
	get name
	get technique

	*/

};

#endif