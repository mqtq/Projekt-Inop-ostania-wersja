/*
Opis: Klasa reprezentuj�ca Teren, czyli obszar, nad kt�rym przelatuj� wszystkie samoloty

Zawiera nast�puj�ce zmienne definiuj�ce Teren:
- wspolrzedna_x_punktu , wspolrzedna_y_punktu - wsp�rz�dne punktu,
kt�ry bedzie �rodkiem okr�gu, w kt�rym nast�pi
sprawdzenie ilo�ci samolot�w
- promie� punktu
- dzien - dzie�, w kt�rym w zdanym obszarze znaduje si� najmniej samolot�w
- godzina - godzina, w kt�rej w okre�lonym dniu w zadanym obszarze znajduje si� najmniej samolot�w
- najmniejsza_ilosc_w_danym_dniu - najmniejsza ilo�� samolot�w w danym dniu, w danej godzinie i zadanym obszarze
- zbi�r(tablic�) dni
- zbi�r(tablic�) godzin
- zbi�r(tablic�) Samolot�w, kt�re przelatuj� nad obszarem

Zawiera nast�puj�ce metody:
- konstruktory i destruktor
- settery, ustawiaj�ce warto�ci powy�szych zmiennych
- gettery, zwracaj�ce warto�ci powy�szych zmiennych
- dodaj_lot() - dodaje pojedynczy lot
- wczytaj_plik() - umo�liwia sczytanie danych wej�ciowych z pliku
- licz_ilosc_samolotow_nad_obszarem() - liczy ilosc samolot�w przelatuj�cych nad obszarem


Autor: Mateusz Wasiak, Marcin Ludwisiak, Jakub Zi�ba, Martyna R�j, Damian Goss
Data utworzenia: 19.04.2018r.
Modyfikacje pliku:


------------------------------------------------------------
ToDo:

1. Implementacja cia�a funkcji:
- void set_obszar(double _wspolrzedna_x_punktu, double _wspolrzedna_y_punktu, double _promien_punktu);
- void set_obszar(string _nazwa_pliku);
- void dodaj_lot(_Samolot_);
- void wczytaj_plik(string _nazwa_pliku);
- void licz_ilosc_samolotow_nad_obszarem();
2. Czy tworzymy konstruktor parametrowy?
3. Vectory
- w konstruktorze domyslnym
- ew. w konstruktorze parametrowym

*/

#ifndef _Teren_h_
#define _Teren_h_

#include "_Fix_.h"
#include "_Samolot_.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class _Teren_
{
public:
	_Teren_();
	_Teren_(const _Teren_ &copy);	// konstruktor kopiujacy
	~_Teren_();

	// sety:
	void set_wspolrzedna_x_punktu(double _wspolrzedna_x_punktu);
	void set_wspolrzedna_y_punktu(double _wspolrzedna_y_punktu);
	void set_promien_okregu(double _promien_okregu);
	void set_dzien(int _dzien);
	void set_godzina(int _godzina);
	void set_najmniejsza_ilosc_w_danym_dniu(int _najmniejsza_ilosc_w_danym_dniu);

	void set_obszar(double _wspolrzedna_x_punktu, double _wspolrzedna_y_punktu, double _promien_okregu);	//ustawia obszar wed�ug podanych wsp�rz�dnych
	void set_obszar(string _nazwa_pliku);		//ustawia obszar z pliku

												// gety:
	double get_wspolrzedna_x_punktu();
	double get_wspolrzedna_y_punktu();
	double get_promien_okregu();
	int get_dzien();
	int get_godzina();
	int get_najmniejsza_ilosc_w_danym_dniu();


	void dodaj_lot(_Samolot_);	//dodaje pojedy�czy lot
	void wczytaj_plik(string _nazwa_pliku);	//wczytuje plik

	void licz_ilosc_samolotow_nad_obszarem();	//liczy ilosc samolot�w przelatuj�cych nad obszarem

	_Teren_ & operator = (_Teren_ const& zmienna);	// przeladowany operator przyrownania

	
	_Teren_ & operator<< (string  wspolrzedna_x_punktu_s); //rzutowania ze stringow na rozne typy

private:
	double wspolrzedna_x_punktu;
	double wspolrzedna_y_punktu;
	double promien_okregu; // promien
	int dzien;
	int godzina;
	int najmniejsza_ilosc_w_danym_dniu;
	vector <int> dni;
	vector <int> godziny;
	vector <_Samolot_> loty_z_danego_dnia;
};

#endif