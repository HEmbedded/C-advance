#include <stdio.h>

void nhapmang (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        do
        {
            printf("Gia tri cua arr[%d] = ",i);
            scanf("%d",&arr[i]);
        } while (arr[i]<0 || arr[i]>9);      
    }
    
}

void xuatmang(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d \n",i,arr[i]);
    }
}

int tongchan(int arr[],int size)
{
    int sizechan=0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sizechan++;
        }          
    }
    return sizechan;
}

int tongle(int arr[],int size)
{
    int sizele=0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            sizele++;
        }      
    }
    return sizele;
}


int main(int argc, char const *argv[])
{
    int size;
    printf("Nhap kich thuoc cua mang = ");
    scanf("%d",&size);
    int arr[size];
    nhapmang(arr,size);
    //xuatmang(arr,size);
    int sizechan = tongchan(arr,size);
    int sizele   = tongle(arr,size);
    //printf("%d %d ",sizechan,sizele);
    int arrchan[sizechan], arrle[sizele];
    int chan=0 ,le = 0;
    for (int i = 0; i < size; i++)
    {
        if ((arr[i]%2) == 0)
        {
            arrchan[chan] = arr[i];
            chan++;
        }else
        {
            arrle[le] = arr[i];
            le++;
        }            
    }

    if (le ==  0)
    {
        printf("Khong co so le trong mang\n");
    }else
    {
        printf("Phan tu cua mang le \n");
        xuatmang(arrle,sizele);
    }

    if (chan ==  0)
    {
        printf("Khong co so chan trong mang\n");
    }else
    {
        printf("Phan tu cua mang chan \n");
        xuatmang(arrchan,sizechan);
    }
    
    return 0;
}
