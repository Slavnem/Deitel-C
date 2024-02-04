// santrançta at problemi
#include <stdio.h>

#define EKSEN_XY 8

static short dizi_santranc_at[EKSEN_XY][EKSEN_XY] = { 0 }; // değerleri saklayan dizi
const static short dizi_santranc_y[EKSEN_XY] = { 2,1,-1,-2,-2,-1,1,2 }; // sabit yatay değerler
const static short dizi_santranc_x[EKSEN_XY] = { 1,2,2,1,-1,-2,-2,-1 }; // sabit dikey değerler

// ++santrancYerKontrol
short santrancYerKontrol(
	short santranc_yer_x, // yatay(x) deki yeri kontrol için
	short santranc_yer_y // dikey(y) deki yeri kontrol için
);

// ++santrancHesap
short santrancHesap(
	short santranc_x, // yatay
	short santranc_y, // dikey
	short santranc_hareket // hareket sayısı
);

// ++santrancYazdir
void santrancYazdir(
	short santranc_tur // kaç tur yazdıracağı
);

// +main
int main(void)
{
	santrancHesap(
		0, // başlangıçtan sonraki gideceği yatay(x) miktarı
		0, // başlangıçtan sonraki gideceği dikey(y) miktarı
		1 // başalngıçtan sonraki hareket miktarı
	);

	// hepsi bittikten sonra ekrana çıktı vermek
	santrancYazdir(EKSEN_XY * EKSEN_XY);
}
// -main

// +santrancYerKontrol
short santrancYerKontrol(
	short santranc_yer_x,
	short santranc_yer_y
)
{
	/* eğer santrançta 0 dahil ve 8 i aşmadan devam ediyorsa 1 ve boş yer varsa 
	1 döndür, eğer yoksa zaten otomatik 0 döndürür */
	return (
		santranc_yer_x >= 0 && santranc_yer_x < EKSEN_XY &&
		santranc_yer_y >= 0 && santranc_yer_y < EKSEN_XY &&
		dizi_santranc_at[santranc_yer_x][santranc_yer_y] == 0
		);
}
// -santrancYerKontrol

// +santrancHesap
short santrancHesap(
	short santranc_x,
	short santranc_y,
	short santranc_hareket
)
{
	// eğer tur sayısı dolmuşsa bitir
	if (santranc_hareket == EKSEN_XY * EKSEN_XY)
	{
		return 1;
	}

	short __santranc_hareket_x; // hareket edeceği yatay konum
	short __santranc_hareket_y; // hareket edeceği dikey konum
	short __santranc_hareket_sayac; // hareket edeceği tur miktarı

	// hareket turu eksen miktarından küçükse hareket etsin
	for (__santranc_hareket_sayac = 0;
		__santranc_hareket_sayac < EKSEN_XY;
		__santranc_hareket_sayac++)
	{
		__santranc_hareket_x = santranc_x + dizi_santranc_x[__santranc_hareket_sayac]; // yeni yer yatay(x)
		__santranc_hareket_y = santranc_y + dizi_santranc_y[__santranc_hareket_sayac]; // yeni yer dikey(y)

		// boş yer varsa eğer
		if (santrancYerKontrol(__santranc_hareket_x, __santranc_hareket_y) == 1)
		{
			// dizideki yere hareket sayısını yaz
			dizi_santranc_at[__santranc_hareket_x][__santranc_hareket_y] = santranc_hareket;

			// kendi tur sayısını 1 arttır ve doğruysa 1 döndür
			if (santrancHesap(__santranc_hareket_x, __santranc_hareket_y, santranc_hareket + 1) == 1)
			{
				return 1;
			}
			// değilse 0
			else
			{
				dizi_santranc_at[__santranc_hareket_x][__santranc_hareket_y] = 0;
			}
		}
	}
	// döngü bitmişse 0 ile bitir
	return 0;
}
// -santrancHesap

// +santrancYazdir
void santrancYazdir(
	short santranc_tur
)
{
	short __santranc_sayac_x; // yatay eksen sayacı
	short __santranc_sayac_y; // dikey eksen sayacı

	for (__santranc_sayac_x = 0;
		__santranc_sayac_x < EKSEN_XY;
		__santranc_sayac_x++)
	{
		for (__santranc_sayac_y = 0;
			__santranc_sayac_y < EKSEN_XY;
			__santranc_sayac_y++)
		{
			// eğer 10 dan küçük ise başına 0 ekle, hoş gözüksün diye
			if (dizi_santranc_at[__santranc_sayac_x][__santranc_sayac_y] +1 < 10)
			{
				printf("0%hd ", dizi_santranc_at[__santranc_sayac_x][__santranc_sayac_y] +1);
			}
			else
			{
				printf("%hd ", dizi_santranc_at[__santranc_sayac_x][__santranc_sayac_y] +1);
			}
		}
		puts(""); // yataydaki o satır bitti, yeni satıra geç
	}
}
// -santrancYazdir