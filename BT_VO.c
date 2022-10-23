// Cho 1 cái thùng, nó chứa ngẫu nhiên số vớ đỏ vàng xanh
// Viết chương trình đếm có bao nhiêu đôi vớ mỗi loại
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    VO_DO,
    VO_VANG,
    VO_XANH
}VO;

typedef struct
{
    VO *ptr;
    int size;
}typeBox;

void nhapThongTin(typeBox *mang)
{
    char name[8];
    printf("Nhap chieu dai cua mang: ");
    scanf("%d",&(mang->size));
    
    mang->ptr = (VO*)malloc(mang->size * sizeof(VO));
    
    for (int i = 0; i < mang->size; i++)
    {       
        label:
        printf("Nhap gia tri cua arr[%d]: ",i);
        scanf("%s",name);     
        if (strcmp((char*)"VO_DO", name ) == 0)
        {
            mang->ptr[i] = VO_DO;
        }
        else if (strcmp((char*)"VO_VANG",name ) == 0)
        {
            mang->ptr[i] = VO_VANG;
        }
        else if (strcmp((char*)"VO_XANH", name ) == 0)
        {
            mang->ptr[i] = VO_XANH;
        }
        else
        {
            printf("Ban da nhap sai, vui long nhap lai\n");
            goto label;
        }               
    }  
}

int demdoivo(typeBox mang, VO mau)
{
    int count=0;
    for (int i = 0; i < mang.size; i++)
    {
        if (mang.ptr[i] == mau)
        {
            count++;
        }        
    }
    return (count/2);
}
int main(int argc, char const *argv[])
{
    typeBox arr;

    nhapThongTin(&arr);
    //Kiểm tra đã nhập được giá trị
    printf("Gia tri cua mang da nhap la:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d]: %d\n",i,arr.ptr[i]);
    }
    printf("So doi vo do la: %d\n",demdoivo(arr,VO_DO));

    printf("So doi vo xanh la: %d\n",demdoivo(arr,VO_XANH));

    printf("So doi vo vang la: %d\n",demdoivo(arr,VO_VANG));

    printf("Tong so doi vo la: %d\n",demdoivo(arr,VO_VANG)+demdoivo(arr,VO_XANH)+demdoivo(arr,VO_DO));

    

    
    return 0;
}
