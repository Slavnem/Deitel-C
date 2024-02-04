/*
    //////////////////////
    Yazan: Slavnem
    Dil: C
    //////////////////////
*/

// Kutuphaneler
#include <stdio.h>

// Simpletron
#define SIMPLETRON_MIN 0
#define SIMPLETRON_MAX 1000
#define SIMPLETRON_KILL -99999

// komut bulucu
#define DIVID_COMMAND 10
#define MOD_COMMAND 10
#define MIN_LIMIT_OPERAND 99

// değer bulucu
#define MOD_USERVAL 10000

// bellek çıktısı
#define OUTPUT_COLUMN 10
#define OUTPUT_ROW (SIMPLETRON_MAX / OUTPUT_COLUMN)

// Giris/Cikis islemleri
#define READ 0X0A
#define WRITE 0X0B

// Yukleme/Saklama islemleri
#define LOAD 0X14
#define STORE 0X15

// Aritmetik islemler
#define ADD 0X1E
#define SUBTRACT 0X1F
#define DIVIDE 0X20
#define MULTIPLY 0X21
#define MOD 0X22
#define POW 0X23

// Kontrolun aktarilmasi islemleri
#define BRANCH 0X28
#define BRANCHNEG 0X29
#define BRANCHZERO 0X2A
#define HALT 0X2B

// ACIKLAMA:
// BRANCH: Bellekteki belirli bir konuma dallan

// BRANCH NEG: Eger akumulator degeri 0'dan kucuk ise,
// operandin numarasindaki bellek adresine dallanir yani atlar
// bu yuzden haltf ciktisi goremeyebiliriz eger branchneg komutundan
// sonra yazilmis ise

// BRANCH ZERO: Eger akumulator degeri 0 ise
// operand numarasina gore bellegin adresine dallan, atla (git)

// NOT: 23-11-2023 11:57
// Tamsayılı sistem yerine komutlar da 16(hexadedicmal)
// (1,2,3,4,5,6,7,8,9,a,b,c,d,e,f) ile komutlar yeniden düzenlenicek

// NOT: 25-11-2023 12:!4
// Çıktı olarak 16(hexadecimal) sistemde çıktı veriyor fakat
// 16lık sistemde girdi alamıyor. Program saçmalıyor, hatanın düzeltilmesi lazım
// Hata kaynağı: SATIR 238

// fonksiyon ön tanımları
void read(float*);
void write(const float*);
void load(float*, const float*);
void store(float*, const float*);
void add(float*, const float*);
void subtract(float*, const float*);
void divide(float*, const float*);
void multiply(float*, const float*);
void mod(float*, const float*);
void pow(float*, const float*);
void branch(int*, const int*);
void branchneg(int*, const int*, const float*);
void branchzero(int*, const int*, const float*);
void halt(const float*, const int*, const int*, const float*);

// Ana degiskenler
enum BOOLTYPE
{
    BOOL_FALSE = 0,
    BOOL_TRUE = 1,
    BOOL_LEAK = 2 // kod açığı
};

enum MSGSIMPLETRON
{
    MSGSIMP_LOAD_COMPLETE = 0,
    MSGSIMP_RUN_START = 1,
    MSGSIMP_LOAD_TERMINATE = 2,
    MSGSIMP_ERROR_DIVIDE_ZERO = 3,
    MSGSIMP_ERROR_POW_UNDEFINED = 4
};

enum BRACKET
{
    BRACKET_NORMAL
};

const int NUM_SimpletronCommand[] =
{
    READ, WRITE,
    LOAD, STORE,
    ADD, SUBTRACT, DIVIDE, MULTIPLY, MOD, POW,
    BRANCH, BRANCHNEG, BRANCHZERO, HALT
};

const char* MSGPtr_SimpletronCommand[] =
{
    "READ | OKU",
    "WRITE | YAZ",
    "LOAD | YUKLE",
    "STORE | DEPOLA",
    "ADD | TOPLA",
    "SUBTRACT | CIKAR",
    "DIVIDE | BOL",
    "MULTIPLY | CARPMA",
    "MOD | KALAN",
    "POW | USSU",
    "BRANCH | DAL",
    "BRANCHNEG | DAL NEGATIF",
    "BRANCHZERO | DAL SIFIR",
    "HALT | DUR"
};

const char* MSGPtr_SimpletronStart[] =
{
    "*** Simpletron'a Hosgeldiniz! ***",
    "*** Lutfen programinizi her sefer de bir komut ***",
    "*** (veya kelime) olarak giriniz. Konum numarasi ***",
    "*** ve bir soru isareti (?) yazacagim ***",
    "*** Ardindan siz bu konum icin kelimeyi giriniz ***",
    "*** Programiniza girisi durdurmak icin -9999 giriniz ***"
};

