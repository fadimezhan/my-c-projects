//sayi 3 ise; 111
//            122
//            123 tipinde yazdiran program..
//Fadime Özhan
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int sayi,sayac;
	system("CLS");
	printf("(Cikis icin 0 tusuna basiniz.)\n ");
	printf("Bir sayi giriniz:\n");
	scanf("%d",&sayi);
	if(sayi!=0){
	for(int i=1;i<=sayi;i++){
		sayac=sayi;
		for(int j=1;j<=i;j++){
			printf("%d",j);
			
		}
		while(i<sayac){
			printf("%d",i);
			sayac--;
		}
		printf("\n");
	}
	printf("\nDevam etmek icin bir tusa basin.\n");
	getch();
	}
	else return 0;
	main();
}