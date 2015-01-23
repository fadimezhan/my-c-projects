/*
PROJE ÖDEVÝ
FADÝME ÖZHAN
Numara : 13253047
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>


void admin();//yapýldý
void memurf();
void kullanicif();
void kul_is();
void kul_ekle(struct kullanici *kisi1);
void kul_sil(struct kullanici *kisi1);
void kul_gün(struct kullanici *kisi1);
void kul_ara(struct kullanici *kisi1);
void memur_is();
void memur_ekle(struct memur *kisi2);
void memur_sil(struct memur *kisi2);
void sig_is();
int si_ekle(struct siginmaci *kisi);
void si_sil(struct siginmaci *kisi);
void si_gün(struct siginmaci *kisi);
void si_ara(struct siginmaci *kisi);
void si_lis(struct siginmaci *kisi);
//void ku_go(adiste);
void sifre_de(struct kullanici *kisi1);
int sorgulama(struct kullanici *kisi1);
int sorgulamatel(struct kullanici *kisi1);

#define si_boyutu sizeof(struct siginmaci)

int i,x,y;
int k_sifre;
char adiste[15];


FILE *kullanici;
FILE *siginmaci;
FILE *memur;

struct siginmaci{

	    char ad[20],soyad[20],cinsiyet[10],uyruk[20],meslek[20],egitim[50],gel_sehir[20],do_yeri[20],yer_adres[50],eposta[20];
	    char do_tarihi[10],tel[20],ge_tarihi[10];
		int kayit;
		char sinu[10];
};

struct kullanici{
	char isim[20],soyisim[20],adres[20],kullanici_adi[20],yetki_turu[20],e_posta[20];
	char tel[10],tc[11],sifre[20];
	char ku_no,kayit;
};
struct memur{
	char isim[20],soyisim[20],sifre[20],dogumtarihi[20],cinsiyet[10];
};

struct siginmaci kisi[BUFSIZ],siginmacisildir[BUFSIZ],siginmaciguncelleme[BUFSIZ],temp[BUFSIZ];
struct kullanici kisi1[BUFSIZ],kullanicisildir[BUFSIZ],kullaniciguncelleme[BUFSIZ];
struct memur kisi2[BUFSIZ],memursildir[BUFSIZ];

void main()
{
	char yetki,kullaniciadi[10];
	int ku_sifre,me_sifre;
	char sifre[6]={'1','2','3','4','5','6'};
	char sifre_iste[6];
	for(int i=0;i<BUFSIZ;i++)
	{
		kisi1[i].kayit='0';
		kisi[i].kayit='0';
	}
	bas:
	system("CLS");
	printf("\n\t\tSIGINMACI TAKIP SISTEMI\n\n\t1-Admin\n\t2-Siginmaci Memuru\n\t3-Kullanici\n\t4-Cikis\n\nYetki Turunuz : ");
	yetki=getch();
	switch(yetki)
	{
	case '1': 
		printf("\n\nAdmin Sifreniz :");
		sifre_iste[0]=getch();printf("*");
		sifre_iste[1]=getch();printf("*");
		sifre_iste[2]=getch();printf("*");
		sifre_iste[3]=getch();printf("*");
		sifre_iste[4]=getch();printf("*");
		sifre_iste[5]=getch();printf("*");
	if(sifre_iste[0]==sifre[0]&&sifre_iste[1]==sifre[1]&&sifre_iste[2]==sifre[2]&&sifre_iste[3]==sifre[3]&&sifre_iste[4]==sifre[4]&&sifre_iste[5]==sifre[5])
		admin();
			else {printf("Sifre Yanlis!");}getch();goto bas;
	case '2': 		printf("\n\Memur Sifreniz :");
		sifre_iste[0]=getch();printf("*");
		sifre_iste[1]=getch();printf("*");
		sifre_iste[2]=getch();printf("*");
		sifre_iste[3]=getch();printf("*");
		sifre_iste[4]=getch();printf("*");
		sifre_iste[5]=getch();printf("*");
	if(sifre_iste[0]==sifre[0]&&sifre_iste[1]==sifre[1]&&sifre_iste[2]==sifre[2]&&sifre_iste[3]==sifre[3]&&sifre_iste[4]==sifre[4]&&sifre_iste[5]==sifre[5])
		memurf();
			else {printf("Sifre Yanlis!");}getch();goto bas;    
			
	case '3':kullanicif(); goto bas;
		/*printf("\n\Kullanici Sifreniz :");
		sifre_iste[0]=getch();printf("*");
		sifre_iste[1]=getch();printf("*");
		sifre_iste[2]=getch();printf("*");
		sifre_iste[3]=getch();printf("*");
		sifre_iste[4]=getch();printf("*");
		sifre_iste[5]=getch();printf("*");
	if(sifre_iste[0]==sifre[0]&&sifre_iste[1]==sifre[1]&&sifre_iste[2]==sifre[2]&&sifre_iste[3]==sifre[3]&&sifre_iste[4]==sifre[4]&&sifre_iste[5]==sifre[5])
		kullanicif();
		else {printf("Sifre Yanlis!");}getch();goto bas; */
	case '4':exit(1);
	default:system("CLS");printf("Tanimsiz bir deger girdiniz.Tekrar Deneyin!\n\n");goto bas;
	};

}

void admin()
{
	system("CLS");
	char islem;
	 printf("\t\tADMIN\n\n\t1-Kullanici Islemleri\n\t2-Siginmaci Islemleri\n\t3-Memur Islemleri\n\t4-Ana Menu\n\nYapmak Istediginiz Islem (1-2-3-4) : ");islem=getch();
	 switch(islem){
	 case '1':kul_is();return;
	 case '2':sig_is();return;
	 case '3':memur_is();return;
	 case '4':return;
	 default:system("CLS");printf("Tanimsiz bir deger girdiniz. Tekrar Deneyin!\n\n"); return;
	 };


	getch();
}

void memurf()
{
	system("CLS");
	char islem;

	 printf("\t\tSiginmaci Memuru\n\n\t\n\t1-Siginmaci Islemleri\n\t2-Ana Menu\n\nYapmak Istediginiz Islem (1-2) : ");islem=getch();
	 switch(islem){
	 case '1':sig_is();return;
	 case '2':return;
	 default:system("CLS");printf("Tanimsiz bir deger girdiniz. Tekrar Deneyin!\n\n"); return;
	 };
	 getch();

}

void kullanicif()
{
	char islem;
	char adiste[15];
	char sifreiste[15];
	printf("\nKullanici Adiniz :");gets(adiste);
	printf("\nKullanici Sifreniz :");gets(sifreiste);
	kullanici=fopen("kullanici.txt","r");
	
for(int i=0;i<BUFSIZ;i++)
{
  while(fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc/*numara*/,kisi1[i].tel/*TC*/,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta)!=EOF)
	{
	   if(strcmp(kisi1[i].kullanici_adi,adiste)==0)
		{
		   if(strcmp(kisi1[i].sifre,sifreiste)==0)
			{ bas:
			  system("CLS");
	          printf("\tKullanici\n\n\t1-Bilgilerini Goruntule\n\t2-Sifre Degistir\n\t3-Ana Menu\n\nYapmak istediginiz islem (1-2-3) :");scanf("%d",&islem);
	          switch(islem)
	             {
		case 1:printf("\n\t\tKULLANICI BILGILERI\n");
	                 kullanici=fopen("kullanici.txt","r");
	                 for(int i=0;i<BUFSIZ;i++)
	                    {
	                      while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta)!=EOF)
		                    {
		                     if(strcmp(kisi1[i].kullanici_adi,adiste)==0)
			                    {
			                    	printf("\n\nKullanici Numarasi :%s\nT.C :%s\nIsim :%s\nSoyisim :%s\nTelefon :%s\nAdres :%s\nYetki :%s\nKullanici Adi :%s\nSifre :%s\nE-Posta :%s",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta);
				                    getch();
				
			                     }
		                    }
	
	                    }
	                    fclose(kullanici);main();
	    case 2://sifre degistir fonksiyonu
                  char yenisifre[15];
	              char eminmi;
	              printf("Yeni Sifre : ");scanf("%s",yenisifre);
	              printf("\nSifrenizi degistirmek istediginize emin misiniz? (E/H) :");eminmi=getch();
	                if(eminmi=='e' || eminmi=='E')
					{
						strcpy(kisi1[i].sifre,yenisifre);
						printf("\n\nSifreniz basariyla degistirilmistir..");
						getch();
						 fclose(kullanici);main();
					}
	                
					else { fclose(kullanici);main();}
	    case 3: fclose(kullanici);return;
	    default:system("CLS");printf("Tanimsiz bir deger girdiniz. Tekrar Deneyin!\n\n");  fclose(kullanici);return;
					   }

					}
					else
				    {
					printf("\nSifre veya kullanici adi yanlis.. Tekrar deneyin!");getch(); fclose(kullanici);return;
				    }
				}
				else
				{
					printf("\nSifre veya kullanici adi yanlis.. Tekrar deneyin!");getch(); fclose(kullanici);return;
				}
		}}
}

