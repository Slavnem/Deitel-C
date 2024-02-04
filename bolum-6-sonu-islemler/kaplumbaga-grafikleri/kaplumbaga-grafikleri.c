// Kaplumba�a Grafikleri
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EKSEN 2
#define EKSEN_XY 50
#define KOMUTLAR 7
#define KOMUT_YAZI_KARAKTER 7

// bu numaralar de�i�tirilemez
enum KaplumbagaDurum { DRM_ASAGI = 0, DRM_YUKARI = 1 };
enum KaplumbagaKomutlar { KOM_ASAGI = 0, KOM_YUKARI = 1, KOM_SAG = 2, KOM_SOL = 3, KOM_BOSLUK = 4, KOM_YAZILDI = 5, KOM_SON = 9 };
// bu numaralar de�i�ebilir ��nk� sadece say�s� de�i�cek
enum KaplumbagaDurum Kaplumbaga_Durum;
enum KaplumbagaKomutlar Kaplumbaga_Komutlar;

// komutlar�n yaz� hali
const char KomutlarYazi[KOMUTLAR][KOMUT_YAZI_KARAKTER] = {
	{'A','s','a','g','i'},
	{'Y','u','k','a','r','i'},
	{'S','a','g'},
	{'S','o','l'},
	{'B','o','s','l','u','k'},
	{'Y','a','z','i','l','d','i'},
	{'S','o','n'}
};

// komutlar� diziye i�leyecek olan fonksiyon tan�m�
void komutHazirlayici(
	unsigned int komut_eksenDizi[][EKSEN_XY], // x ve y eksenlerindeki de�erlerimizi i�eren dizi
	unsigned short komut_eksen, // x ve y ekseni miktar� kadar d�necek (2)
	unsigned short komut_tur // komutu ka� kez d�necek sayac�
	);

// eksenlere kaydedilmi� komutlar� ekrana yazd�racak olan fonksiyon tan�m�
void komutYazdirici(
	const unsigned int komut_eksenDizi[][EKSEN_XY], // x ve y eksenlerindeki de�erlerimizi i�eren dizi
	unsigned short komut_eksen, // x ve y ekseni miktar� kadar d�necek (2)
	unsigned short komut_tur, // komutu ka� kez d�necek sayac�
	const char komut_yazi[][KOMUT_YAZI_KARAKTER] // komutlar�n yaz�l� hali
);

// main fonksiyonu ba�lang�c�
int main(void)
{
	// kaplumba�a dizi
	static unsigned int kaplumbagaDizi[EKSEN][EKSEN_XY] = { 0 };

	srand(time(NULL)); // rastgele say� i�in

	// eksen ve turlardaki komutlar� haz�rlama
	komutHazirlayici(
		kaplumbagaDizi, // eksenleri i�eren dizi
		EKSEN, // eksen sayac� i�in de�er
		EKSEN_XY // bu eksenlerde ka� tur d�necek onun i�in saya�
	);
} // main fonksiyonu sonu

// komutHazirlayici fonksiyonu ba�lang�c�
void komutHazirlayici(
	unsigned int komut_eksenDizi[][EKSEN_XY], // x ve y eksenlerindeki de�erlerimizi i�eren dizi
	unsigned short komut_eksen, // x ve y ekseni miktar� kadar d�necek (2)
	unsigned short komut_tur // komutu ka� kez d�necek sayac�
)
{
	unsigned short _eksen_sayac; // eksen d�ng�s� i�in saya�
	unsigned short _tur_sayac; // eksende d�nece�i tur i�in saya�
	unsigned short _rastgele_komut; // rastgele gelecek komutlar
	unsigned short _son_komut = KOM_BOSLUK; // son komutumuz BOSLUK olsun istedik

	for ( // eksen miktar� kadar d�necek
		_eksen_sayac = 0;
		_eksen_sayac < komut_eksen;
		_eksen_sayac++
		)
	{
		for ( // eksendeki yapt��� tur
			_tur_sayac = 0;
			_tur_sayac < komut_tur;
			_tur_sayac++
			)
		{ // hangi eksende ve tur da ise, dizide o yere rastgele komut atamak
			_rastgele_komut = 1 + (rand() % _son_komut); // son komuta b�l�m�nden kalana 1 ekleme
			komut_eksenDizi[_eksen_sayac][_tur_sayac] = _rastgele_komut;
		}
	}

	// son komutumuz 9 olmal� yani biti� komutu o y�zden son eksendeki son komutu bir daha d�zenliyip biti� komudu yap�caz
	Kaplumbaga_Durum = KOM_YAZILDI; // kaplumba�an�n dizisinin hepsi yaz�ld��� i�in YAZILDI'ya ayarl�yoruz
	komut_eksenDizi[komut_eksen][komut_tur] = Kaplumbaga_Durum; // tan�mlama yapmad���m�z i�in dizi 0 dan ba�lar bu y�zden 1 d��t�m

	// komutlar� haz�rlad�k, �imdi de ekrana yazd�rmak i�in di�er fonksiyona ge�iyoruz
	komutYazdirici(
		komut_eksenDizi, // komutlar� i�eren dizi
		komut_eksen, // d�nece�i eksen miktar�
		komut_tur, // d�nece�i tur miktar�
		KomutlarYazi // komutlar�n yaz� hali
	);
} // komutHazirlayici fonksyionu sonu

