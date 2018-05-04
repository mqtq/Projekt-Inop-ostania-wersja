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
	fstream plik(_nazwa_pliku);
	if (!plik.good())
	{
		exit(442);									//blad odczytu pliku - kod 442
	}
	else
	{
		string id_samolotu;				//id samolotu
		string uid;						//id lotu 
		string date;					//data
		string ts;						//czas startu
		string src;							//???
		string attr;						//???
		string dep;						//kod lotniska (wylot)
		string tdep;					//godzina wylotu
		string arr;						//kod lotniska (ladowanie)
		string tarr;					//godzina ladowania
		string ac;							//???
		string acn;						//kod samolotu
		string eqp;						//kod wyposazenia lotu
		string act;							//???
		string ndep;					//liczba (umowna) odcinkow wznoszenia
		string narr;					//liczba (umowna) odcinkow ladowania
		string szerokosc_geograficzna;	//szerokosc geograficzna
		string dlugosc_geograficzna;	//dlugosc geograficzna
		string hh_mm_ss;				//godzina w fixie
		string wysokosc1;
		string wysokosc2;
		string nazwa_fix;
		string asp;						//predkosc wzgledem powietrza (w wezlach)
		string gsp;						//predkosc wzgledem ziemi
		string d;							//???
		string vr;							//???

		string tmp = "";
		stringstream tmpstr;

		_Samolot_ samolot;
		_Fix_ fix;

		while (!plik.eof())
		{
			tmpstr.str("");
			tmp = "";
			std::getline(plik, tmp);
			tmpstr << tmp;
			if (tmp[0] != ' ')
			{
				if (tmp[0] != ':')
				{
					//czytanie naglowka
					tmpstr >> id_samolotu;
					tmpstr >> uid;
					tmpstr >> date;
					//tmpstr >> ts;
					//tmpstr >> src;
					//tmpstr >> attr;
					//tmpstr >> dep;
					//tmpstr >> tdep;
					//tmpstr >> arr;
					//tmpstr >> tarr;
					//tmpstr >> ac;
					//tmpstr >> acn;
					//tmpstr >> eqp;
					//tmpstr >> act;
					//tmpstr >> ndep;
					//tmpstr >> narr;

					samolot.set_identyfikator_lotu(id_samolotu);
					samolot.set_unikalny_ID_lotu(uid);
					/*samolot.set_nazwa_lotniska_startowego(dep);
					samolot.set_nazwa_lotniska_koncowego(arr);*/

					bool czy_dalej_w_petli = true;
					while (czy_dalej_w_petli)
					{
						tmp = "";
						tmpstr.str("");
						std::getline(plik, tmp);

						tmpstr << tmp;
						if (tmp[0] != ':')
						{
							if (tmp[0] != '>')
							{
								//zczytywanie fixow
								tmpstr >> szerokosc_geograficzna;
								tmpstr >> dlugosc_geograficzna;
								tmpstr >> hh_mm_ss;

								////////////////
								//WYSWIETLENIE DLA SPRAWDZENIA - nie dziala

								std::cout << "TU";
								getchar();
								////////////////

								fix.set_dlugosc_geograficzna(dlugosc_geograficzna);
								fix.set_szerokosc_geograficzna(szerokosc_geograficzna);
								fix.set_czas(hh_mm_ss);

								while (!tmpstr.eof())
								{
									tmpstr >> tmp;
									switch (tmp[0])
									{
									case 'a':
									{
										asp = tmp;			//asp lub -az
									}
									break;
									case 'd':
									{
										d = tmp;
									}
									case 'f':
									{
										nazwa_fix = tmp;
									}
									break;
									case 'g':
									{
										gsp = tmp;			//gsp lub grp
									}
									break;
									case 'v':
									{
										vr = tmp;
									}

									default:
									{
										wysokosc1 = tmp;
										tmpstr >> wysokosc2;

										fix.set_wysokosc1(wysokosc1);
										fix.set_wysokosc2(wysokosc2);
									}
									break;
									}
								}
								samolot.dodaj_punkt_przelotu(fix);
							}
							else
							{
								czy_dalej_w_petli = false;
								dodaj_lot(samolot);
							}
						}
					}
				}
			}

		}



	}

	plik.close();
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


_Teren_ & _Teren_::operator<< (string  wspolrzedna_x_punktu_s)
{
	//C++11
	//wspolrzedna_x_punktu = std::stod(wspolrzedna_x_punktu_s);

	//C++98
	std::istringstream isstream_1(wspolrzedna_x_punktu_s);
	isstream_1 >> wspolrzedna_x_punktu;

	///////////////////////////////////////////////////////////////////////////////////

	//C++11
	string  wspolrzedna_y_punktu_s;
	//wspolrzedna_y_punktu = std::stod(wspolrzedna_y_punktu_s);

	//C++98
	std::istringstream isstream_2(wspolrzedna_y_punktu_s);
	isstream_2 >> wspolrzedna_y_punktu;

	///////////////////////////////////////////////////////////////////////////////////

	//C++11
	string  promien_okregu_s;
	//promien_okregu = std::stod(promien_okregu_s);

	//C++98
	std::istringstream isstream_3(promien_okregu_s);
	isstream_3 >> promien_okregu;

	///////////////////////////////////////////////////////////////////////////////////

	//C++11
	string  dzien_s;
	//dzien = std::stod(dzien_s);

	//C++98
	std::istringstream isstream_4(dzien_s);
	isstream_4 >> dzien;

	///////////////////////////////////////////////////////////////////////////////////

	//C++11
	string  godzina_s;
	//dzien = std::stod(godzina_s);

	//C++98
	std::istringstream isstream_5(godzina_s);
	isstream_5 >> godzina;

	///////////////////////////////////////////////////////////////////////////////////

	//C++11
	string  najmniejsza_ilosc_w_danym_dniu_s;
	//najmniejsza_ilosc_w_danym_dniu = std::stod(najmniejsza_ilosc_w_danym_dniu_s);

	//C++98
	std::istringstream isstream_6(najmniejsza_ilosc_w_danym_dniu_s);
	isstream_6 >> najmniejsza_ilosc_w_danym_dniu;

	return *this;
}
