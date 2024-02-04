/*
    //////////////////////
    Yazan: Slavnem
    Dil: C
    //////////////////////
*/

// Kütüphane
#include <stdio.h>

// Ön islemci tanimlari
#define ADD 10 // toplama
#define SUBTRACT 11 // cikarma
#define MULTIPLY 12 // carpma
#define DIVIDE 13 // bolme

// donus degeri numaralandirma
enum TRETURN
{
	RFALSE = 0, // false
	RTRUE = 1, // true
	RUNKNOWN = 2, // bilinmeyen
	RLEAK = 3 // guvenlik acigi
};

// işlemleri numaralandirma
enum PROCESS
{
	PID_ADD = 0, PID_SUBTRACT = 1,
	PID_MULTIPLY = 2, PID_DIVIDE = 3
};

// ekrana cikti vermeyi numaralandirma
enum PRINTER
{
	PRINT_VALUE = 0, // degerleri cikti vermek
	PRINT_PROCESS = 1, // islemi yazdirma
	PRINT_RESULT = 2 // sonucu cikti verme
};

// işlemlerin numarası
const int iProcessNum[] =
{
	PID_ADD,
	PID_SUBTRACT,
	PID_MULTIPLY,
	PID_DIVIDE
};

// işlemlerin metin çıktısı
const char* strProcessPtr[] =
{
	"Toplama", // ADD
	"Cikarma", // SUBTRACT
	"Carpma",  // MULTIPLY
	"Bolme"    // DIVIDE
};

// ekran ciktilarinin metin ciktisi
const char* strPrinterPtr[] =
{
	"Alinan deger",   // PRINTER_VALUE,
	"Yapilan islem", // PRINTER_PROCESS
	"Islem sonucu"   // PRINTER_RESULT
};

// fonksiyon ön tanımlama
int runProgram(void);

// main
int main(void)
{
	runProgram();
}

// fonksiyon
int runProgram(void)
{
	// ihtiyac duyulan fonksiynolar on tanimlama
	void add(double*, double*);
	void subtract(double*, double*);
	void multiply(double*, double*);
	void divide(double*, double*);

	// ekrana cikti vermeyi saglayan fonksiyon on tanimi
	void printer(const char*[], const int*, const size_t*);
	void printResult(const int* processtype, const double* userval1, const double* userval2, const double* tempval);

	// islemleri tutan dizi
	const int processNumArray[] =
	{
		PID_ADD, PID_SUBTRACT,
		PID_MULTIPLY, PID_DIVIDE
	};

	// islemlerin aktifligini tutan dizinin uzunlugu
	int sizeNumArray = sizeof(processNumArray) / sizeof(processNumArray[0]);

	// eger islem dizisinde bir sey yoksa program bilinmeyen donsun
	if(sizeNumArray < 1)
		return RUNKNOWN;

	void(*multiProcess[])(double*, double*) =
	{
		add, subtract, multiply, divide
	};

	// islem numarasi
	// secilen islem kontrol sonucu
	int islemPID;
	int islemSonuc;

	// dizi boyutu
	size_t __size_processptr = (sizeof(strProcessPtr) / sizeof(strProcessPtr[0]));

	// islem numarasi kontrol
	do {
		// islemleri sirayla cikti ver
		printer(strProcessPtr, &iProcessNum[0], &__size_processptr);

		// cikti ver ve deger al
		printf("Islem numarasi giriniz: ");
		scanf("%d", &islemPID);

		// kontrol et
		if(islemPID < 0 || islemPID > (sizeNumArray -1))
			// islem secimi hatali
			islemSonuc = RFALSE;
		else
			// islem secimi dogru
			islemSonuc = RTRUE;
	} while(!islemSonuc);

	// islem girisi basarili
	// kullanicidan deger isteme
	double __userval1;
	double __userval2;
	double __tempuserval;

	printf("2 tane ondalikli deger giriniz: ");
	scanf("%lf%lf", &__userval1, &__userval2);

	// kullanıcının girdigi bir degerin 1 tanesini
	// gecici degiskene kopyaliyoruz
	__tempuserval = __userval2;

	// girilen islem koduna gore islem yapma
	switch(islemPID)
	{
		// ADD, SUBTRACT, MULTIPLY, DIVIDE
		case PID_ADD:
		case PID_SUBTRACT:
		case PID_MULTIPLY:
		case PID_DIVIDE:
			// gecici degiskeni kullanmamizin amaci
			// islem yaparken degerde degisiklik yapilacak
			// bu yuzden bu degiskeni gecici olarak kullaniyoruz
			(*multiProcess[islemPID])(&__userval1, &__tempuserval);

			// girilen degerler, yapilan islemler
			// sonucu kullaniciya cikti vermeliyiz
			printResult((&islemPID), (&__userval1), (&__userval2), (&__tempuserval));
		break;

		// bilinmeyen islem kodu
		default:
			printf("\nIslem numarasi kontrol guvenlik acigi!\n");
			return RLEAK;
	}
}

// ADD
void add(double* valOne, double* valResult)
{
	*valResult = (*valOne) + (*valResult);
}

// SUBTRACT
void subtract(double* valOne, double* valResult)
{
	*valResult = (*valOne) - (*valResult);
}

// MULTIPLY
void multiply(double* valOne, double* valResult)
{
	*valResult = (*valOne) * (*valResult);
}

// DIVIDE
void divide(double* valOne, double* valResult)
{
	if((*valOne) == 0 && (*valResult) == 0)
		(*valResult) = -1;
	else if((*valOne) == 0 && (*valResult) > 0)
		(*valResult) = -2;
	else if((*valOne) > 0 && (*valResult) == 0)
		(*valResult) = 0;
	else if((*valOne) < 0 || (*valResult) < 0)
		(*valResult) = -3;
	else
		(*valResult) = (*valOne) / (*valResult);
}

// PRINTER
void printer(const char* printPtr[], const int* printNumPtr, const size_t* sizeArraysPtr)
{
	/* Eğer yazdırılabilecek metin varsa ve metin sonuna gelinmemişse ve
	yazdırılabilecek sayı varsa ve sayı 0'a eşit ya da büyükse
	yazdırsın
	*/
	for(size_t count = 0; ((printPtr[count] != NULL) || (*printPtr[count] != '\0')) && ((printNumPtr + count) != NULL || *(printNumPtr + count) >= 0) && (count < *(sizeArraysPtr)); count++)
	{
		printf("\n%zu) %s", *(printNumPtr + count), (printPtr[count]));
	}

	// boş satır
	puts("");
}

// PRINTRESULT
void printResult(const int* processtype, const double* userval1, const double* userval2, const double* tempval)
{
	puts("-------------------");
	printf("%s: %.2lf & %.2lf\n", strPrinterPtr[PRINT_VALUE], *userval1, *userval2);
	printf("%s: %s\n", strPrinterPtr[PRINT_PROCESS], strProcessPtr[*processtype]);
	printf("%s: %.2lf\n", strPrinterPtr[PRINT_RESULT], *tempval);
	puts("-------------------");
}
