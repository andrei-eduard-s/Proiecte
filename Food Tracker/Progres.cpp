#include <cstring>
#include <iostream>
#include "Progres.h"
//#include "Test.h"
using namespace std;
inline int foo(char*& token, char  delim[4], char*& next_token)
{
	int a = atoi(token);
	token = strtok_s(NULL, delim, &next_token);
	return a;
}
inline int mainProgres()
{
	char str[] = "<2400,2000,100,300>";

	char delim[] = ",><";

	cout << "The tokens are:" << endl;

	char* next_token = NULL;
	char* token = strtok_s(str, delim, &next_token);

	int calorie = foo(token, delim, next_token);
	int carbohidrati = foo(token, delim, next_token);
	int grasimi = foo(token, delim, next_token);
	int proteine = foo(token, delim, next_token);

	return 0;
}