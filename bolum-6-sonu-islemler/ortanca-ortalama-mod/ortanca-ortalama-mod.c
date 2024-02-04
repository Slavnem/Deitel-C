// ortanca deðer, ortalama ve mod bulma
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAYILAR_DIZI 24
#define MOD_DIZI 10

void diziYazdir(const unsigned short dizi[], unsigned short _dizi_sinir);
void ortanca(const unsigned short dizi[], unsigned short _ortanca_sinir);
void ortalama(const unsigned short dizi[], unsigned short _ortalama_sinir);
void mod(const unsigned short dizi[], unsigned short _dizi_sinir, unsigned short _mod_sinir);

// main fonksiyonu baþlangýcý
int main(void)
{
	unsigned short sayilar[24];
	unsigned short _sayi_sayac;

	srand(time(NULL)); // iþlemciden rastgele zaman numarasý almasý için

	for (_sayi_sayac = 0; _sayi_sayac < SAYILAR_DIZI; _sayi_sayac++)
	{
		// rastgele sayýyý 10'a bölüp kalan rakamý diziye atamayý saðlayacak
		sayilar[_sayi_sayac] = rand() % 10;
	}

	diziYazdir(sayilar, SAYILAR_DIZI);
	ortanca(sayilar, SAYILAR_DIZI);
	ortalama(sayilar, SAYILAR_DIZI);
	mod(sayilar, SAYILAR_DIZI, MOD_DIZI);
} // main fonksiyonu sonu

// diziYazdir fonksiyonu baþlangýcý
void diziYazdir(const unsigned short dizi[], unsigned short _dizi_sinir)
{
	unsigned short _dizi_sayac;

	printf("=====Dizi====="); // baþlýk
	/* MÝNÝK BÝLGÝ: alttaki for döngüsünde, sayaçýn 6 ile bölümünden kalan 0 olcak en baþta
	kendisi otomatik yeni satýr oluþturacak bundan dolayý printf ile yazdýk */

	for (_dizi_sayac = 0; _dizi_sayac < SAYILAR_DIZI; _dizi_sayac++)
	{
		if (_dizi_sayac % 6 == 0)
		{
			puts(""); // yeni satýr
		}

		printf("%hu ", dizi[_dizi_sayac]);
	}

	puts(""); // yeni satýr
} // diziYazdir fonksiyonu baþlangýcý

// ortanca fonksiyonu baþlangýcý
void ortanca(const unsigned short dizi[], unsigned short _ortanca_sinir)
{
	unsigned short _ortanca;
	// tek sayý da mý yoksa çift sayý miktarýnda mý dizi, bunu öðrenmek için kontrol
	if (_ortanca_sinir % 2 == 0)
	{ // çift ise eðer
		_ortanca = ((dizi[_ortanca_sinir / 2] + dizi[(_ortanca_sinir / 2) - 1]) / 2);
	}
	else
	{ // tek ise eðer
		_ortanca = (dizi[(_ortanca_sinir - 1) / 2]);
	}

	puts("=====ortanca====="); // baþlýk
	printf("%hu ortanca degerdir\n", _ortanca);
} // ortanca fonksiyonu sonu

/* AÇIKLAMA: Normal de main fonksiyonun da for döngüsünün içine ek bir satýrla
sayýlarý toplatýp sonra dizi boyutuna böldürüp daha rahatça bulabiliriz fakat
burdaki amaç sayýlarý sýrayla toplamýsýný saðlayýp sonra bölüp ortalamayý bulmak */

// short: %hi veya %hd, unsigned short: %hu

/* AÇIKLAMA 2: Hep short kullanýyoruz nedeni ise bizim sayýlarýmýz hem 32.767'den veya
unsigned short 65.535 den büyük olmaycak bu yüzden, short kullanmak bellekte daha az yer tutmasý
açýsýndan daha performanslý bir seçenek bizim için ve biz negatif deðer bulundurmayacaðýmýz için
unsigned olmasý bizim için negatif veri depolamayýp, toplam negatif veri toplayabileceði miktarý
32.768'i pozitife aktaracak ve 32.767 yerine 65.535 pozitif sayý tutabileceðiz, ve 0 da var ama onu saymýyoruz */

// ortalama fonksiyonu baþlangýcý
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

	puts("=====ortalama====="); // baþlýk
	printf("%.2f, %hu sayinin ortalamasidir\n", _ortalama, _ortalama_sinir);
} // ortalama fonksiyonu sonu

// mod fonksiyonu baþlangýcý
void mod(const unsigned short dizi[], unsigned short _dizi_sinir, unsigned short _mod_sinir)
{
	/* MOD AÇIKLAMA: 10 tane rakam elde edebiliyoruz en fazla bu yüzden
	þimdi kullanacaðým yöntem iþe yarar ama daha fazla sayý alsaydý bu yöntem
	iþe yaramayabilirdi, örnek sayýlar: 1111111111, 446687678654, 2468734314, 911319, 65536 gibi sayýlar olsaydý eðer
	bu yöntem sonuçsuz kalýrdýk veya performans açýsýndan kötü olurdu */
	unsigned short _mod_sayac;
	unsigned short _mod_miktar_sayac;
	unsigned short modDizi[MOD_DIZI] = { 0 };

	for (_mod_sayac = 0; _mod_sayac < _dizi_sinir; _mod_sayac++)
	{
		++modDizi[dizi[_mod_sayac]];
	}

	puts("=====mod====="); // baþlýk

	for (_mod_sayac = 0; _mod_sayac < _mod_sinir; _mod_sayac++)
	{
		printf("[%hu: %hu+] ", _mod_sayac, modDizi[_mod_sayac]);

		for (_mod_miktar_sayac = 0; _mod_miktar_sayac < modDizi[_mod_sayac]; ++_mod_miktar_sayac)
		{
			printf("+");
		}

		puts(""); // yeni satýr
	}
}