void kul_is(){
	     char islem;
		 system("CLS");
		 
		 bas:
		 printf("\t\tKullanici Islemleri\n\n\t1-Kullanici Ekleme\n\t2-Kullanici Silme\n\t3-Kullanici Bilgilerini Guncelleme\n\t4-Kullanici Arama\n\t5-Ana Menu\n\nYapacaginiz Islem (1-2-3-4-5) :");
		 islem=getch();
		 switch(islem){
		 case '1':kul_ekle(kisi1);return;
		 case '2':kul_sil(kisi1);return;
		 case '3':kul_gün(kisi1);return;
		 case '4':kul_ara(kisi1);return;
		 case '5':return;
		 default:system("CLS");printf("Tanimsiz bir deger girdiniz. Tekrar Deneyin!\n\n"); goto bas;
		 }
}

void kul_ekle(struct kullanici *kisi1){
	FILE *kullanici;
	
	kullanici=fopen("kullanici.txt","a");
	//fprintf(kullanici,"%10d%11s%15s%15s%15s%15s%15s%15s%15s\n","Kullanici No","Tc","Isim","Soyisim","Tel","Adres","Yetki Turu","Kullanici Adi","Sifre");
	for(int i=0;i<BUFSIZ;i++)
	{
		if(kisi1[i].kayit=='0'){
	        do{
				printf("\nYetki Turu :"); gets(kisi1[i].yetki_turu);
			}while(isalpha(*kisi1[i].yetki_turu)==0);
			if(kisi1[i].yetki_turu=="memur")
				memur_ekle(kisi2);
			else{
			do{
				printf("\nT.C  :");gets(kisi1[i].tc); x=sorgulama(kisi1);		
			}while(x==1);
			do{
			printf("\nIsim :");gets(kisi1[i].isim);
			}while(isalpha(*kisi1[i].isim)==0);
			do{
				printf("\nSoyisim :");gets(kisi1[i].soyisim);
			}while(isalpha(*kisi1[i].soyisim)==0);
			int a=0;
			
			do{
				printf("\nTel :");gets(kisi1[i].tel);y=sorgulamatel(kisi1);	
			}while(y==1);
				printf("\nE-Posta(varsa) :");gets(kisi1[i].e_posta);
			do{
				printf("\nAdres :");gets(kisi1[i].adres);
			}while(isalpha(*kisi1[i].adres)==0);
			
		
				printf("\nKullanici Adi :");gets(kisi1[i].kullanici_adi);
                printf("\nSifre :");gets(kisi1[i].sifre);
				kisi1[i].kayit=='1';
				printf("\n\nKayit basariyla eklendi...");
		
				k_sifre=*(kisi1[i].sifre);

				fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta);
				
                fclose(kullanici);
				getch();
			}

	}return;
	}
}

void kul_sil(struct kullanici *kisi1)
{
	bas:
	system("cls");
	
	char cevap;
	
	    char isim[11];
		int denetleyici=0;
		printf("Silinecek kullanicinin adini giriniz: ");gets(isim);
	   kullanici=fopen("kullanici.txt","r+");
		int x=0;
		if (kullanici == NULL)
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else
		{
			system("cls");
			
			printf("\n\t\tKULLANICI SILME\n\n");
			
			for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc/*numara*/,kisi1[i].tel/*TC*/,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta)!=EOF)
			{
				if(strcmp(kisi1[i].isim,isim)==0)
				{	
					denetleyici=1;
					//printf("girdi.");getch();
					strcpy(kullanicisildir[x].tc," ");
					strcpy(kullanicisildir[x].tel," ");
					strcpy(kullanicisildir[x].isim," ");		
					strcpy(kullanicisildir[x].soyisim," ");	
					strcpy(kullanicisildir[x].e_posta," ");	
					strcpy(kullanicisildir[x].adres," ");	
				    strcpy(kullanicisildir[x].sifre," ");
					strcpy(kullanicisildir[x].kullanici_adi," ");
					strcpy(kullanicisildir[x].yetki_turu," ");
				}
				else 
				{	
					//printf("digerine girdi.");getch();
					strcpy(kullanicisildir[x].isim,kisi1[i].isim);		
					strcpy(kullanicisildir[x].soyisim,kisi1[i].soyisim);	
					strcpy(kullanicisildir[x].tc,kisi1[i].tc);	
					strcpy(kullanicisildir[x].e_posta,kisi1[i].e_posta);	
					strcpy(kullanicisildir[x].tel,kisi1[i].tel);	
					strcpy(kullanicisildir[x].adres,kisi1[i].adres);	
					strcpy(kullanicisildir[x].sifre,kisi1[i].sifre);
					strcpy(kullanicisildir[x].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullanicisildir[x].yetki_turu,kisi1[i].yetki_turu);
				}
				x++;
			}
			fclose(kullanici);
			if (denetleyici==0)
			{
				printf("Dosyada %s adli kullanici bulunamadi.",isim);
				getch();
				goto bas;
			}
			
			else {
				kullanici=fopen("kullanici.txt","w");
			for(int j=0 ; j<x ; j++)
			{
				fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullanicisildir[j].tc/*numara*/,kullanicisildir[j].tel/*TC*/,kullanicisildir[j].isim,kullanicisildir[j].soyisim,kullanicisildir[j].tel,kullanicisildir[j].adres,kullanicisildir[j].yetki_turu,kullanicisildir[j].kullanici_adi,kullanicisildir[j].sifre,kullanicisildir[j].e_posta);
			}
			fclose(kullanici);
			printf("%s numarali kullanici basariyla silinmistir",isim);getch();return;
			}}
		}
		istek:
	printf("\n\n     Yeni bir kisi daha silmek istiyor musunuz(e/h) : "); // baþka ekleme yapýp yapmayacaðýmýz sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		return;				
	}
	else if (cevap=='e')
	{
		goto bas;
	//	kul_sil(kisi1);				
	}
	else goto istek;
	
}

