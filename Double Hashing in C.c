/* Hash Table: Double Hashing
Dimas Prihady Setyawan 5025211184
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>

struct data
{
	int key;
	int value;
};

struct hashtable_item
{
    int flag;

    struct data *item;
};

struct hashtable_item *array;
int max = 7;
int size = 0;
int prime = 3;

int hashcode_1(int key)
{
    return(key%max);
}

int hashcode_2(int key)
{
    return(prime-(key%prime));
}

void insert_element(int key, int value)
{
	int hash_1 = hashcode_1(key);
	int hash_2 = hashcode_2(key);

	int index = hash_1;

	/* create new data to insert */
	struct data *new_item = (struct data*) malloc(sizeof(struct data));
	new_item->key = key;
	new_item->value = value;

	if (size == max)
        {
		printf("\n [PENUH] Hash table penuh, tidak bisa memasukan lagi \n");
		return;
	}

	/* probing through other array elements */
	while (array[index].flag == 1) {
		if (array[index].item->key == key)
                {
			printf("\n [INFO] Key sudah ada, Value diperbarui \n");
			array[index].item->value = value;
			return;
		}
		index = (index + hash_2) % max;
		if (index == hash_1)
                {
			printf("\n [GAGAL] Penambahan gagal \n");
			return;
		}
		printf("\n Probing \n");

	}

	array[index].item = new_item;
	array[index].flag = 1;
	size++;
	printf("\n[BERHASIL] Key (%d) berhasil dimasukan \n", key);

}

void remove_element(int key)
{
    int hash_1 = hashcode_1(key);
	int hash_2 = hashcode_2(key);
	int index = hash_1;

	if (size == 0)
    {
        printf("[INFO] Hash table kosong");
        return;
    }
    while (array[index].flag != 0)
    {
        if (array[index].flag == 1 && array[index].item ->key ==key)
        {
            array[index].item = NULL;
            array[index].flag = 2;
            size--;

            printf("\n [INFO] Key (%d) telah terhapus \n", key);
			return;
        }
        index = (index + hash_2) % max;
		if (index == hash_1)
            {
                break;
            }
    }
    printf("\n [INFO] Key (%d) tidak ada \n", key);

}

int size_of_hashtable()
{
	return size;
}

void display()
{
    int i;
    for (i =0; i< max;i++)
    {
        if (array[i].flag != 1)
        {
            printf("\n [INFO] Array[%d] tidak memiliki elemen \n", i);
        }
        else
        {
            printf("\n Array[%d] memiliki element \n Key (%d) dan Value (%d) \n", i, array[i].item->key, array[i].item->value);
        }
    }
}

void init_array()
{
	int i;
	for(i = 0; i < max; i++)
        {
		array[i].item = NULL;
		array[i].flag = 0;
	}
	prime = get_prime();
}

int get_prime()
{
	int i,j;
	for (i = max - 1; i >= 1; i--)
        {
		int flag = 0;
		for (j = 2; j <= (int)sqrt(i); j++)
                {
			if (i % j == 0)
                        {
				flag++;
			}
		}
		if (flag == 0)
                {
			return i;
		}
	}
	return 3;

}

void main()
{
	int choice, key, value, n, c;
	system("cls");

	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
	init_array();

	do {
		printf("Implementasi Hash Table menggunakan Double Hashing.\n\n");
		printf("MENU    : \n1.Masukan item ke Hash Table"
                              "\n2.Menghapus item dari Hash Table"
                              "\n3.Cek ukuran dari Hash Table"
                              "\n4.Tampilkan Hash Table"
		       "\n\n Masukan pilihan anda-:");

		scanf("%d", &choice);

		switch(choice)
                {

		case 1:

		      printf("Memasukan elemen ke Hash Table\n");
		      printf("Masukan Key dan Value-:\t");
		      scanf("%d %d", &key, &value);
		      insert_element(key, value);

		      break;

   		case 2:

		      printf("Menghapus dari Hash Table \n Masukan Key untuk dihapus: ");
		      scanf("%d", &key);
		      remove_element(key);

		      break;

		case 3:

		      n = size_of_hashtable();
		      printf("Ukuran dari Hashtable adalah: %d\n", n);

		      break;

		case 4:

		      display();

		      break;

		default:

		       printf("Pilihan salah/tidak ada\n");

		}

		printf("\n Apakah ingin melanjutkan?:(tekan 1 jika iya)\t");
		scanf("%d", &c);

	}while(c == 1);

	getch();

}

