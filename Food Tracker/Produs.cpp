#include <iostream>
using namespace std;
#include "Aliment.h"
#include "Produs.h"
inline void Produs::setQuantity(double qty)
{
	quantity = qty;
}
inline double Produs::getQuantity()
{
	return quantity;
}
inline void Produs::setPortion(int por)
{
	portion = por;
}
inline int Produs::getPortion()
{
	return portion;
}
