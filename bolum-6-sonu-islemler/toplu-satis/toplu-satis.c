// Toplu Sat��
/* 5 �r�n ve 4 sorumlu, iki indisli dizi
* �al�a�nlar g�nde bir kez her �r�n i�in fatura sunmal�
* her faturada sat�� sorumlusu numaras�, �r�n, numaras�, �r�n�n sat���ndan elde edilen miktar
* ge�en aya ait t�m fatura bilindi�ini varsayal�m
* t�m toplamlar 2 boyutlu sales dizisinde depolanmal�d�r, ge�en ay�n t�m bilgilerini i�ledikten sonra
* �izelge olarak g�ster, her s�tunun ilgili sat�� sorumlusu ve sat�r�n ilgili �r�n� g�sterdi�i bi�imde
* her bir sat�r�n toplam� her �r�n�n t�m ay boyunca yap�ld�� sat���, her s�tun ise bir eleman�n t�m ay
* boyunca yapt��� sat��� g�stermelidir
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define URUN_MIKTAR 5
#define SATIS_SORUMLU 4
#define UST_FATURA_SINIR 5

// sat�� sorumlulular�n�n satt��� �r�nlerin miktar�n�n depoland��� dizi
static unsigned short Satis_Sorumlu_Dizi[SATIS_SORUMLU][URUN_MIKTAR] = { 0 };
// fonksiyon ile rastgele fiyat da verebilirdim ama sorudan kopmamak ad�na b�yle yapt�m
static unsigned short Urun_Fiyat_Dizi[URUN_MIKTAR] = { 3, 2, 4, 5, 1 };
// �r�nlerin toplam fiyat�n�n tutuldu�u dizi
static unsigned short Urun_Toplam_Dizi[URUN_MIKTAR] = { 0 };

// fonksiyon tan�m�
void sales(
	const unsigned short fatura_ust_sinir, // fatural� son �r�n�n numaras�
	const unsigned short satis_sorumlu_sinir, // satis sorumlusu son ki�inin numaras�
	const unsigned short urun_fiyat_dizi[], // �r�nlerin fiyatlar�n�n oldu�u dizi
	unsigned short urun_toplam_dizi[], // �r�nlerin toplam fiyat�n�n oldu�u dizi
	unsigned short satis_sorumlu_dizi[][UST_FATURA_SINIR] // sat�� sorumlular�n�n hangi �r�nden ne kadar fatura verdi�inin bilgisi
);

void salesYazdir(
	const unsigned short fatura_ust_sinir, // fatural� son �r�n�n numaras�
	const unsigned short satis_sorumlu_sinir, // satis sorumlusu son ki�inin numaras�
	const unsigned short urun_fiyat_dizi[], // �r�nlerin fiyatlar�n�n oldu�u dizi
	const unsigned short urun_toplam_dizi[], // �r�nlerin toplam fiyat�n�n oldu�u dizi
	const unsigned short satis_sorumlu_dizi[][UST_FATURA_SINIR] // sat�� sorumlular�n�n hangi �r�nden ne kadar fatura verdi�inin bilgisi
);

// main fonksiyonu ba�lang�c�
int main(void)
{
	srand(time(NULL)); // i�emciden rastgele zaman almak

	sales(
		UST_FATURA_SINIR, // en �ok vermesi gereken fatura g�nl�k
		SATIS_SORUMLU, // sat�� sorumlular�n�n say�s�
		Urun_Fiyat_Dizi, // �r�nlerin fiyatlar�n�n oldu�u dizi
		Urun_Toplam_Dizi, // O �r�nden toplam ne kadar sat�ld� dizisi
		Satis_Sorumlu_Dizi // �al��an ve satt�klar� �r�nlerin oldu�u dizi
	);
} // main fonksiyonu sonu

// sales fonksiyonu tan�m
void sales(
	const unsigned short fatura_ust_sinir, // fatural� son �r�n�n numaras�
	const unsigned short satis_sorumlu_sinir, // satis sorumlusu son ki�inin numaras�
	const unsigned short urun_fiyat_dizi[], // �r�nlerin fiyatlar�n�n oldu�u dizi
	unsigned short urun_toplam_dizi[], // �r�nlerin toplam fiyat�n�n oldu�u dizi
	unsigned short satis_sorumlu_dizi[][UST_FATURA_SINIR] // sat�� sorumlular�n�n hangi �r�nden ne kadar fatura verdi�inin bilgisi
)
{ // sales fonksiyonu ba�lang�c�
	unsigned short _satis_sorumlu_sayac;
	unsigned short _satis_urun_sayac;

	for ( // sat�� sorumlusu sayac�
		_satis_sorumlu_sayac = 0;
		_satis_sorumlu_sayac < satis_sorumlu_sinir;
		_satis_sorumlu_sayac++)
	{
		for ( // �r�n fatura sayac�
			_satis_urun_sayac = 0;
			_satis_urun_sayac < fatura_ust_sinir;
			_satis_urun_sayac++)
		{
			// rastgele fatura miktar� bulmak
			satis_sorumlu_dizi[_satis_sorumlu_sayac][_satis_urun_sayac] = 1 + (rand() % 5);
			// �r�nlerin faturas�n� ekrana yazd�r�p test etme
			// ekrana sorumlu ki�iyi yazd�r�p test etme | printf("sorumlu: %hd\t", _satis_sorumlu_sayac);
			// ekrana faturay� yazd�r�p test etme | printf("fatura: %hd\n", satis_sorumlu_dizi[_satis_sorumlu_sayac][_satis_urun_sayac]);

			// o �r�nden toplanan fatura miktar�na g�re toplam paray� bulmak
			urun_toplam_dizi[_satis_urun_sayac] +=
				(satis_sorumlu_dizi[_satis_sorumlu_sayac][_satis_urun_sayac]) *
				(urun_fiyat_dizi[_satis_urun_sayac]);

			// �r�nlerin fiyatlar�n� do�ru hesapl�yomu diye toplam paray� yazd�rmak
			// printf("toplam fiyat: %hd\n", urun_toplam_dizi[_satis_urun_sayac]);

			// rastgele ��kan faturalar olu�uyormu diye ekrana test olarak yazd�rma kodu
			// printf("%hd\n", satis_sorumlu_dizi[_satis_sorumlu_sayac][_satis_urun_sayac]);
		}
	}

	// salesYazdir ile sorumlular� �r�nleri ve fiyatlar�n� yazd�rmak
	salesYazdir(
		fatura_ust_sinir,
		satis_sorumlu_sinir,
		urun_fiyat_dizi,
		urun_toplam_dizi,
		satis_sorumlu_dizi
	);

	// �r�nlerin toplam fiyat�n� yazd�ran test kodu
	/* for (
		_satis_urun_sayac = 0;
		_satis_urun_sayac < fatura_ust_sinir;
		_satis_urun_sayac++)
	{
		printf("toplam: %hd\n", urun_toplam_dizi[_satis_urun_sayac]);
	} */
} // sales fonksiyonu sonu

