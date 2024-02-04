// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön İşlemci Tanımları
// En düşük ve yüksek labirent boyut
#define MIN_VEKTOR_X 3
#define MIN_VEKTOR_Y 3

#define MAX_VEKTOR_X 20
#define MAX_VEKTOR_Y 30

// labirent rastgele yön için değer
#define MIN_RAND_VEKTOR_X (MIN_VEKTOR_X - 1)

// en küçük en büyük labirent ilerleme
#define GO_MAX_VEKTOR_X (MAX_VEKTOR_X - 2)
#define GO_MAX_VEKTOR_Y (MAX_VEKTOR_Y)

// labirent başlangıç
#define START_VEKTOR_Y 0

// labirent yönleri
#define VEKTOR 4

// Değişken Tanımları
static const char* strMazeSymbol[] =
{
    "#", // duvar
    "." // yol
};

const char* strMaze[] =
{
    "Labirent yuksekligi icin deger giriniz: ",
    "Labirent genisligi icin deger giriniz: "
};

const char* strMazeError[] =
{
    "Labirent olusturulamadi!",
    "Labirent rastgele yon hesaplama hatasi"
};

enum MAZE
{
    MAZE_WALL = 0, // duvar
    MAZE_ROAD // yol
};

enum MAZESTR
{
    MAZESTR_INPUTVECX = 0, // x yükseklik
    MAZESTR_INPUTVECY // y genişlik
};

enum MAZESTAT
{
    MAZESTAT_SUCCESS = 0, // başarı
    MAZESTAT_ERROR = 3, // hata
    MAZESTAT_LEAK = 4 // kod açığı
};

enum MAZERR
{
    MAZERR_CRE = 0, // labirent oluşturma hatası
    MAZERR_CALCRANDOM, // labirent rastgele yön hesaplama hatası
    MAZERR_NOERR // hata yok
};

enum MAZECREATE
{
    MAZECRE_START = 0, // labirent oluşturma başlangıcı
    MAZECRE_CONTINUE, // labirent oluşturmaya devam
    MAZECRE_END // labirent oluşturmayı sonlandırma
};

enum MAZECELL
{ // labirent hücreleri
    MCELL_NORTH = 0, // kuzey
    MCELL_SOUTH, // güney
    MCELL_EAST, // doğu
    MCELL_WEST, // batı
    MCELL_FULL, // hücre dolu
    MCELL_FREE // hücre boş
};

// Fonksiyon Tanımları
void userInput(size_t*, size_t*);
int mazeGenerator(const size_t*, const size_t*);
void mazeFill(char*, const char*);
void mazePrinter(const char*, const size_t*, const size_t*);

// main
int main(void)
{
    size_t __userVektorX;
    size_t __userVektorY;

    // rastgele sayı üretmek için srand
    srand(time(NULL));

    // kullanıcıdan girdi almak
    userInput((&__userVektorX), (&__userVektorY));

    // labirent oluşturucuyu çalıştırıp döndürmek
    return mazeGenerator((&__userVektorX), (&__userVektorY));
}

// userInput
void userInput(size_t* mazexPtr, size_t* mazeyPtr)
{
    do
    { // X
        printf("%s [%d - %d]: ", strMaze[MAZESTR_INPUTVECX] ,MIN_VEKTOR_X, MAX_VEKTOR_X);
        scanf("%zu", mazexPtr);
    } while((*mazexPtr) < MIN_VEKTOR_X || (*mazexPtr) > MAX_VEKTOR_X);

    do
    { // Y
        printf("%s [%d - %d]: ", strMaze[MAZESTR_INPUTVECY], MIN_VEKTOR_Y, MAX_VEKTOR_Y);
        scanf("%zu", mazeyPtr);
    } while ((*mazeyPtr) < MIN_VEKTOR_Y || (*mazeyPtr) > MAX_VEKTOR_Y);
}

