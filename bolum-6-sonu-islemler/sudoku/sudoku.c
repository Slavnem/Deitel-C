// C Sudoku
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAYI_SINIR 6
#define RASTGELE_SAYI_SINIR 2

// ++submain
void submain(void);

// ++_SudokuBaslangic
short _SudokuBaslangic(
    const short, // kare siniri
    const short, // rastgele sayi siniri
    short[][SAYI_SINIR] // dizi sudoku
);

// ++_SudokuTamKontrol
short _SudokuTamKontrol(
    const short, // sayi siniri
    const short, // satir numarasi
    const short, // sutun numarasi
    const short, // anahtar sayi
    const short[][SAYI_SINIR] // dizi sudoku
);

// ++_SudokuBosYer
short _SudokuBosYer(
    const short, // sayi siniri
    const short, // satir numarasi
    const short, // sutun numarasi
    const short[][SAYI_SINIR] // dizi sudoku
);

// satir ve sutunlarin durum icin
enum BosDurum {
       SATIR_BOS = 0, SUTUN_BOS = 1,
       SATIR_DOLU = 2, SUTUN_DOLU = 3,
       HEPSI_BOS = 4, HEPSI_DOLU = 5 } e_bos_durum;


// ++_SudokuYazdir
void _SudokuYazdir(
    const short,
    const short[][SAYI_SINIR]
);

// +main
int main(void)
{
    submain();
}
// -main

// +submain
void submain(void)
{
    // alabilecegi sayilari tutan degistirilemez dizi
    const short __dizi_sayilar[] = {1,2,3,4,5,6};
    // satir ve sutundaki sayilari tutan statik dizi
    static short __dizi_sudoku[SAYI_SINIR][SAYI_SINIR] = {0};

    srand(time(NULL));

    _SudokuBaslangic(
        SAYI_SINIR,
        RASTGELE_SAYI_SINIR,
        __dizi_sudoku
    );

    _SudokuYazdir(
        SAYI_SINIR,
        __dizi_sudoku
    );
}
// -submain

// +_SudokuBaslangic
short _SudokuBaslangic(
    const short _sb_sayi_sinir, // kare siniri
    const short _sb_rastgele_sinir, // rastgele sayi siniri
    short _sb_dizi_sudoku[][SAYI_SINIR] // dizi sudoku
)
{
    enum IstekDurum { HAYIR = 0, EVET = 1 } e_istek_durum;
    enum SudokuDurum { DEVAM = 1, BITIS = 2 } e_sudoku_durum;

    short __sb_satir_sayac; // satir sayaci
    short __sb_sutun_sayac; // sutun sayaci
    short __sb_satir_sayi_miktar = 0; // satir siniri asiyor mu asmiyo mu kontrol icin
    short __sb_sutun_sayi_miktar = 0; // sutun siniri asiyor mu asmiyo mu kontrol icin
    // uretilen rastgele sayinin atandigi degisken, belli araliklarda uretilen rastgele sayi
    short __sb_sinirli_rastgele_sayi;
    // sutun numarasi buyudukce evet cikmasi icin birkac tur daha dondurmesi icin ek sayac
    short __sb_bir_sans_daha;

    for(__sb_satir_sayac = 0; __sb_satir_sayac < _sb_sayi_sinir; __sb_satir_sayac++)
    {
        __sb_satir_sayi_miktar = 0;

        for(__sb_sutun_sayac = 0; __sb_sutun_sayac < _sb_sayi_sinir; __sb_sutun_sayac++)
        {
            // cikan sonuc bos mu degil mi bir deger dondurecek
            e_bos_durum = _SudokuBosYer(
                _sb_rastgele_sinir,
                __sb_satir_sayac,
                __sb_sutun_sayac,
                _sb_dizi_sudoku
            );
            
            // eger bos yer varsa
            if(e_bos_durum == HEPSI_BOS)
            {
                // yer bos ise
                if(_sb_dizi_sudoku[__sb_satir_sayac][__sb_sutun_sayac] == 0)
                {
                    // satirdaki sayi miktari siniri asmamissa
                    if(__sb_satir_sayi_miktar < _sb_rastgele_sinir)
                    {
                        // sutun numarasi yarisindan oncesiyse %50 sans
                        if(__sb_sutun_sayac <= (_sb_sayi_sinir / 2))
                        {
                            e_istek_durum = rand() % 2;
                        }
                        else
                        {
                            // eger sutun numarasi yarisindan sonra ise daha yuksek evet orani
                            __sb_bir_sans_daha = 0;

                            while(__sb_bir_sans_daha < (_sb_sayi_sinir / 2) + 1 && e_istek_durum != EVET)
                            {
                                e_istek_durum = rand() % 2;
                            }
                        }

                        // eger evet cikmissa rastgele sayi olusturcak ve kontrol edicek
                        if(e_istek_durum == EVET)
                        {
                            __sb_sinirli_rastgele_sayi = 1 + (rand() % SAYI_SINIR);

                            e_sudoku_durum = _SudokuTamKontrol(
                                _sb_sayi_sinir,
                                __sb_satir_sayac,
                                __sb_sutun_sayac,
                                __sb_sinirli_rastgele_sayi,
                                _sb_dizi_sudoku
                            );

                            // eger sayiyi kullanmada sikinti yok ise devam etsin
                            if(e_sudoku_durum == DEVAM)
                            {
                                // sayiyi dizideki yere ata
                                _sb_dizi_sudoku[__sb_satir_sayac][__sb_sutun_sayac]  = __sb_sinirli_rastgele_sayi;
                                __sb_satir_sayi_miktar += 1; // satirdaki sayi miktarini 1 arttir
                            }
                        }
                    }
                }
            }
        }
    }
}
// -_SudokuBaslangic

