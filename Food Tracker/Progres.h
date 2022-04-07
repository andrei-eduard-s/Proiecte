#pragma once
#include <cstring>
#include <iostream>
class Progres {
public:
	const char progres_delim[4] = { ",><" };

	int calorii;
	int proteine;
	int carbo;
	int grasime;

	int transform(char*& token, char*& next_token)
	{
		int a = atoi(token);
		token = strtok_s(NULL, progres_delim, &next_token);
		return a;
	}
	Progres() 
	{
		calorii = 0;
		proteine = 0;
		carbo = 0;
		grasime = 0;
	}

	Progres(char line[])
	{
		char* next_token = NULL;
		char* token = strtok_s(line, progres_delim, &next_token);

		calorii = transform(token, next_token);
		proteine = transform(token, next_token);
		carbo = transform(token, next_token);
		grasime = transform(token, next_token);
	}

	Progres operator%(int p)
	{
		Progres k;

		k.calorii = calorii * p / 100;
		k.proteine = proteine * p / 100;
		k.carbo = carbo * p / 100;
		k.grasime = grasime * p / 100;

		return k;
	}

	Progres operator+(Progres p)
	{
		Progres k;

		k.calorii = calorii + p.calorii;
		k.proteine = proteine + p.proteine;
		k.carbo = carbo + p.carbo;
		k.grasime = grasime + p.grasime;

		return k;
	}
};