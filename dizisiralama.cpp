//fonksiyonlarla dizide arama,siralama
#include<stdio.h>
#include<conio.h>

int siraliMI(int dizi[],int N);
void sirala(int dizi[],int N);
int arama(int dizi[],int N,int aranan);

void main(){
	int dizi[]={1,9,5,7,3,8},N=6,test,aranan,sonuc;
	test=siraliMI(dizi,N);
	if(test==0)
		sirala(dizi,N);
	printf("\nDizide aramak istedeiginiz deger : ");scanf("%d",&aranan);
	sonuc=arama(dizi,N,aranan);
		printf("%d",sonuc);
	getch();
}

int siraliMI(int dizi[],int N){
	int i,j,temp;
	for(i=N-1;i>0;i--){
		for(j=0;j<i;j++){
			if(dizi[j]>dizi[j+1])
				return 0;
		}
	}
				return 1;
}

void sirala(int dizi[],int N){
	int i,j,temp;
	for(i=N-1;i>0;i--){
		for(j=0;j<i;j++){
			if(dizi[j]>dizi[j+1]){
				temp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=temp;
			}	
		}
	}
	for(i=0;i<N;i++)
	printf("%d\t",dizi[i]);
	getch();

}

int arama(int dizi[],int N,int aranan){
	int i,j;
	for(j=N-1;j>0;j++){
		for(i=0;i<j;i++){
			if(dizi[i]==aranan){
				return i;//indis yollar..
			}

		}
	}
	return -1;
}