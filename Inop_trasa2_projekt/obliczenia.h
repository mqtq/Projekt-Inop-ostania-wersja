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


double licz_odleglosc_punktu_od_prostej(double X1, double Y1, double X2, double Y2, double X_punktu, double Y_punktu)
{
	double a, b, c, x1=deg2rad(X1) * 60 * 1.1515, x2 = deg2rad(X2) * 60 * 1.1515, y1 = deg2rad(Y1) * 60 * 1.1515, y2 = deg2rad(Y2) * 60 * 1.1515, x_punktu = deg2rad(X_punktu) * 60 * 1.1515, y_punktu = deg2rad(Y_punktu) * 60 * 1.1515;
	a = y2 - y1;
	b = x1 - x2;
	c = y1 * x2 - y2 * x1;
	double odleglosc = ((fabs(a*x_punktu + b * y_punktu + c)) / (sqrt(a*a + b * b)));
	return odleglosc;

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

bool czy_punkt_nalezy_do_okregu(double X_srodek_okregu, double Y_srodek_okregu, double R, double X1, double Y1)
{
	bool wynik = false;
	if (R >= distance(X_srodek_okregu,Y_srodek_okregu,X1,Y1,'K'))
	{
		wynik = true;
	}
	return wynik;
}



#endif // !_obliczenia_h_
