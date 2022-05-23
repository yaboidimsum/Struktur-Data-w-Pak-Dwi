/*Hash Tabel: Linear Probing
Dimas Prihady Setyawan NRP: 5025211184
*/
#include <stdio.h>
#include <stdlib.h>
#define size 10

int hashtable[size]={NULL};

void insert_data()
{
    int value, key, index,i;

    printf("Insert number into Hash Table : \n");
    scanf("%d",&value);

   key = value % size;

    for(i=0; i<size; i++){

        index = (key+i) % size;
        if(hashtable[index] == NULL){

        hashtable[index] = value;
        break;
        }

    }
    if(i == size){
        printf("Number can't be insert");
    }

}

void search_data(){

    int value, key, index,i;

    printf("[SEARCH]Insert the number : \n");
    scanf("%d",&value);

    key = value % size;

    for(i=0; i<size; i++){
        index = (key+i) % size;
        if(hashtable[index] == value){

            printf("[FOUND] The number is in index -",index);
            break;
    }
    }
    if(i == size){
        printf("[MISSING] The number doesn't exist\n");
    }
}

void display_data(){

    printf("Numbers that are in the table: \n");
    for(int i=0; i< size; i++)

        printf("\nin Index - %d \t the number is  %d", i, hashtable[i]);

}

int main(){

    int option;
    while(1){

     printf("\n\t\t\t MENU\n\n 1. Insert data\n 2. Display data \n 3. Search data \n 4. EXIT \n Option : ");
     scanf("%d",&option);

     switch(option){
         case 1:
         insert_data();
        break;

         case 2:
         display_data();
         break;

         case 3:
         search_data();
         break;

         case 4:
           exit(0);
     }
   }
   return 0;
 }
