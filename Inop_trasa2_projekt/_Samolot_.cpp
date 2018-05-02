#include "_Samolot_.h"


_Samolot_::_Samolot_()
{
	this->unikalny_ID_lotu = 0;
	this->nazwa_lotniska_startowego = "lotnisko startowe";
	this->nazwa_lotniska_koncowego = "lotnisko koncowe";
}

_Samolot_::_Samolot_(const _Samolot_ & copy)
{
	this->identyfikator_lotu = copy.identyfikator_lotu;
	this->nazwa_lotniska_koncowego = copy.nazwa_lotniska_koncowego;
	this->nazwa_lotniska_startowego = copy.nazwa_lotniska_startowego;
	this->unikalny_ID_lotu = copy.unikalny_ID_lotu;
	this->punkty_przelotu = copy.punkty_przelotu;
}


_Samolot_::~_Samolot_()
{
}


void _Samolot_::set_unikalny_ID_lotu(double _unikalny_ID_lotu)
{
	this->unikalny_ID_lotu = _unikalny_ID_lotu;
}

void _Samolot_::set_nazwa_lotniska_startowego(string _nazwa_lotniska_starowego)
{
	this->nazwa_lotniska_startowego = _nazwa_lotniska_starowego;
}

void _Samolot_::set_nazwa_lotniska_koncowego(string _nazwa_lotniska_koncowego)
{
	this->nazwa_lotniska_koncowego = _nazwa_lotniska_koncowego;
}

void _Samolot_::set_identyfikator_lotu(string _identyfikator_lotu)
{
	this->identyfikator_lotu = _identyfikator_lotu;
}

void _Samolot_::set_unikalny_ID_lotu(string _unikalny_ID_lotu)
{
	stringstream tmp;
	tmp << _unikalny_ID_lotu;
	tmp >> unikalny_ID_lotu;
}

string _Samolot_::get_identyfikator_lotu()
{
	return identyfikator_lotu;
}

double _Samolot_::get_unikalny_ID_lotu()
{
	return unikalny_ID_lotu;
}

string _Samolot_::get_nazwa_lotniska_starowego()
{
	return nazwa_lotniska_startowego;
}

string _Samolot_::get_nazwa_lotniska_koncowego()
{
	return nazwa_lotniska_koncowego;
}

void _Samolot_::dodaj_punkt_przelotu(_Fix_)
{
}

bool _Samolot_::czy_przelatuje_nad_fixem(double _dlugosc_geograficzna, double _szerokosc_geograficzna, double _promien, int & _czas)
{
	return false;
}

_Samolot_ & _Samolot_::operator=(_Samolot_ const & zmienna)
{
	this->identyfikator_lotu = zmienna.identyfikator_lotu;
	this->unikalny_ID_lotu = zmienna.unikalny_ID_lotu;
	this->nazwa_lotniska_startowego = zmienna.nazwa_lotniska_startowego;
	this->nazwa_lotniska_koncowego = zmienna.nazwa_lotniska_koncowego;
	this->punkty_przelotu = zmienna.punkty_przelotu;
	return *this;
}