// mazeGenerator
int mazeGenerator(const size_t* sizeMazeXPtr, const size_t* sizeMazeYPtr)
{
    int __statusMazeCreate = MAZECRE_CONTINUE; // labirent oluşturmayı başlat

    // labirent için rastgele başlama konumu atama
    int __mazeRandomAreaSize = (*sizeMazeXPtr - 2) * (*sizeMazeYPtr - 2); // rastgele yol oluşturulacak alanın boyutu
    int __mazeRandomDirection; // rastgele verilen yön değerini tutacak olan değişken

    int __mazeNowX = ((rand() % ((*sizeMazeXPtr) - 2)) + 1); // labirentin anlık x konumunu tutacak olan değişken
    int __mazeNowY = 1; // labirentin anlık y konumunu tutacak olan değişken

    int __mazeTestX = __mazeNowX; // test amaçlı kullanılacak x yön değeri
    int __mazeTestY = __mazeNowY; // test amaçlı kullanılacak y yön değeri

    int __mazeBackupPoint = 0; // yön olmama durumunda geri gitmeyi sağlayan kayıt noktası değeri

    size_t __countMazeX; // x, dikey olarak labirent sayacı
    size_t __countMazeY; // y, yatay olarak labirent sayacı
    size_t __countMazeSaveAddr; // labirent kayıt adresi sayacı
    
    // alınan girdi ile labirent oluşturma
    char __mazeArr[(*sizeMazeXPtr)][(*sizeMazeYPtr)];

    // labrientin son konumunu yön değerine göre tutan değişken
    int __mazeLastPointArr[__mazeRandomAreaSize];

    // oluşturulan labirenti başlangıç konumundan başlayarak
    // başlangıç olarak tamamını duvarla doldurmak
    for(__countMazeX = 0; __countMazeX < (*sizeMazeXPtr); __countMazeX++)
    {
        // yatay
        for(__countMazeY = 0; __countMazeY < (*sizeMazeYPtr); __countMazeY++)
        {
            __mazeArr[__countMazeX][__countMazeY] = *(strMazeSymbol[MAZE_WALL]);
        }
    }

    // labirent oluşturmayı devam ettir
    __statusMazeCreate = MAZECRE_CONTINUE;

    // labirent kayıt noktası bitmedikçe dönsün
    for(__countMazeSaveAddr = 0; __countMazeSaveAddr < __mazeRandomAreaSize && __statusMazeCreate == MAZECRE_CONTINUE; /* biz kendimizi arttırma yapacağız */)
    {
        // eğer kuzey, güney gidemiyorsa sadece doğu ve batıya gidebilmesini sağlayan rastgele sayı oluştursun
        if(__mazeTestX == 1 || __mazeTestX == (*sizeMazeXPtr - 2))
        {
            // rastgele sayı ile yön tayin etmek ama sadece doğu ve batı
            __mazeRandomDirection = (rand() % (VEKTOR - 2)) + 2;
        }
        else
        { // her yön
            // rastgele sayı ile yön tayin etmek
            __mazeRandomDirection = (rand() % (VEKTOR));
        }

        // yöne göre işlem
        switch(__mazeRandomDirection)
        {
            // KUZEY
            case MCELL_NORTH:
                if((__mazeNowX - 2) > 1 && __mazeArr[__mazeNowX - 2][__mazeNowY] == (*strMazeSymbol[MAZE_WALL]))
                {
                    __mazeTestX = __mazeNowX - 1;
                }
                else
                {
                    __mazeNowX > 1 ? (__mazeTestX = __mazeNowX - 1) : (__mazeTestX = __mazeNowX);
                }
            break;
            // GÜNEY
            case MCELL_SOUTH:
                if((__mazeNowX + 2) < (*sizeMazeXPtr - 3) && __mazeArr[__mazeNowX + 2][__mazeNowY] == (*strMazeSymbol[MAZE_WALL]))
                {
                    __mazeTestX = __mazeNowX + 1;
                }
                else
                {
                    __mazeNowX < (*sizeMazeXPtr - 3) ? (__mazeTestX = __mazeNowX + 1) : (__mazeTestX = __mazeNowX);
                }
            break;
            // DOĞU
            case MCELL_EAST:
                if((__mazeNowY + 2) < (*sizeMazeYPtr - 2) && __mazeArr[__mazeNowX][__mazeNowY + 2] == (*strMazeSymbol[MAZE_WALL]))
                {
                    __mazeTestY = __mazeNowY + 1;
                }
                else
                {
                    __mazeNowY < (*sizeMazeYPtr - 2) ? (__mazeTestY = __mazeNowY + 1) : (__mazeTestY = __mazeNowY);
                }
            break;
            // BATI
            case MCELL_WEST:
                if((__mazeNowY - 2) > 1 && __mazeArr[__mazeNowX][__mazeNowY - 2] == (*strMazeSymbol[MAZE_WALL]))
                {
                    __mazeTestY = __mazeNowY - 1;
                }
                else
                {
                    __mazeNowY > 1 ? (__mazeTestY = __mazeNowY - 1) : (__mazeTestY = __mazeNowY);
                }
            break;
            // HESAPLAMA HATASI
            default:
                printf("\n%s\n", strMazeError[MAZERR_CALCRANDOM]);
                return MAZERR_CALCRANDOM;
        }

        // YOL YAPILAMAZ!
        if(__mazeArr[__mazeTestX][__mazeTestY] == (*strMazeSymbol[MAZE_ROAD]))
        {
            // OLASI DİĞER YÖNLERİ KONTROL ETMEK
            // KUZEY
            if(__mazeRandomDirection != MCELL_NORTH && (__mazeTestX - 2) > 1 && __mazeArr[__mazeTestX - 2][__mazeTestY] == (*strMazeSymbol[MAZE_WALL]))
            {
                __mazeNowX > 1 ? (__mazeTestX = __mazeNowX - 1 ,__mazeRandomDirection = MCELL_NORTH) : (__mazeTestX = __mazeNowX);
            }
            // GÜNEY
            else if(__mazeRandomDirection != MCELL_SOUTH && (__mazeTestX + 2) < (*sizeMazeXPtr - 3) && __mazeArr[__mazeTestX + 2][__mazeTestY] == (*strMazeSymbol[MAZE_WALL]))
            {
                __mazeNowX < (*sizeMazeXPtr - 3) ? (__mazeTestX = __mazeNowX + 1, __mazeRandomDirection = MCELL_SOUTH) : (__mazeTestX = __mazeNowX);
            }
            // DOĞU
            else if(__mazeRandomDirection != MCELL_EAST && (__mazeTestY + 2) < (*sizeMazeYPtr - 2) && __mazeArr[__mazeTestX][__mazeTestY + 2] == (*strMazeSymbol[MAZE_WALL]))
            {
                __mazeNowY < (*sizeMazeYPtr - 2) ? (__mazeTestY = __mazeNowY + 1, __mazeRandomDirection = MCELL_EAST) : (__mazeTestY = __mazeNowY);
            }
            // BATI
            else if(__mazeRandomDirection != MCELL_WEST && (__mazeTestY - 2) > 1 && __mazeArr[__mazeTestX][__mazeTestY - 2] == (*strMazeSymbol[MAZE_WALL]))
            {
                __mazeNowY > 1 ? (__mazeTestY = __mazeNowY - 1, __mazeRandomDirection = MCELL_WEST) : (__mazeTestY = __mazeNowY);
            }
            else
            {
                // geri gelme konumunu yenile
                __mazeBackupPoint > 0 ? (__mazeBackupPoint -= 1) : (__mazeBackupPoint = 0);

                // yöne göre işlem
                switch(__mazeLastPointArr[__mazeBackupPoint])
                {
                    // KUZEY
                    case MCELL_NORTH:
                        __mazeNowX > 1 ? (__mazeTestX = __mazeNowX - 1) : (__mazeTestX = __mazeNowX);
                    break;
                    // GÜNEY
                    case MCELL_SOUTH:
                        __mazeNowX < (*sizeMazeXPtr - 3) ? (__mazeTestX = __mazeNowX + 1) : (__mazeTestX = __mazeNowX);
                    break;
                    // DOĞU
                    case MCELL_EAST:
                        __mazeNowY < (*sizeMazeYPtr - 2) ? (__mazeTestY = __mazeNowY + 1) : (__mazeTestY = __mazeNowY);
                    break;
                    // BATI
                    case MCELL_WEST:
                        __mazeNowY > 1 ? (__mazeTestY = __mazeNowY - 1) : (__mazeTestY = __mazeNowY);
                    break;
                    // HESAPLAMA HATASI
                    default:
                        printf("\n%s\n", strMazeError[MAZERR_CALCRANDOM]);
                        return MAZERR_CALCRANDOM;
                }
            }

            // bir tur daha döndür
            // continue;
        }

        // YOL YAPILABİLİR
        // yön bilgilerini güncelle
        __mazeNowX = __mazeTestX;
        __mazeNowY = __mazeTestY;

        // yöne yol ekle
        __mazeArr[__mazeNowX][__mazeNowY] = (*strMazeSymbol[MAZE_ROAD]);

        // son kayıt noktasını güncelle
        __mazeBackupPoint = __countMazeSaveAddr;

        // son kayıt noktası yön bilgisini güncelle
        __mazeLastPointArr[__mazeBackupPoint] = __mazeRandomDirection;

        // sayacı arttır
        ++__countMazeSaveAddr;

        // test amaçlı bilgileri çıktı ver
        printf("maze now x: %d\tmaze now y: %d\n", __mazeNowX, __mazeNowY);
        printf("counter: %d\n", __countMazeSaveAddr);
        printf("maze bakcup size: %d\n", __mazeRandomAreaSize);
        printf("maze backup point: %d\tmaze backup value: %d\n", __mazeBackupPoint, __mazeLastPointArr[__mazeBackupPoint]);           
    }

    // test amaçlı labirenti çıktı vermek
    mazePrinter((&__mazeArr[0][0]), sizeMazeXPtr, sizeMazeYPtr);

    // başarılı dönüş
    return MAZERR_NOERR;
}

// mazeFill
void mazeFill(char* mazePtr, const char* mazeSymbolPtr)
{
    *(mazePtr) = *(mazeSymbolPtr);
}

// mazePrinter
void mazePrinter(const char* mazeBasePtr, const size_t* sizeMazeXPtr, const size_t* sizeMazeYPtr)
{
    size_t __mazeCountX; // x, dikey sayaç
    size_t __mazeCountY; // y, yatay sayaç

    // döngü ile çıktı vermek
    // dikey döngü
    for(__mazeCountX = 0; __mazeCountX < (*sizeMazeXPtr); __mazeCountX++)
    {
        // yatay döngü
        for(__mazeCountY = 0; __mazeCountY < (*sizeMazeYPtr); __mazeCountY++)
        {
            // anlık konuma ait değeri çıktı verme
            printf("%c ", *(mazeBasePtr + __mazeCountY + ((*sizeMazeYPtr) * (__mazeCountX))));
        }

        // boş satır
        puts("");
    }
}