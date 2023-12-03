#include<stdio.h>
#include<string.h>


	struct Student{
		char fullName[50];
		int age;
		char phoneNumbers[50];
		char email[50];
	};
	
int main(){
	struct Student sinhVien;
	strcpy(sinhVien.fullName,"Dinh Ba Cuong");
	sinhVien.age=18;
	strcpy(sinhVien.phoneNumbers,"01234567");
	strcpy(sinhVien.email,"cuong2005@gmail.com");
	printf("Thong tin cua sinh vien la:\n");
	printf("Ho va ten cua sinh vien la: %s\n",sinhVien.fullName);
	printf("Tuoi cua sinh vien la: %d\n",sinhVien.age);
	printf("So dien thoai cua sinh vien la: %s\n",sinhVien.phoneNumbers);
	printf("Email cua sinh vien la: %s\n",sinhVien.email);
	return 0;
}
