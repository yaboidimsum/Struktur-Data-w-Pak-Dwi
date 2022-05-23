/* Hash Table: Separate Chaining
Dimas Prihady Setyawan 5025211184
*/

#include <stdio.h>
#include <stdlib.h>
#define hash_size 10

typedef struct HashNode{
    int key;
    struct HashNode* next, *prev;
}*HashTable;

typedef struct {
    HashTable *table;
    unsigned capacity,size;
}ArrayHash;

void init(ArrayHash* Hash_Table){
    Hash_Table->table = (HashTable*)malloc(hash_size*sizeof(HashTable));
    Hash_Table->capacity = hash_size;
    Hash_Table->size = 0u;
    for(unsigned i=0; i<Hash_Table->capacity; i++){
        Hash_Table->table[i] = NULL;
    }
}

HashTable Create_Node(int num){
    HashTable new_Node = (HashTable)malloc(sizeof(HashTable));
    new_Node->key = num;
    new_Node->next = NULL;
    new_Node->prev = NULL;
    return new_Node;
}

HashTable __chain_insert(HashTable root,int num){
    if(root==NULL){
        printf("Inserted\n");
        return Create_Node(num);
    }else if(root->key < num){
        printf("Turn\n");
        root->next = __chain_insert(root->next,num);
    }else if(root->key > num){
        printf("Move\n");
        root->prev = __chain_insert(root->prev,num);
    }
    return root;
}

void Separate_Chain_Insert(ArrayHash* Hash_Table, int num){
    int pos = num%Hash_Table->capacity;
    printf("Masuk ke index %d\n", pos);
    Hash_Table->table[pos] = __chain_insert(Hash_Table->table[pos],num);
    Hash_Table->size++;
}

HashTable __find_table(HashTable root, int num){
    while(root){
        if(root->key==num){
            return root;
        }
        else if(root->key < num){
            root = root->next;
        }else if(root->key > num){
            root = root->prev;
        }
    }return root;
}

void Separate_Chain_Search(ArrayHash* Hash_Table, int num){
    int pos = (num%Hash_Table->capacity);
    printf("pos: %d\n", pos);
    HashTable temp = __find_table(Hash_Table->table[pos],num);
    if(temp == NULL){
        printf("[INFO]Data tidak ada\n");
    }else if(temp->key==num){
        printf("Data %d berada di index %d\n", temp->key ,pos);
    }else{
        printf("[INFO]Data tidak ada\n");
    }
}

HashTable findMinNode(HashTable node) {
    HashTable currNode = node;
    while (currNode && currNode->prev != NULL)
        currNode = currNode->prev;

    return currNode;
}

HashTable Htbale_remove(HashTable root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key)
        root->next = Htbale_remove(root->next, value);
    else if (value < root->key)
        root->prev = Htbale_remove(root->prev, value);
    else {

        if (root->prev == NULL) {
            HashTable rightChild = root->next;
            free(root);
            return rightChild;
        }
        else if (root->next == NULL) {
            HashTable leftChild = root->prev;
            free(root);
            return leftChild;
        }

        HashTable temp = findMinNode(root->next);
        root->key     = temp->key;
        root->next   = Htbale_remove(root->next, temp->key);
    }
    return root;
}

void Separate_Chain_Delete(ArrayHash* Hash_Table, int num){
    int pos = (num%Hash_Table->capacity);
    printf("pos: %d\n", pos);
    HashTable temp = __find_table(Hash_Table->table[pos],num);
    if(temp == NULL){
        printf("[INFO]Data tidak ada\n");
    }else if(temp->key==num){
        Hash_Table->table[pos] = Htbale_remove(Hash_Table->table[pos], num);
        printf("[BERHASIL] Terhapus\n");
    }else{
        printf("[INFO]Data tidak ada\n");
    }

}

int main(){

    ArrayHash HashTable;
    init(&HashTable);
    int num;
    int option;
    while(1){

     printf("\n\t\t\t MENU\n\n 1. Insert data\n 2. Search data \n 3. Delete data \n 4. EXIT \n Option : ");
     scanf("%d",&option);

     switch(option){
         case 1:
         printf("Masukan angka yang ingin dimasukan: ");
         scanf("%d", &num);
         Separate_Chain_Insert(&HashTable,num);
         break;

         case 2:
         printf("Masukan angka yang ingin dicari: ");
         scanf("%d", &num);
         Separate_Chain_Search(&HashTable,num);
         break;

         case 3:
         printf("Masukan angka yang ingin dihapus: ");
         scanf("%d", &num);
         Separate_Chain_Delete(&HashTable,num);
         break;

         case 4:
           exit(0);
     }
   }
   return 0;
 }