const char* MSGPtr_SimpletronMessage[] =
{
    "*** Program yuklenmesi tamamlandi ***",
    "*** Program yurutulmesi basliyor ***",
    "*** Simpletron yurutmesi sonlandirildi ***",
    "*** Sifir ile bolme girisimi ***\n*** Simpletron yurutmesi normal olmayan bir bicimde sonlandirildi ***",
    "*** 0 ussu 0 deneme girisimi ***\nSimpletron sonlandiriliyor..."
};

const char* MSGPtr_SimpletronBracket[] =
{
    "==================="
};

const size_t SIZE_SimpletronCommand = (sizeof(NUM_SimpletronCommand) / sizeof(NUM_SimpletronCommand[0]));
const size_t SIZE_SimpletronStart = (sizeof(MSGPtr_SimpletronStart) / sizeof(MSGPtr_SimpletronStart[0]));

int main(void)
{
    int startSimpletron(void);
    int runSimpletron(void);

    startSimpletron(); // baslangic
    runSimpletron(); // calisma
}

int startSimpletron(void)
{
    size_t __ss_counter;

    for(__ss_counter = 0; __ss_counter < SIZE_SimpletronStart; __ss_counter++)
        printf("%s\n", (MSGPtr_SimpletronStart[__ss_counter]));

    // iki kisimi birbirinden ayrac ile ayiriyoruz
    printf("%s\n", (MSGPtr_SimpletronBracket[BRACKET_NORMAL]));

    for(__ss_counter = 0; __ss_counter < SIZE_SimpletronCommand; __ss_counter++)
        printf("+%x: %s\n", (NUM_SimpletronCommand[__ss_counter]), (MSGPtr_SimpletronCommand[__ss_counter]));

    return BOOL_TRUE;
}

int runSimpletron(void)
{
    // hespalama fonksiyonu tanımı
    int calculateSimpletron(float*, const int*);

    // değişken tanımları
    enum BOOLTYPE program = BOOL_FALSE;

    // simpletron için oluşturulmuş bellek dizisi
    float memory[SIMPLETRON_MAX] = {0};

    //  sayılması istenen komutları sayan sayaç
    int userComVal;
    int userVal;
    int instructionCounter;
    int instructionRegister = 0;
    int operationCode = 0;
    int operand = 0;
    int temp_mod_command;

    const int sizeMemory = (sizeof(memory) / sizeof(memory[0]));

    // islem
    for(instructionCounter = 0; instructionCounter < sizeMemory; instructionCounter++)
    {
        // tur
        printf("%02d ? ", instructionCounter);

        // kullanicidan deger almak
        scanf("%8d", &userComVal);

        // durdurma degeri girilmisse donguye son ver
        if(userComVal == SIMPLETRON_KILL)
        {
            if(instructionCounter > 0)
                program = BOOL_TRUE;
            
            break;
        }
        
        // komutların basamak değerine gelene kadar bölünsün
        // komut numarasını bulunacak
        for(operationCode = userComVal; operationCode > MIN_LIMIT_OPERAND; operationCode /= DIVID_COMMAND);

        // mod değerini değerin uzunluğunu göre hesaplama
        // bu sayede operandda kalanı bulmamızı sağlayacak olan bölüm değeri ortaya çıkacak
        for(temp_mod_command = MOD_COMMAND; (userComVal / temp_mod_command) > MIN_LIMIT_OPERAND; temp_mod_command *= MOD_COMMAND);

        // operand
        operand = (userComVal % temp_mod_command);

        // cikis degeri kontrolu basarili gecmisse
        // ve istenmeyen aralikta sayi girilmisse
        // sonraki tura gec
        if(operand < SIMPLETRON_MIN || operand > SIMPLETRON_MAX)
        {
            // bu turu atliyoruz ve sonraki tura basliyoruz
            instructionCounter -= 1;
            continue;
        }

        // program bitmedigi icin numaraya gore islem yapiyoruz
        switch(operationCode)
        {
            case READ: // VERI OKU
            case WRITE: // VERI YAZ
            case LOAD: // VERI YUKLE
            case STORE: // VERI DEPOLA
            case ADD: // VERI TOPLA
            case SUBTRACT: // VERI CIKAR
            case DIVIDE: // VERI BOL
            case MULTIPLY: // VERI CARP
            case MOD: // VERI BOLUM KALAN
            case POW: // VERI USSU
            case BRANCH: // VERI DAL
            case BRANCHNEG: // VERI DAL NEGATIF
            case BRANCHZERO: // VERI DAL SIFIR
            case HALT: // DURDUR
                // degerleri atama
                memory[instructionCounter] = userComVal;
                break;

            // BILINMEYEN
            default:
                // bu turdaki degeri sifirliyoruz
                memory[instructionCounter] = 0;

                // bu turu atliyoruz ve sonraki tura basliyoruz
                instructionCounter -= 1;
                continue;
        }
    }

    // komut girilmesi bittigi icin simdi sira yurutmede
    switch(program) {
        // doğru
        case BOOL_TRUE:
            puts(MSGPtr_SimpletronMessage[MSGSIMP_LOAD_COMPLETE]);
            puts(MSGPtr_SimpletronMessage[MSGSIMP_RUN_START]);

            return calculateSimpletron(&memory[0], &sizeMemory);
        // hata
        default:
            return BOOL_FALSE;

    }

    // program basariyla calisti
    return BOOL_TRUE;
}

