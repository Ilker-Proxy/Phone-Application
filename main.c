#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char lastName[20];
    char phone[11];
}Record;

void menu();
int phoneAdd();
int phoneList();
int phoneSearch(char*);

int main(void) {
    int choice=0;
    char searchName[20];
    int searchResult=0;
    do {
        menu();
        printf("SECIMINIZI YAPINIZ: ");
        scanf("%d",&choice);
    switch (choice) {
        case 1:if (phoneAdd() == 0)
                    printf("TELEFON NUMARASI BASARILI BIR SEKILDE EKLENDI");
               else
                   printf("TELEFON NUMARASI MAALESEF EKLENEMEDI");
            break;
        case 2:if (phoneList() == 0)
                printf("TELEFON NUMARALARI BASARILI BIR SEKILDE LISTELENDI\n");
            else
                printf("TELEFON NUMARALARI LISTELENIRKEN HATA OLUSTU.\n");
            bre ak;
        case 3: printf("ARANACAK ISMI GIRINIZ :");
                scanf("%s",&searchName);
                 searchResult = phoneSearch(searchName);
                if (searchResult == 0)
                    printf("ARANILAN KAYIT BULUNAMADI");
                else
                    printf("TOPLAM %d KAYIT BULUNDU.",searchResult);
            break;
        case 4:printf("CIKIS YAPTINIZ! HOSCA KALIN");
        return 0;
        break;
        default: printf("LUTFEN 1-4 ARASINDA BİR SECIM YAPINIZ.\n");
    }
    }while (choice != 4);
    return 0;
}
void menu() {
    printf("---------------------------\n");
    printf("*                         *\n");
    printf("*     TELEFON REHBERI     *\n");
    printf("*     1.TELEFON EKLE      *\n");
    printf("*  2.TELEFONLARI LISTELE  *\n");
    printf("*       3.ARAMA YAP       *\n");
    printf("*       4.CIKIS YAP       *\n");
    printf("*                         *\n");
    printf("---------------------------\n");
}
int phoneAdd() {
    Record newRecord;
    FILE *fptr;
    fptr=fopen("data.txt","a");
    if (fptr ==NULL)
        return -1;
    printf("ISIM GIRINIZ (MAX 20 KARAKTER): ");
    scanf("%s",newRecord.name);
    printf("SOYISIM GIRINIZ  (MAX 20 KARAKTER): ");
    scanf("%s",newRecord.lastName);
    printf("TELEFON NUMARASINI GIRIN :");
    scanf("%s",newRecord.phone);
    fprintf(fptr,"\n%s %s %s",newRecord.name,newRecord.lastName,newRecord.phone);
    fclose(fptr);
    return 0;
}
int phoneList() {
    Record currentRecord;
    FILE *fptr;
    int i;
    fptr =fopen("data.txt","r");
    if (fptr ==  NULL)
        return -1;
    printf("\n\n ISIM\t\t\tSOYISIM\t\t\tTELEFON\n");
    printf("----\t\t\t-------\t\t\t-------\n\n");
    while (!feof(fptr)) {
        fscanf(fptr,"%s%s%s",currentRecord.name,currentRecord.lastName,currentRecord.phone);
        printf("%s\t\t\t%s\t\t\t%s\n",currentRecord.name,currentRecord.lastName,currentRecord.phone);
    }
    fclose(fptr);
    return 0;
}
phoneSearch(char *ptrSearch) {
    Record currentRecord;
    FILE *fptr;
    int i;
    fptr =fopen("data.txt","r");
    if (fptr ==  NULL)
        return -1;
    printf("\n\n ISIM\t\t\tSOYISIM\t\t\tTELEFON\n");
    printf(" ----\t\t\t-------\t\t\t-------\n\n");
    while (!feof(fptr)) {
        fscanf(fptr,"%s%s%s",currentRecord.name,currentRecord.lastName,currentRecord.phone);
        if (strcmp(ptrSearch,currentRecord.name) == 0) {
            printf("%s\t\t\t%s\t\t\t%s\n",currentRecord.name,currentRecord.lastName,currentRecord.phone);
            i++;
        }
    }
    fclose(fptr);
    return  i;
}