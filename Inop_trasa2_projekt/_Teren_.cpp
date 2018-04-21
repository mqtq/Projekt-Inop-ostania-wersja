#include "_Teren_.h"


_Teren_::_Teren_()
{
	this->wspolrzedna_x_punktu = 0.0;
	this->wspolrzedna_y_punktu = 0.0;
	this->promien_okregu = 0.0;
	this->dzien = 0;
	this->godzina = 0;
	this->najmniejsza_ilosc_w_danym_dniu = 0;
}

_Teren_::_Teren_(const _Teren_ & copy)
{
	this->wspolrzedna_x_punktu = copy.wspolrzedna_x_punktu;
	this->wspolrzedna_y_punktu = copy.wspolrzedna_y_punktu;
	this->promien_okregu = copy.promien_okregu;
	this->dzien = copy.dzien;
	this->godzina = copy.godzina;
	this->najmniejsza_ilosc_w_danym_dniu = copy.najmniejsza_ilosc_w_danym_dniu;
	this->dni = copy.dni;
	this->godziny = copy.godziny;
	this->loty_z_danego_dnia = copy.loty_z_danego_dnia;
}


_Teren_::~_Teren_()
{
}

void _Teren_::set_wspolrzedna_x_punktu(double _wspolrzedna_x_punktu)
{
	this->wspolrzedna_x_punktu = _wspolrzedna_x_punktu;
}

void _Teren_::set_wspolrzedna_y_punktu(double _wspolrzedna_y_punktu)
{
	this->wspolrzedna_y_punktu = _wspolrzedna_y_punktu;
}

void _Teren_::set_promien_okregu(double _promien_okregu)
{
	this->promien_okregu = _promien_okregu;
}

void _Teren_::set_dzien(int _dzien)
{
	this->dzien = _dzien;
}

void _Teren_::set_godzina(int _godzina)
{
	this->godzina = _godzina;
}

void _Teren_::set_najmniejsza_ilosc_w_danym_dniu(int _najmniejsza_ilosc_w_danym_dniu)
{
	this->najmniejsza_ilosc_w_danym_dniu = _najmniejsza_ilosc_w_danym_dniu;
}

void _Teren_::set_obszar(double _wspolrzedna_x_punktu, double _wspolrzedna_y_punktu, double _promien_okregu)
{
}

void _Teren_::set_obszar(string _nazwa_pliku)
{
}

double _Teren_::get_wspolrzedna_x_punktu()
{
	return wspolrzedna_x_punktu;
}

double _Teren_::get_wspolrzedna_y_punktu()
{
	return wspolrzedna_y_punktu;
}

double _Teren_::get_promien_okregu()
{
	return promien_okregu;
}

int _Teren_::get_dzien()
{
	return dzien;
}

int _Teren_::get_godzina()
{
	return godzina;
}

int _Teren_::get_najmniejsza_ilosc_w_danym_dniu()
{
	return najmniejsza_ilosc_w_danym_dniu;
}

void _Teren_::dodaj_lot(_Samolot_)
{
}

void _Teren_::wczytaj_plik(string _nazwa_pliku)
{
}

void _Teren_::licz_ilosc_samolotow_nad_obszarem()
{
}

_Teren_ & _Teren_::operator=(_Teren_ const & zmienna)
{
	this->wspolrzedna_x_punktu = zmienna.wspolrzedna_x_punktu;
	this->wspolrzedna_y_punktu = zmienna.wspolrzedna_y_punktu;
	this->promien_okregu = zmienna.promien_okregu;
	this->dzien = zmienna.dzien;
	this->godzina = zmienna.godzina;
	this->najmniejsza_ilosc_w_danym_dniu = zmienna.najmniejsza_ilosc_w_danym_dniu;
	this->dni = zmienna.dni;
	this->godziny = zmienna.godziny;
	this->loty_z_danego_dnia = zmienna.loty_z_danego_dnia;
	return *this;
}
