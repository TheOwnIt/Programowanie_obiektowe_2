#include <iostream>
#include <string>
#include <tr1/unordered_map>
#include "towar.h"
#include "transport.h"
#include "kontener.h"
#include "magazyn.h"
#include <cstdlib>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
using namespace std::tr1;

int main() {
	// definiuje rodzaj transportu i jego ladownosc
	transport ship;
	ship.ladownosc = 90;
	transport train;
	train.ladownosc = 20;
	transport truck;
	truck.ladownosc = 1;
	
	//1 - dodaje rodzaj towaru
	towar czesci_elektroniczne;
	towar telefony;
	towar buty;
	towar odziez;
	
	//2 - dodaje kontenery
	kontener kontener;
	kontener.ilosc = 40;
	cout<<"Ilosc kontenerow: "<<kontener.ilosc<<endl;
	
	//3	- dodaje ilosci transportowe
	ship.ilosc = 1;
	train.ilosc = 2;
	truck.ilosc = 10;
	
	//4 - definiuje magazyny i zeruje stany

	magazyn gdansk;
	magazyn wroclaw;
	magazyn krakow;
	magazyn poznan;
	gdansk.ilosc_kontener = 0;
	wroclaw.ilosc_kontener= 0;
	krakow.ilosc_kontener = 0;
	poznan.ilosc_kontener = 0;
	//5 - ilosci kontenerow dla poszczegolnych czesci
	czesci_elektroniczne.ilosc = 10;
	telefony.ilosc = 20;
	buty.ilosc = 5;
	odziez.ilosc = 5;
	
	//6
	cout<<"Zadanie 6"<<endl;
	transport NJ_GD;
	ship.zajetosc = czesci_elektroniczne.ilosc + telefony.ilosc + buty.ilosc + odziez.ilosc;
	cout<<"Laduje Statek - Ilosc kontenerow na statku: "<< ship.zajetosc <<endl;
	
	int NJ_GD_miejsce = ship.zaladuj(ship.zajetosc, ship.ladownosc);
	
	if(NJ_GD_miejsce >= 0){
		cout << "Towar zaladowany. Zostalo miejsca na "<<NJ_GD_miejsce<<" kontenerow."<<endl;
	}else{
		cout <<"Towar nie wejdzie na obiekt"<<endl;
	}
	cout << "Ilosc kontenerow na statku: "<<ship.zajetosc<<endl;
	//7
	cout << "Rozladowywuje statek w Gdansku."<<endl;
	gdansk.ilosc_kontener = ship.zajetosc;
	ship.zajetosc = 0;
	cout << "Ilosc kontenerow na statku: "<<ship.zajetosc<<endl;
	cout << "Ilosc kontenerow w Gdansku: "<<gdansk.ilosc_kontener<<endl;
	
	ship.kursy++;
	
	cout<<"Nacisnik klawisz aby przejsc do nastepnego etapu!"<<endl;
	system("pause");
	system("CLS");
	//8
	
	cout<<"Zaczynam transport do Wroclawia:"<<endl;
	for(int i=0; i<=gdansk.ilosc_kontener/train.ladownosc;i++){
		cout<<"Pociag nr."<<i+1<<endl;
		gdansk.ilosc_kontener = gdansk.ilosc_kontener - train.ladownosc;
		cout << "Ilosc kontenerow w Gdansku: "<<gdansk.ilosc_kontener<<endl;
		train.zajetosc = train.ladownosc;
		wroclaw.ilosc_kontener = wroclaw.ilosc_kontener+ train.zajetosc;
		cout << "Ilosc kontenerow w Wroclawiu: "<<wroclaw.ilosc_kontener<<endl;
		train.zajetosc = 0;
		train.kursy++;
	}
	cout<<"Nacisnik klawisz aby przejsc do nastepnego etapu!"<<endl;
	system("pause");
	system("CLS");
	//9
		cout <<"Zaczynam tranport Buty i Odziez do Wroclawia:"<<endl;
	int buty_odziez = buty.ilosc + odziez.ilosc;
	for(int i=1;i<=buty_odziez/truck.ladownosc;i++){
		cout<<"Ciezarowka nr."<<i<<endl;
		wroclaw.ilosc_kontener = wroclaw.ilosc_kontener - truck.ladownosc;
		cout << "Ilosc kontenerow w Wroclawiu: "<<wroclaw.ilosc_kontener<<endl;
		truck.zajetosc = truck.ladownosc;
		poznan.ilosc_kontener = truck.zajetosc;
		cout << "Ilosc kontenerow w Poznaniu: "<<poznan.ilosc_kontener<<endl;
		truck.zajetosc = 0;
		truck.kursy++;
	}
	cout<<"Nacisnik klawisz aby przejsc do nastepnego etapu!"<<endl;
	system("pause");
	system("CLS");
	//10
			cout <<"Zaczynam tranport elektroniki do Krakowa:"<<endl;
	int elektronika = czesci_elektroniczne.ilosc + telefony.ilosc;
	for(int i=1;i<=elektronika/truck.ladownosc;i++){
		cout<<"Ciezarowka nr."<<i<<endl;
		wroclaw.ilosc_kontener = wroclaw.ilosc_kontener - truck.ladownosc;
		cout << "Ilosc kontenerow w Wroclawiu: "<<wroclaw.ilosc_kontener<<endl;
		truck.zajetosc = truck.ladownosc;
		krakow.ilosc_kontener = krakow.ilosc_kontener + truck.zajetosc;
		cout << "Ilosc kontenerow w Krakowie: "<<krakow.ilosc_kontener<<endl;
		truck.zajetosc = 0;
		truck.kursy++;
	}
	cout<<"Nacisnik klawisz aby przejsc do nastepnego etapu!"<<endl;
	system("pause");
	system("CLS");
	//11
	cout<<"Ilosc kursow statku: "<<ship.kursy<<endl;
	cout<<"Ilosc kursow pociag: "<<train.kursy<<endl;
	cout<<"Ilosc kursow ciezarowka: "<<truck.kursy<<endl;
	cout<<"Kursy lacznie: "<<ship.kursy + train.kursy + truck.kursy<<endl;
	
	return 0;
	
}
