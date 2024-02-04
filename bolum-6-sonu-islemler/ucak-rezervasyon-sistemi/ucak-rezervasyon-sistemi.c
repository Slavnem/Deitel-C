// u�ak rezervasyon sistemi
#include <stdio.h>

#define EN_KOLTUK 10 // 10 tane koltuk
#define EN_SINIF 2 // birinci/ekonomik s�n�f
#define SINIF_KOLTUK 5 // birinci/ekonomik s�n�f her birinden 5 koltuk 
#define EN_SINIF_KARAKTER 14 // en fazla karakter depolama s�n�r�

// U�ak Dolu/Bo� ve Birinci/Ekonomik S�n�f Tan�mlama
enum ProgramDurum { HATA = -1, DEVAM = 1, SON = 2 };
enum UcakSinif { BIRINCI = 0, EKONOMIK = 1 } Koltuk_Sinif;
enum UcakKoltukDurum { BOS, DOLU } Koltuk_Durum;
enum IstekDurum { HAYIR, EVET } Istek_Durum;
enum BiletDurum { BEKLIYOR, SATILDI } Bilet_Durum;

// hata kontrol kodu
static signed short hata_kodu = DEVAM; // hata olmad�k�a otomatik olarak 1 kal�cak

// U�ak Koltuk Durumu
static unsigned short UcakKoltukDizi[EN_KOLTUK] = { 0 };
static unsigned short UcakSinifDolulukDizi[EN_SINIF] = { 0 };
char UcakKoltukTuru[EN_SINIF][EN_SINIF_KARAKTER] =
{
	{ 'B','i','r','i','n','c','i',' ','S','i','n','i','f'},
	{ 'E','k','o','n','o','m','i','k',' ','S','i','n','i','f'}
};

/* ilk fonksiyon �al��acak s�n�f miktar� 2, koltuk s�n�flar� ve durumlar�, koltuk say�s� arg�manlar�
* �al��acak fonksiyon ilk bo� koltuklar� s�ral�cak ve sonra kullan�c�ya koltuk i�in soru soracak
* birinci s�n�f koltuklar doldu�unda ekonomik koltuk ister istemez sorusu, e�er isterse ekonomik koltuk
* e�er istemezse di�er u�u� 3 saat sonra mesaj�, e�er ekonomik dolu birinci s�n�f bo� ise, birinci sn�f
* i�in sor, isterse birinci s�n�f, istemezse di�er u�u� 3 saat sonra
*/

void rezervasyonOlustur(
	const unsigned short koltuk_sinif, // ka� t�r koltuk s�n�f� var
	const unsigned short koltuk_tekrar, // koltuk s�n�flar�ndaki koltuk say�s�
	const unsigned short koltuk_sinir, // t�m koltuklar�n s�n�r�
	unsigned short koltuk_dizi[], // koltuklar�n dolu ya da bo� oldu�unu anlam�m�z� sa�layan dizi
	unsigned short sinif_koltuk_dizi[], // o sinifin kotluklar� bo� mu yoksa dolumu
	const char koltuk_sinif_dizi[][EN_SINIF_KARAKTER], // koltuk s�n�flar�n�n ad�n� bar�nd�ran dizi
	const unsigned short koltuk_sinif_karakter_sinir, // koltuk s�n�flar� ad�n�n karakter s�n�r�
	const unsigned short koltuk_sinif_enaz, // en d���k s�raya sahip koltuk s�n�f�
	const unsigned short koltuk_sinif_enfazla // en y�ksek numaraya sahip koltuk s�n�f�
	); // hay�r 0, evet 1
void koltukYazdir(
	const unsigned short koltuk_sinif, // ka� t�r koltuk s�n�f� var
	const unsigned short koltuk_tekrar, // koltuk s�n�flar�ndaki koltuk say�s�
	const unsigned short koltuk_sinir, // t�m koltuklar�n s�n�r�
	const unsigned short koltuk_dizi[], // koltuklar�n dolu ya da bo� oldu�unu anlam�m�z� sa�layan dizi
	const unsigned short sinif_koltuk_dizi[], // o sinifin kotluklar� bo� mu yoksa dolumu
	const char koltuk_sinif_dizi[][EN_SINIF_KARAKTER], // koltuk s�n�flar�n�n ad�n� bar�nd�ran dizi
	const unsigned short koltuk_sinif_karakter_sinir, // koltuk s�n�flar� ad�n�n karakter s�n�r�
	const unsigned short koltuk_sinif_enaz, // en d���k s�raya sahip koltuk s�n�f�
	const unsigned short koltuk_sinif_enfazla // en y�ksek numaraya sahip koltuk s�n�f�
	);

