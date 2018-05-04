/*
Opis: Klasa reprezentuj¹ca Teren, czyli obszar, nad którym przelatuj¹ wszystkie samoloty

Zawiera nastêpuj¹ce zmienne definiuj¹ce Teren:
- wspolrzedna_x_punktu , wspolrzedna_y_punktu - wspó³rzêdne punktu,
który bedzie œrodkiem okrêgu, w którym nast¹pi
sprawdzenie iloœci samolotów
- promieñ punktu
- dzien - dzieñ, w którym w zdanym obszarze znaduje siê najmniej samolotów
- godzina - godzina, w której w okreœlonym dniu w zadanym obszarze znajduje siê najmniej samolotów
- najmniejsza_ilosc_w_danym_dniu - najmniejsza iloœæ samolotów w danym dniu, w danej godzinie i zadanym obszarze
- zbiór(tablicê) dni
- zbiór(tablicê) godzin
- zbiór(tablicê) Samolotów, które przelatuj¹ nad obszarem

Zawiera nastêpuj¹ce metody:
- konstruktory i destruktor
- settery, ustawiaj¹ce wartoœci powy¿szych zmiennych
- gettery, zwracaj¹ce wartoœci powy¿szych zmiennych
- dodaj_lot() - dodaje pojedynczy lot
- wczytaj_plik() - umo¿liwia sczytanie danych wejœciowych z pliku
- licz_ilosc_samolotow_nad_obszarem() - liczy ilosc samolotów przelatuj¹cych nad obszarem


Autor: Mateusz Wasiak, Marcin Ludwisiak, Jakub Ziêba, Martyna Rój, Damian Goss
Data utworzenia: 19.04.2018r.
Modyfikacje pliku:


------------------------------------------------------------
ToDo:

1. Implementacja cia³a funkcji:
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

	void set_obszar(double _wspolrzedna_x_punktu, double _wspolrzedna_y_punktu, double _promien_okregu);	//ustawia obszar wed³ug podanych wspó³rzêdnych
	void set_obszar(string _nazwa_pliku);		//ustawia obszar z pliku

												// gety:
	double get_wspolrzedna_x_punktu();
	double get_wspolrzedna_y_punktu();
	double get_promien_okregu();
	int get_dzien();
	int get_godzina();
	int get_najmniejsza_ilosc_w_danym_dniu();


	void dodaj_lot(_Samolot_);	//dodaje pojedyñczy lot
	void wczytaj_plik(string _nazwa_pliku);	//wczytuje plik

	void licz_ilosc_samolotow_nad_obszarem();	//liczy ilosc samolotów przelatuj¹cych nad obszarem

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