int calculateSimpletron(float* mem, const int* size_mem)
{
    float accumulator = 0.0;
    int instructionCounter = 0;
    int normCommandCounter = 0;
    int instructionRegister = 0;
    int operationCode = 0;
    int operand = 0;
    int temp_mod_command;

    for(instructionCounter = 0; instructionCounter < *size_mem; instructionCounter++)
    {
        if(*(mem + instructionCounter) == 0)
            break;

        // degerleri hesaplama
        instructionRegister = *(mem + instructionCounter);

        // komutların basamak değerine gelene kadar bölünsün
        // komut numarasını bulunacak
        for(operationCode = instructionRegister; operationCode > MIN_LIMIT_OPERAND; operationCode /= DIVID_COMMAND);

        // mod değerini değerin uzunluğunu göre hesaplama
        // bu sayede operandda kalanı bulmamızı sağlayacak olan bölüm değeri ortaya çıkacak
        for(temp_mod_command = MOD_COMMAND; (instructionRegister / temp_mod_command) > MIN_LIMIT_OPERAND; temp_mod_command *= MOD_COMMAND);

        // operand
        operand = instructionRegister % temp_mod_command;

        // operasyon koduna gore islem
        switch(operationCode)
        {
            // OKU
            case READ:
                read((mem + (operand - 1)));
                break;
            // YAZ
            case WRITE:
                write((mem + (operand - 1)));
                break;
            // YUKLE
            case LOAD:
                load(&accumulator, (mem + (operand - 1)));
                break;
            // DEPOLA
            case STORE:
                store((mem + (operand - 1)), &accumulator);
                break;
            // TOPLA
            case ADD:
                add(&accumulator, (mem + (operand - 1)));
                break;
            // CIKAR
            case SUBTRACT:
                subtract(&accumulator, (mem + (operand - 1)));
                break;
            // BOL
            case DIVIDE:
                divide(&accumulator, (mem + (operand - 1)));
                break;
            // CARP
            case MULTIPLY:
                multiply(&accumulator, (mem + (operand - 1)));
                break;
            // KALAN
            case MOD:
                mod(&accumulator, (mem + (operand - 1)));
                break;
            // USSU
            case POW:
                pow(&accumulator, (mem + (operand - 1)));
                break;
            // DAL
            case BRANCH:
                branch(&instructionCounter, &operand);
                break;
            // DAL NEGATIF
            case BRANCHNEG:
                branchneg(&instructionCounter, &operand, &accumulator);
                break;
            // DAL SIFIR
            case BRANCHZERO:
                branchzero(&instructionCounter, &operand, &accumulator);
                break;
            // DURDUR
            case HALT:
                halt(mem, size_mem, &(normCommandCounter), &accumulator);

                // istenmeyen halt komutu, sayaçtan 1 azalt
                normCommandCounter -= 1;
                break;
            // KOD AÇIĞI
            default:
                return BOOL_LEAK; // kod açığı
        }

        // istenilen komutları sayan sayaç
        normCommandCounter += 1;
    }

    return BOOL_TRUE;
}

// Hesaplama ve İşlem Fonksiyonları
void read(float* memoryParamPtr)
{
    printf("Bir deger giriniz: ");
    scanf("%f", memoryParamPtr);
}

void write(const float* valueParamPtr)
{
    printf("Deger: %.2f\n", *valueParamPtr);
}

void load(float* accumulatorParamPtr, const float* memory_valueParamPtr)
{
    *accumulatorParamPtr = *memory_valueParamPtr;
}

void store(float* memoryParamPtr, const float* accumulatorParamPtr)
{
    *memoryParamPtr = *accumulatorParamPtr;
}

void add(float* accumulatorParamPtr, const float* memory_valueParamPtr)
{
    *accumulatorParamPtr += *memory_valueParamPtr;
}

void subtract(float* accumulatorParamPtr, const float* memory_valueParamPtr)
{
    *accumulatorParamPtr -= *memory_valueParamPtr;
}

