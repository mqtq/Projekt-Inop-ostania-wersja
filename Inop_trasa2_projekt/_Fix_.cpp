#include "_Fix_.h"


_Fix_::_Fix_()
{
	this->dlugosc_geograficzna = 0;
	this->szerokosc_geograficzna = 0;
	this->wysokosc1 = 0;
	this->wysokosc2 = 0;
	this->typ = 0;
	this->czas = 0;
}


_Fix_::_Fix_(double _dlugosc_geograficzna, double _szerokosc_geograficzna, double _wysokosc1, double _wysokosc2, double _typ, int _czas)
// lista inicjalizayjna:
	: dlugosc_geograficzna(_dlugosc_geograficzna), szerokosc_geograficzna(_szerokosc_geograficzna), wysokosc1(_wysokosc1), wysokosc2(_wysokosc2),
	typ(_typ), czas(_czas)
{
}

_Fix_::_Fix_(const _Fix_ & copy)
{
	this->czas = copy.czas;
	this->dlugosc_geograficzna = copy.dlugosc_geograficzna;
	this->szerokosc_geograficzna = copy.szerokosc_geograficzna;
	this->typ = copy.typ;
	this->wysokosc1 = copy.wysokosc1;
	this->wysokosc2 = copy.wysokosc2;
}

_Fix_::~_Fix_()
{
}

void _Fix_::set_dlugosc_geograficzna(double _dlugosc_geograficzna)
{
	this->dlugosc_geograficzna = _dlugosc_geograficzna;
}

void _Fix_::set_szerokosc_geograficzna(double _szerokosc_geograficzna)
{
	this->szerokosc_geograficzna = _szerokosc_geograficzna;
}

void _Fix_::set_wysokosc1(double _wysokosc1)
{
	this->wysokosc1 = _wysokosc1;
}

void _Fix_::set_wysokosc2(double _wysokosc2)
{
	this->wysokosc2 = _wysokosc2;
}

void _Fix_::set_typ(double _typ)
{
	this->typ = _typ;
}

void _Fix_::set_czas(int _czas)
{
	this->czas = _czas;
}

void _Fix_::set_czas(string _czas)
{
	string tmp = _czas;
	while (tmp.find(':') != string::npos)
	{
		tmp.erase(tmp.find(':'), 1);
	}
	stringstream tmpstr;
	tmpstr << tmp;
	tmpstr >> this->czas;
}

void _Fix_::set_wysokosc1(string _wysokosc1)
{
	stringstream tmp;
	tmp << _wysokosc1;
	tmp >> wysokosc1;
}

void _Fix_::set_dlugosc_geograficzna(string _dlugosc_geograficzna)
{
	stringstream tmpstr;
	string tmp = _dlugosc_geograficzna;
	tmpstr << tmp;
	tmpstr >> dlugosc_geograficzna;
}

void _Fix_::set_szerokosc_geograficzna(string _szerokosc_geograficzna)
{
	stringstream tmpstr;
	string tmp = _szerokosc_geograficzna;
	tmpstr << tmp;
	tmpstr >> szerokosc_geograficzna;
}

void _Fix_::set_wysokosc2(string _wysokosc2)
{
	stringstream tmp;
	tmp << _wysokosc2;
	tmp >> wysokosc2;
}

double _Fix_::get_dlugosc_geograficzna()
{
	return dlugosc_geograficzna;
}

double _Fix_::get_szerokosc_geograficzna()
{
	return szerokosc_geograficzna;
}

double _Fix_::get_wysokosc1()
{
	return wysokosc1;
}

double _Fix_::get_wysokosc2()
{
	return wysokosc2;
}

double _Fix_::get_typ()
{
	return typ;
}

double _Fix_::get_czas()
{
	return czas;
}

void _Fix_::set_wartosci(double _dlugosc_geograficzna, double _szerokosc_geograficzna, double _wysokosc1, double _wysokosc2, double _typ, int _czas)
{
	this->dlugosc_geograficzna = _dlugosc_geograficzna;
	this->szerokosc_geograficzna = _szerokosc_geograficzna;
	this->wysokosc1 = _wysokosc1;
	this->wysokosc2 = _wysokosc2;
	this->typ = _typ;
	this->czas = _czas;
}

_Fix_ & _Fix_::operator = (_Fix_ const & zmienna)
{
	this->czas = zmienna.czas;
	this->dlugosc_geograficzna = zmienna.czas;
	this->szerokosc_geograficzna = zmienna.szerokosc_geograficzna;
	this->typ = zmienna.typ;
	this->wysokosc1 = zmienna.wysokosc1;
	this->wysokosc2 = zmienna.wysokosc2;
	return *this;
}



