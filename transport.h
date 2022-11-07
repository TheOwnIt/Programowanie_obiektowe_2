#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class transport
{

		public:
			int kursy=0;
			int ladownosc;
			int ilosc;
			int zajetosc;
			double zaladuj(int ilosc, int ladownosc);
			double rozladuj;
			double transportuj(int pojemnosc, int ilosc);
};

double transport::zaladuj(int ilosc, int ladownosc){
	return(ladownosc - ilosc);
	
	
}

double transport::transportuj(int pojemnosc, int ilosc){
	return(ilosc / pojemnosc);
	
	
	
}
