#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

// fonksiyon tanimlari
void minimum(int* grades, int* lowGradePtr, size_t pupils, size_t tests);
void maximum(int* grades, int* highGradePtr, size_t pupils, size_t tests);
void average(int* grades, int* averageGrades, size_t pupils, size_t tests);
void printArray(int* grades, int* totalLength, size_t pupils, size_t tests);
void printChArrayPtr(const char* arrayPtr[], size_t sizeArray);

void (*processGrades[])(int*, int*, size_t, size_t) =
{
	printArray,
	minimum,
	maximum,
	average
};

enum NOTMENU
{
	E__NOTDIZI = 0, // Notlarin bulundugu diziyi yazdirma
	E__MINNOT = 1, // En dusuk (minimum) not
	E__MAXNOT = 2, // En yuksek (maximum) not
	E__OGRORT = 3, // Herbir ogrencinin tum testlerdeki ortalamasini yazdirma
	E__SON = 4 // programi sonlandir
};

enum DURUM
{
	E__YANLIS = 0,
	E__DOGRU = 1
};

enum AKTIFLIK
{
	E__PASIF = 0, // deaktif
	E__AKTIF = 1 // aktif
};

const char* menuler_ArrayPtr[] =
{
	"Notlarin bulundugu diziyi yazdir",
	"Minimum notu bul",
	"Maksimum notu bul",
	"Herbir ogrencinin tum testlerdeki ortalamasini yazdir",
	"Programi sonlandir"
};

const int aktifMenu_Array[] =
{
	E__AKTIF, // not dizi
	E__AKTIF, // min not
	E__AKTIF, // max not
	E__AKTIF // ogrenciler ortalama
};

int main(void)
{
	// menuler dizisi boyutu
	const int __size_menulerPtr = sizeof(menuler_ArrayPtr) / sizeof(menuler_ArrayPtr[0]);

	// ogrencilere ait notlarin tutuldugu dizi
	int studentGrades[STUDENTS][EXAMS] =
	{
			{ 77, 68, 86, 73 },
			{ 96, 87, 89, 78 },
			{ 70, 90, 86, 81 }
	};

	int averageGrades[STUDENTS] = {0};

	enum DURUM __eDurum;

	const int __size_students = sizeof(studentGrades) / sizeof(studentGrades[0]);
	const int __size_exams = sizeof(studentGrades[0]) / sizeof(studentGrades[0][0]);

	const int __size_average = sizeof(averageGrades) / sizeof(averageGrades[0]);
	const int __size_average_grade = sizeof(averageGrades) / sizeof(averageGrades);

	int __size_total = (__size_students * __size_exams);
	int __lowGrade;
	int __highGrade;
	int __temp_value;

	do
	{
		// bilgilendirici cikti
		puts("Bir secim yapiniz:");
		printChArrayPtr(menuler_ArrayPtr, __size_menulerPtr);

		scanf("%d", &__temp_value); // gelen degeri oku

		switch(__temp_value)
		{
			case E__NOTDIZI:
			case E__MINNOT:
			case E__MAXNOT:
			case E__OGRORT:
			case E__SON:
				__eDurum = E__DOGRU;
				break;
			default:
				__eDurum = E__YANLIS;
				break;
		}
	} while(__eDurum != E__DOGRU);

	// ek kontrol ama normalde abarti guvenli acigi olmayacagindan
	// gerek yok
	if(__eDurum == E__DOGRU)
	{
		switch(__temp_value)
		{
			// not dizisini yazdir
			case E__NOTDIZI:
				(*processGrades[E__NOTDIZI])
				(
					&studentGrades[0][0], &__size_total,
					__size_students, __size_exams
				);
				break;
			// en dusuk not
			case E__MINNOT:
				(*processGrades[E__MINNOT])
				(
					&studentGrades[0][0], &__lowGrade,
					(__size_students), // STUDENTS
					(__size_exams) // EXAMS
				);

				printf("En dusuk not: %d\n", (__lowGrade));
				break;
			// en yuksek not
			case E__MAXNOT:
				(*processGrades[E__MAXNOT])
				(
					&studentGrades[0][0], &__highGrade,
					(__size_students), // STUDENTS
					(__size_exams) // EXAMS
				);

				printf("En yuksek not: %d\n", (__highGrade));
				break;
			// hepsi ortalama not
			case E__OGRORT:
				(*processGrades[E__OGRORT])
				(
					&studentGrades[0][0], &averageGrades[0],
					(__size_students), // STUDENTS
					(__size_exams) // EXAMS
				);

				// ortalamayi cikti ver
				(*processGrades[E__NOTDIZI])
				(
					&averageGrades[0], &__size_total,
					__size_average, __size_average_grade
				);
				break;
			// program sonlandir
			default:
				return E__SON;
		}
	}
}

