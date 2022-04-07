#pragma once
#include<vector>
#include "user.h"
#include "Meal.h"
#include "Aliment.h"

class FoodTracker
{
public: 
	user acc;
	vector<Aliment> va; //vector aliment
	vector<Meal> vm; //vector meal

};