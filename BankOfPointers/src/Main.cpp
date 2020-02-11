// INCLUDES.
#include<iostream>
#include<ctime>
#include<cstdlib>
#include "../Bank.h"

int main()
{
	static bool seeded = false;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = true;
	}

	Bank bankOfAbertay;

	return 0;
}