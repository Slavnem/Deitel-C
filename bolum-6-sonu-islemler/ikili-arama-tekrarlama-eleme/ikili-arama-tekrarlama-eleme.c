// rastgele sayılar alıp aynı olanları ikili eleme ile eleyip aynı olmayanları çıktı verme
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SINIR 20

/* NOT: MANTIK HATASI SORUN
* HATALI SATIR İLE İLGİLİ AÇIKLAMA 94-95. SATIR DA
* sayı arama yapıyor ve buluyor ise 0 döndürüyor fakat!
* bu sayıdan 1 tane varsa ve biz bu sayıyı arattığımızda zaten
* bu sayıyı bulması gerekmiyor mu? program 1 veya 5 tane var mı bilmiyor,
* biz bir sayaç dizisi oluşturmalıyız ve dizi içinde hiç yoksa sayacı 1 arttırıp
* dizideki bir sonraki sıraya bu sayıyı eklemeliyiz ve sıradaki kontrollerde
* onun da kontrol edilmesini sağlamalıyız, en sonda ise dizi de içindeki değer
1(bir) olanları tekrarsız diziye aktarıp ekrana basmalıyız */

// 11.05.2023 HATA DÜZELTİLDİ!

// ++submain
void submain(void);

// ++diziSiralama
void diziSiralama(
	const short siralama_sinir,
	short siralama_rastgele_dizi[]
);

// ++ikiliKontrol
short ikiliKontrol(
	short ikili_sayac,
	short ikili_sinir,
	const short ikili_aranan,
	const short ikili_rastgele_dizi[]
);

// ++tekrarsizYazdir
void tekrarsizYazdir(
	short yazdir_sayac,
	const short yazdir_sinir,
	const short yazdir_dizi_tekrarsiz[]
);

// +main
short main(void)
{
	submain();
}
// -main

// +submain
void submain(void)
{
	short __submain_dizi_rastgele[SINIR];
	short __submain_rastgele_sayac;
	short __submain_rastgele_sayi;
	short __submain_dizi_ayni[SINIR] = { 0 }; // başlangıçta hiçbiri yok, eğer varsa 1 artar
	short __submain_dizi_tekrarsiz[SINIR];
	short __submain_tekrarsiz_sayac = 0;
	short __submain_tekrarsiz_aranan;
	short __submain_dizi_sayi[SINIR] = { 0 };
	short __submain_ikili_kontrol_donus_deger;

	srand(time(NULL));

	// rastgele sayı atama döngüsü
	for (__submain_rastgele_sayac = 0;
		__submain_rastgele_sayac < SINIR;
		__submain_rastgele_sayac++)
	{
		__submain_rastgele_sayi = rand() % SINIR; // rastgele sayı
		__submain_dizi_rastgele[__submain_rastgele_sayac] = __submain_rastgele_sayi; // dizideki sıraya göre atama

		// oluşan rastgele sayıyı ekrana çıktı vermek
		printf("%hd) %hd rastgele sayidir\n",
			__submain_rastgele_sayac+1,
			__submain_rastgele_sayi);
	}

	// iki kısım arasını ayırma
	puts("-------------------");

	// diziyi sıralı hale getirme
	diziSiralama(
		SINIR,
		__submain_dizi_rastgele
	);

	// dizi sıralanmış mı yoksa sıralanmamış mı ekrana çıktı verip öğrenme ve doğrulama
	for (__submain_rastgele_sayac = 0;
		__submain_rastgele_sayac < SINIR;
		__submain_rastgele_sayac++)
	{
		printf("%hd) %hd siralanmis rastgele sayidir\n",
			__submain_rastgele_sayac + 1,
			__submain_dizi_rastgele[__submain_rastgele_sayac]);
	}

	/* NOT: MANTIK HATASI YAPTIĞIMIZ KISIM, YUKARIDAKİ AÇIKLAMAYI OKUYUP HATAYI DÜZELTELİM */
	// 11.05.2023 HATA DÜZELTİLDİ!

	// sayılardan kaç tane varsa diziye ekleme döngüsü
	for (__submain_rastgele_sayac = 0;
		__submain_rastgele_sayac < SINIR;
		__submain_rastgele_sayac++)
	{
		// aranan sayı
		__submain_tekrarsiz_aranan = __submain_dizi_rastgele[__submain_rastgele_sayac];

		__submain_ikili_kontrol_donus_deger = ikiliKontrol(
			__submain_rastgele_sayac,
			SINIR - 1,
			__submain_tekrarsiz_aranan,
			__submain_dizi_rastgele);

		if (__submain_ikili_kontrol_donus_deger < SINIR)
		{
			++__submain_dizi_sayi[__submain_ikili_kontrol_donus_deger];
		}
	}

	for (__submain_rastgele_sayac = 0;
		__submain_rastgele_sayac < SINIR;
		__submain_rastgele_sayac++)
	{
		// sadece 1 tane varsa o sayıdan
		if (__submain_dizi_sayi[__submain_rastgele_sayac] == 1)
		{
			__submain_dizi_tekrarsiz[__submain_tekrarsiz_sayac] = __submain_rastgele_sayac;
			++__submain_tekrarsiz_sayac;
		}
	}

	// iki kısım arasını ayırma
	puts("-------------------");

	// ekrana tekrarlanmamış sayıları çıktı vermek
	tekrarsizYazdir(
		0,
		__submain_tekrarsiz_sayac,
		__submain_dizi_tekrarsiz
	);
}
// -submain