void kul_gün(struct kullanici *kisi1)
{
	int x,secim;
	system("cls");
	int denetleyici=0;
	int k=0,denetleyici2=0;
	char cevap;
	char guncelle_ad[20];
	char guncelle_adres[11];
	char guncelle_soyad[15];
	char guncelle_kullaniciadi[15];
	char guncelle_sifre[15];
	char guncelle_tel[15];
	char guncelle_tc[15];
	char guncelle_eposta[15];
	char guncelle_yetki[15];
			
			/*x=sorgulama(guncelle_tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}*/
		system("cls");
		kullanici = fopen("kullanici.txt", "r+");//Dosyayý okuma+yazma modunda açýyoruz...
		//if (kullanici == NULL)//Dosya açýlmassa(daha önce açýlmýþ ve silinmiþse veya açma iþlemi gerçekleþtirilmemiþse) NULL deðeri gelir
		//{
		//	printf("Dosya veya sunucu bulunamadi!\n");
		//}
		//else//Dosya daha önce varsa güncelleme iþlemi yapýlabilir.
		//{
			system("cls");
			printf("\n\t\tKULLANICI GUNCELLEME\n\n");
			printf("\nGuncellenicek kisinin ismini giriniz:");scanf("%s",&guncelle_ad);
			printf("\n\n%s Kullanicisi Icin :\n\t1-Ismi Guncelle\n\t2-Soyismi Guncelle\n\t3-Adres Guncelle\n\t4-Kullanici Adi\n\t5-E-posta Guncelle\n\t6-Sifre Guncelle\n\t7-T.C. Guncelle\n\t8-Tel Guncelle\nSeciminiz (1-2-3-4-5-6-7-8) :",guncelle_ad);
			scanf("%d",&secim);
			switch(secim)
			{

			case 1://isim guncellemek için girer....  
				for(int i=0;i<BUFSIZ;i++)
				{
			while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[i].tc/*numara*/,kullaniciguncelleme[i].tel/*TC*/,kullaniciguncelleme[i].isim,kullaniciguncelleme[i].soyisim,kullaniciguncelleme[i].tel,kullaniciguncelleme[i].adres,kullaniciguncelleme[i].yetki_turu,kullaniciguncelleme[i].kullanici_adi,kullaniciguncelleme[i].sifre,kullaniciguncelleme[i].e_posta)!=EOF)
			{
				
				if (strcmp(kisi1[i].isim, guncelle_ad)==0)//Aranan isimle karþýlaþtýrma yaptýrýp doðruysa bilgileri deðiþtiriyoruz
				{	
					//kiþi bilgileri deðiþtirilerek k deðerine göre olan struct deðiþkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					
					printf("\n\nYeni Adi:");
					_flushall();
					gets(kullaniciguncelleme[i].isim);
					//strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				}
				else
				{
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
				}
				k++;
			}
			fclose(kullanici);
		//}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s adli biri bulunmamaktadir.",guncelle_ad);
			getch();
			kul_gün(kisi1);
		}
		else 
		{
			kullanici=fopen("kullanici.txt","w");//dosyayý sýfýrdan açýp tekrar yazdýrmak için yazma modunda açýyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[j].tc/*numara*/,kullaniciguncelleme[j].tel/*TC*/,kullaniciguncelleme[j].isim,kullaniciguncelleme[j].soyisim,kullaniciguncelleme[j].tel,kullaniciguncelleme[j].adres,kullaniciguncelleme[j].yetki_turu,kullaniciguncelleme[j].kullanici_adi,kullaniciguncelleme[j].sifre,kullaniciguncelleme[j].e_posta);
		}
		fclose(kullanici);return;
		}}

			case 2://soyisim guncellemek için girer...
				
				for(int i=0;i<BUFSIZ;i++)
				{
					while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[i].tc/*numara*/,kullaniciguncelleme[i].tel/*TC*/,kullaniciguncelleme[i].isim,kullaniciguncelleme[i].soyisim,kullaniciguncelleme[i].tel,kullaniciguncelleme[i].adres,kullaniciguncelleme[i].yetki_turu,kullaniciguncelleme[i].kullanici_adi,kullaniciguncelleme[i].sifre,kullaniciguncelleme[i].e_posta)!=EOF)
			{
				
				if (strcmp(kisi1[i].isim, guncelle_ad)==0)//Aranan isimle karþýlaþtýrma yaptýrýp doðruysa bilgileri deðiþtiriyoruz
				{	
					//kiþi bilgileri deðiþtirilerek k deðerine göre olan struct deðiþkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					printf("\nYeni Soyadi:");
					_flushall();
					gets(kullaniciguncelleme[i].soyisim);
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					//strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				}
				else
				{
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
				}
				k++;
					}}
			fclose(kullanici);
		//}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s adli biri bulunmamaktadir.",guncelle_ad);
			getch();
			kul_gün(kisi1);
		}
		else 
		{
			kullanici=fopen("kullanici.txt","w");//dosyayý sýfýrdan açýp tekrar yazdýrmak için yazma modunda açýyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[j].tc/*numara*/,kullaniciguncelleme[j].tel/*TC*/,kullaniciguncelleme[j].isim,kullaniciguncelleme[j].soyisim,kullaniciguncelleme[j].tel,kullaniciguncelleme[j].adres,kullaniciguncelleme[j].yetki_turu,kullaniciguncelleme[j].kullanici_adi,kullaniciguncelleme[j].sifre,kullaniciguncelleme[j].e_posta);

		}
		fclose(kullanici);
		}return;
			
			case 3://adres guncellemek için girer..
			
				for(int i=0;i<BUFSIZ;i++)
				{
                   while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[i].tc/*numara*/,kullaniciguncelleme[i].tel/*TC*/,kullaniciguncelleme[i].isim,kullaniciguncelleme[i].soyisim,kullaniciguncelleme[i].tel,kullaniciguncelleme[i].adres,kullaniciguncelleme[i].yetki_turu,kullaniciguncelleme[i].kullanici_adi,kullaniciguncelleme[i].sifre,kullaniciguncelleme[i].e_posta)!=EOF)
                   {
				if (strcmp(kisi1[i].isim, guncelle_ad)==0)//Aranan isimle karþýlaþtýrma yaptýrýp doðruysa bilgileri deðiþtiriyoruz
				{	
					//kiþi bilgileri deðiþtirilerek k deðerine göre olan struct deðiþkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					
					printf("\nYeni Adres :");
					_flushall();
					gets(kullaniciguncelleme[i].adres);
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					//strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				}
				else
				{
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
				}
				k++;
				   }}
			fclose(kullanici);
		//}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s adli biri bulunmamaktadir.",guncelle_ad);
			getch();
			kul_gün(kisi1);
		}
		else 
		{
			kullanici=fopen("kullanici.txt","w");//dosyayý sýfýrdan açýp tekrar yazdýrmak için yazma modunda açýyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[j].tc/*numara*/,kullaniciguncelleme[j].tel/*TC*/,kullaniciguncelleme[j].isim,kullaniciguncelleme[j].soyisim,kullaniciguncelleme[j].tel,kullaniciguncelleme[j].adres,kullaniciguncelleme[j].yetki_turu,kullaniciguncelleme[j].kullanici_adi,kullaniciguncelleme[j].sifre,kullaniciguncelleme[j].e_posta);

		}fclose(kullanici);
		}return;
		
			
			case 4://kullanici adi guncellemek için girer...
			
				for(int i=0;i<BUFSIZ;i++)
				{
					while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[i].tc/*numara*/,kullaniciguncelleme[i].tel/*TC*/,kullaniciguncelleme[i].isim,kullaniciguncelleme[i].soyisim,kullaniciguncelleme[i].tel,kullaniciguncelleme[i].adres,kullaniciguncelleme[i].yetki_turu,kullaniciguncelleme[i].kullanici_adi,kullaniciguncelleme[i].sifre,kullaniciguncelleme[i].e_posta)!=EOF)
			{
				
				if (strcmp(kisi1[i].isim, guncelle_ad)==0)//Aranan isimle karþýlaþtýrma yaptýrýp doðruysa bilgileri deðiþtiriyoruz
				{	
					//kiþi bilgileri deðiþtirilerek k deðerine göre olan struct deðiþkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					
					printf("\nYeni Kullanici Adi :");
					_flushall();
					gets(kullaniciguncelleme[i].adres);
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					//strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				}
				else
				{
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
				}
				k++;
					}}
			fclose(kullanici);
		//}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s adli biri bulunmamaktadir.",guncelle_ad);
			getch();
			kul_gün(kisi1);
		}
		else 
		{
			kullanici=fopen("kullanici.txt","w");//dosyayý sýfýrdan açýp tekrar yazdýrmak için yazma modunda açýyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[j].tc/*numara*/,kullaniciguncelleme[j].tel/*TC*/,kullaniciguncelleme[j].isim,kullaniciguncelleme[j].soyisim,kullaniciguncelleme[j].tel,kullaniciguncelleme[j].adres,kullaniciguncelleme[j].yetki_turu,kullaniciguncelleme[j].kullanici_adi,kullaniciguncelleme[j].sifre,kullaniciguncelleme[j].e_posta);

		}fclose(kullanici);
		
		}return;
			
			case 5://e-posta guncellemek için girer...
			
				for(int i=0;i<BUFSIZ;i++)
				{
					while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[i].tc/*numara*/,kullaniciguncelleme[i].tel/*TC*/,kullaniciguncelleme[i].isim,kullaniciguncelleme[i].soyisim,kullaniciguncelleme[i].tel,kullaniciguncelleme[i].adres,kullaniciguncelleme[i].yetki_turu,kullaniciguncelleme[i].kullanici_adi,kullaniciguncelleme[i].sifre,kullaniciguncelleme[i].e_posta)!=EOF)
			{
				
				if (strcmp(kisi1[i].isim, guncelle_ad)==0)//Aranan isimle karþýlaþtýrma yaptýrýp doðruysa bilgileri deðiþtiriyoruz
				{	
					//kiþi bilgileri deðiþtirilerek k deðerine göre olan struct deðiþkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					
					printf("\nYeni Kullanici Adi :");
					_flushall();
					gets(kullaniciguncelleme[i].adres);
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					//strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				}
				else
				{
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
				}
				k++;
					}}
			fclose(kullanici);
		//}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s adli biri bulunmamaktadir.",guncelle_ad);
			getch();
			kul_gün(kisi1);
		}
		else 
		{
			kullanici=fopen("kullanici.txt","w");//dosyayý sýfýrdan açýp tekrar yazdýrmak için yazma modunda açýyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[j].tc/*numara*/,kullaniciguncelleme[j].tel/*TC*/,kullaniciguncelleme[j].isim,kullaniciguncelleme[j].soyisim,kullaniciguncelleme[j].tel,kullaniciguncelleme[j].adres,kullaniciguncelleme[j].yetki_turu,kullaniciguncelleme[j].kullanici_adi,kullaniciguncelleme[j].sifre,kullaniciguncelleme[j].e_posta);

		}fclose(kullanici);
		
		}return;	
		
			case 6://sifre guncellemek için girer..
	
				for(int i=0;i<BUFSIZ;i++)
				{
					while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[i].tc/*numara*/,kullaniciguncelleme[i].tel/*TC*/,kullaniciguncelleme[i].isim,kullaniciguncelleme[i].soyisim,kullaniciguncelleme[i].tel,kullaniciguncelleme[i].adres,kullaniciguncelleme[i].yetki_turu,kullaniciguncelleme[i].kullanici_adi,kullaniciguncelleme[i].sifre,kullaniciguncelleme[i].e_posta)!=EOF)
			{
				
				if (strcmp(kisi1[i].isim, guncelle_ad)==0)//Aranan isimle karþýlaþtýrma yaptýrýp doðruysa bilgileri deðiþtiriyoruz
				{	
					//kiþi bilgileri deðiþtirilerek k deðerine göre olan struct deðiþkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					
					printf("\nYeni Sifre :");
					_flushall();
					gets(kullaniciguncelleme[i].adres);
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					//strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				}
				else
				{
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
				}
				k++;
					}}
			fclose(kullanici);
		//}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s adli biri bulunmamaktadir.",guncelle_ad);
			getch();
			kul_gün(kisi1);
		}
		else 
		{
			kullanici=fopen("kullanici.txt","w");//dosyayý sýfýrdan açýp tekrar yazdýrmak için yazma modunda açýyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[j].tc/*numara*/,kullaniciguncelleme[j].tel/*TC*/,kullaniciguncelleme[j].isim,kullaniciguncelleme[j].soyisim,kullaniciguncelleme[j].tel,kullaniciguncelleme[j].adres,kullaniciguncelleme[j].yetki_turu,kullaniciguncelleme[j].kullanici_adi,kullaniciguncelleme[j].sifre,kullaniciguncelleme[j].e_posta);

		}fclose(kullanici);
		
		}return;
			
			case 7://t.c. guncellemek için girer....
					
				for(int i=0;i<BUFSIZ;i++)
				{
					while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[i].tc/*numara*/,kullaniciguncelleme[i].tel/*TC*/,kullaniciguncelleme[i].isim,kullaniciguncelleme[i].soyisim,kullaniciguncelleme[i].tel,kullaniciguncelleme[i].adres,kullaniciguncelleme[i].yetki_turu,kullaniciguncelleme[i].kullanici_adi,kullaniciguncelleme[i].sifre,kullaniciguncelleme[i].e_posta)!=EOF)
			{
				
				if (strcmp(kisi1[i].isim, guncelle_ad)==0)//Aranan isimle karþýlaþtýrma yaptýrýp doðruysa bilgileri deðiþtiriyoruz
				{	
					//kiþi bilgileri deðiþtirilerek k deðerine göre olan struct deðiþkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					
					printf("\nYeni T.C. numarasi :");
					_flushall();
					gets(kullaniciguncelleme[i].adres);
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					//strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				}
				else
				{
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
				}
				k++;
					}}
			fclose(kullanici);
		//}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s adli biri bulunmamaktadir.",guncelle_ad);
			getch();
			kul_gün(kisi1);
		}
		else 
		{
			kullanici=fopen("kullanici.txt","w");//dosyayý sýfýrdan açýp tekrar yazdýrmak için yazma modunda açýyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[j].tc/*numara*/,kullaniciguncelleme[j].tel/*TC*/,kullaniciguncelleme[j].isim,kullaniciguncelleme[j].soyisim,kullaniciguncelleme[j].tel,kullaniciguncelleme[j].adres,kullaniciguncelleme[j].yetki_turu,kullaniciguncelleme[j].kullanici_adi,kullaniciguncelleme[j].sifre,kullaniciguncelleme[j].e_posta);
		
		}fclose(kullanici);
        }
		return;
			
			case 8://tel guncellemek için girer...
					
				for(int i=0;i<BUFSIZ;i++)
				{
					while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[i].tc/*numara*/,kullaniciguncelleme[i].tel/*TC*/,kullaniciguncelleme[i].isim,kullaniciguncelleme[i].soyisim,kullaniciguncelleme[i].tel,kullaniciguncelleme[i].adres,kullaniciguncelleme[i].yetki_turu,kullaniciguncelleme[i].kullanici_adi,kullaniciguncelleme[i].sifre,kullaniciguncelleme[i].e_posta)!=EOF)
			{
				
				if (strcmp(kisi1[i].isim, guncelle_ad)==0)//Aranan isimle karþýlaþtýrma yaptýrýp doðruysa bilgileri deðiþtiriyoruz
				{	
					//kiþi bilgileri deðiþtirilerek k deðerine göre olan struct deðiþkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					
					printf("\nYeni Telefon Numarasi :");
					_flushall();
					gets(kullaniciguncelleme[i].adres);
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					//strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				}
				else
				{
					strcpy(kullaniciguncelleme[k].isim,kisi1[i].isim);			
					strcpy(kullaniciguncelleme[k].soyisim,kisi1[i].soyisim);
					strcpy(kullaniciguncelleme[k].adres,kisi1[i].adres);
					strcpy(kullaniciguncelleme[k].e_posta,kisi1[i].e_posta);
					strcpy(kullaniciguncelleme[k].kullanici_adi,kisi1[i].kullanici_adi);
					strcpy(kullaniciguncelleme[k].sifre,kisi1[i].sifre);
					strcpy(kullaniciguncelleme[k].tc,kisi1[i].tc);
					strcpy(kullaniciguncelleme[k].tel,kisi1[i].tel);
					strcpy(kullaniciguncelleme[k].yetki_turu,kisi1[i].yetki_turu);

				}
				k++;
					}}
			fclose(kullanici);
		//}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s adli biri bulunmamaktadir.",guncelle_ad);
			getch();
			kul_gün(kisi1);
		}
		else 
		{
			kullanici=fopen("kullanici.txt","w");//dosyayý sýfýrdan açýp tekrar yazdýrmak için yazma modunda açýyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kullaniciguncelleme[j].tc/*numara*/,kullaniciguncelleme[j].tel/*TC*/,kullaniciguncelleme[j].isim,kullaniciguncelleme[j].soyisim,kullaniciguncelleme[j].tel,kullaniciguncelleme[j].adres,kullaniciguncelleme[j].yetki_turu,kullaniciguncelleme[j].kullanici_adi,kullaniciguncelleme[j].sifre,kullaniciguncelleme[j].e_posta);
		
		}fclose(kullanici);return;
			default :printf("Tanimsiz deger girdiniz.Tekrar deneyin!");getch();
				kul_gün(kisi1);
			}

}}

