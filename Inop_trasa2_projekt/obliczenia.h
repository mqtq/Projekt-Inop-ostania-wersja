/*
	Opis: Plik zawieraj¹cy funkcje s³u¿¹ce do obliczeñ matematycznych wykorzystywanych w programie  

	Zawiera nastêpuj¹ce funkcje:
	- deg2rad - zamienia stopnie na radiany
	- rad2deg - zamienia radiany na stopnie
	- licz_odleglosc_punktu_od_prostej - liczy odleg³oœæ punktu od prostej (wspó³rzêdne przekazywane za pomoc¹ 
	-distance - liczy odleg³oœæ dwóch punktów od siebie
	-czy_punkt_nalezy_do_okregu - sprawdza, czy punkt nale¿y do okrêgu

	autor: Mateusz Wasiak, Jakub Ziêba, Martyna Rój, Damian Goss, Marcin Ludwisiak
	data powstania: 20180419

	Modyfikacje pliku:
*/
#ifndef _obliczenia_h_
#define _obliczenia_h_

#include <cmath>


double deg2rad(double deg) 
{
	return (deg * 3.14159265358979323846 / 180);
}

double rad2deg(double rad) 
{
	return (rad * 180 / 3.14159265358979323846);
}

double distance(double lat1, double lon1, double lat2, double lon2, char unit) {
	double theta, dist;
	theta = lon1 - lon2;
	dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
	dist = acos(dist);
	dist = rad2deg(dist);
	dist = dist * 60 * 1.1515;
	switch (unit) {
	case 'M':
		break;
	case 'K':
		dist = dist * 1.609344;
		break;
	case 'N':
		dist = dist * 0.8684;
		break;
	}
	return (dist);
}

void licz_wspolczynniki_prostej_przechodzacej_przez_dwa_punkty(double x1, double y1, double x2, double y2, double &a, double &b)
{
	a = (y1 - y2) / (x1 - x2);
	b = y1 - a * x1;
}

void licz_wspolczynniki_prostej_prostopadlej_do_danej_prostej_przechodzacej_przez_dany_punkt(double a_danej_prostej, double b_danej_prostej, double x, double y, double &a_prostej_prostopadlej, double &b_prostej_prostopadlej)
{
	a_prostej_prostopadlej = (-1) / a_danej_prostej;
	b_prostej_prostopadlej = y - a_prostej_prostopadlej * x;
}

void licz_wspolrzedne_punktu_przeciecia_dwoch_prostych(double a1, double b1, double a2, double b2, double x, double y)
{
	x = (b2 - b1) / (a1 - a2);
	y = a1 * x + b1;
}

bool czy_punkty_leza_po_tej_samej_stronie_trzeciego_punktu(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a, b, c;
	a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	b = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
	c = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
	bool wynik = false;
	if (fabs(a + b - c) < pow(10, -1))
	{
		wynik = true;
	}
	return wynik;
}

#endif // !_obliczenia_h_
