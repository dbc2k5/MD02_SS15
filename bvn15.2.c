#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

struct Student{
	char fullName[50];
	int age;
	char phoneNumbers[50];
	char emai[50];
};

int main(){
	struct Student sinhVien;
	printf("Nhap ho va ten sinh vien: ");
	scanf("%s",sinhVien.fullName);
	fflush(stdin);
	printf("Nhap tuoi cua sinh vien: ");
	scanf("%d",&sinhVien.age);
	printf("Nhap so dien thoai cua sinh vien: ");
	scanf("%s",sinhVien.phoneNumbers);
	printf("Nhap dia chi email cua sinh vien: ");
	scanf("%s",sinhVien.emai);
	
	printf("Thong tin sinh vien la: \n");
	printf("Ho va ten sinh vien la: %s\n",sinhVien.fullName);
	printf("Tuoi cua sinh vien la: %d\n",&sinhVien.age);
	printf("So dien thoai cua sinh vien la: %s\n",sinhVien.phoneNumbers);
	printf("Dia chi email cua sinh vien la: %s\n",sinhVien.emai);
	return 0;
}