void kul_ara(struct kullanici *kisi1)
{
	int secim;
	char isimara[15];
	char soyisimara[15];
	char adresara[15];
	char telara[15];
	char kullaniciadiara[15];
	char epostaara[15];

	system("CLS");
	printf("\n\t\tKULLANICI ARAMA\n\n\t1-Isme Gore Ara\n\t2-Soyisme Gore Ara\n\t3-Adrese Gore Ara\n\t4-Telefon Numarasina Gore Ara\n\t5-E-Postaya Gore Ara\n\t6-Ana Menu\n\nSeciminiz (1-2-3-4-5-6) : "); scanf("%d",&secim);
	switch(secim)
	{
	case 1://Isme Gore Ara
		printf("\nAradiginiz kisinin adini giriniz : ");scanf("%s",isimara);
		kullanici=fopen("kullanici.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
		while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta)!=EOF)
		{
			if(strcmp(kisi1[i].isim,isimara)==0)//isimara 0 olunca giriyo..:(
			{
                 printf("%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta);
                  getch();
				kul_ara(kisi1);
			}
			else
			{
				printf("\nAradiginiz kisi bulunamadi.Tekrar deneyin!");
			    getch();
			    kul_ara(kisi1);
			}
		}}
	case 2://Soyisme Gore Ara
		printf("\nAradiginiz kisinin soyadini giriniz : ");scanf("%s",soyisimara);
		kullanici=fopen("kullanici.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
		while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta)!=EOF)
		{
			if(strcmp(kisi1[i].soyisim,soyisimara)==0)//isimara 0 olunca giriyo..:(
			{
                 printf("%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta);
                  getch();
				kul_ara(kisi1);
			}
			else
			{
				printf("\nAradiginiz kisi bulunamadi.Tekrar deneyin!");
			    getch();
			    kul_ara(kisi1);
			}
		}}
	case 3://Adrese Gore Ara
			printf("\nAradiginiz kisinin adresini giriniz : ");scanf("%s",adresara);
		kullanici=fopen("kullanici.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
		while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta)!=EOF)
		{
			if(strcmp(kisi1[i].adres,adresara)==0)//isimara 0 olunca giriyo..:(
			{
                 printf("%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta);
                  getch();
				kul_ara(kisi1);
			}
			else
			{
				printf("\nAradiginiz kisi bulunamadi.Tekrar deneyin!");
			    getch();
			    kul_ara(kisi1);
			}
		}}
	case 4://Telefon Numarasina Gore Ara
			printf("\nAradiginiz kisinin telefon numarasini giriniz : ");scanf("%s",telara);
		kullanici=fopen("kullanici.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
		while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta)!=EOF)
		{
			if(strcmp(kisi1[i].tel,telara)==0)//isimara 0 olunca giriyo..:(
			{
                 printf("%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta);
                  getch();
				kul_ara(kisi1);
			}
			else
			{
				printf("\nAradiginiz kisi bulunamadi.Tekrar deneyin!");
			    getch();
			    kul_ara(kisi1);
			}
		}}
	case 5://epostaya gore ara
				printf("\nAradiginiz kisinin e-posta adresini giriniz : ");scanf("%s",epostaara);
		kullanici=fopen("kullanici.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
		while (fscanf(kullanici,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta)!=EOF)
		{
			if(strcmp(kisi1[i].e_posta,epostaara)==0)//isimara 0 olunca giriyo..:(
			{
                 printf("%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n",kisi1[i].tc,kisi1[i].tel,kisi1[i].isim,kisi1[i].soyisim,kisi1[i].tel,kisi1[i].adres,kisi1[i].yetki_turu,kisi1[i].kullanici_adi,kisi1[i].sifre,kisi1[i].e_posta);
                  getch();
				kul_ara(kisi1);
			}
			else
			{
				printf("\nAradiginiz kisi bulunamadi.Tekrar deneyin!");
			    getch();
			    kul_ara(kisi1);
			}
		}}

	case 6:  main();

	default:printf("\nTanimsiz deger girdiniz.Tekrar deneyin!");getch();kul_ara(kisi1);
	}
}