void minimum(int* grades, int* lowGradePtr, size_t pupils, size_t tests)
{
	size_t __countStudent;
	size_t __countExam;

	// en dusuk deger olarak dizinin baslangicini veriyoruz
	int __lowestGrade = *grades;
	int __temp;

	// ogrenci sayisi kadar donecek sayac
	for(__countStudent = 0; __countStudent < pupils; __countStudent++)
	{
		/* Slavnem - 12/10/2023 22:19
		/* //////////////////////////
		/* NOT: Normalde her ogrenci icin aynı not miktari verdik
		/* yani hepsi 4 tane not alicak fakat eger biri 3, digeri 2 not
		/* alacagi bir sistem olsaydi burda hata alicaktik
		/* bu tarz bi durumu onlemek icin dongude denk gelen ogrencinin
		/* kendisine ayrilan kisimi 'sizeof' ile boyutunu olcup __countExam
		/* icin o kadar donme siniri koymamiz gerekir fakat bizim suan icin
		/* boyle bir sey yapmamizi gerektirecek bir durum yok
		*/

		// ogrenci notu kadar donecek sayac
		for(__countExam = 0; __countExam < tests; __countExam++) {
			__temp = *(grades + ((__countStudent * tests) + __countExam));
			__temp < __lowestGrade? (__lowestGrade = __temp) : (__lowestGrade == __lowestGrade);
		}
	}

	/* bulunan en dusuk notun degerini lowGrade'e atadik
	/* istersek bellek adresini de atayabiliriz ama gerek yok
	/* cunku eger __lowestGrade'e bellek adresindeki deger degisirse
	/* lowGradePtr'e ait degerde degisecektir cunku kendisi __lowestGrade'in
	/* bellek adresine isaret etmis olucak oyle bir durumda
	*/
	*lowGradePtr = __lowestGrade;
}

void maximum(int* grades, int* highGradePtr, size_t pupils, size_t tests)
{
	size_t __countStudent;
	size_t __countExam;

	// en dusuk deger olarak dizinin baslangicini veriyoruz
	int __highestGrade = *grades;
	int __temp;

	// ogrenci sayisi kadar donecek sayac
	for(__countStudent = 0; __countStudent < pupils; __countStudent++)
	{
		// ogrenci notu kadar donecek sayac
		for(__countExam = 0; __countExam < tests; __countExam++) {
			__temp = *(grades + ((__countStudent * tests) + __countExam));
			__temp > __highestGrade ? (__highestGrade = __temp) : (__highestGrade == __highestGrade);
		}
	}

	/* bulunan en dusuk notun degerini lowGrade'e atadik
	/* istersek bellek adresini de atayabiliriz ama gerek yok
	/* cunku eger __lowestGrade'e bellek adresindeki deger degisirse
	/* lowGradePtr'e ait degerde degisecektir cunku kendisi __lowestGrade'in
	/* bellek adresine isaret etmis olucak oyle bir durumda
	*/
	*highGradePtr = __highestGrade;
}

void average(int* grades, int* averageGrades, size_t pupils, size_t tests)
{
	size_t __countAverage;
	size_t __countAverMini;

	int __temp;

	for(__countAverage = 0; __countAverage < pupils; __countAverage++)
	{
		// notlarin toplamini tutan gecici degiskene ait veriyi sifirliyoruz
		__temp = 0;

		// notlarini topluyoruz
		for(__countAverMini = 0; __countAverMini < tests; __countAverMini++)
		{
			__temp +=  *(grades + ((__countAverage * tests) + __countAverMini));
		}

		// ogrencinin sirasina gore notlarin ortalamasini alip
		// veriyi adrese yeni deger olarak atiyoruz
		*(averageGrades + __countAverage) = (__temp / tests);
	}
}

void printArray(int* grades, int* totalLength, size_t pupils, size_t tests)
{
	// sayaclar
	size_t __count;
	size_t __countMini;

	// sayac ile cikti
	for(__count = 0; __count < pupils; __count++)
	{
		printf("Ogrenci[%d]: ", __count);

		for(__countMini = 0; __countMini < tests; __countMini++)
		{
			// degeri cikti ver
			printf("%d ", *(grades + ((__count * tests) + __countMini)));
		}

		// yeni satır
		printf("\n");
	}
}

void printChArrayPtr(const char* arrayPtr[], size_t sizeArray)
{
	size_t __count;

	for(__count = 0; __count < sizeArray; __count++)
	{
		printf("[%d] %s\n", __count, arrayPtr[__count]);
	}
}