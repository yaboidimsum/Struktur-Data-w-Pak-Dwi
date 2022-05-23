#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    char*x;
    char*y;
    scanf("%[^\n]", string);

    x =&string[0];
    y =&string [strlen(string)-1];

    while(x<=y)
    {
        if(*x==*y){
            --y;
            x++;}

        else {break;}
    }

    if(x>y)
    {
        printf("String merupakan Palindrom");
    }
    else
    {
        printf("String bukan Palindrom ");
    }


    return 0;
}