void memur_is()
{
	char islem;
		 system("CLS");
		 printf("\t\tMemur Islemleri\n\n\t1-Memur Ekle\n\t2-Memur Sil\n\t3-Ana Menu\n\nYapacaginiz Islem (1-2-3) :");
		 islem=getch();
		 switch(islem){
		 case '1':memur_ekle(kisi2);return;
		 case '2':memur_sil(kisi2);return;
		 case '3':return;
		 default:system("CLS");printf("Tanimsiz bir deger girdiniz. Tekrar Deneyin!\n\n"); return;
		 }
}

void memur_ekle(struct memur *kisi2)
{
    memur=fopen("memur.txt","a");
 for(int i=0;i<BUFSIZ;i++){
            do{
				printf("\nIsim :");gets(kisi2[i].isim);
			}while(isalpha(*kisi2[i].isim)==0);
			do{
				printf("\nSoyisim :");gets(kisi2[i].soyisim);
			}while(isalpha(*kisi2[i].soyisim)==0);
			
			do{
				printf("\nCinsiyet :");gets(kisi2[i].cinsiyet);
			}while(isalpha(*kisi2[i].cinsiyet)==0);
			do{
				printf("\nDogum  Tarihi :");gets(kisi2[i].dogumtarihi);
			}while(isdigit(*kisi2[i].dogumtarihi)==0);
		    printf("\nSifre :");gets(kisi2[i].sifre);
			printf("\n\nKayit basariyla eklendi...");
				
			fprintf(memur,"%15s%15s%15s%15s%15s\n",kisi2[i].isim,kisi2[i].soyisim,kisi2[i].cinsiyet,kisi2[i].dogumtarihi,kisi2[i].sifre);
				
                fclose(memur);
				getch();
				return ;
    }
}
void memur_sil(struct memur *kisi2)
{
	bas:
	system("cls");
	
	char cevap;
	
	    char isim[11];
		int denetleyici=0;
		printf("Silinecek memurun adini giriniz: ");gets(isim);
	   memur=fopen("memur.txt","r+");
		int x=0;
		if (memur == NULL)
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else
		{
			system("cls");
			
			printf("\n\t\tMEMUR SILME\n\n");
			
			for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(memur,"%15s%15s%15s%15s%15s\n",kisi2[i].isim,kisi2[i].soyisim,kisi2[i].cinsiyet,kisi2[i].dogumtarihi,kisi2[i].sifre)!=EOF)
			{
				if(strcmp(kisi2[i].isim,isim)==0)
				{	
					denetleyici=1;
					//printf("girdi.");getch();
					strcpy(memursildir[x].isim," ");
					strcpy(memursildir[x].soyisim," ");
					strcpy(memursildir[x].cinsiyet," ");		
					strcpy(memursildir[x].dogumtarihi," ");	
					strcpy(memursildir[x].sifre," ");	
				}
				else 
				{	
					//printf("digerine girdi.");getch();
					strcpy(memursildir[x].isim,kisi2[i].isim);
					strcpy(memursildir[x].soyisim,kisi2[i].soyisim);
					strcpy(memursildir[x].cinsiyet,kisi2[i].cinsiyet);		
					strcpy(memursildir[x].dogumtarihi,kisi2[i].dogumtarihi);	
					strcpy(memursildir[x].sifre,kisi2[i].sifre);	
				}
				x++;
			}
			fclose(memur);
			if (denetleyici==0)
			{
				printf("Dosyada %s adli memur bulunamadi.",isim);
				getch();
				goto bas;
			}
			
			else {
				memur=fopen("memur.txt","w");
			for(int j=0 ; j<x ; j++)
			{
			fprintf(memur,"%15s%15s%15s%15s%15s\n",memursildir[j].isim,memursildir[j].soyisim,memursildir[j].cinsiyet,memursildir[j].dogumtarihi,memursildir[j].sifre);
			}
			fclose(memur);
			printf("%s adli memur basariyla silinmistir",isim);getch();return;
			}}
		}
		istek:
	printf("\n\n     Yeni bir kisi daha silmek istiyor musunuz(e/h) : "); // baþka ekleme yapýp yapmayacaðýmýz sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		return;				
	}
	else if (cevap=='e')
	{
		goto bas;
	//	kul_sil(kisi1);				
	}
	else goto istek;
}