// salesYazdir fonksiyonu tan�m�
void salesYazdir(
	const unsigned short fatura_ust_sinir, // fatural� son �r�n�n numaras�
	const unsigned short satis_sorumlu_sinir, // satis sorumlusu son ki�inin numaras�
	const unsigned short urun_fiyat_dizi[], // �r�nlerin fiyatlar�n�n oldu�u dizi
	const unsigned short urun_toplam_dizi[], // �r�nlerin toplam fiyat�n�n oldu�u dizi
	const unsigned short satis_sorumlu_dizi[][UST_FATURA_SINIR] // sat�� sorumlular�n�n hangi �r�nden ne kadar fatura verdi�inin bilgisi
)
{ // salesYazdir fonksiyonu ba�lang�c�
	auto unsigned short _sales_satir_sayac;
	auto unsigned short _sales_sorumlu_sayac = 0; // belirlenen satir siniri hesaplamak i�in ba�lang�� de�eri verdim
	auto unsigned short _sales_urun_sayac;
	auto unsigned short _satir_sinir = 5;

	// Sorumlu Ki�i S�tun
	for (
		_sales_satir_sayac = 0;
		_sales_satir_sayac < ((satis_sorumlu_sinir / _satir_sinir) +1);
		_sales_satir_sayac++
		)
	{
		// Sorumlu ba�l�k
		printf("%s", "\nSorumlu:");

		// ekrana sat�r ve s�tunu olu�turmak
		for ( // s�tun sayac�
			_sales_sorumlu_sayac = (_sales_satir_sayac * _satir_sinir);
			_sales_sorumlu_sayac < satis_sorumlu_sinir && _sales_sorumlu_sayac < ((_sales_satir_sayac +1) * _satir_sinir);
			_sales_sorumlu_sayac++)
		{
			printf("\t [%hd]", _sales_sorumlu_sayac + 1);
		}
		puts(""); // yeni sat�r

		for ( // �r�n fatura sayac�
			_sales_urun_sayac = 0;
			_sales_urun_sayac < fatura_ust_sinir;
			_sales_urun_sayac++
			)
		{
			// �r�n s�ras� 
			printf("[%hd]Urun: ", _sales_urun_sayac+1);

			for ( // sat�� sorumlusu sayac�
				_sales_sorumlu_sayac = (_sales_satir_sayac * _satir_sinir);
				_sales_sorumlu_sayac < satis_sorumlu_sinir && _sales_sorumlu_sayac < ((_sales_satir_sayac + 1)* _satir_sinir);
				_sales_sorumlu_sayac++
				)
			{
				// ba��na bo�luk b�rak�p sonras�nda 1 bo�luk b�rak�yoruz ki hizal� olsun
				printf("\t%3hd", satis_sorumlu_dizi[_sales_sorumlu_sayac][_sales_urun_sayac]);
			}

			puts(""); // yeni sat�r
			printf("[%hd]Toplam: %hd\n", _sales_urun_sayac + 1, urun_toplam_dizi[_sales_urun_sayac]);
		}

		if (_sales_sorumlu_sayac % _satir_sinir == 0)
		{
			puts("\n"); // yeni sat�r
		}
	}
} // salesYazdir fonksiyonu sonu