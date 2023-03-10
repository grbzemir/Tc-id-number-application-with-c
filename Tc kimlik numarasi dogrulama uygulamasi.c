#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


// TC KİMLİK NO DOĞRULAMA 
// 1. kural: ilk 10 rakamın toplamının mod 10 u 11. sayiyi verecek
// 2. kural: 1,3,5,7,9.  rakamlarının toplamının 7 katı ile 2,4,6,8. rakamlarının 9 katının toplamının mod10 u 10. sayi verecek
// 3. kural: 1,3,5,7,9.   rakamlarının toplamının 8 katının mod10 u 11. sayi verecek 

int TcKimlikKontorl(char *ptr)
{
    // 1. kural
    
    int ilkOnRakamToplami=0;
    int i;
    i=0;
    while(i<10)
    {
        ilkOnRakamToplami=ilkOnRakamToplami+ptr[i]-'0';

        i++;
    }
     
     ilkOnRakamToplami=ilkOnRakamToplami%10;

     int onbirinciRakam=ptr[10]-'0';

        if (ilkOnRakamToplami!=onbirinciRakam)
        {
            return 0;
        }
    
    // 2. kural

    int tekRakamToplami=0;
    i=0;
    while(i<9)
    {
        tekRakamToplami=tekRakamToplami+ptr[i]-'0';

        i=i+2;
    }
    int temp = tekRakamToplami*7;

    int cifRakamToplami=0;
    i=1;

    while(i<8)
    {
        cifRakamToplami=cifRakamToplami+ptr[i]-'0';
        i=i+2;
    }

    cifRakamToplami=cifRakamToplami*9;

    int ikincikural=(tekRakamToplami+cifRakamToplami)%10;

    int onuncuRakam=ptr[9]-'0';
    if(ikincikural!=onuncuRakam)
    {
        return 0;
    }

    int ucuncukuraltekRakamToplami=(tekRakamToplami*8)%10;

    if(onbirinciRakam!=ucuncukuraltekRakamToplami)
    
        return 0;
    
    
        return 0;
    }

int main ()
{
   
   system("cls");
   system("color 0a");
   printf("KIMLIK DOGRULAMA UYGULAMASI\n\n");
   
   char tcNumarasi[11];

   printf("Tc numaranizi giriniz : ");

   scanf("%s",tcNumarasi);

   int sonuc;
   sonuc=TcKimlikKontorl(tcNumarasi);

   if (sonuc==1)
   {
    printf("Tc kimlik numarasi dogru");
   }
   else
   {
    printf("Tc kimlik numarasi yanlis");
   }

    return 0;
}