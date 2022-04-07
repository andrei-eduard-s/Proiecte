#pragma once
#include <string>
class Aliment {
public:
	inline void setName(std::string);
	inline std::string getName();
	inline void setEnergy_value(double);
	inline double getEnergy_value();
	inline void setFats(double);
	inline double getFats();
	inline void setCarbohydrates(double);
	inline double getCarbohydrates();
	inline void setFibre(double);
	inline double getFibre();
	inline void setProteins(double);
	inline double getProteins();
	inline void setSalt_value(double);
	inline double getSalt_value();
	inline void setQuantity(double);
	inline double getQuantity();
private:
	std::string name;
	double energy_value;
	double fats;
	double carbohydrates;
	double fibre;
	double proteins;
	double salt_value;
	double quantity;
};