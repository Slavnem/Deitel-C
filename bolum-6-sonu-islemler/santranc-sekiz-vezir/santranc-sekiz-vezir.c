// santranç 8 vezir rastgele
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EKSEN_XY 8
#define VEZIR 8

/*
* çapraz olarak -1 vereceği yerleri hesaplamak için
* küçük ve büyük değişken ile küçük dğeri ve büyüğü bulucaz
* aralarındaki farkı bulup bunu da bir değişkene vericez
* 0dan başlatıp x'i x ile y'i y ile başlatıcaz ama anlık konumundaki fark ile toplayıp
* yani x = 0,  y = 2 olabilir veya x = 0, y = 0 gibi
*/

// ++vezirHesap
// 8 tur dönecek en fazla
short vezirHesap(
	const short hesap_vezir,
	short hesap_satir_x,
	short hesap_sutun_y,
	short hesap_vezir_dizi[][EKSEN_XY],
	short hesap_vezir_sayac
);

/*
NOT: KONUM HESAPLAYIP İLERLEME DE MANTIK HATALARI VAR!
*/

// ++vezirKontrol
// vezir yeri boş ise 1 yani doğru, dolu ise 0 yani yanlış döndürecek
short vezirKontrol(
	const short kontrol_eksen_x,
	const short kontrol_vezir,
	const short kontrol_vezir_dizi[][EKSEN_XY]
);

// ++vezirYazdir
void vezirYazdir(
	const short vezir,
	const short eksen_x,
	const short eksen_y,
	const short dizi_eksen_xy[][EKSEN_XY]
);

// +main
short main(void)
{
	// 0 = boş, 1 = başka bir vezir orayı görüyor
	// vezir sayısı VEZIR = orda bir vezir var
	static short dizi_vezir[EKSEN_XY][EKSEN_XY] = { 0 };
	static short vezir_miktar = 0;

	srand(time(NULL));

	vezirHesap
	(
		VEZIR, // vezir sayısı
		0, // satır başlangıç değeri
		rand() % VEZIR, // ilk satırdaki rastgele sütun yeri
		dizi_vezir, // vezir içeren dizi,
		0 // sayaç
	);

	vezirYazdir
	(
		VEZIR, // vezir miktarı
		0, // yatay(x) ekseni başlangıc değeri
		0, // dikey(y) ekseni başlangıç değeri
		dizi_vezir
	);
}
// -main

