#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student{
	char fullName[50];
	int age;
	char phoneNumbers[50];
	char email[50];
}; 

void suaThongTin(struct Student *sinhVien, int soLuong, int viTri) {
    if (viTri >= 0 && viTri < soLuong) {
        nhapThongTin(&sinhVien[viTri]);
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

void xoaSinhVien(struct Student *sinhVien, int *soLuong, int viTri) {
    if (viTri >= 0 && viTri < *soLuong) {
        for (int i = viTri; i < *soLuong - 1; i++) {
            sinhVien[i] = sinhVien[i + 1];
        }
        (*soLuong)--;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

void inDanhSach(const struct Student *sinhVien, int soLuong) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < soLuong; i++) {
        inThongTin(&sinhVien[i]);
    }
}

int main(){

    struct Student sinhVien[100];  
    
    
    int soLuong = 0, viTri;

    int choice;

    do {
        
        printf("\nMenu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua thong tin sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. In danh sach sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap sinh vien can them: ");
               	printf("Nhap ho va ten sinh vien: ");
               	scanf("%s",sinhVien.fullName);
	            fflush(stdin);
	            printf("Nhap tuoi cua sinh vien: ");
				scanf("%d",&sinhVien.age);
                printf("Nhap so dien thoai cua sinh vien: ");
             	scanf("%s",sinhVien.phoneNumbers);
            	printf("Nhap dia chi email cua sinh vien: ");
            	scanf("%s",sinhVien.emai);
     
                break;
            case 2:
                printf("Nhap vi tri can sua: ");
                scanf("%d", &index);
                suaThongTin(SinhVien, soLuong, viTri);
                break;
            case 3:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &viTri);
                xoaSinhVien(dsSinhVien, &soLuong, viTri);
                break;
            case 4:
                inDanhSach(dsSinhVien, soLuong);
                break;
            case 0:
                exit(0);
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (1==1);

    return 0;
}
}
