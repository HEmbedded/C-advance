#include <stdio.h>
#include <stdlib.h>

//Cấu tạo biến stack gồm 1 mảng (con trỏ vị trí và kích thước), và vị trí của giá trị trên cùng
typedef struct stack
{
    int *ptrStack;
    int size;
    int top;
}STACK;

//Cấu hình cho ngăn xếp
void Init(STACK *list)
{
    //Nhập chiều dài của ngăn xếp
    int size;   
    printf("Nhap chieu dai cua ngan xep: ");
    scanf("%d",&(list->size));
    int *ptr;
    ptr = (int*)malloc(size * sizeof(int));

    //Cho địa chỉ con trỏ vừa cấp phát vào con trỏ của ngăn xếp
    list->ptrStack = ptr;
    
    //Gán giá trị top của ngăn xếp = 0 (đang ở dưới đáy ngăn xếp)
    list->top = 0;
}

//Hàm kiểm tra ngăn xếp có rỗng hay không
int IsEmpty(STACK list)
{
    //Nếu vị trí top == 0 có nghĩa không có giá trị trong ngăn xếp (top sẽ tăng 1 giá trị sau khi có giá trị vào mà ban đầu = 0)
    if (list.top == 0){
        return 1;
    }else return 0;
}

//Hàm kiểm tra ngăn xếp có đầy hay không ?
int IsFull (STACK list)
{
    //Nếu vị trí top == chiều dài của ngăn xếp thì đầy
    //index bắt đầu = 0, size bắt đầu từ 1, mà index tăng 1 sau khi có mỗi giá trị thêm vào => thêm 5 thì index = 5 = size
    if (list.top == list.size){
        return 1;
    }else return 0;
}

//Hàm thêm 1 giá trị vào ngăn xếp
void Push (STACK *list, int data)
{
    //Nếu ngăn xếp chưa đầy
    if (IsFull(*list)==0) 
    {       
        //Thêm giá trị vào cuối ngăn xếp (cũng chính vị vị trí của top (index))
        list->ptrStack[list->top] = data;

        //Tăng top lên trên sau khi đã thêm giá trị
        list->top++;
    }else printf("Ngan xep da day !\n");
}

//Hàm xóa 1 giá trị của ngăn xếp
int Pop (STACK *list)
{
    int x = '\0';
    //Nếu ngăn xếp không rỗng
    if (!IsEmpty(*list)) 
    {
        //Gán giá trị vào biến tạm để xuất giá trị bị xóa
        x = list->ptrStack[list->top-1];
        //Cho giá trị trên cùng của dãy giá trị bằng null
        list->ptrStack[list->top-1] = '\0';

        //Giảm index 1 đơn vị
        list->top--;      
    }
    else
    {//Ngược lại nếu ngăn xếp rỗng: không có giá trị nào để xóa
        printf("Ngan xep rong !\n");
    }
    //Trả về giá trị đã xóa
    return x;
}

//Xuất tất cả giá trị đang có trong ngăn xếp
void Output(STACK list)
{
    //Nếu ngăn xếp rỗng
    if (IsEmpty(list) == 1)
    {
        printf("Ngan xep rong !\n");
    } else
    {
        //Xét từ đầu đến trước giá trị của top 1 đơn vị
        for(int i = 0; i <= list.top-1; i++)
        {
            printf("Q[%d] = %d\n",i,list.ptrStack[i]);
        }
    }
}

//Xuất ra giá trị dưới đáy của ngăn xếp
void bottomStack (STACK list)
{
    if (IsEmpty(list) == 1)
    {
        printf("Ngan xep rong !\n");
    }else printf("Gia tri duoi day cua ngan xep la: %d\n",list.ptrStack[0]);
}

//xuất ra giá trị đang ở trên đỉnh cùng của ngăn xếp
void topStack (STACK list)
{
    if (IsEmpty(list) == 1)
    {
        printf("Ngan xep rong !\n");
    }else printf("Gia tri tren cung cua ngan xep la: %d\n",list.ptrStack[list.top-1]);
}


int main(int argc, char const *argv[])
{
    //khai bao ngăn xếp
    STACK list;

    //khoi tao ngăn xếp
    Init(&list);     

    //Thêm giá trị cho ngăn xếp  
    Push(&list,14);
    Push(&list,64);
    Push(&list,654);
    Push(&list,972);
    Push(&list,641);

    printf("Ngan xep sau khi them gia tri \n");
    //Xuất tất cả giá trị trong ngăn xếp sau khi thêm
    Output(list);
    bottomStack(list);
    topStack(list);

    //Xóa đi giá trị
    printf("Xoa gia tri cua ngan xep...\n");
    printf("Gia tri bi xoa la: %d \n",Pop(&list));
    printf("Gia tri bi xoa la: %d \n",Pop(&list));
    //printf("Gia tri bi xoa la: %d \n",Pop(&list));
    //printf("Gia tri bi xoa la: %d \n",Pop(&list));
   


    //Xuất tất cả giá trị trong ngăn xếp sau khi xóa
    printf("Ngan xep sau khi xoa phan tu \n");
    Output(list);
    bottomStack(list);
    topStack(list);

    //Thêm 1 giá trị
    Push(&list,999);
    printf("Ngan xep sau khi them phan tu 999 \n");
    Output(list);
    bottomStack(list);
    topStack(list);

    return 0;
}