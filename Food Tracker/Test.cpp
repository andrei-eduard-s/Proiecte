#include <cstring>
#include <iostream>
//#include "Test.h"
#include "Progres.h"

using namespace std;

ostream& operator<<(ostream& o, const Progres& p) {
	o << p.calorii << " " << p.carbo << " " << p.proteine << " " << p.grasime << std::endl;

	return o;
}

#define DEJUN_PROCENTAGE 20
#define PRANZ_PROCENTAGE 40
#define CINA_PROCENTAGE 30
#define GUSTARI_PROCENTAGE 10

int Testmain()
{
	char str[] = "<1986,65,205,50>";

	char str1[] = "<1986,65,205,50>";
	char str2[] = "<1986,65,205,50>";
	char str3[] = "<1986,65,205,50>";
	char str4[] = "<1986,65,205,50>";
	Progres total_exp(str);

	Progres dejun_exp = total_exp % DEJUN_PROCENTAGE;
	Progres pranz_exp = total_exp % PRANZ_PROCENTAGE;
	Progres cina_exp = total_exp % CINA_PROCENTAGE;
	Progres gustari_exp = total_exp % GUSTARI_PROCENTAGE;

	//strcpy_s(str, "<0,0,0,0>");
	//Progres p2(str);

	Progres dejun_real(str1);
	Progres pranz_real(str2);
	Progres cina_real(str3);
	Progres gustari_real(str4);

	Progres total_real = dejun_real + pranz_real + cina_real + gustari_real;

	cout << total_real;

	return 0;
}