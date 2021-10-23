#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
	Type stop_flag;
	getStop(stop_flag);  

	Polynomial<Type> L1(stop_flag), L2(stop_flag), L3(stop_flag);

    L1.getPoly(); 
    L2.getPoly(); 

    L3.addPoly(L1,L2); //L1 = L2 +L3
    L3.dispPloy(); 

	return 0;
}