// +_SudokuTamKontrol
short _SudokuTamKontrol(
    const short _stk_sayi_sinir, // sayi siniri
    const short _stk_satir, // satir numarasi
    const short _stk_sutun, // sutun numarasi
    const short _stk_anahtar, // anahtar sayi
    const short _stk_dizi_sudoku[][SAYI_SINIR] // dizi sudoku
)
{
    enum KontrolDurum { HATA = 0, BASARI = 1 } e_kontrol_durum;

    short __stk_sayac;

    for(__stk_sayac = 0; __stk_sayac < _stk_sayi_sinir; __stk_sayac++)
    {
        // satir da ayni sayi varsa basari vermesin
        if(_stk_dizi_sudoku[_stk_satir][__stk_sayac] == _stk_anahtar)
        {
            return HATA;
        }
        // eger o sutun da ayni sayi varsa basari vermesin
        else if(_stk_dizi_sudoku[__stk_sayac][_stk_sutun] == _stk_anahtar)
        {
            return HATA;
        }
    }

    // eger ne satirda ne sutunda o sayi yoksa basari versin
    return BASARI;
}
// -_SudokuTamKontrol

// +_SudokuBosYer
short _SudokuBosYer(
    const short _sby_sayi_sinir, // sayi siniri
    const short _sby_satir, // satir numarasi
    const short _sby_sutun, // sutun numarasi
    const short _sby_dizi_sudoku[][SAYI_SINIR] // dizi sudoku
)
{   
    short __sby_sayac;
    short __sby_satir_sayac = 0;
    short __sby_sutun_sayac = 0;

    for(__sby_sayac = 0; __sby_sayac < _sby_sayi_sinir; __sby_sayac++)
    {
        // oldugu satirda sayi varsa sayaci 1 arttir
        if(_sby_dizi_sudoku[_sby_satir][__sby_sayac] != 0)
        {
            __sby_satir_sayac += 1;
        }

        // oldugu sutun da sayi varsa sayaci 1 arttir
        if(_sby_dizi_sudoku[__sby_sayac][_sby_sutun] != 0)
        {
            __sby_sutun_sayac += 1;
        }
    }

    // eger sayac siniri asiyosa hangisi asiyo diye kontrol
    if(__sby_satir_sayac > _sby_sayi_sinir)
    {
        // hem satir hem de sutun doluysa HEPSI_DOLU
        if(__sby_sutun_sayac > _sby_sayi_sinir)
        {
            e_bos_durum = HEPSI_DOLU;
        }
        // sadece satir dolu ise SATIR_DOLU
        else
        {
            e_bos_durum = SATIR_DOLU;
        }
    }
    // eger satir dolu degilse
    else if(__sby_satir_sayac <= _sby_sayi_sinir )
    {
        // sutun dolu ise SUTUN_DOLU
        if(__sby_sutun_sayac > _sby_sayi_sinir)
        {
            e_bos_durum = SUTUN_DOLU;
        }
        // hicbiri siniri asmamissa HEPSI_BOS
        else
        {
            e_bos_durum = HEPSI_BOS;
        }
    }

    // durumu dondur
    return e_bos_durum;
}
// -_SudokuBosYer

// +_SudokuYazdir
void _SudokuYazdir(
    const short _sy_sayi_sinir,
    const short _sy_dizi_sudoku[][SAYI_SINIR]
)
{
    short __sy_satir_sayac; // satir sayaci
    short __sy_sutun_sayac; // sutun sayaci

    // satir sayaci
    for(__sy_satir_sayac = 0; __sy_satir_sayac < _sy_sayi_sinir; __sy_satir_sayac++)
    {
        // sutun sayaci
        for(__sy_sutun_sayac = 0; __sy_sutun_sayac < _sy_sayi_sinir; __sy_sutun_sayac++)
        {
            // cikti ver
            printf("%hd ", _sy_dizi_sudoku[__sy_satir_sayac][__sy_sutun_sayac]);
        }

        puts(""); // yeni satir
    }
}
// -_SudokuYazdir