void sig_is()
{
	     char islem;
		 system("CLS");
		 char yeni;
		 FILE *siginmaci;
		 bas:
		 printf("\t\tSiginmaci Islemleri\n\n\t1-Siginmaci Ekleme\n\t2-Siginmaci Silme\n\t3-Siginmaci Arama\n\t4-Siginmaci Listele\n\t5-Siginmaci Guncelleme\n\t6-Ana Menu\n\nYapacaginiz Islem (1-2-3-4-5-6) :");
		 islem=getch();
		 switch(islem){
		 case '1':si_ekle(kisi);return;
		 case '2': si_sil(kisi);return;
		 case '3':si_ara(kisi);return;
		 case'4':si_lis(kisi);return;
		 case '5':si_gün(kisi);return;
		 case '6':return;
		 default:system("CLS");printf("Tanimsiz bir deger girdiniz. Tekrar Deneyin!\n\n"); goto bas;
		 }
}

int si_ekle(struct siginmaci *kisi)
{
    FILE *siginmaci;
	siginmaci=fopen("siginmaci.txt","a");
	
	//fprintf(siginmaci,"%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n","Siginmaci No","Ad","Soyad","Cinsiyet","Dogum Tarihi","Dogum Yeri","Uyruk","Egitim Durumu","Meslek","Yerlestigi Adres","Gelis Tarihi","Telefon","E-Posta");
	for(int i=0;i<BUFSIZ;i++)
	{
		if(kisi[i].kayit=='0'){
			do{
				printf("\nSiginmaci Numarasi : %s",kisi[i].sinu);gets(kisi[i].sinu);
			}while(isdigit(*kisi[i].sinu)==0);
			do{
				printf("\nAd :");gets(kisi[i].ad);
			}while(isalpha(*kisi[i].ad)==0);
			do{
				printf("\nSoyad :");gets(kisi[i].soyad);
			}while(isalpha(*kisi[i].soyad)==0);
			do{
				printf("\nCinsiyet :");gets(kisi[i].cinsiyet);
			}while(isalpha(*kisi[i].cinsiyet)==0);
			do{
				printf("\nDogum Tarihi :");gets(kisi[i].do_tarihi);
			}while(isdigit(*kisi[i].do_tarihi)==0);	
			do{
				printf("\nDogum Yeri :");gets(kisi[i].do_yeri);
			}while(isalpha(*kisi[i].do_yeri)==0);
			do{
				printf("\nUyruk :"); gets(kisi[i].uyruk);
			}while(isalpha(*kisi[i].uyruk)==0);
			do{
				printf("\nEgitim Durumu :"); gets(kisi[i].egitim);
			}while(isalpha(*kisi[i].egitim)==0);
			do{
				printf("\nMeslek :"); gets(kisi[i].meslek);
			}while(isalpha(*kisi[i].meslek)==0);
			do{
				printf("\nYerlestigi Adres :"); gets(kisi[i].yer_adres);
			}while(isalpha(*kisi[i].yer_adres)==0);
			do{
				printf("\nGelis Tarihi :");gets(kisi[i].ge_tarihi);
			}while(isdigit(*kisi[i].ge_tarihi)==0);
			do{
				printf("\nTelefon :");gets(kisi[i].tel);
			}while(isdigit(*kisi[i].tel)==0);
			
			kisi[i].kayit=='1';	
			printf("\n\nKayit basariyla eklendi...");
		
               
				//for(int i=0;i<BUFSIZ;i++){
			fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
				//}
			/*for(int j=0;j<strlen(kisi[i].eposta);j++){
			printf("\nE-Posta(varsa) :");gets(kisi1[i].e_posta);	
			if(j=='@')
				fprintf(siginmaci,"%s",kisi[i].eposta);
			}*/
                fclose(siginmaci);
				getch();return kisi[i].kayit;

		
	}
	}
}
  //strcmp(isim,insan.isim)==0
 
void si_sil(struct siginmaci *kisi)
{
	bas:
	system("cls");
	
	char cevap;
	
	    char sino[11];
		int denetleyici=0;
		printf("Silinecek siginmacinin numarasini giriniz: ");gets(sino);
	   siginmaci=fopen("siginmaci.txt","r+");
		int x=0;
		if (siginmaci == NULL)
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else
		{
			system("cls");
			
			printf("\n\t\tSIGINMACI SILME\n\n");
			
			
			for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
			{
				if(strcmp(kisi[i].sinu,sino)==0)
				{	
					//printf("girdi..");getch();
					denetleyici=1;
					strcpy(siginmacisildir[x].sinu," ");	
					strcpy(siginmacisildir[x].ad," ");		
					strcpy(siginmacisildir[x].soyad," ");	
					strcpy(siginmacisildir[x].cinsiyet," ");	
					strcpy(siginmacisildir[x].do_tarihi," ");	
					strcpy(siginmacisildir[x].do_yeri," ");
					strcpy(siginmacisildir[x].uyruk," ");
					strcpy(siginmacisildir[x].egitim," ");	
					strcpy(siginmacisildir[x].meslek," ");
					strcpy(siginmacisildir[x].yer_adres," ");
					strcpy(siginmacisildir[x].ge_tarihi," ");	
					strcpy(siginmacisildir[x].tel," ");		
				}
				else 
				{	
					//printf("girmedi...");getch();
					strcpy(siginmacisildir[x].sinu,kisi[i].sinu);
					strcpy(siginmacisildir[x].ad,kisi[i].ad);		
					strcpy(siginmacisildir[x].soyad,kisi[i].soyad);	
					strcpy(siginmacisildir[x].cinsiyet,kisi[i].cinsiyet);	
					strcpy(siginmacisildir[x].do_tarihi,kisi[i].do_tarihi);	
					strcpy(siginmacisildir[x].do_yeri,kisi[i].do_yeri);
					strcpy(siginmacisildir[x].uyruk,kisi[i].uyruk);
					strcpy(siginmacisildir[x].egitim,kisi[i].egitim);	
					strcpy(siginmacisildir[x].meslek,kisi[i].meslek);
					strcpy(siginmacisildir[x].yer_adres,kisi[i].yer_adres);
					strcpy(siginmacisildir[x].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmacisildir[x].tel,kisi[i].tel);	
				}
				x++;
			}
			fclose(siginmaci);
			if (denetleyici==0)
			{
				printf("Dosyada %s adli siginmaci bulunamadi.",sino);
				getch();goto bas;
			}
			else{
			siginmaci=fopen("siginmaci.txt","w");
			for(int j=0 ; j<x ; j++)
			{
				fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmacisildir[j].sinu,siginmacisildir[j].ad,siginmacisildir[j].soyad,siginmacisildir[j].cinsiyet,siginmacisildir[j].do_tarihi,siginmacisildir[j].do_yeri,siginmacisildir[j].uyruk,siginmacisildir[j].egitim,siginmacisildir[j].meslek,siginmacisildir[j].yer_adres,siginmacisildir[j].ge_tarihi,siginmacisildir[j].tel);
			}
			fclose(siginmaci);
			printf("%s siginmacisi basariyla silinmistir",sino);getch();return;
			}}
		}
			istek:
	printf("\n\n     Yeni bir kisi daha silmek istiyor musunuz(e/h) : "); // baþka ekleme yapýp yapmayacaðýmýz sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		return;				
	}
	else if (cevap=='e')
	{
		goto bas;
		//si_sil(kisi);				
	}
	else goto istek;
}

