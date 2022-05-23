#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void main ()
{
//    clrscr();
    int data [9] =  {3,9,11,12,15,17,23,31,35};
    int low, high;
    int flag = 0, d =36;
    float pos1;
    int pos, n=9;
    low = 0;
    high=n-1;
    do{
        pos1 = (float) (d-data[low])/(data[high]-data[low]) * (high-low)+low;
        pos = floor(pos1);
        if (data [pos]==d)
        {
            flag = 1;
            break;
        }
        if (data[pos] > d) high = pos-1;
        else
            if (data[pos] < d) low = pos+1;
    }while (d >= data [low] && d <= data[high]);
    if (flag == 0) printf("Data tidak ada\n"); else printf("Data ada\n");
}
