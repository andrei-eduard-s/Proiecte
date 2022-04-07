#pragma once
#include "Progres.h"
#include "Produs.h"
#include <list>
class Menu {
public:
	
private:
	Progres p_expected;
	Progres p_real;
	std::list <Produs> suggested;
	std::list <Produs> consumed;
	//? vector in loc de list ?
};