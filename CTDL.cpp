#include <stdio.h>
#include <conio.h>
#include <string.h>
const int Nmax=100;
typedef char infor1[15];
typedef float infor2;
typedef int infor3;
struct element{
	infor1 ht;
	infor2 cc;
	infor3 cntc;
};
typedef element DS [Nmax];
DS A;
int n,t,cv;
infor1 x;
infor2 y;
infor3 z;
void DisPlay(DS A,int n){
	int i;
	for (i=1;i<=n;i++){
		printf ("\n %15s %7.2f %7d",A[i].ht,A[i].cc,A[i].cntc);
	}
}
void InsertElement (DS A,int &n,int t,infor1 x,infor2 y,infor3 z){
	int i;
	if ((n<Nmax) && (t>=1) && (t<=n+1)){
		for (i=n;i>=t;i--){
			A[i+1]=A[i];
		}
		strcpy (A[t].ht,x); A[t].cc=y; A[t].cntc=z;
		n++;		
	}
}
void GetList (DS &A,int &n){
	n=0;
	do{
		printf ("\n Nhap ho ten:");
		fflush (stdin);
		gets (x);
		if (strlen (x)>0){
			printf ("\n Nhap chieu cao:");
			scanf ("%f",&y);
			z=int (y*100-105);
			InsertElement (A,n,n+1,x,y,z);
		}
	}
	while (strlen (x)>0);	
}
int Search (DS A,int n,infor1 x){
	int i=1;
	while ((i<=n)&&(strcmp (A[i].ht,x)))
		i++;
	if (i<=n)	return i;
	else	return -1;	
}
void DeleteElement (DS A,int &n,int t){
	int i;
	if ((t>=1)&& (t<=n)){
		for (i=t;i<=n;i++){
			A[i]=A[i+1];
		}
		n--;
	}
}
main(){
	n=0;
	do{
		printf ("\n 1.Nhap danh sach");
		printf ("\n 2.Liet ke danh sach");
		printf ("\n 3.Them 1 phan tu vao danh sach");
		printf ("\n 4.Tim theo ten");
		printf ("\n 5.Xoa 1 phan tu theo vi tri");
		printf ("\n 6.Xoa 1 phan tu theo ten");
		printf ("\n 0.Ket thuc");
		printf ("\n Nhap STT cong viec muon thuc hien:");
		scanf ("%d",&cv);
		switch (cv){
			case 1: GetList (A,n);
				break;
			case 2: DisPlay (A,n);
				break;
			case 3: printf ("\n Nhap ho ten can them:"); fflush (stdin); gets (x);
					printf ("\n Nhap chieu cao can them:"); scanf ("%f",&y);
					z=y*100-105;
					printf ("\n Nhap vi tri can them vao:"); scanf ("%d",&t);
					InsertElement (A,n,t,x,y,z);
					break;
			case 4:	printf ("\n Nhap ho va ten nguoi tim:"); fflush (stdin);
					gets (x);
					t=Search (A,n,x);
					if (t!=-1){
						printf ("\n %7.2f %7d",A[t].cc,A[t].cntc);	
					}
					else	printf ("\n Tim khong co");
					break;
			case 5:	printf ("\n Nhap ho va ten nguoi can xoa:"); scanf ("%d",&t);
					DeleteElement (A,n,t);
					break;
			case 6:	printf ("\nNhap ho va ten nguoi can xoa:"); fflush (stdin); gets (x);
					t=Search(A,n,x);
					if (t!=-1){
						DeleteElement (A,n,t);
					}						
					else 	printf ("\n Tim khong co");
					break;					
		}
	}
	while (cv!=0);	
}
