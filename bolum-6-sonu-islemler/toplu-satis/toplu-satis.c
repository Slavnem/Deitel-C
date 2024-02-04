// Toplu Satýþ
/* 5 ürün ve 4 sorumlu, iki indisli dizi
* çalýaþnlar günde bir kez her ürün için fatura sunmalý
* her faturada satýþ sorumlusu numarasý, ürün, numarasý, ürünün satýþýndan elde edilen miktar
* geçen aya ait tüm fatura bilindiðini varsayalým
* tüm toplamlar 2 boyutlu sales dizisinde depolanmalýdýr, geçen ayýn tüm bilgilerini iþledikten sonra
* çizelge olarak göster, her sütunun ilgili satýþ sorumlusu ve satýrýn ilgili ürünü gösterdiði biçimde
* her bir satýrýn toplamý her ürünün tüm ay boyunca yapýldýð satýþý, her sütun ise bir elemanýn tüm ay
* boyunca yaptýðý satýþý göstermelidir
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define URUN_MIKTAR 5
#define SATIS_SORUMLU 4
#define UST_FATURA_SINIR 5

// satýþ sorumlulularýnýn sattýðý ürünlerin miktarýnýn depolandýðý dizi
static unsigned short Satis_Sorumlu_Dizi[SATIS_SORUMLU][URUN_MIKTAR] = { 0 };
// fonksiyon ile rastgele fiyat da verebilirdim ama sorudan kopmamak adýna böyle yaptým
static unsigned short Urun_Fiyat_Dizi[URUN_MIKTAR] = { 3, 2, 4, 5, 1 };
// ürünlerin toplam fiyatýnýn tutulduðu dizi
static unsigned short Urun_Toplam_Dizi[URUN_MIKTAR] = { 0 };

// fonksiyon tanýmý
void sales(
	const unsigned short fatura_ust_sinir, // faturalý son ürünün numarasý
	const unsigned short satis_sorumlu_sinir, // satis sorumlusu son kiþinin numarasý
	const unsigned short urun_fiyat_dizi[], // ürünlerin fiyatlarýnýn olduðu dizi
	unsigned short urun_toplam_dizi[], // ürünlerin toplam fiyatýnýn olduðu dizi
	unsigned short satis_sorumlu_dizi[][UST_FATURA_SINIR] // satýþ sorumlularýnýn hangi üründen ne kadar fatura verdiðinin bilgisi
);

void salesYazdir(
	const unsigned short fatura_ust_sinir, // faturalý son ürünün numarasý
	const unsigned short satis_sorumlu_sinir, // satis sorumlusu son kiþinin numarasý
	const unsigned short urun_fiyat_dizi[], // ürünlerin fiyatlarýnýn olduðu dizi
	const unsigned short urun_toplam_dizi[], // ürünlerin toplam fiyatýnýn olduðu dizi
	const unsigned short satis_sorumlu_dizi[][UST_FATURA_SINIR] // satýþ sorumlularýnýn hangi üründen ne kadar fatura verdiðinin bilgisi
);

// main fonksiyonu baþlangýcý
int main(void)
{
	srand(time(NULL)); // iþemciden rastgele zaman almak

	sales(
		UST_FATURA_SINIR, // en çok vermesi gereken fatura günlük
		SATIS_SORUMLU, // satýþ sorumlularýnýn sayýsý
		Urun_Fiyat_Dizi, // ürünlerin fiyatlarýnýn olduðu dizi
		Urun_Toplam_Dizi, // O üründen toplam ne kadar satýldý dizisi
		Satis_Sorumlu_Dizi // çalýþan ve sattýklarý ürünlerin olduðu dizi
	);
} // main fonksiyonu sonu

// sales fonksiyonu taným
void sales(
	const unsigned short fatura_ust_sinir, // faturalý son ürünün numarasý
	const unsigned short satis_sorumlu_sinir, // satis sorumlusu son kiþinin numarasý
	const unsigned short urun_fiyat_dizi[], // ürünlerin fiyatlarýnýn olduðu dizi
	unsigned short urun_toplam_dizi[], // ürünlerin toplam fiyatýnýn olduðu dizi
	unsigned short satis_sorumlu_dizi[][UST_FATURA_SINIR] // satýþ sorumlularýnýn hangi üründen ne kadar fatura verdiðinin bilgisi
)
{ // sales fonksiyonu baþlangýcý
	unsigned short _satis_sorumlu_sayac;
	unsigned short _satis_urun_sayac;

	for ( // satýþ sorumlusu sayacý
		_satis_sorumlu_sayac = 0;
		_satis_sorumlu_sayac < satis_sorumlu_sinir;
		_satis_sorumlu_sayac++)
	{
		for ( // ürün fatura sayacý
			_satis_urun_sayac = 0;
			_satis_urun_sayac < fatura_ust_sinir;
			_satis_urun_sayac++)
		{
			// rastgele fatura miktarý bulmak
			satis_sorumlu_dizi[_satis_sorumlu_sayac][_satis_urun_sayac] = 1 + (rand() % 5);
			// ürünlerin faturasýný ekrana yazdýrýp test etme
			// ekrana sorumlu kiþiyi yazdýrýp test etme | printf("sorumlu: %hd\t", _satis_sorumlu_sayac);
			// ekrana faturayý yazdýrýp test etme | printf("fatura: %hd\n", satis_sorumlu_dizi[_satis_sorumlu_sayac][_satis_urun_sayac]);

			// o üründen toplanan fatura miktarýna göre toplam parayý bulmak
			urun_toplam_dizi[_satis_urun_sayac] +=
				(satis_sorumlu_dizi[_satis_sorumlu_sayac][_satis_urun_sayac]) *
				(urun_fiyat_dizi[_satis_urun_sayac]);

			// ürünlerin fiyatlarýný doðru hesaplýyomu diye toplam parayý yazdýrmak
			// printf("toplam fiyat: %hd\n", urun_toplam_dizi[_satis_urun_sayac]);

			// rastgele çýkan faturalar oluþuyormu diye ekrana test olarak yazdýrma kodu
			// printf("%hd\n", satis_sorumlu_dizi[_satis_sorumlu_sayac][_satis_urun_sayac]);
		}
	}

	// salesYazdir ile sorumlularý ürünleri ve fiyatlarýný yazdýrmak
	salesYazdir(
		fatura_ust_sinir,
		satis_sorumlu_sinir,
		urun_fiyat_dizi,
		urun_toplam_dizi,
		satis_sorumlu_dizi
	);

	// ürünlerin toplam fiyatýný yazdýran test kodu
	/* for (
		_satis_urun_sayac = 0;
		_satis_urun_sayac < fatura_ust_sinir;
		_satis_urun_sayac++)
	{
		printf("toplam: %hd\n", urun_toplam_dizi[_satis_urun_sayac]);
	} */
} // sales fonksiyonu sonu

