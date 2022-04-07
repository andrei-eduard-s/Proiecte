#include <iostream>
#include "Meal.h"
using namespace std;

inline void Meal::setData(std::string s)
{
	data = s;
}
std::string Meal::getData()
{
	return data;
}