void divide(float* accumulatorParamPtr, const float* memory_valueParamPtr)
{
    switch(*memory_valueParamPtr == 0 || *accumulatorParamPtr == 0)
    {
        // 0 bölme denemesi
        case 1:
            printf("\n%s\n", (MSGPtr_SimpletronMessage[MSGSIMP_ERROR_DIVIDE_ZERO]));
        break;
        // hata yok
        default:
            *accumulatorParamPtr /= *memory_valueParamPtr;
        break;
    }
}

void multiply(float* accumulatorParamPtr, const float* memory_valueParamPtr)
{
    *accumulatorParamPtr *= *memory_valueParamPtr;
}

void mod(float* accumulatorParamPtr, const float* memory_valueParamPtr)
{
    *accumulatorParamPtr = (int)*accumulatorParamPtr % (int)*memory_valueParamPtr;
}

void pow(float* accumulatorParamPtr, const float* memory_valueParamPtr)
{
    /*
    * =================================
    * Akümülator ve bellek adresindeki
    * değeri kontrol etme
    * =================================
    */

    if(*accumulatorParamPtr > 0 && *memory_valueParamPtr == 0)
    {
        *accumulatorParamPtr = 1;
        return;
    }
    else if(*accumulatorParamPtr == 0 && *memory_valueParamPtr == 0)
    {
        printf("\n%s\n", (MSGPtr_SimpletronMessage[MSGSIMP_ERROR_POW_UNDEFINED]));
        return;
    }
    else if(*accumulatorParamPtr == 0 && *memory_valueParamPtr > 0)
    {
        *accumulatorParamPtr = 0;
        return;
    }

    // geçici olarak sayı değerini tutan değişken ve sayaç
    float temp = *accumulatorParamPtr;
    int temp_end = *memory_valueParamPtr;
    size_t counter;

    // döngü ile değerin üssünü almak
    for(counter = 2; counter <= temp_end; counter++)
    {
        multiply(accumulatorParamPtr, &temp);
    }
}

void branch(int* inscounterParamPtr, const int* operandParamPtr)
{
    *inscounterParamPtr = *operandParamPtr;
}

void branchneg(int* inscounterParamPtr, const int* operandParamPtr, const float* accumulatorParamPtr)
{
    if(*accumulatorParamPtr < 0.0)
        *inscounterParamPtr = *operandParamPtr - 1;
}

void branchzero(int* inscounterParamPtr, const int* operandParamPtr, const float* accumulatorParamPtr)
{
    if(*accumulatorParamPtr == 0.0)
        *inscounterParamPtr = *operandParamPtr - 1;
}

void halt(const float* memoryParamPtr, const int* memorysizeParamPtr, const int* inscounterParamPtr, const float* accumulatorParamPtr)
{
    const int insregister = *(memoryParamPtr + (*inscounterParamPtr));
    const int space = 5;
    const int mspace = 3;

    int counter;
    int mcounter;
    int operationCode = 0;
    int operand = 0;
    int temp_mod_command;

    // komutların basamak değerine gelene kadar bölünsün
    // komut numarasını bulunacak
    for(operationCode = insregister; operationCode > MIN_LIMIT_OPERAND; operationCode /= DIVID_COMMAND);

    // mod değerini değerin uzunluğunu göre hesaplama
    // bu sayede operandda kalanı bulmamızı sağlayacak olan bölüm değeri ortaya çıkacak
    for(temp_mod_command = MOD_COMMAND; (insregister / temp_mod_command) > MIN_LIMIT_OPERAND; temp_mod_command *= MOD_COMMAND);

    // operand
    operand = insregister % temp_mod_command;

    // REGISTERS ana sutunlarini belli etmek
    printf("\nREGISTERS:\n");
    printf("accumulator: %+05.2f\n", *accumulatorParamPtr);
    printf("instructionCounter: %02d\n", *inscounterParamPtr);
    printf("instructionRegister: %+05d\n", *inscounterParamPtr);
    printf("operationCode: %02d\n", operationCode);
    printf("operand: %02d\n", operand);

    // MEMORY ana sutunlarini belli etmek
    printf("\nMEMORY:\n");

    // sütun numaralarını yazdırmak
    for(counter = 0; counter < OUTPUT_COLUMN; counter++)
    {
        printf("%*d",  (space + mspace + 1), (counter + 1));
    }

    // satır satır verileri yazdırmak
    for(counter = 0; counter < OUTPUT_ROW; counter++)
    {
        // satir numarasi
        printf("\n%03d", (counter * OUTPUT_COLUMN));

        for(mcounter = 0; mcounter < OUTPUT_COLUMN; mcounter++)
        {
            printf("%*c", mspace);
            printf("%+0*d", (space + 2), (int)*(memoryParamPtr + ((counter * OUTPUT_COLUMN) + mcounter)));
        }
    }

    // yürütme sonlandırıldı mesajı
    printf("\n%s\n", MSGPtr_SimpletronMessage[MSGSIMP_LOAD_TERMINATE]);
}