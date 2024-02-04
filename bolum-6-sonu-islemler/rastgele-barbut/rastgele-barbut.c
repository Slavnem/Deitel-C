// barbut oyunu 1000 kez rastgele
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BARBUT_DURUM 2

// fonksiyon tanımı
void barbutOyun(unsigned short barbut_tur, enum BarbutDurum barbut_durum, const unsigned short barbut_dizi[]);
void barbutListe(const barbut_oynama, const enum BarbutDurum barbut_durum, const unsigned short barbut_dizi[]);

// OyunDurumu için enum tanım
enum Durum { DEVAM = 2, KAZANDI = 1, KAYBETTI = 0 } oyunDurum;

// Oyun için dizi
unsigned short barbutDizi[BARBUT_DURUM] = { 0 };

// main fonksiyonu başlangıcı
int main(void)
{
	srand(time(NULL));
	barbutOyun(1000, oyunDurum, barbutDizi);
} // main fonksiyonu sonu

// barbutOyun fonksiyonu başlangıcı
void barbutOyun(unsigned short barbut_tur, enum BarbutDurum barbut_durum, unsigned short barbut_dizi[])
{
	unsigned short _barbut_puan;
	unsigned short _barbut_gecici_puan;
	unsigned short _barbut_sayac;

	for (_barbut_sayac = 0; _barbut_sayac < barbut_tur; _barbut_sayac++)
	{
		_barbut_puan = (1 + (rand() % 6)) + (1 + (rand() % 6));

		switch (_barbut_puan)
		{
		// ilk atış kazanma
		case 7:
		case 11:
			barbut_durum = KAZANDI;
			break;
		// ilk atış kaybetme
		case 2:
		case 3:
		case 12:
			barbut_durum = KAYBETTI;
			break;
		// puanı hatırla
		default:
			_barbut_gecici_puan = _barbut_puan;
			barbut_durum = DEVAM;
			break;
		}

		while (barbut_durum == DEVAM)
		{
			_barbut_puan = (1 + (rand() % 6)) + (1 + (rand() % 6));

			// oyunun durumunu belirle
			if (_barbut_puan == _barbut_gecici_puan)
			{
				barbut_durum = KAZANDI;
			}
			else
			{
				if (_barbut_puan == 7)
				{
					// 7 atarak kaybeder
					barbut_durum = KAYBETTI;
				}
			}
		}

		if (barbut_durum == KAZANDI)
		{
			++barbut_dizi[barbut_durum];
		}
		else
		{
			++barbut_dizi[barbut_durum];
		}
	}

	barbutListe(1000, barbut_durum, barbut_dizi);
}

// barbutListe fonksiyonu başlangıcı
void barbutListe(const barbut_oynama, const enum BarbutDurum barbut_durum, const unsigned short barbut_dizi[])
{
	printf("Barbut oyunu %hd kez oynandi\n", barbut_oynama);
	printf("[%hd] kez barbut oyunu kaybedildi\n", barbut_dizi[KAYBETTI]);
	printf("[%hd] kez barbut oyunu kazanildi\n", barbut_dizi[KAZANDI]);
} // barbutListe fonksiyonu sonu