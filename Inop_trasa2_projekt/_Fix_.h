/*
Opis: Klasa reprezentuj¹ca Fix, czyli punkt obszaru, przez który przelatuje samolot.

Zawiera nastêpuj¹ce zmienne definiuj¹ce Fix:
- d³ugoœæ geograficzna fixu
- szerokoœæ geografizna fixu
- wysokoœæ - flight level (wysokoœæ 1)
- wysokoœæ - flight level (wysokoœæ 2)
- czas - czas, w którym samolot znajduje siê nad danym fixem

Zawiera nastêpuj¹ce metody:
- konstruktory i destruktor
- settery, ustawiaj¹ce wartoœci powy¿szych zmiennych
- gettery, zwracaj¹ce wartoœci powy¿szych zmiennych
- ustaw_wartosci() - ustawia wartosci wszystkich zmiennych jednoczeœnie

Autor: Mateusz Wasiak, Marcin Ludwisiak, Jakub Ziêba, Martyna Rój, Damian Goss
Data utworzenia: 19.04.2018r.
Modyfikacje pliku:

------------------------------------------------------------
ToDo:


*/

#ifndef _Fix_h_
#define _Fix_h_

class _Fix_
{
public:
	_Fix_();
	// Konstruktor parametrowy zapewniaj¹cy ustawienie parametrow na odpowiednie wartoœci:
	_Fix_(double _dlugosc_geograficzna, double _szerokosc_geograficzna, double _wysokosc1, double _wysokosc2, double _typ, int _czas);
	_Fix_(const _Fix_ &copy);	// konstruktor kopiujacy
	~_Fix_();

	// sety:
	void set_dlugosc_geograficzna(double _dlugosc_geograficzna);		// ustawia parametr wspolrzedzna_N
	void set_szerokosc_geograficzna(double _szerokosc_geograficzna);	// ustawia parametr wspolrzedzna_W
	void set_wysokosc1(double _wysokosc1);	 // ustawia parametr wysokosc1
	void set_wysokosc2(double _wysokosc2);	// ustawia parametr wysokosc2
	void set_typ(double _typ);	// ustawia parametr typ
	void set_czas(int _czas);	// ustawia parametr czas

								// gety:
	double get_dlugosc_geograficzna();	// zwraca parametr wspolrzedzna_N
	double get_szerokosc_geograficzna();	// zwraca parametr wspolrzedzna_W
	double get_wysokosc1();	// zwraca parametr wysokosc1
	double get_wysokosc2();	// zwraca parametr wysokosc2
	double get_typ();	// zwraca parametr typ
	double get_czas();	// zwraca parametr czas

						// Ustawia wszystkie parametry w klasie:
	void set_wartosci(double _dlugosc_geograficzna, double _szerokosc_geograficzna, double _wysokosc1, double _wysokosc2, double _typ, int _czas);

	_Fix_ & operator = (_Fix_ const& zmienna);	// przeladowany operator przyrownania

private:
	double dlugosc_geograficzna;
	double szerokosc_geograficzna;
	double wysokosc1;
	double wysokosc2;
	double typ;
	int czas;
};

#endif