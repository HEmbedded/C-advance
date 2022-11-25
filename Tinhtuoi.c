//Tính tuổi theo quy tắc ngày tháng hiện tại phải trùng hoặc lớn hơn ngày tháng sinh thì mới tính được 1 tuổi
#include <stdio.h>

//Hàm tính có phải năm nhuận
//VD: 1600 và 2000 là các năm nhuận nhưng 1700, 1800 và 1900 không phải năm nhuận.
int IsLeapYear(int year)
{
    if (year%4 != 0)            //Nếu không chia hết cho 4 là năm không nhuận
    {
        return 0;
    } else if (year%100 !=0)    //Nếu chia hết cho 4 và không chia hết cho 100 thì là năm nhuận
    {
        return 1;
    } else if (year%400 != 0)   //Nếu chia hết cho 4 và chia hết cho 100 thì xét thêm có chia hết cho 400
    {                           //Nếu chia hết thì là năm nhuận, không thì năm không nhuận
        return 0;
    }else return 1;       
}

int tinhtuoi(int daynow, int monthnow, int yearnow, int ngay, int thang, int nam)
{
    int tuoi;
    //Nếu năm hiện tại lớn hơn năm sinh && tháng hiện tại > tháng sinh (chỉ cần tháng và năm lớn hơn năm, tháng sinh thì có thể tính ra tuổi ngay)
    //Hoặc năm hiện tại > năm sinh và tháng giống nhau thì ta xét đến ngày, nếu ngày sinh lớn hơn hiện tại (qua sinh nhật) thì cứ lấy năm trừ
    if ((yearnow > nam && monthnow > thang) || (yearnow > nam && monthnow == thang && daynow <= ngay))
    {
        tuoi = yearnow - nam;
    } 
    //Các trường hợp còn lại (chưa đến sinh nhật) thì cứ lấy năm hiện tại - năm sinh - 1 là ra được tuổi
    else 
    {
        tuoi = yearnow - nam - 1;
    }
    if (tuoi < 0)
    {
        tuoi = 0;
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
    printf("%d\n",yearnow%4);

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
        }      
        else if( 
                    daynow>31                                                                           || //Ngày lớn hơn 31
                    daynow<=0                                                                           || //Ngày bé hơn 30
                    (monthnow == 2 && IsLeapYear(yearnow) == 1 && daynow > 29)                          || //Ngày của tháng 2 lớn hơn 29 vào năm nhuận
                    (monthnow == 2 && IsLeapYear(yearnow) == 0 && daynow > 28)                          || //Ngày của tháng 2 lớn hơn 28 vào năm không nhuận
                    ((monthnow == 4 || monthnow == 6 || monthnow == 9 || monthnow == 11) && daynow>30)     //Ngày của tháng có 30 ngày 
                )
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
        }else if (nam>yearnow)
        {
            printf("Ban chua duoc sinh ra, vui long nhap lai nam sinh: \n");
            scanf("%d",&nam);
        }else if (thang>12 || thang <= 0)
        {
            printf("Thang khong hop le, vui long nhap lai: \n");
            scanf("%d",&thang);
        }
        else if (
                    ngay>31                                                                 || //Ngày lớn hơn 31
                    ngay<=0                                                                 || //Ngày bé hơn 30
                    (thang == 2 && IsLeapYear(nam) == 1 && ngay > 29)                       || //Ngày của tháng 2 lớn hơn 29 vào năm nhuận
                    (thang == 2 && IsLeapYear(nam) == 0 && ngay > 28)                       || //Ngày của tháng 2 lớn hơn 28 vào năm không nhuận
                    ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay>30)       //Ngày của tháng có 30 ngày
                )
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
    if (tuoi == 0)
    {
        printf("Ban con la em be, chua du 1 tuoi !\n");
    }else printf("Tuoi cua ban la %d",tuoi);
    
    return 0;
}
