#include <iostream>
using namespace std;
#include "user.h"

/*user::user(char num, int varst, bool sx, double inalt, double greut, double greut_d)
{
	setUser();
}
user::setUser(char num, int varst, bool sx, double inalt, double greut, double greut_d)
{

}*/
inline void user::setName(std::string n)
{
	name = n;
}
inline string user::getName()
{
	return name;
}
inline void user::setAge(int a)
{
	age = a;
}
inline int user::getAge()
{
	return age;
}
inline void user::setSex(bool s)
{
	sex = s;
}
inline bool user::getSex()
{
	return sex;
}
inline void user::setHeight(double h)
{
	height = h;
}
inline double user::getHeight()
{
	return height;
}
inline void user::setWeight(double w)
{
	weight = w;
}
inline double user::getWeight()
{
	return weight;
}
inline void user::setWeight_goal(double wg)
{
	weight_goal = wg;
}
inline void user::setBMI()
{
	double x;
	x = weight / (height * height);
	if (x <= 18)
		user_BMI = under;
	else
		if (x <= 24)
			user_BMI = average;
		else
			if (x <= 29)
				user_BMI = over;
			else
				if (x <= 39)
					user_BMI = obese;
				else
						user_BMI = obese_extreme;
}
inline int user::getBMI()
{
	return user_BMI;
}
inline void user::setActivity(activity act)
{
	user_activity = act;
}
inline int user::getActivity()
{
	return user_activity;
}
inline void user::setGoal(goal g)
{
	user_goal = g;
}
inline void user::setMetabolism(activity y, BMI z)
{
	if (z == under)
		if (y == sedentary || y == light || y == moderate)
			user_metabolism = fast;
		else
			user_metabolism = metabolism::normal;
	else
		if (z == average)
			if (y == sedentary || y == light)
				user_metabolism = fast;
			else
				user_metabolism = metabolism::normal;
		else
			if (z == over)
				if (y == intense)
					user_metabolism = slow;
				else
					user_metabolism = metabolism::normal;
			else
				if (z == obese)
					if (y == sedentary)
						user_metabolism = metabolism::normal;
					else
						user_metabolism = slow;
				else
					user_metabolism = slow;
}
inline int user::getMetabolism()
{
	return user_metabolism;
}