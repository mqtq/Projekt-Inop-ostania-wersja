/*
Opis: Klasa reprezentuj¹ca Samolot, kotry przelatuje przez Fixy

Zawiera nastêpuj¹ce zmienne definiuj¹ce Samolot:
- identyfikator lotu
- unikalny ID lotu
- nazwê lotniska startowego
- nazwê lotniska koñcowego
- zbiór(tablicê) fixów, przez które przelatuje samolot

Zawiera nastêpuj¹ce metody:
- konstruktory i destruktor
- settery, ustawiaj¹ce wartoœci powy¿szych zmiennych
- gettery, zwracaj¹ce wartoœci powy¿szych zmiennych
- add_punkt_przelotu() - dodaje kolejny punkt(fix), przez który przelatuje samolot
- czy_przelatuje_nad_obszarem() - sprawdza, czy samolot przelatuje nad konkretnym fixem

Autor: Mateusz Wasiak, Marcin Ludwisiak, Jakub Ziêba, Martyna Rój, Damian Goss
Data utworzenia: 19.04.2018r.
Modyfikacje pliku:


------------------------------------------------------------
ToDo:

1. Implementacja cia³a funkcji:
- void dodaj_punkt_przelotu(_Fix_);
- bool czy_przelatuje_nad_fixem(double _dlugosc_geograficzna, double _szerokosc_geograficzna, double _promien, int &_czas);
2. Czy tworzymy konstruktor parametrowy?
3. Vectory
- w konstruktorze domyslnym
- ew. w konstruktorze parametrowym

*/

#ifndef _Samolot_h_
#define _Samolot_h_

#include "_Fix_.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class _Samolot_
{
public:
	_Samolot_();
	_Samolot_(const _Samolot_ &copy);	// konstruktor kopiujacy
	~_Samolot_();

	// sety:
	void set_unikalny_ID_lotu(double _unikalny_ID_lotu);		//ustawia parametr unikalny_ID_lotu
	void set_nazwa_lotniska_startowego(string _nazwa_lotniska_starowego);	//ustawia nazwe_lotniska_startowego
	void set_nazwa_lotniska_koncowego(string _nazwa_lotniska_koncowego);	//ustawia nazwe_lotniska_startowego
	void set_identyfikator_lotu(string _identyfikator_lotu);	//ustawia parametr identyfikator_lotu
	void set_unikalny_ID_lotu(string _unikalny_ID_lotu);		//ustawia parametr unikalny_ID_lotu


																			// gety:
	string get_identyfikator_lotu();	//zwraca parametr identyfikator_lotu
	double get_unikalny_ID_lotu();	//zwraca parametr unikalny_ID_lotu
	string get_nazwa_lotniska_starowego();	//zwraca nazwe_lotniska_startowego
	string get_nazwa_lotniska_koncowego();	//zwraca nazwe_lotniska_koncowego

	void dodaj_punkt_przelotu(_Fix_);		//dodaje kolejny punkt przelotu								
											//sprawdza, czy samolot przelatuje nad obszarem i zwraca godzinê wejœcia nad obszar:
	bool czy_przelatuje_nad_fixem(double _dlugosc_geograficzna, double _szerokosc_geograficzna, double _promien, int &_czas); // vector ????????????

	_Samolot_ & operator = (_Samolot_ const& zmienna);	// przeladowany operator przyrownania

private:
	string identyfikator_lotu;
	double unikalny_ID_lotu;
	string nazwa_lotniska_startowego;
	string nazwa_lotniska_koncowego;
	vector <_Fix_> punkty_przelotu;
};

#endif