// +vezirHesap
short vezirHesap
(
	const short hesap_vezir,
	short hesap_satir_x,
	short hesap_sutun_y,
	short hesap_vezir_dizi[][EKSEN_XY],
	short hesap_vezir_sayac
)
{
	static short __hesap_vezir_bos_sutun = 0; // başlangıç olarak boş sütun vardır diyoruz
	unsigned short __hesap_vezir_surekli_sayac; // sürekli kullanılan sabit durmayan sayaç
	short __hesap_vezir_soldan_capraz_x;
	short __hesap_vezir_soldan_capraz_y;
	short __hesap_vezir_capraz_xy_fark;
	short __hesap_vezir_sagdan_capraz_x;
	short __hesap_vezir_sagdan_capraz_y;

	/*
	* eğer fark eksili ise artıya çevirmessek -fark, çevirirsek +fark -1
	* soldan sağa
	* x = 2, y = 5, y -x = 3, x - 3 +1 = 0; y-3 +1 = 3; x =0, y=3 eğer x ve y 8'den küçük ise devam etsin
	* x = 5, y = 2, y - x = -3, y + -3 +1 = 0; x-3 +1 = 3; x =3, y=0
	* (soldan sağa formül x ve y için: x - fark +1, y - fark +1)
	*  sağdan sola
	* x = 2, y = 5, y + fark -1, eğer fark eksi(-) ise -1 ile çarpışıp artı(+) olacak
	* y = 7, x = 4, eğer x ve y 0'dan büyük veya eşit ise devam etsin
	* (sağdan sola formül x için: x - fark +1)
	* (sağdan sola formül y için: y + fark -1)
	*/

	// boş yer var mı kontrol ediyoruz
	if (hesap_vezir_sayac < 0 ||
		hesap_vezir_sayac >= hesap_vezir ||
		__hesap_vezir_bos_sutun == -1)
	{
		// daha da dönemeyecek hale gelmiştir bu yüzden döndürme sonlanıyor
		return 0;
	}
	else
	{
		// boş sütun kalmamış varsayıyoruz
		__hesap_vezir_bos_sutun = -1;

		// eğer boş yer varsa devam
		if (vezirKontrol(hesap_satir_x, hesap_vezir, hesap_vezir_dizi) == 1)
		{
			// farkı buluyoruz
			__hesap_vezir_capraz_xy_fark = hesap_sutun_y - hesap_satir_x;

			if (__hesap_vezir_capraz_xy_fark < 0)
			{
				// fark eksili(-) ise -1 ile çarpıp pozitif yap
				__hesap_vezir_capraz_xy_fark *= (-1);
			}

			// soldan sağa ve sağdan sola x ve y için konum hesaplıyoruz
			__hesap_vezir_soldan_capraz_x = (hesap_satir_x - __hesap_vezir_capraz_xy_fark) + 1;
			__hesap_vezir_soldan_capraz_y = (hesap_sutun_y - __hesap_vezir_capraz_xy_fark) + 1;
			__hesap_vezir_sagdan_capraz_x = (hesap_satir_x - __hesap_vezir_capraz_xy_fark) + 1;
			__hesap_vezir_sagdan_capraz_y = (hesap_sutun_y + __hesap_vezir_capraz_xy_fark) - 1;

			// soldan sağa
			/* soldan sağa mantığı: soldaki satır en üstten başalr ve sütun da satırla birlikte 
			1er 1er artar, satır 1,2,3.. diye giderken sütun da 2,3,4... diye gidebilir ve bu sayede
			soldan sağa çapraz yapmış oluruz */
			for (__hesap_vezir_surekli_sayac = __hesap_vezir_soldan_capraz_x;
				__hesap_vezir_surekli_sayac >= 0 && __hesap_vezir_surekli_sayac < hesap_vezir &&
				__hesap_vezir_soldan_capraz_y >= 0 && __hesap_vezir_soldan_capraz_y < hesap_vezir;
				__hesap_vezir_surekli_sayac++ && __hesap_vezir_soldan_capraz_y++)
			{
				hesap_vezir_dizi[__hesap_vezir_surekli_sayac][__hesap_vezir_soldan_capraz_y] = 1;
			}

			// sağdan sola
			/* sağdan sola mantığı: sağdaki satır en üstten başlar ve sütun ise son sütun sayısı
			yani en köşe 8 den başlar, satır gittikçe artar ama sütun azalır, 7,6,5... diye ve 
			bu sayede sağdan sola çapraz yapmış oluruz */
			for (__hesap_vezir_surekli_sayac = __hesap_vezir_sagdan_capraz_x;
				__hesap_vezir_surekli_sayac >= 0 && __hesap_vezir_surekli_sayac < hesap_vezir &&
				__hesap_vezir_sagdan_capraz_y >= 0 && __hesap_vezir_sagdan_capraz_y < hesap_vezir;
				__hesap_vezir_surekli_sayac++ && __hesap_vezir_sagdan_capraz_y--)
			{
				hesap_vezir_dizi[__hesap_vezir_surekli_sayac][__hesap_vezir_sagdan_capraz_y] = 1;
			}

			// o sütunu ve satırı full dolu hale getirmek çünkü vezir yukarı aşağı ve sağ sola düz gidebiliyor
			for (__hesap_vezir_surekli_sayac = 0;
				__hesap_vezir_surekli_sayac < hesap_vezir;
				__hesap_vezir_surekli_sayac++)
			{
				hesap_vezir_dizi[__hesap_vezir_surekli_sayac][hesap_sutun_y] = 1; // satır 1 ile doluyor
				hesap_vezir_dizi[hesap_satir_x][__hesap_vezir_surekli_sayac] = 1; // sütun 1 ile doluyor
			}

			// vezirin asıl olduğu konuma VEZIR
			// daha rahat okuyabileyim diye test amaçlı 2 yazdım, 8 ile 0 birbirine benziyor
			hesap_vezir_dizi[hesap_satir_x][hesap_sutun_y] = hesap_vezir;

			// sıradaki satır için satırı 1 arttırıyoruz
			hesap_satir_x += 1;
			if (hesap_satir_x < hesap_vezir)
			{
				/* boş yer var mı kontrol ediyoruz */
				for (__hesap_vezir_surekli_sayac = 0;
					__hesap_vezir_surekli_sayac < hesap_vezir;
					__hesap_vezir_surekli_sayac++)
				{
					// eğer o satırda boş sütun varsa 0'a eşit olacaktır çünkü diziye başta otomatik 0 verdik
					if (hesap_vezir_dizi [hesap_satir_x] [__hesap_vezir_surekli_sayac] == 0)
					{
						// boş olan sütunun numarasını veriyoruz
						__hesap_vezir_bos_sutun = __hesap_vezir_surekli_sayac;
						break;
					}
				}

				return vezirHesap
				(
					hesap_vezir, // vezir sayısı sabit
					hesap_satir_x, // satır numarası
					__hesap_vezir_bos_sutun, // boşta oaln sütun numarası
					hesap_vezir_dizi, // vezirlerin, dolu ve boş yerlerin tutulduğu dizi
					hesap_vezir_sayac++ // tur sayacı
				);
			}
		}

		// eğer boş yer kalmamışsa daha dönmeyecek fonksiyon
		return 0;
	}
}
// -vezirHesap

// +vezirKontrol
short vezirKontrol
(
	const short kontrol_eksen_x,
	const short kontrol_vezir,
	const short kontrol_vezir_dizi[][EKSEN_XY]
)
{
	unsigned short __kontrol_vezir_sayac;

	for (__kontrol_vezir_sayac = 0;
		__kontrol_vezir_sayac < kontrol_vezir;
		__kontrol_vezir_sayac++)
	{
		if (kontrol_vezir_dizi[kontrol_eksen_x][__kontrol_vezir_sayac] == 0)
		{
			// boş yer varsa 1 döndür
			return 1;
		}
	}

	// boş yer yoksa 0 döndürecek
	return 0;
}
// -vezirKontrol

// +vezirYazdir
void vezirYazdir
(
	const short vezir,
	const short eksen_x,
	const short eksen_y,
	const short dizi_eksen_xy[][EKSEN_XY]
)
{
	unsigned short __yazdir_eksen_x_sayac;
	unsigned short __yazdir_eksen_y_sayac;

	for (__yazdir_eksen_x_sayac = 0;
		__yazdir_eksen_x_sayac < vezir;
		__yazdir_eksen_x_sayac++)
	{
		for (__yazdir_eksen_y_sayac = 0;
			__yazdir_eksen_y_sayac < vezir;
			__yazdir_eksen_y_sayac++)
		{
			// satır ve sütunun çıktısını vermek sırayla
			printf("%hd ", dizi_eksen_xy[__yazdir_eksen_x_sayac][__yazdir_eksen_y_sayac]);
		}
		puts(""); // yeni satır
	}
}
// -vezirYazdir