// komutYazdirici fonksiyonu ba�lang�c�
void komutYazdirici(
	const unsigned int komut_eksenDizi[][EKSEN_XY], // x ve y eksenlerindeki de�erlerimizi i�eren dizi
	unsigned short komut_eksen, // x ve y ekseni miktar� kadar d�necek (2)
	unsigned short komut_tur, // komutu ka� kez d�necek sayac�
	const char komut_yazi[][KOMUT_YAZI_KARAKTER] // komutlar�n yaz�l� hali
)
{
	unsigned short _yazdirici_eksen_sayac; // eksen d�nme sayac�
	unsigned short _yazdirici_tur_sayac; // tur d�nme sayac�
	unsigned short _yazdirici_komut_yazi; // komutun yaz� hali d�nme sayac�

	for ( // eksen miktar� kadar d�necek
		_yazdirici_eksen_sayac = 0;
		_yazdirici_eksen_sayac < komut_eksen;
		_yazdirici_eksen_sayac++
		)
	{
		for ( // eksende yapt��� tur
			_yazdirici_tur_sayac = 0;
			_yazdirici_tur_sayac < komut_tur;
			_yazdirici_tur_sayac++
			)
		{
			Kaplumbaga_Durum = rand() % 2; // a��a�� ve yukar� oldu�u i�in 2 dedim, 1 kal�rsa yukar�, 0 kal�rsa a��a��


			if (Kaplumbaga_Durum == 1)
			{ // e�er kalem yukar� ise eksende ka��nc� tur da ise o turdaki de�eri yazs�n
				printf(
					"[%hd. %s][%hd. %s] %d: ",
					_yazdirici_eksen_sayac +1, // eksen numaras�
					"eksen", // eksen yaz�s�
					_yazdirici_tur_sayac +1, // tur numaras�
					"tur", // tur yaz�s�
					komut_eksenDizi[_yazdirici_eksen_sayac][_yazdirici_tur_sayac] // eksen ve tur daki de�er
				);

				for ( // yazd�rman�n sona ermesi ve ekrana ��kt�s�n� vermek
					_yazdirici_komut_yazi = 0;
					_yazdirici_komut_yazi < KOMUT_YAZI_KARAKTER;
					_yazdirici_komut_yazi++
					)
				{
					// komut ad�n� yazd�r�yoruz
					printf("%c", komut_yazi[(komut_eksenDizi[_yazdirici_eksen_sayac][_yazdirici_tur_sayac])][_yazdirici_komut_yazi]);
				}
				puts(""); // yeni sat�r
			}
		}
	}

	// dizinin i�indeki her �ey yaz�ld��� i�in biti� i yap�yoruz
	printf("[%hd %s][%hd %s] %s %hd: ",
		_yazdirici_eksen_sayac, // son eksen
		"eksen", // eksen yaz�s�
		komut_tur, // son tur
		"tur", // tur yaz�s�
		"yazildi ve bitti, bitis degeri:",
		KOM_SON // SON komutu numaras�
	);

	for (
		_yazdirici_komut_yazi = 0;
		_yazdirici_komut_yazi < KOMUT_YAZI_KARAKTER;
		_yazdirici_komut_yazi++
		)
	{
		// komut ad�n� yazd�r�yoruz
		// 6 bizim son komutumuza tekabul ediyor
		printf("%c", komut_yazi[6][_yazdirici_komut_yazi]);
	}
	puts(""); // yeni sat�r
} // komutYazdirici fonksiyonu sonu
