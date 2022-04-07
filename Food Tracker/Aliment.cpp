#include <iostream>
using namespace std;
#include "Aliment.h"
inline void Aliment::setName(std::string n)
{
	name = n;
}
inline string Aliment::getName()
{
	return name;
}
inline void Aliment::setEnergy_value(double ev)
{
	energy_value = ev;
}
inline double Aliment::getEnergy_value()
{
	return energy_value;
}
inline void Aliment::setFats(double fat)
{
	fats = fat;
}
inline double Aliment::getFats()
{
	return fats;
}
inline void Aliment::setCarbohydrates(double ch)
{
	carbohydrates = ch;
}
inline double Aliment::getCarbohydrates()
{
	return carbohydrates;
}
inline void Aliment::setFibre(double fibr)
{
	fibre = fibr;
}
inline double Aliment::getFibre()
{
	return fibre;
}
inline void Aliment::setProteins(double prt)
{
	proteins = prt;
}
inline double Aliment::getProteins()
{
	return proteins;
}
inline void Aliment::setSalt_value(double sa_v)
{
	salt_value = sa_v;
}
inline double Aliment::getSalt_value()
{
	return salt_value;
}
inline void Aliment::setQuantity(double qty)
{
	quantity = qty;
}
inline double Aliment::getQuantity()
{
	return quantity;
}