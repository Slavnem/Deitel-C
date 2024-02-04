// 36.000 kez zar rastgele at
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZAR_TOPLAM 13

void zarTopla(unsigned short zar_alt, unsigned short zar_ust, unsigned short zar_tur, unsigned short zar_dizi[]);
void zarListele(unsigned short zar_alt, unsigned short zar_ust, unsigned short zar_tur, const unsigned short zar_dizi[]);

unsigned short zarDizi[ZAR_TOPLAM] = { 0 };

// main fonksiyonu başlangıcı
int main(void)
{
	srand(time(NULL));
	zarTopla(1, 6, 36000, zarDizi);
} // main fonksiyonu sonu

// zarTopla fonksiyonu başlangıcı
void zarTopla(unsigned short zar_alt, unsigned short zar_ust, unsigned short zar_tur, unsigned short zar_dizi[])
{
	unsigned short _zar_sayac;
	unsigned short _zar_deger;

	for (_zar_sayac = 0; _zar_sayac < zar_tur; _zar_sayac++)
	{
		_zar_deger = (1 + (rand() % 6)) + (1 + (rand() % 6));
		++zar_dizi[_zar_deger];
	}

	zarListele(1, 6, 11, zar_dizi);
} // zarTopla fonksiyonu sonu

// zarListele fonksiyonu başlangıcı
void zarListele(unsigned short zar_alt, unsigned short zar_ust, unsigned short zar_tur, const unsigned short zar_dizi[])
{
	unsigned short _zar_liste_sayac;

	for (_zar_liste_sayac = 2; _zar_liste_sayac < zar_tur; _zar_liste_sayac++)
	{
		printf("[%hd] %hd kez cikti\n", _zar_liste_sayac, zar_dizi[_zar_liste_sayac]);
	}
} // zarListele fonksiyonu sonu