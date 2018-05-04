/*
Opis: plik main
Autor: Mateusz Wasiak, Marcin Ludwisiak, Jakub Ziêba, Martyna Rój, Damian Goss
Data utworzenia: 19.04.2018r.
Modyfikacje pliku:

------------------------------------------------------------
ToDo:

*/


#include <iostream>
#include "_Teren_.h"

int main()
{
	_Teren_ tmp;
	tmp.wczytaj_plik("in.txt");

	system("pause");
	return 0;
}