void si_gün(struct siginmaci *kisi)
{
	   char sino[15],guncellead[15],guncellesoyad[15], guncellecinsiyet[15], guncelledogumtarihi[15], guncelledogumyeri[15], guncelleuyruk[15], guncelleegitim[15],guncellemeslek[15],guncelleadres[15],guncellegelistarihi[15],guncelletel[15];
	   int secim,denetleyici=0,k=0;
	    printf("\n\t\tSIGINMACI GUNCELLEME\n\n");
		siginmaci=fopen("siginmaci.txt","r+");
	    printf("\nGuncellenicek kisinin siginmaci numarasini giriniz:");scanf("%s",sino);
	    printf("\n\n%s Numarali Siginmaci Icin :\n\t1-Ismi Guncelle\n\t2-Soyismi Guncelle\n\t3-Cinsiyeti Guncelle\n\t4-Dogum Tarihi Guncelle\n\t5-Dogum Yeri Guncelle\n\t6-Uyruk Guncelle\n\t7-Egitim Durumu Guncelle\n\t8-Meslek Guncelle\n\t9-Yerlestigi Adresi Guncelle\n\t10-Gelis Tarihi Guncelle\n\t11-Ana Menu\n\nSeciminiz (1-2-3-4-5-6-7-8-9-10-11) :",sino);scanf("%d",&secim);
		
		switch(secim)
		{
		  case 1://isim gunceller...
			
			  for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					  //printf("girdi..");getch();
					denetleyici=1;
					printf("Yeni Adi : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].ad);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						//printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}

		  case 2://soyisim gunceller..
			     for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					 // printf("girdi..");getch();
					denetleyici=1;
					printf("Yeni Soyadi : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].soyad);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						//printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 3://cinsiyet gunceller....
			     for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					denetleyici=1;
					printf("Yeni Cinsiyeti : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 4://dogum tarihi gunceller...
			     for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					 // printf("girdi..");getch();
					denetleyici=1;
					printf("Yeni Dogum Tarihi : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						//printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 5://dogumyeri guncller....
			   for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					denetleyici=1;
					printf("Yeni Dogum Yeri : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].do_yeri);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 6://uyruk gunceller...
			   for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					  //printf("girdi..");getch();
					denetleyici=1;
					printf("Yeni Uyruk : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].uyruk);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						//printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 7://egitim durumu guncller...
			   for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					  //printf("girdi..");getch();
					denetleyici=1;
					printf("Yeni Egitim Durumu : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].ad);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						//printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 8://meslek guncller...
			   for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					  //printf("girdi..");getch();
					denetleyici=1;
					printf("Yeni Meslek : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].meslek);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						//printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 9://yerleþiði adresi gunceller...
			   for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					denetleyici=1;
					printf("Yeni Yerlestigi Adres : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].yer_adres);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						//printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 10://Gelis tarihini guncller....
			   for(int i=0;i<BUFSIZ;i++)
			{
				while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,sino)==0)
				  {
					 // printf("girdi..");getch();
					denetleyici=1;
					printf("Yeni Gelis Tarihi : ");
					_flushall();//bellegi bosaltýr...
					gets(siginmaciguncelleme[i].ge_tarihi);
					strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
					strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					printf("\nKisi guncellenmistir.\n\n");
					getch();
					system("CLS");
				  }
					else
					{
						//printf("girmedi...");getch();
					  strcpy(siginmaciguncelleme[k].sinu,kisi[i].sinu);
					  strcpy(siginmaciguncelleme[k].ad,kisi[i].ad);
				      strcpy(siginmaciguncelleme[k].soyad,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].cinsiyet,kisi[i].cinsiyet);
					  strcpy(siginmaciguncelleme[k].do_tarihi,kisi[i].do_tarihi);
					  strcpy(siginmaciguncelleme[k].do_yeri,kisi[i].do_yeri);
					  strcpy(siginmaciguncelleme[k].uyruk,kisi[i].uyruk);
					  strcpy(siginmaciguncelleme[k].egitim,kisi[i].egitim);
					  strcpy(siginmaciguncelleme[k].meslek,kisi[i].soyad);
					  strcpy(siginmaciguncelleme[k].yer_adres,kisi[i].yer_adres);
					  strcpy(siginmaciguncelleme[k].ge_tarihi,kisi[i].ge_tarihi);
					  strcpy(siginmaciguncelleme[k].tel,kisi[i].tel);
					}
					k++;
				}fclose(siginmaci);
				if(denetleyici==0)
				{
					printf("Kayitlar arasinda %s numarali biri bulunmamaktadir.",sino);
					getch();
					si_gün(kisi);
				}
				else
				{
					siginmaci=fopen("siginmaci.txt","w");
					for(int j=0;j<k;j++)
					{
						fprintf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",siginmaciguncelleme[j].sinu,siginmaciguncelleme[j].ad,siginmaciguncelleme[j].soyad,siginmaciguncelleme[j].cinsiyet,siginmaciguncelleme[j].do_tarihi,siginmaciguncelleme[j].do_yeri,siginmaciguncelleme[j].uyruk,siginmaciguncelleme[j].egitim,siginmaciguncelleme[j].meslek,siginmaciguncelleme[j].yer_adres,siginmaciguncelleme[j].ge_tarihi,siginmaciguncelleme[j].tel);
					}
					fclose(siginmaci);return;
				}}
		  case 11:return;
		  default:printf("Tanimsiz deger girdiniz.Tekrar deneyin!");getch();si_gün(kisi);

		}
}

void si_ara(struct siginmaci *kisi){
	char adi[10];
	int secim;
	system("cls");
	siginmaci=fopen("siginmaci.txt","r");
	printf("\n\tSiginmaci Arama\n\n\t1-Siginmaci Numarasina Gore Arama\n\t2-Ada Gore Arama\n\t3-Soyada Gore Arama\n\t4-Dogum Tarihine Gore Arama\n\t5-Ana Menu\n\nSeciminiz (1-2-3-4-5) :");scanf("%d",&secim);
	switch(secim)
	{
	case 1://siginmaci nosuna göre
		printf("\nAradiginiz kisinin siginmaci numarasini giriniz :");scanf("%s",adi);
	for(int i=0;i<BUFSIZ;i++)
	{
		while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].sinu,adi)==0)
				  {
			//fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
			printf("Siginmaci Numarasi : %s\n\nIsmi : %s\n\nSoyismi : %s\n\nCinsiyet : %s\n\nDogum tarihi : %s\n\nDogum Yeri : %s\n\nUyruk : %s\n\nEgitim Durumu : %s\n\nMeslek : %s\n\nYerlestigi Adres : %s\n\nGelis tarihi : %s\n\nTelefon :%s\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
			getch();
			si_ara(kisi);
		         }
					else
					{
			printf("\nAradiginiz kisi bulunamadi..");getch();si_ara(kisi);
					}
    }
	}
	case 2://Ada göre
	printf("\nAradiginiz kisinin adini giriniz :");scanf("%s",adi);
	for(int i=0;i<BUFSIZ;i++)
	{
		while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].ad,adi)==0)
				  {
			//fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
			printf("Siginmaci Numarasi : %s\n\nIsmi : %s\n\nSoyismi : %s\n\nCinsiyet : %s\n\nDogum tarihi : %s\n\nDogum Yeri : %s\n\nUyruk : %s\n\nEgitim Durumu : %s\n\nMeslek : %s\n\nYerlestigi Adres : %s\n\nGelis tarihi : %s\n\nTelefon :%s\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
			getch();
			si_ara(kisi);
		         }
					else
					{
			printf("\nAradiginiz kisi bulunamadi..");getch();si_ara(kisi);
					}
    }
	}
	case 3://soyada gore
		printf("\nAradiginiz kisinin soyadini giriniz :");scanf("%s",adi);
	for(int i=0;i<BUFSIZ;i++)
	{
		while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].soyad,adi)==0)
				  {
			//fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
			printf("Siginmaci Numarasi : %s\n\nIsmi : %s\n\nSoyismi : %s\n\nCinsiyet : %s\n\nDogum tarihi : %s\n\nDogum Yeri : %s\n\nUyruk : %s\n\nEgitim Durumu : %s\n\nMeslek : %s\n\nYerlestigi Adres : %s\n\nGelis tarihi : %s\n\nTelefon :%s\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
			getch();
			si_ara(kisi);
		         }
					else
					{
			printf("\nAradiginiz kisi bulunamadi..");getch();si_ara(kisi);
					}
    }
	}
	case 4://dogum tarihine gore
		printf("\nAradiginiz kisinin dogum tarihini giriniz :");scanf("%s",adi);
	for(int i=0;i<BUFSIZ;i++)
	{
		while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
				{
					if(strcmp(kisi[i].do_tarihi,adi)==0)
				  {
			//fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
			printf("Siginmaci Numarasi : %s\nIsmi : %s\nSoyismi : %s\nCinsiyet : %s\nDogum tarihi : %s\nDogum Yeri : %s\nUyruk : %s\nEgitim Durumu : %s\nMeslek : %s\nYerlestigi Adres : %s\nGelis tarihi : %s\nTelefon :%s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
			getch();
			si_ara(kisi);
		         }
					else
					{
			printf("\nAradiginiz kisi bulunamadi..");getch();si_ara(kisi);
					}
    }
	}

	case 5: main();

	default:printf("\nTanimsiz deger girdiniz.Tekrar deneyin!");getch();si_ara(kisi);
	
	}fclose(siginmaci);return;
}