// ++iziSiralama
void diziSiralama(
	const short siralama_sinir,
	short siralama_rastgele_dizi[]
)
{
	short __siralama_sayac;
	short __siralama_ic_sayac;
	short __siralama_gecici;

	for (__siralama_sayac = siralama_sinir;
		__siralama_sayac > 0;
		--__siralama_sayac)
	{
		for (__siralama_ic_sayac = 0;
			__siralama_ic_sayac < __siralama_sayac -1;
			__siralama_ic_sayac++)
		{
			if (siralama_rastgele_dizi[__siralama_ic_sayac] > siralama_rastgele_dizi[__siralama_ic_sayac +1])
			{
				__siralama_gecici = siralama_rastgele_dizi[__siralama_ic_sayac];
				siralama_rastgele_dizi[__siralama_ic_sayac] = siralama_rastgele_dizi[__siralama_ic_sayac +1];
				siralama_rastgele_dizi[__siralama_ic_sayac +1] = __siralama_gecici;
			}
		}
	}
}
// -diziSiralama

// +ikiliKontrol
short ikiliKontrol(
	short ikili_sayac,
	short ikili_sinir,
	const short ikili_aranan,
	const short ikili_rastgele_dizi[]
)
{
	short __ikili_orta;

	while (ikili_sayac <= ikili_sinir)
	{
		__ikili_orta = (ikili_sayac + ikili_sinir) / 2; // başlangıçta ortalıyoruz

		// aranan sayı ortancaya eşitse
		if (ikili_aranan == ikili_rastgele_dizi[__ikili_orta])
		{
			// sayı bulundu ise kendisi dönsün
			return ikili_aranan;
		}
		// aranan sayı ortancadan küçükse
		else if (ikili_aranan < ikili_rastgele_dizi[__ikili_orta])
		{
			ikili_sinir = __ikili_orta - 1;
		}
		else
		{
			ikili_sayac = __ikili_orta + 1;
		}
	}

	// sayı bulunmadığında -1
	return -1;
}
// -ikiliKontrol

// +tekrarsizYazdir
void tekrarsizYazdir(
	short yazdir_sayac,
	const short yazdir_sinir,
	const short yazdir_dizi_tekrarsiz[]
)
{
	while (yazdir_sayac < yazdir_sinir)
	{
		// ekrana çıktı vermek
		printf("%hd) %hd tekrarlanmamis sayidir\n",
			yazdir_sayac + 1,
			yazdir_dizi_tekrarsiz[yazdir_sayac]);

		// sayacı 1 arttırma ve sonra yeni tur için kullanılır hale getirme
		++yazdir_sayac;
	}
}
// -tekrarsizYazdir