// salesYazdir fonksiyonu tanýmý
void salesYazdir(
	const unsigned short fatura_ust_sinir, // faturalý son ürünün numarasý
	const unsigned short satis_sorumlu_sinir, // satis sorumlusu son kiþinin numarasý
	const unsigned short urun_fiyat_dizi[], // ürünlerin fiyatlarýnýn olduðu dizi
	const unsigned short urun_toplam_dizi[], // ürünlerin toplam fiyatýnýn olduðu dizi
	const unsigned short satis_sorumlu_dizi[][UST_FATURA_SINIR] // satýþ sorumlularýnýn hangi üründen ne kadar fatura verdiðinin bilgisi
)
{ // salesYazdir fonksiyonu baþlangýcý
	auto unsigned short _sales_satir_sayac;
	auto unsigned short _sales_sorumlu_sayac = 0; // belirlenen satir siniri hesaplamak için baþlangýç deðeri verdim
	auto unsigned short _sales_urun_sayac;
	auto unsigned short _satir_sinir = 5;

	// Sorumlu Kiþi Sütun
	for (
		_sales_satir_sayac = 0;
		_sales_satir_sayac < ((satis_sorumlu_sinir / _satir_sinir) +1);
		_sales_satir_sayac++
		)
	{
		// Sorumlu baþlýk
		printf("%s", "\nSorumlu:");

		// ekrana satýr ve sütunu oluþturmak
		for ( // sütun sayacý
			_sales_sorumlu_sayac = (_sales_satir_sayac * _satir_sinir);
			_sales_sorumlu_sayac < satis_sorumlu_sinir && _sales_sorumlu_sayac < ((_sales_satir_sayac +1) * _satir_sinir);
			_sales_sorumlu_sayac++)
		{
			printf("\t [%hd]", _sales_sorumlu_sayac + 1);
		}
		puts(""); // yeni satýr

		for ( // ürün fatura sayacý
			_sales_urun_sayac = 0;
			_sales_urun_sayac < fatura_ust_sinir;
			_sales_urun_sayac++
			)
		{
			// Ürün sýrasý 
			printf("[%hd]Urun: ", _sales_urun_sayac+1);

			for ( // satýþ sorumlusu sayacý
				_sales_sorumlu_sayac = (_sales_satir_sayac * _satir_sinir);
				_sales_sorumlu_sayac < satis_sorumlu_sinir && _sales_sorumlu_sayac < ((_sales_satir_sayac + 1)* _satir_sinir);
				_sales_sorumlu_sayac++
				)
			{
				// baþýna boþluk býrakýp sonrasýnda 1 boþluk býrakýyoruz ki hizalý olsun
				printf("\t%3hd", satis_sorumlu_dizi[_sales_sorumlu_sayac][_sales_urun_sayac]);
			}

			puts(""); // yeni satýr
			printf("[%hd]Toplam: %hd\n", _sales_urun_sayac + 1, urun_toplam_dizi[_sales_urun_sayac]);
		}

		if (_sales_sorumlu_sayac % _satir_sinir == 0)
		{
			puts("\n"); // yeni satýr
		}
	}
} // salesYazdir fonksiyonu sonu