/*
Nama : Dimas Prihady Setyawan
NRP  : 5025211184
Kelas: Struktur Data C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tambah_data();
void cari_data();
void tampil_data();
void hapus_data();
void semua_data();
int flag=0;

struct data
{
    char NIK[20];
    char Nama[50];
    char TTL[50];
    char Kelamin[20];
    char Golongan_Darah[20];
    char Alamat[50];
    char RT_RW[10];
    char Desa[50];
    char Kecamatan[50];
    char Kota[50];
    char Agama[20];
    char Status_Kawin[20];
    char Pekerjaan[20];
    char Kewarganegaraan[20];
};

struct data KTP[50];

int main ()
{
    int nomor = 0;
     printf("---------------------------------");
     printf("\n1.Tambah Data KTP");
     printf("\n2.Cari Data KTP");
     printf("\n3.Tampil Data KTP");
     printf("\n4.Hapus Data KTP");
     printf("\n5.Selesai\n");

     for (int i = 1;i > 0; i++)
     {
        printf("Masukan pilihan anda: ");
        scanf("%d", &nomor);

        if (nomor == 1)
        {
         tambah_data();
        }
        else if(nomor == 2)
        {
        cari_data();
        }
        else if(nomor == 3)
        {
        tampil_data();
        }
        else if (nomor == 4)
        {
        hapus_data();
        }
        else
        {
            printf("Pilihan tidak ada!");
        }
     }
}

void tambah_data()
{
//Fungsi menambahkan Data KTP
    printf("\n------------Input Data------------\n\n");
    getchar();

    printf("NIK \t\t\t= ");
    gets(KTP[flag].NIK);

    printf("Nama \t\t\t= ");
    gets(KTP[flag].Nama);

    printf("Tempat/Tgl Lahir \t= ");
    gets(KTP[flag].TTL);

    printf("Jenis Kelamin \t\t= ");
    gets(KTP[flag].Kelamin);

    printf("Golongan Darah \t\t= ");
    gets(KTP[flag].Golongan_Darah);

    printf("Alamat \t\t\t= ");
    gets(KTP[flag].Alamat);

    printf("RT/RW \t\t\t= ");
    gets(KTP[flag].RT_RW);

    printf("Kelurahan/Desa \t\t= ");
    gets(KTP[flag].Desa);

    printf("Kecamatan \t\t= ");
    gets(KTP[flag].Kecamatan);

    printf("Kota \t\t\t= ");
    gets(KTP[flag].Kota);

    printf("Agama \t\t\t= ");
    gets(KTP[flag].Agama);

    printf("Status Perkawinan \t= ");
    gets(KTP[flag].Status_Kawin);

    printf("Pekerjaan \t\t= ");
    gets(KTP[flag].Pekerjaan);

    printf("Kewarganegaraan \t= ");
    gets(KTP[flag].Kewarganegaraan);

    flag++;

    printf("\n------------------------------\n\n");
}

void semua_data(int i)
{
    printf("NIK \t\t\t = %s\n", KTP[i].NIK);
    printf("Nama \t\t\t = %s\n", KTP[i].Nama);
    printf("Tempat/Tgl Lahir \t = %s\n", KTP[i].TTL);
    printf("Jenis Kelamin \t\t = %s\n", KTP[i].Kelamin);
    printf("Golongan Darah \t\t = %s\n", KTP[i].Golongan_Darah);
    printf("Alamat \t\t\t = %s\n", KTP[i].Alamat);
    printf("RT/RW \t\t\t = %s\n", KTP[i].RT_RW);
    printf("Kelurahan/Desa \t\t = %s\n", KTP[i].Desa);
    printf("Kecamatan \t\t = %s\n", KTP[i].Kecamatan);
    printf("Agama \t\t\t = %s\n", KTP[i].Agama);
    printf("Status Perkawinan \t = %s\n", KTP[i].Status_Kawin);
    printf("Pekerjaan \t\t = %s\n", KTP[i].Pekerjaan);
    printf("Kewarganegaraan \t = %s\n", KTP[i].Kewarganegaraan);
}

void cari_data()
{
    char cari_NIK[100];
    printf("\n----------Pencarian Data----------\n\n"); getchar();

    printf("Masukan nomor NIK: "); gets(cari_NIK);

    for (int i=0 ; i<=flag ; i++)
    {
        if (strcmp(cari_NIK, KTP[i].NIK)==0){
            printf("\nData yang dimasukan:  %d\n\n", i+1);
            semua_data(i);}
            else {
            printf("Data tidak tersedia\n");
        }
    }
    printf("\n----------------------------------\n\n");
}

void tampil_data()
{
    printf("\n----------- Data Tersedia -----------\n\n");

    for (int i=0 ; i<flag ; i++){
        printf("\n Nomor Data KTP %d\n\n", i+1);
        semua_data(i);}

    if(flag<0){
        printf("\n Data Tidak Tersedia\n");}
    printf("\n----------------------------------\n\n");
}

void hapus_data()
{
char hapus_NIK[50];
char check[10];

    printf("\n----------- Data Pembuangan ----------- n\n");
    getchar();

    printf("Enter NIK : ");
    gets(hapus_NIK);

    for (int i=0 ; i<=flag ; i++)
    {
        if (strcmp(hapus_NIK, KTP[i].NIK)==0){
            printf("\n");
            semua_data(i);
            printf("\n Yakin akan dihapus? (Y/N)");
            scanf("%d", &check);

            if (check== 'Y'){
                for (int j=0 ; j<=flag+1 ; j++){
                    KTP[j]=KTP[j+1];}
                printf("Terhapus penuh\n");
                flag--;
                } else if (check=='N'){
                printf("Tidak terhapus penuh\n");
            }
        } else{
            printf("Data tidak tersedia\n");
        }
    }
}


















