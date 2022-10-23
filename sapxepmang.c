#include <stdio.h>
#include <stdlib.h>

struct typeArr
{
    int *arr;
    int size;
};

struct typeArr *NhapThongTin()
{
    static struct typeArr arr;
    
    int *ptr;
    int size;

    printf("Nhap kich thuoc cua mang: ");
    scanf("%d",&size);

    ptr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Gia tri mang arr[%d]: ",i);
        scanf("%d",&ptr[i]);
    }
    arr.arr=ptr;
    arr.size=size;
    
    return &arr;
}



struct typeArr bedenlon(struct typeArr *Arr)
{
    int temp;
    for (int i = 0; i < (Arr->size)-1; i++)
    {
        for (int j = i + 1; j < Arr->size; j++)
        {
            if(Arr->arr[i] > Arr->arr[j])
            {
                temp = Arr->arr[j];
                Arr->arr[j] =  Arr->arr[i];
                Arr->arr[i] = temp;
            }
        }      
    }

    printf("Mang tu be den lon\n");
    for (int k=0; k < Arr->size; k++)
    {
        printf("Arr[%d]: %d\n",k,Arr->arr[k]);
    }        
}

struct typeArr londenbe(struct typeArr *Arr)
{
    int temp;
    for (int i = 0; i < (Arr->size)-1; i++)
    {
        for (int j = i + 1; j < Arr->size; j++)
        {
            if(Arr->arr[i] < Arr->arr[j])
            {
                temp = Arr->arr[j];
                Arr->arr[j] =  Arr->arr[i];
                Arr->arr[i] = temp;
            }
        }      
    }

    printf("Mang tu lon den be\n");
    for (int k=0; k < Arr->size; k++)
    {
        printf("Arr[%d]: %d\n",k,Arr->arr[k]);
    }        
}

void MAX(struct typeArr *Arr)
{
    int max = Arr->arr[0];
    for (int i = 0; i < Arr->size; i++)
    {
        if (max < Arr->arr[i+1])
        {
            max = Arr->arr[i+1];
        }       
    }
    printf("Gia tri lon nhat cua mang la: %d\n",max);    
}

void nhapyeucau (struct typeArr *Arr)
{
    int yc;
    printf("1: Sap xep mang tu be den lon\n");
    printf("2: Sap xep mang tu lon den be\n");
    printf("3: Tim so lon nhat trong mang\n");
    printf("4: Thoat chuong trinh\n");
    do
    {
        printf("Nhap vao yeu cau cua ban: ");
        scanf("%d",&yc);
    } while (yc > 4 || yc <=0);
    
    switch (yc)
    {
    case 1:
        bedenlon(Arr);
        break;
    case 2:
        londenbe(Arr);
        break;
    case 3:
        MAX(Arr);
        break;   
    case 4:
        printf("Da thoat chuong trinh");
        break;
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    struct typeArr *mang;

    mang = NhapThongTin();

    //Kiểm tra mảng đã được nhập hay chưa ?
    printf("Gia tri cua mang da nhap\n");
    for (int i = 0; i < mang->size; i++)
    {
        printf("Arr[%d]: %d\n",i,mang->arr[i]);
    }
    
    nhapyeucau(mang);

    return 0;
}