// main fonksiyonu ba�lang�c�
int main(int hata_kontrol)
{
	if (hata_kodu == 1)
	{
		// program ba�ar�yla �al��maya devam etsin
		rezervasyonOlustur(EN_SINIF, SINIF_KOLTUK, EN_KOLTUK, UcakKoltukDizi, UcakSinifDolulukDizi, UcakKoltukTuru, EN_SINIF_KARAKTER, BIRINCI, EKONOMIK);
	}
	else if (hata_kodu == 2)
	{ // kullan�c� istekli son
		return 2; // kullanici istekli
	}
	else
	{
		return -1; // hata
	}
} // main fonksiyonu sonu

// rezervasyonOlustur fonksiyonu ba�lang�c�
void rezervasyonOlustur(
	const unsigned short koltuk_sinif, // ka� t�r koltuk s�n�f� var
	const unsigned short koltuk_tekrar, // koltuk s�n�flar�ndaki koltuk say�s�
	const unsigned short koltuk_sinir, // t�m koltuklar�n s�n�r�
	unsigned short koltuk_dizi[], // koltuklar�n dolu ya da bo� oldu�unu anlam�m�z� sa�layan dizi
	unsigned short sinif_koltuk_dizi[], // o sinifin kotluklar� bo� mu yoksa dolumu
	const char koltuk_sinif_dizi[][EN_SINIF_KARAKTER], // koltuk s�n�flar�n�n ad�n� bar�nd�ran dizi
	const unsigned short koltuk_sinif_karakter_sinir, // koltuk s�n�flar� ad�n�n karakter s�n�r�
	const unsigned short koltuk_sinif_enaz, // en d���k s�raya sahip koltuk s�n�f�
	const unsigned short koltuk_sinif_enfazla // en y�ksek numaraya sahip koltuk s�n�f�
)
{
	unsigned short _kullanici_son = HAYIR; // programa son vermesin diye hay�r
	unsigned short _kullanici_koltuk_durum = BOS; // evet, koltuklarda hala bo� yer var
	unsigned short _kullanici_sinif;
	unsigned short _kullanici_sinif_sayac;
	unsigned short _kullanici_durum = BOS; // kullan�c� sat�n almak istemi�se 1
	unsigned short _kullanici_sayac;
	unsigned short _kullanici_koltuk_numara;

	for (_kullanici_sayac = 0; _kullanici_sayac < koltuk_sinir && _kullanici_durum == BOS; _kullanici_sayac++)
	{
		// ekrana koltuk s�n�flar� ve mevcut koltuklar�n� yazd�rmak
		Bilet_Durum = BEKLIYOR;
		koltukYazdir(koltuk_sinif, koltuk_tekrar, koltuk_sinir, koltuk_dizi, sinif_koltuk_dizi, koltuk_sinif_dizi, koltuk_sinif_karakter_sinir, koltuk_sinif_enaz, koltuk_sinif_enfazla+1);

		/* Koltuk s�n�f� dolu ya da bo� kontrol d�ng�s�
		toplamda 10 koltuk var ama 10'dan fazla kez d�nmek mant�k hatas�, bu y�zden kontrol sa�l�yoruz
		koltuklar�n hepsi dolu ise program kapan�yor */
		for (_kullanici_sinif_sayac = koltuk_sinif_enaz;
			_kullanici_sinif_sayac < koltuk_sinif_enfazla+1;
			_kullanici_sinif_sayac++)
		{
			if (sinif_koltuk_dizi[_kullanici_sinif_sayac] == BOS)
			{ // e�er d�ng� de herhangi bir koltuk bo� ise, o koltuk s�n�f� bo� yazd�r d�ng�y� sonland�r
				_kullanici_koltuk_durum = BOS; // evet koltukta yer var, program devam etsin
				break;
			}
			else
			{ // e�er o koltuk s�n�f�ndaki koltuklar doluysa, o koltuk s�n�f dolu yazd�r
				_kullanici_koltuk_durum = DOLU; // hay�r koltukda yer yok, program sonlans�n
			}
		}

		if (_kullanici_koltuk_durum == DOLU)
		{ // hi� koltuk yeri kalmam��sa
			hata_kodu = SON;
			_kullanici_durum = DOLU; // kullanici dolu duruma geliyor
			
			puts("Hic bos koltuk kalmadi, diger ucus 3 saat sonra...");
			main(hata_kodu); // koltuk kalmad��� i�in programa son veriliyor
		}
		else if (sinif_koltuk_dizi[BIRINCI] == DOLU)
		{
			do
			{
				printf("%hd. siniftaki koltuklarin hepsi dolu. Koltuk almaya devam etmek istiyor musunuz? [1:Evet,0:Hayir] ", BIRINCI+1);
				scanf("%hd", &_kullanici_son);
			} while (_kullanici_son < HAYIR || _kullanici_son > EVET);

			if (_kullanici_son == HAYIR)
			{ // daha koltuk sat�n almak istemiyor
				_kullanici_durum = DOLU; // kullanici dolu duruma geliyor
				hata_kodu = SON; // hata durumu son a getiriliyor, 2

				puts("Diger ucus 3 saat sonra...");
				main(hata_kodu); // kullan�c� iste�iyle programa son veriliyor
			}
		}


		if (hata_kodu == DEVAM && _kullanici_durum == BOS && _kullanici_koltuk_durum == BOS)
		{ // hata olu�mam��sa ve kullan�c� son vermemi�se devam ve koltuklarda yer varsa
			do
			{
				// ekrana s�n�flar� ve sat�n al�nabilir koltuklar�n� yazmak
				printf("%hd) Hangi sinif koltuk istersiniz: ", _kullanici_sayac + 1);
				scanf("%hd", &_kullanici_sinif);

				for (
					_kullanici_sinif_sayac = ((_kullanici_sinif - 1) * koltuk_tekrar);
					_kullanici_sinif_sayac < (_kullanici_sinif * koltuk_tekrar);
					_kullanici_sinif_sayac++)
				{
					if (koltuk_dizi[_kullanici_sinif_sayac] == BOS)
					{ // e�er koltuk varsa devam
						Koltuk_Durum = BOS;
						_kullanici_durum = Koltuk_Durum;
						sinif_koltuk_dizi[(_kullanici_sinif - 1)] = Koltuk_Durum;
						break;
					}
					else
					{ // e�er hi� koltuk yoksa d�nmesin
						Koltuk_Durum = DOLU;
						_kullanici_durum = Koltuk_Durum;
						sinif_koltuk_dizi[(_kullanici_sinif - 1)] = Koltuk_Durum;
					}
				}
			} while (_kullanici_sinif < 1 || _kullanici_sinif > koltuk_sinif || _kullanici_durum != BOS);

			Bilet_Durum = BEKLIYOR;
			koltukYazdir(koltuk_sinif, koltuk_tekrar, koltuk_sinir, koltuk_dizi, sinif_koltuk_dizi, koltuk_sinif_dizi, koltuk_sinif_karakter_sinir, _kullanici_sinif - 1, _kullanici_sinif);

			do
			{
				printf("Koltuk numarasi giriniz: ");
				scanf("%hd", &_kullanici_koltuk_numara);
			} while (
				koltuk_dizi[(_kullanici_koltuk_numara - 1)] != 0 ||
				_kullanici_koltuk_numara < (((_kullanici_sinif - 1) * koltuk_tekrar) + 1) ||
				_kullanici_koltuk_numara >(_kullanici_sinif * koltuk_tekrar));

			/* mant�ksal hata �nleme kodu */
			if (koltuk_dizi[(_kullanici_koltuk_numara - 1)] != BOS)
			{
				puts("Son islem de mantiksal hata yaptiniz, satin alinan yer bir daha satin aliniyor!! [Mantik Hatasi]");
				puts("Program sonlaniyor...");

				break; // d�n�y� k�r�yoruz
				hata_kodu = HATA; // hata koduna -1 veriyorum ��nk� kod hatas� i�in 0 kullan�yorum, mant�k hatas� i�in -1
				main(hata_kodu); // hata kodu d�n�yor, 1 = ba�ar�, -1,0,2,3,4... = hata
			}

			// girilen koltuk say�s�ndaki yeri 1 ile doldur
			koltuk_dizi[(_kullanici_koltuk_numara - 1)] = DOLU;

			// Koltuk s�n�f� dolu ya da bo� kontrol d�ng�s�
			for (_kullanici_sinif_sayac = ((_kullanici_sinif - 1) * koltuk_tekrar);
				_kullanici_sinif_sayac < (_kullanici_sinif * koltuk_tekrar);
				_kullanici_sinif_sayac++)
			{
				if (koltuk_dizi[_kullanici_sinif_sayac] == DOLU)
				{ // e�er o koltuk s�n�f�ndaki koltuklar doluysa, o koltuk s�n�f dolu yazd�r
					sinif_koltuk_dizi[(_kullanici_sinif - 1)] = DOLU;
				}
				else
				{ // e�er d�ng� de herhangi bir koltuk bo� ise, o koltuk s�n�f� bo� yazd�r d�ng�y� sonland�r
					sinif_koltuk_dizi[(_kullanici_sinif - 1)] = BOS;
					break;
				}
			}

			// ekrana bitel s�ras�, koltuk s�n�f� ve numaras�n� yazd�rma
			Bilet_Durum = SATILDI; // sadece sat�lan koltuk ve s�n�f� yazd�rmak i�in
			puts("--------------------"); // yeni sat�r
			printf("%hd. bilet:\n", _kullanici_sayac + 1);
			// koltuk s�n�f�n� yazd�rma
			koltukYazdir(koltuk_sinif, koltuk_tekrar, koltuk_sinir, NULL, NULL, koltuk_sinif_dizi, koltuk_sinif_karakter_sinir, _kullanici_sinif - 1, _kullanici_sinif);
			printf("%hd nolu koltuk satin alindi\n", _kullanici_koltuk_numara); // sat�n ald��� koltuk numaras�n� yazd�rma
			puts("--------------------"); // yeni sat�r

			/* veri 1 yani dolmu� oluyor mu yoksa veriyi yazm�yor mu test kodu */
			// printf("%hd\n", koltuk_dizi[(((_kullanici_sinif - 1) * koltuk_tekrar) + (_kullanici_koltuk_numara - 1))]);
		}
	}
} // rezervasyonOlustur fonksiyonu sonu

