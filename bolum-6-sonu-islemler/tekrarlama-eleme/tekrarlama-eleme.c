// tekrarlamanın elenmesi
#include <stdio.h>

#define SINIR_SAYI 20

void kullaniciDizi(unsigned short dizi[], unsigned short _alt_sinir, unsigned short _ust_sinir, unsigned short _dizi_sinir);

// main fonksiyonu başlangıcı
int main(void)
{
	unsigned short dizi[SINIR_SAYI] = { 0 };
	kullaniciDizi(dizi, 10, 100, SINIR_SAYI);
} // main fonksiyonu sonu

// kullaniciDizi fonksiyonu başlangıcı
void kullaniciDizi(unsigned short dizi[], unsigned short _alt_sinir, unsigned short _ust_sinir, unsigned short _dizi_sinir)
{
	signed short _sayi;
	unsigned short _durum = 1;
	unsigned short _sayac_dizi;
	unsigned short _sayac_dizi_kontrol;

	for (_sayac_dizi = 0; _sayac_dizi < _dizi_sinir; ++_sayac_dizi)
	{
		do
		{
			printf("%hd) Bir sayi giriniz[10-100]: ", _sayac_dizi+1);
			scanf("%hd", &_sayi);
		} while (_sayi < 10 || _sayi > 100);

		for (_sayac_dizi_kontrol = 0; _sayac_dizi_kontrol < _dizi_sinir; _sayac_dizi_kontrol++)
		{
			if (_sayi == dizi[_sayac_dizi_kontrol])
			{
				_durum = 0;
				break;
			}
		}

		if (_durum == 1)
		{
			dizi[_sayac_dizi] = _sayi;
			printf("[%hu]. sayi: %hd\n", _sayac_dizi+1, dizi[_sayac_dizi]);
		}
		else
		{
			puts("Iki kez ayni sayiyi girdiniz, program sonlaniyor...");
			break;
		}
	}

}