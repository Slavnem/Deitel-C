// Kutuphaneler
#include <stdio.h>

// Simpletron
#define SIMPLETRON_MAX 100

// Giris/Cikis islemleri
#define READ 10
#define WRITE 11

// Yukleme/Saklama islemleri
#define LOAD 20
#define STORE 21

// Aritmetik islemler
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33

// Kontrolun aktarilmasi islemleri
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

// ACIKLAMA:
// BRANCH: Bellekteki belirli bir konuma dallan

// BRANCH NEG: Eger akumulator degeri 0'dan kucuk ise,
// operandin numarasindaki bellek adresine dallanir yani atlar
// bu yuzden haltf ciktisi goremeyebiliriz eger branchneg komutundan
// sonra yazilmis ise

// BRANCH ZERO: Eger akumulator degeri 0 ise
// operand numarasina gore bellegin adresine dallan, atla (git)

// Fonksiyon tanım
void halt(int memory[], const int memorysize, const int inscounter, const int accumulator)
{
    int counter;
    int mcounter;
    
    const int insregister = memory[inscounter];
    const int operationCode = insregister / 100;
    const int operand = insregister % 100;

    const int mspace = 3;
    const int space = 5;
    const int rowSize = (memorysize / 10);

    // REGISTERS ana sutunlarini belli etmek
    printf("\nREGISTERS:\n");
    printf("accumulator: %+05d\n", accumulator);
    printf("instructionCounter: %02d\n", inscounter);
    printf("instructionRegister: %+05d\n", inscounter);
    printf("operationCode: %02d\n", operationCode);
    printf("operand: %02d\n", operand);

    // MEMORY ana sutunlarini belli etmek
    printf("\nMEMORY:\n");

    for(counter = 0; counter < rowSize; counter++)
        printf("%*d", ((space + mspace)), counter);

    for(counter = 0; counter < rowSize; counter++)
    {
        // satir numarasi
        printf("\n%2d", (counter * rowSize));

        for(mcounter = 0; (counter * rowSize) < memorysize && mcounter < rowSize; mcounter++)
        {
            printf("%*c", mspace);
            printf("%+0*d", (space + 1), memory[((counter * rowSize) + mcounter)]);
        }
    }
}

// Ana degiskenler
enum BOOLTYPE
{
    BOOL_FALSE = 0,
    BOOL_TRUE = 1
};

enum SPECIALNUM
{
    NUM_END = 0
};

enum MSGSIMPLETRON
{
    MSGSIMP_LOAD_COMPLETE = 0,
    MSGSIMP_RUN_START = 1,
    MSGSIMP_LOAD_TERMINATE = 2,
    MSGSIMP_ERROR_DIVIDE_ZERO = 3
};

enum BRACKET
{
    BRACKET_NORMAL
};

const int NUM_SimpletronCommand[] =
{
    READ, WRITE,
    LOAD, STORE,
    ADD, SUBTRACT, DIVIDE, MULTIPLY,
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
    "*** Sifir ile bolme girisimi ***\n*** Simpletron yurutmesi normal olmayan bir bicimde sonlandirildi ***"
};

const char* MSGPtr_SimpletronBracket[] =
{
    "==================="
};

const int NUM_Special[] =
{
    -99999
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
        printf("+%d: %s\n", (NUM_SimpletronCommand[__ss_counter]), (MSGPtr_SimpletronCommand[__ss_counter]));

    return BOOL_TRUE;
}

int runSimpletron(void)
{
    int calculateSimpletron(int[], const int);

    enum BOOLTYPE program = BOOL_FALSE;

    int memory[SIMPLETRON_MAX] = {0};
    int operationCode;
    int instructionCounter;
    int value;

    const int sizeMemory = (sizeof(memory) / sizeof(memory[0]));

    // islem
    for(instructionCounter = 0; instructionCounter < sizeMemory; instructionCounter++)
    {
        // tur
        printf("%02d ? ", instructionCounter);

        // kullanicidan deger almak
        scanf("%6d", &value);

        // durdurma degeri girilmisse donguye son ver
        if(value == (NUM_Special[NUM_END]))
        {
            if(instructionCounter > 0)
                program = BOOL_TRUE;
            
            break;
        }

        // cikis degeri kontrolu basarili gecmisse ve istenmeyen
        // aralikta sayi girilmisse, sonraki tura gec
        if(value < 0 || value > 9999)
        {
            // bu turu atliyoruz ve sonraki tura basliyoruz
            instructionCounter -= 1;
            continue;
        }
        
        // girilen kodu bulma
        operationCode = (value / 100);

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
            case BRANCH: // VERI DAL
            case BRANCHNEG: // VERI DAL NEGATIF
            case BRANCHZERO: // VERI DAL SIFIR
            case HALT: // DURDUR
                // degerleri atama
                memory[instructionCounter] = value;
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
    if(program == BOOL_TRUE)
    {
        puts(MSGPtr_SimpletronMessage[MSGSIMP_LOAD_COMPLETE]);
        puts(MSGPtr_SimpletronMessage[MSGSIMP_RUN_START]);

        return calculateSimpletron(memory, sizeMemory);
    }
    else
        return BOOL_FALSE;

    // program basariyla calisti
    return BOOL_TRUE;
}

int calculateSimpletron(int mem[], const int size_mem)
{
    int accumulator = 0;
    int instructionCounter = 0;
    int normCommandCounter = 0;
    int instructionRegister = 0;
    int operationCode = 0;
    int operand = 0;

    for(instructionCounter = 0; instructionCounter < size_mem; instructionCounter++)
    {
        if(mem[instructionCounter] == 0)
            break;

        // degerleri hesaplama
        instructionRegister = mem[instructionCounter];

        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;

        // operasyon koduna gore islem
        switch(operationCode)
        {
            // OKU
            case READ:
                printf("Bir deger giriniz: ");
                scanf("%d", &mem[operand]);
                break;
            // YAZ
            case WRITE:
                printf("\nDeger: %d\n", mem[operand]);
                break;
            // YUKLE
            case LOAD:
                accumulator = mem[operand];
                break;
            // DEPOLA
            case STORE:
                mem[operand] = accumulator;
                break;
            // TOPLA
            case ADD:
                accumulator += mem[operand];
                break;
            // CIKAR
            case SUBTRACT:
                accumulator -= mem[operand];
                break;
            // BOL
            case DIVIDE:
                if(mem[operand] == 0 || accumulator == 0)
                    return printf("\n%s\n", (MSGPtr_SimpletronMessage[MSGSIMP_ERROR_DIVIDE_ZERO]));

                accumulator /= mem[operand];
                break;
            // CARP
            case MULTIPLY:
                accumulator *= mem[operand];
                break;
            // DAL
            case BRANCH:
                instructionCounter = operand;
                break;
            // DAL NEGATIF
            case BRANCHNEG:
                if(accumulator < 0)
                    instructionCounter = operand - 1;
                break;
            // DAL SIFIR
            case BRANCHZERO:
                if(accumulator == 0)
                    instructionCounter = operand - 1;
                break;
            // DURDUR
            case HALT:
                halt(mem, size_mem, (normCommandCounter), accumulator);
                printf("\n%s\n", MSGPtr_SimpletronMessage[MSGSIMP_LOAD_TERMINATE]);

                // istenmeyen halt komutu, sayaçtan 1 azalt
                normCommandCounter -= 1;
                break;
        }

        // istenilen komutları sayan sayaç
        normCommandCounter += 1;
    }

    return BOOL_TRUE;
}