#include<stdio.h>
int main()
{
    int arr[10]={1,3,5,7,9,11};
    int n=6;
    int ITEM=9;
    int BEG=1, END=6, MID;
    int LOC=0;
    while(BEG<=END)
    {
        MID= (BEG+END)/2;
        if (ITEM<arr[MID])
        {
            END=MID-1;
        }
        else
        {
            BEG=MID+1;
        }
        MID=(BEG+END)/2;
    }
    if (ITEM=arr[MID])
    {
        LOC=MID;
        printf("data is found at index %d ", LOC);
    }
    else
    {
        LOC=0;
        printf("Data not found");
    }
    return 0;
}