// koltukYazdir fonksiyonu ba�lang�c�
void koltukYazdir(
	const unsigned short koltuk_sinif, // ka� t�r koltuk s�n�f� var
	const unsigned short koltuk_tekrar, // koltuk s�n�flar�ndaki koltuk say�s�
	const unsigned short koltuk_sinir, // t�m koltuklar�n s�n�r�
	const unsigned short koltuk_dizi[], // koltuklar�n dolu ya da bo� oldu�unu anlam�m�z� sa�layan dizi
	const unsigned short sinif_koltuk_dizi[], // o sinifin kotluklar� bo� mu yoksa dolumu
	const char koltuk_sinif_dizi[][EN_SINIF_KARAKTER], // koltuk s�n�flar�n�n ad�n� bar�nd�ran dizi
	const unsigned short koltuk_sinif_karakter_sinir, // koltuk s�n�flar� ad�n�n karakter s�n�r�
	const unsigned short koltuk_sinif_enaz, // en d���k s�raya sahip koltuk s�n�f�
	const unsigned short koltuk_sinif_enfazla // en y�ksek numaraya sahip koltuk s�n�f�
)
{
	auto unsigned short _koltuk_tur_sayac; // 2 tur d�necek
	auto unsigned short _koltuk_yazi_sayac; // ka� karakter varsa o kadar d�necek
	auto unsigned short _koltuk_tekrar_sayac; // koltuk s�n�r� kadar d�necek

	if (Bilet_Durum == SATILDI)
	{ // e�er bilet sat�lm��sa sadece sat�lma bilgilerini yazd�r
		for (_koltuk_tur_sayac = koltuk_sinif_enaz; _koltuk_tur_sayac < koltuk_sinif_enfazla; _koltuk_tur_sayac++)
		{ // koltuk s�n�f�nda depolanm�� olan karakterleri s�rayla yazar
			for (_koltuk_yazi_sayac = 0; _koltuk_yazi_sayac < koltuk_sinif_karakter_sinir; _koltuk_yazi_sayac++)
			{
				printf("%c", koltuk_sinif_dizi[_koltuk_tur_sayac][_koltuk_yazi_sayac]);
			}
		}
	}
	else
	{ // e�er bilet sat�lmam�� ise koltuk s�n�flar�n� ve biletleri g�ster
		for (_koltuk_tur_sayac = koltuk_sinif_enaz; _koltuk_tur_sayac < koltuk_sinif_enfazla; _koltuk_tur_sayac++)
		{
			// TEST KODU: s�n�f bo� ise 0, dolu ise �st�ne 1 yazacakt�r
			//printf("sinif durum: %hd\n", sinif_koltuk_dizi[_koltuk_tur_sayac]);

			if (sinif_koltuk_dizi[_koltuk_tur_sayac] == BOS)
			{ // koltuk s�n�f� bo� ise ekrana yazd�r yoksa yazd�rma
				printf("[%hd] ", _koltuk_tur_sayac + 1); // u�u� s�n�f� s�ra
				for (_koltuk_yazi_sayac = 0; _koltuk_yazi_sayac < koltuk_sinif_karakter_sinir; _koltuk_yazi_sayac++)
				{
					printf("%c", koltuk_sinif_dizi[_koltuk_tur_sayac][_koltuk_yazi_sayac]);
				}
				printf(" bos koltuklar:\n");

				for (_koltuk_tekrar_sayac = (_koltuk_tur_sayac * koltuk_tekrar);
					_koltuk_tekrar_sayac < ((_koltuk_tur_sayac +1) * koltuk_tekrar);
					_koltuk_tekrar_sayac++)
				{
					if (koltuk_dizi[_koltuk_tekrar_sayac] == 0)
					{
						printf("%hd ", _koltuk_tekrar_sayac + 1);
					}
				}
				puts(""); // yeni sat�r
			}
		}
	}
	puts(""); // yeni sat�r
} // koltukYazdir fonksiyonu sonu