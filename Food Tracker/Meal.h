#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "Progres.h"
class Meal {
public:
	inline void setData(std::string);
	inline std::string getData();
private:
	Menu breakfast;
	Menu lunch;
	Menu dinner;
	Menu snacks;
	Progres expected_total;
	Progres real_total;
	std::string data;
};