#pragma once
#include "Aliment.h"
class Produs {
public:
	inline void setQuantity(double);
	inline double getQuantity();
	inline void setPortion(int);
	inline int getPortion();
private:
	Aliment aliment;
	double quantity;
	int portion;
};