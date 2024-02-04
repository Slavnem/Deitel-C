// ortanca de�er, ortalama ve mod bulma
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAYILAR_DIZI 24
#define MOD_DIZI 10

void diziYazdir(const unsigned short dizi[], unsigned short _dizi_sinir);
void ortanca(const unsigned short dizi[], unsigned short _ortanca_sinir);
void ortalama(const unsigned short dizi[], unsigned short _ortalama_sinir);
void mod(const unsigned short dizi[], unsigned short _dizi_sinir, unsigned short _mod_sinir);

// main fonksiyonu ba�lang�c�
int main(void)
{
	unsigned short sayilar[24];
	unsigned short _sayi_sayac;

	srand(time(NULL)); // i�lemciden rastgele zaman numaras� almas� i�in

	for (_sayi_sayac = 0; _sayi_sayac < SAYILAR_DIZI; _sayi_sayac++)
	{
		// rastgele say�y� 10'a b�l�p kalan rakam� diziye atamay� sa�layacak
		sayilar[_sayi_sayac] = rand() % 10;
	}

	diziYazdir(sayilar, SAYILAR_DIZI);
	ortanca(sayilar, SAYILAR_DIZI);
	ortalama(sayilar, SAYILAR_DIZI);
	mod(sayilar, SAYILAR_DIZI, MOD_DIZI);
} // main fonksiyonu sonu

// diziYazdir fonksiyonu ba�lang�c�
void diziYazdir(const unsigned short dizi[], unsigned short _dizi_sinir)
{
	unsigned short _dizi_sayac;

	printf("=====Dizi====="); // ba�l�k
	/* M�N�K B�LG�: alttaki for d�ng�s�nde, saya��n 6 ile b�l�m�nden kalan 0 olcak en ba�ta
	kendisi otomatik yeni sat�r olu�turacak bundan dolay� printf ile yazd�k */

	for (_dizi_sayac = 0; _dizi_sayac < SAYILAR_DIZI; _dizi_sayac++)
	{
		if (_dizi_sayac % 6 == 0)
		{
			puts(""); // yeni sat�r
		}

		printf("%hu ", dizi[_dizi_sayac]);
	}

	puts(""); // yeni sat�r
} // diziYazdir fonksiyonu ba�lang�c�

// ortanca fonksiyonu ba�lang�c�
void ortanca(const unsigned short dizi[], unsigned short _ortanca_sinir)
{
	unsigned short _ortanca;
	// tek say� da m� yoksa �ift say� miktar�nda m� dizi, bunu ��renmek i�in kontrol
	if (_ortanca_sinir % 2 == 0)
	{ // �ift ise e�er
		_ortanca = ((dizi[_ortanca_sinir / 2] + dizi[(_ortanca_sinir / 2) - 1]) / 2);
	}
	else
	{ // tek ise e�er
		_ortanca = (dizi[(_ortanca_sinir - 1) / 2]);
	}

	puts("=====ortanca====="); // ba�l�k
	printf("%hu ortanca degerdir\n", _ortanca);
} // ortanca fonksiyonu sonu

/* A�IKLAMA: Normal de main fonksiyonun da for d�ng�s�n�n i�ine ek bir sat�rla
say�lar� toplat�p sonra dizi boyutuna b�ld�r�p daha rahat�a bulabiliriz fakat
burdaki ama� say�lar� s�rayla toplam�s�n� sa�lay�p sonra b�l�p ortalamay� bulmak */

// short: %hi veya %hd, unsigned short: %hu

/* A�IKLAMA 2: Hep short kullan�yoruz nedeni ise bizim say�lar�m�z hem 32.767'den veya
unsigned short 65.535 den b�y�k olmaycak bu y�zden, short kullanmak bellekte daha az yer tutmas�
a��s�ndan daha performansl� bir se�enek bizim i�in ve biz negatif de�er bulundurmayaca��m�z i�in
unsigned olmas� bizim i�in negatif veri depolamay�p, toplam negatif veri toplayabilece�i miktar�
32.768'i pozitife aktaracak ve 32.767 yerine 65.535 pozitif say� tutabilece�iz, ve 0 da var ama onu saym�yoruz */

// ortalama fonksiyonu ba�lang�c�
void ortalama(const unsigned short dizi[], unsigned short _ortalama_sinir)
{
	unsigned short _ortalama_sayac;
	unsigned short _ortalama_toplam = 0;

	float _ortalama;

	for (_ortalama_sayac = 0; _ortalama_sayac < _ortalama_sinir; _ortalama_sayac++)
	{
		_ortalama_toplam += dizi[_ortalama_sayac];
	}

	_ortalama = (float)_ortalama_toplam / (_ortalama_sayac + 1);

	puts("=====ortalama====="); // ba�l�k
	printf("%.2f, %hu sayinin ortalamasidir\n", _ortalama, _ortalama_sinir);
} // ortalama fonksiyonu sonu

// mod fonksiyonu ba�lang�c�
void mod(const unsigned short dizi[], unsigned short _dizi_sinir, unsigned short _mod_sinir)
{
	/* MOD A�IKLAMA: 10 tane rakam elde edebiliyoruz en fazla bu y�zden
	�imdi kullanaca��m y�ntem i�e yarar ama daha fazla say� alsayd� bu y�ntem
	i�e yaramayabilirdi, �rnek say�lar: 1111111111, 446687678654, 2468734314, 911319, 65536 gibi say�lar olsayd� e�er
	bu y�ntem sonu�suz kal�rd�k veya performans a��s�ndan k�t� olurdu */
	unsigned short _mod_sayac;
	unsigned short _mod_miktar_sayac;
	unsigned short modDizi[MOD_DIZI] = { 0 };

	for (_mod_sayac = 0; _mod_sayac < _dizi_sinir; _mod_sayac++)
	{
		++modDizi[dizi[_mod_sayac]];
	}

	puts("=====mod====="); // ba�l�k

	for (_mod_sayac = 0; _mod_sayac < _mod_sinir; _mod_sayac++)
	{
		printf("[%hu: %hu+] ", _mod_sayac, modDizi[_mod_sayac]);

		for (_mod_miktar_sayac = 0; _mod_miktar_sayac < modDizi[_mod_sayac]; ++_mod_miktar_sayac)
		{
			printf("+");
		}

		puts(""); // yeni sat�r
	}
}