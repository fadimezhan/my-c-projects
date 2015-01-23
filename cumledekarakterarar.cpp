//Girilen cumlede istenen karakter sayisini bulur.
//Fadime Özhan :)
#include<stdio.h>
#include<conio.h>

void main(){
	int i=0,sayi=0;
	char cumle[32],aranan;
	printf("Bir cumle giriniz: ");gets(cumle);
	printf("Aranacak karakter :");scanf("%c",&aranan);
	for(i=0;i<32;i++){
		if(cumle[i]==aranan)
			sayi++;
	}
	printf("\n\n%d tane %c girilmistir.",sayi,aranan);
	getch();
}