void si_lis(struct siginmaci *kisi)
{
	system("cls");
	int secim;
	printf("\n\t\tSIGINMACI LISTELEME\n\n\t1-Ada Gore Listele\n\t2-Gelis Tarihine Gore Listele\n\t3-Dogum Tarihine Gore Listele\n\t4-Meslege Gore Listele\n\t5-Ana Menu\n\nSeciminiz (1-2-3-4-5): "); scanf("%d",&secim);
	
	switch(secim)
	{
	case 1:system("cls");printf("\n\t\tAda Gore Listeleme\n\n");
		siginmaci=fopen("siginmaci.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
			while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
			{
				if(strcmp(kisi[i].ad,kisi[i+1].ad)>0)
				{
					//printf("girdi...");getch();
					temp[i]=kisi[i];
					kisi[i]=kisi[i+1];
					kisi[i+1]=temp[i];
				
					//printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);	
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);	
		  
		         // printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);
				  // printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i+2].sinu,kisi[i+2].ad,kisi[i+2].soyad,kisi[i+2].cinsiyet,kisi[i+2].do_tarihi,kisi[i+2].do_yeri,kisi[i+2].uyruk,kisi[i+2].egitim,kisi[i+2].meslek,kisi[i+2].yer_adres,kisi[i+2].ge_tarihi,kisi[i+2].tel);
				}
				else
				{
			   printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);	
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);	
		  
				}
			}
		}
	    fclose(siginmaci);
		getch();
		return;
	case 2://Gelis Tarihine göre
		system("cls");printf("\n\t\Gelis Tarihine Gore Listeleme\n\n");
		siginmaci=fopen("siginmaci.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
			while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
			{
				if(strcmp(kisi[i].ge_tarihi,kisi[i+1].ge_tarihi)>0)
				{
					//printf("girdi...");getch();
					temp[i]=kisi[i];
					kisi[i]=kisi[i+1];
					kisi[i+1]=temp[i];
				
					//printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);	
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);	
		  
		         // printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);
				  // printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i+2].sinu,kisi[i+2].ad,kisi[i+2].soyad,kisi[i+2].cinsiyet,kisi[i+2].do_tarihi,kisi[i+2].do_yeri,kisi[i+2].uyruk,kisi[i+2].egitim,kisi[i+2].meslek,kisi[i+2].yer_adres,kisi[i+2].ge_tarihi,kisi[i+2].tel);
				}
				else
				{
			    printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);	
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);	
		  
				}
			}
		}
	    fclose(siginmaci);
		getch();
		return;
	case 3://Dogum tarihine gore
		system("cls");printf("\n\t\Dogum Tarihine Gore Listeleme\n\n");
		siginmaci=fopen("siginmaci.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
			while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
			{
				if(strcmp(kisi[i].do_tarihi,kisi[i+1].do_tarihi)>0)
				{
					//printf("girdi...");getch();
					temp[i]=kisi[i];
					kisi[i]=kisi[i+1];
					kisi[i+1]=temp[i];
				
					//printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);	
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);	
		  
		         // printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);
				  // printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i+2].sinu,kisi[i+2].ad,kisi[i+2].soyad,kisi[i+2].cinsiyet,kisi[i+2].do_tarihi,kisi[i+2].do_yeri,kisi[i+2].uyruk,kisi[i+2].egitim,kisi[i+2].meslek,kisi[i+2].yer_adres,kisi[i+2].ge_tarihi,kisi[i+2].tel);
				}
				else
				{
			    printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);	
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);	
		  
				}
			}
		}
	    fclose(siginmaci);
		getch();
		return;
	case 4://meslege göre
		system("cls");printf("\n\t\Gelis Tarihine Gore Listeleme\n\n");
		siginmaci=fopen("siginmaci.txt","r");
		for(int i=0;i<BUFSIZ;i++)
		{
			while(fscanf(siginmaci,"%10s%15s%10s%10s%15s%10s%15s%15s%10s%15s%10s%15s\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel)!=EOF)
			{
				if(strcmp(kisi[i].meslek,kisi[i+1].meslek)>0)
				{
					//printf("girdi...");getch();
					temp[i]=kisi[i];
					kisi[i]=kisi[i+1];
					kisi[i+1]=temp[i];
				
					//printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);	
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);	
		  
		         // printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);
				  // printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n",kisi[i+2].sinu,kisi[i+2].ad,kisi[i+2].soyad,kisi[i+2].cinsiyet,kisi[i+2].do_tarihi,kisi[i+2].do_yeri,kisi[i+2].uyruk,kisi[i+2].egitim,kisi[i+2].meslek,kisi[i+2].yer_adres,kisi[i+2].ge_tarihi,kisi[i+2].tel);
				}
				else
				{
			    printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i].sinu,kisi[i].ad,kisi[i].soyad,kisi[i].cinsiyet,kisi[i].do_tarihi,kisi[i].do_yeri,kisi[i].uyruk,kisi[i].egitim,kisi[i].meslek,kisi[i].yer_adres,kisi[i].ge_tarihi,kisi[i].tel);	
				printf("Siginmaci Numarasi: %s\nAdi: %s\nSoyadi:%s\nCinsiyet: %s\nDogum Tarihi: %s\nDogum Yeri: %s\nUyruk: %s\nEgitim: %s\nMeslek: %s\nYerlestigi Adres: %s\nGelis Tarihi: %s\nTelefon :%s\n\n\n",kisi[i+1].sinu,kisi[i+1].ad,kisi[i+1].soyad,kisi[i+1].cinsiyet,kisi[i+1].do_tarihi,kisi[i+1].do_yeri,kisi[i+1].uyruk,kisi[i+1].egitim,kisi[i+1].meslek,kisi[i+1].yer_adres,kisi[i+1].ge_tarihi,kisi[i+1].tel);	
		  
				}
			}
		}
	    fclose(siginmaci);
		getch();
		return;
	case 5://ana menu
		return;
	default:printf("Tanimsiz deger girdiniz.Tekrar deneyin!");getch();si_lis(kisi);

	}
	

}


void ku_go(){

}

void sifre_de(struct kullanici *kisi1)
{
	

}
int sorgulama(struct kullanici *kisi1)
{
	int a=0;
	for (int i = 0; i < 11; i++) //Girilen numaranýn 11 haneli olduðunu ve harf girilip girilmediðini kontrol eden kýsým
	{
		if (isdigit(kisi1[0].tc[i])==0)
		{
			a=1;
		}
	}
	return a;
}

int sorgulamatel(struct kullanici *kisi1)
{
	int a=0;
	for (int i = 0; i < 11; i++) //Girilen numaranýn 11 haneli olduðunu ve harf girilip girilmediðini kontrol eden kýsým
	{
		if(isdigit(kisi1[0].tel[i])==0)
		{
			a=1;
		}
	}
	return a;
}
