#include <stdio.h>

int tinhtuoi(int daynow, int monthnow, int yearnow, int ngay, int thang, int nam)
{
    int tuoi;
    if ((yearnow > nam && monthnow > thang) || (yearnow > nam && monthnow == thang && daynow <= ngay))
    {
        tuoi = yearnow - nam;
    } else 
    {
        tuoi = yearnow - nam - 1;
    }
    return tuoi;
}



int main(int argc, char const *argv[])
{
    int daynow, monthnow, yearnow, ngay, thang, nam;
   
    //Nhập ngày tháng năm hiện tại
    printf("Nhap ngay thang nam hien tai\n");    
    printf("Ngay: ");
    scanf("%d",&daynow);
    printf("Thang: ");
    scanf("%d",&monthnow);
    printf("Nam: ");
    scanf("%d",&yearnow);
    //Kiểm tra ngày tháng năm nhập có hợp lệ ? Nếu không sẽ nhập lại chỗ sai
    while (1)
    {
        if (yearnow<=0)
        {
            printf("Nam khong hop le, vui long nhap lai: \n");
            scanf("%d",&yearnow);
        }else if (monthnow >12 || monthnow <=0)
        {
            printf("Thang khong hop le, vui long nhap lai: \n");
            scanf("%d",&monthnow);
        }else if (daynow>31 || daynow<=0 || (monthnow == 2 && daynow>28) || 
        ((monthnow == 4 || monthnow == 6 || monthnow == 9 || monthnow == 11) && daynow>30))
        {
            printf("Ngay khong hop le, vui long nhap lai: \n");
            scanf("%d",&daynow);
        }else
        {
            break;
        }      
    }      
    printf("Hom nay la ngay %d thang %d nam %d\n",daynow,monthnow,yearnow);
    // Nhập ngày tháng năm sinh của bạn
    printf("Nhap ngay thang nam sinh cua ban\n");    
    printf("Ngay: ");
    scanf("%d",&ngay);
    printf("Thang: ");
    scanf("%d",&thang);
    printf("Nam: ");
    scanf("%d",&nam);
    // Kiểm tra năm sinh có hợp lệ, nếu không sẽ nhập lại vị trí sai
     while (1)
    {
        if (nam<0)
        {
            printf("Nam khong hop le, vui long nhap lai: \n");
            scanf("%d",&nam);
        }else if (nam>=yearnow)
        {
            printf("Ban chua duoc sinh ra, vui long nhap lai nam sinh: \n");
            scanf("%d",&nam);
        }else if (thang>12 || thang <= 0)
        {
            printf("Thang khong hop le, vui long nhap lai: \n");
            scanf("%d",&thang);
        }
        else if (ngay>31 || ngay<=0 || (thang == 2 && ngay>28) || ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay>30))
        {
            printf("Ngay khong hop le, vui long nhap lai: \n");
            scanf("%d",&ngay);
        }else
        {
            break;
        }      
    }      
    printf("Ngay sinh nhat cua ban la ngay %d thang %d nam %d\n",ngay,thang,nam);
    int tuoi = tinhtuoi(daynow, monthnow, yearnow, ngay, thang, nam);
    printf("Tuoi cua ban la %d",tuoi);
    
    return 0;
}
