// Slavnem @2024-05-14
// Dosya Eşleştirme

// Kütüphaneler
#include <stdio.h>

// Kullanıcı yapısı
typedef struct
{
    unsigned int accNum; // hesap numarası
    char firstName[5]; // isim
    char lastName[6]; // soyad
    double balance; // bakiye
} Account;

// Alışveriş yapısı
typedef struct
{
    unsigned int accNum; // hesap numarası
    double money; // dolar tutarı
} Shopping;

// İşlem durumu için
typedef enum
{
    false = 0,
    true
} bool;

// Sabit yazılar
static const char* const __ErrFileNotFound = "Dosya Bulunamadi";
static const char* const __ErrNotMatchedAcc = "Eslenmemis alis veris kayiti...";

// Dosya isimleri
static const char* const __FileNameFor_Account = "account.dat";
static const char* const __FileNameFor_Shopping = "shopping.dat";
static const char* const __FileNameFor_NewRecord = "newrecord.dat";

// main
int main(void)
{
    FILE *filePtr; // dosya okuyucu

    Account tempAccount; // geçici hesap verisi tutma
    Shopping tempShopping; // geçici alış veriş verisi tutan yapı oluştur

    unsigned int rowCounter; // satır sayacı
    unsigned int testCounter; // test amaçlı sayaç

    bool matched; // eşleşme verisini tutacak

    // dosyayı okusun, dosya yoksa sonlansın
    if((filePtr = fopen(__FileNameFor_Account, "r")) == NULL)
    {
        printf("%s: %s\n", (__ErrFileNotFound), (__FileNameFor_Account));
        return false;
    }

    // dosya okumadan önce sayacı sıfırlamak
    rowCounter = 0;

    // dosya sonuna kadar saysın
    while(!feof(filePtr))
    {
        // hesap numarasını oku
        fscanf(filePtr, "%d%4s%5s%lf", 
            &tempAccount.accNum, tempAccount.firstName,
            tempAccount.lastName, &tempAccount.balance);

        // bu satır okunamadı, sonraki satıra geçsin
        if(tempAccount.accNum < 1)
            continue;

        // sayacı arttırsın
        rowCounter++;
    }

    // satır miktarı kadar yapı tutabilecek yapı dizisi oluştursun
    Account arrAccount[rowCounter];

    // dizinin uzunluğunu tutsun
    const unsigned int lengthArrAccount = (sizeof(arrAccount) / sizeof(arrAccount[0]));
    
    // dosyanın başına alsın
    fseek(filePtr, 0, SEEK_SET);

    // verileri alsın ve depolasın
    for(rowCounter = 0; !feof(filePtr) && rowCounter < lengthArrAccount; rowCounter++)
    {
        // veriyi geçici olarak okumak ve geçerli veriyi depolamak
        // veriyi dosyadan okumak
        fscanf(filePtr, "%d%4s%5s%lf",
            &tempAccount.accNum, tempAccount.firstName,
            tempAccount.lastName, &tempAccount.balance);

        // bu satır okunamadı, sonraki satıra geçsin
        if(tempAccount.accNum < 1)
        {
            --rowCounter; // sayaç sürekli artmaması içni 1 düşüyoruz
            continue;
        }

        // veriler geçerli, veriyi depolasın
        arrAccount[rowCounter] = tempAccount;
    }

    // o dosyayı kapatıp yeni dosyayı açmayı deniyoruz çünkü
    // verileri kontrol etmeliyiz fakat ek olarak dosya açma
    // NULL değil ise dosyayı kapatıyoruz
    if(filePtr != NULL)
        fclose(filePtr);

    // yeni dosyayı açıyoruz, eğer dosya yok ise
    // verileri yeni dosyaya direk kaydedicek
    switch((filePtr = fopen(__FileNameFor_Shopping, "r")) != NULL)
    {
        case true:
            // dosyanın başına al
            fseek(filePtr, 0, SEEK_SET);

            // sayacı sıfırla
            rowCounter = 0;

            // eğer geçerli hesap numarası varsa sayacı arttır
            while(!feof(filePtr))
            {
                // eşleşme yok
                matched = false;

                // hesap numarasını oku
                fscanf(filePtr, "%d%lf",
                    &tempShopping.accNum, &tempShopping.money);
        
                // bu satır okunamadı, sonraki satıra geçsin
                if(tempShopping.accNum < 1)
                    continue;

                // eğer veri hesap verileri ile uyuşuyorsa sayacı arttırmasın
                for(testCounter = 0; testCounter < lengthArrAccount; testCounter++)
                {
                    if(arrAccount[testCounter].accNum == tempShopping.accNum)
                    {
                        matched = true; // eşleşti
                        arrAccount[testCounter].balance += tempShopping.money; // ana bakiyeye ekle
                        break;
                    }
                }

                // eşleşme var, sonraki tura geçsin
                if(matched)
                    continue;

                // geçerli hesap numarası var, sayacı arttır
                ++rowCounter;
            }

            // alış veriş bilgilerini tutacak yapı dizisi oluştur
            Shopping arrShopping[rowCounter];

            // dizinin uzunluğunu tutsun
            const unsigned int lengthArrShopping = (sizeof(arrShopping) / sizeof(arrShopping[0]));

            // dosyanın başına al
            fseek(filePtr, 0, SEEK_SET);

            // verileri diziye aktar
            for(rowCounter = 0; !feof(filePtr) && rowCounter < lengthArrShopping; rowCounter++)
            {
                // başalngıçta eşleşme yok olarak belirlendi
                matched = false;

                fscanf(filePtr, "%d%lf",
                    &tempShopping.accNum, &tempShopping.money);

                // geçerli hesap numarası yoksa sonraki tura geç
                if(tempShopping.accNum < 1)
                {
                    --rowCounter;
                    continue;
                }

                // eğer veri hesap verileri ile uyuşuyorsa sayacı arttırmasın
                for(testCounter = 0; testCounter < lengthArrAccount; testCounter++)
                {
                    if(arrAccount[testCounter].accNum == tempShopping.accNum)
                    {
                        // paraya ekleme yap ve eşleşme olduğunu bildir
                        matched = true;
                    }
                }

                // eşleşme var, sayacı 1 düşür ve sonraki tura geç
                if(matched)
                {
                    --rowCounter;
                    continue;
                }

                // veriyi diziye ekle
                arrShopping[rowCounter] = tempShopping;
            }

            // dosya okumayı kapatıyoruz
            if(filePtr != NULL)
                fclose(filePtr);

            // dosyaya yazma işlemi için dosyayı açıyoruz
            if((filePtr = fopen(__FileNameFor_NewRecord, "w")) == NULL)
            {
                printf("%s: %s\n", (__ErrFileNotFound), (__FileNameFor_NewRecord));
                return false;
            }

            // dosyanın başına almaya gerek yok çünkü veriyi otomatik siliyor
            // başlık ekle dosyaya
            fprintf(filePtr, "%-4s%-7s%-8s%-5s\n",
                "Nu", "İsim", "Soyisim", "Tutar");

            // hesap bilgileri çıktısı
            for(rowCounter = 0; rowCounter < lengthArrAccount; rowCounter++)
            {
                // çıktıyı dosyaya yazdır
                fprintf(filePtr, "%-4d%-6s%-8s%-7.2f\n",
                    arrAccount[rowCounter].accNum, arrAccount[rowCounter].firstName,
                    arrAccount[rowCounter].lastName, arrAccount[rowCounter].balance);
            }

            // eşleşmeyen hesap çıktıları
            for(rowCounter = 0; rowCounter < lengthArrShopping; rowCounter++)
            {
                // eşleşmeme bilgisini dosyaya yazdır
                fprintf(filePtr, "%s %d\n",
                    (__ErrNotMatchedAcc), arrShopping[rowCounter].accNum);
            }
        return true; // alış veriş dosyası okuması işlemleri bitti
    }

    // dosya okumayı kapatıyoruz
    if(filePtr != NULL)
        fclose(filePtr);

    // dosyaya yazma işlemi için dosyayı açıyoruz
    if((filePtr = fopen(__FileNameFor_NewRecord, "w")) == NULL)
    {
        printf("%s: %s\n", (__ErrFileNotFound), (__FileNameFor_NewRecord));
        return false;
    }

    // dosyanın başına almaya gerek yok çünkü veriyi otomatik siliyor
    // başlık ekle dosyaya
    fprintf(filePtr, "%-4s%-7s%-8s%-5s\n",
        "Nu", "İsim", "Soyisim", "Tutar");

    // hesap bilgileri çıktısı
    for(rowCounter = 0; rowCounter < lengthArrAccount; rowCounter++)
    {
        // çıktıyı dosyaya yazdır
        fprintf(filePtr, "%-4d%-6s%-8s%-7.2f\n",
            arrAccount[rowCounter].accNum, arrAccount[rowCounter].firstName,
            arrAccount[rowCounter].lastName, arrAccount[rowCounter].balance);
    }
}