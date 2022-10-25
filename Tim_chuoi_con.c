// Tìm chuỗi con trong chuỗi mẹ không dùng thư viện string.h
#include <stdio.h>
#include <stdlib.h>


// Kiểu dữ liệu của mảng
typedef struct{
    char *ptr;
    int size;
}Array;

void xuatchuoi(Array chuoi)
{
    for (int i = 0; i < chuoi.size ; i++)
    {
        printf("%c",chuoi.ptr[i]);
    }
    printf("\n");
}

void timchuoi(Array chuoi, Array chuoicon)
{   
    // dem: đếm số lần xuất hiện của chuỗi con
    // j: biến vòng lặp của chuỗi con
    // temp: biến tạm tăng lên khi 1 kí tự chuỗi con = kí tự chuỗi mẹ. Dùng để so sánh với length
    // length: đếm số lượng kí tự có trong chuỗi con
    int dem=0, j=0, temp = 0, length=0;
    // Đếm độ dài chuỗi con
    for (int i = 0; i < chuoicon.size; i++)
    {
        if (chuoicon.ptr[i] == '\0')
        {
            length = i;
            break;
        }         
    }

    // Quét giá trị của chuỗi con so với chuỗi mẹ
    for (int i = 0; i < chuoi.size; i++)
    {   
        //Nếu kí tự đầu tiên của chuỗi con trùng với kí tự thứ i của chuỗi mẹ
        //Thì tăng biến temp lên so với chiều dài của chuỗi con
        //Trường hợp nếu chuỗi con chỉ có 1 kí tự thì tăng giá trị đếm và đi reset giá trị temp và j (stt của chuỗi con)   
        if (chuoicon.ptr[j] == chuoi.ptr[i])
        {
            // Dành cho trường hợp chỉ có 1 kí tự
            temp++;
            if (temp == length )
                    {                   
                        dem++;
                        goto label;
                    }
            // không thuộc trường hợp chuỗi con là 1 kí tự thì quét kí tự tiếp theo của chuỗi con        
            for (j = 1; j < chuoicon.size; j++)
            {
                // Nếu kí tự tiếp theo của chuỗi con trùng chuỗi mẹ thì tăng biến tạm
                // Nếu biến tạm bằng chiều dài chuỗi con thì reset các giá trị và out khỏi vòng lặp quét chuỗi con
                // Nếu không bằng thì reset các giá trị so sánh và thoát luôn vòng lặp so sánh chuỗi con
                if (chuoicon.ptr[j] == chuoi.ptr[i+j])
                {
                    temp++; 
                    if (temp == length )
                    {
                    
                        dem++;
                        goto label;
                    }
                    // Quay về vòng lặp j
                    continue;

                }
                // Kí tư tiếp theo không trùng thì out ra khỏi vòng lặp j và các biến tạm
                // Về vòng lặp for ban đầu và tăng lên 1 giá trị để so sánh giá trị tiếp theo của chuỗi mẹ
                else                
                {
                    label:
                    temp=0;
                    j=0;
                    break;
                }                              
            }    
        }      
    }
    if (dem == 0)
    {     
        printf("Chuoi con khong xuat hien trong chuoi me: ");
    }else
    {    
        printf("so lan xuat hien cua chuoi con: %d",dem);
    }
}
int main(int argc, char const *argv[])
{
    Array chuoi, chuoicon;
      
    printf("Nhap chieu dai chuoi: ");
    scanf("%d",&(chuoi.size));
    fflush(stdin);

    chuoicon.size=chuoi.size; 

    chuoi.ptr = (char*)malloc(chuoi.size * sizeof(char));

    chuoicon.ptr = (char*)malloc(chuoicon.size * sizeof(char));
   
	printf("Nhap chuoi: ");
    gets(chuoi.ptr);
    fflush(stdin);

    printf("Nhap chuoi con can tim: ");
    gets(chuoicon.ptr);  
    
    timchuoi(chuoi, chuoicon);

    return 0;
}
