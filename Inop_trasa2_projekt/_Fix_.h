/*
Opis: Klasa reprezentuj�ca Fix, czyli punkt obszaru, przez kt�ry przelatuje samolot.

Zawiera nast�puj�ce zmienne definiuj�ce Fix:
- d�ugo�� geograficzna fixu
- szeroko�� geografizna fixu
- wysoko�� - flight level (wysoko�� 1)
- wysoko�� - flight level (wysoko�� 2)
- czas - czas, w kt�rym samolot znajduje si� nad danym fixem

Zawiera nast�puj�ce metody:
- konstruktory i destruktor
- settery, ustawiaj�ce warto�ci powy�szych zmiennych
- gettery, zwracaj�ce warto�ci powy�szych zmiennych
- ustaw_wartosci() - ustawia wartosci wszystkich zmiennych jednocze�nie

Autor: Mateusz Wasiak, Marcin Ludwisiak, Jakub Zi�ba, Martyna R�j, Damian Goss
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
	// Konstruktor parametrowy zapewniaj�cy ustawienie parametrow na odpowiednie warto�ci:
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