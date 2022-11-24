#include <stdio.h>
#include <stdlib.h>

//Cấu tạo biến hàng đợi gồm 1 mảng (con trỏ vị trí và kích thước),
typedef struct queue
{
    int *A;
    int size;
    int front;
}QUEUE;

//Cấu hình cho hàng đợi
void Init(QUEUE *q)
{
    //Nhập chiều dài của hàng đợi
    int size;   
    printf("Nhap chieu dai cua hang doi: ");
    scanf("%d",&(q->size));
    int *ptr;
    ptr = (int*)malloc(size * sizeof(int));

    //Cho địa chỉ con trỏ vừa cấp phát vào con trỏ của hàng đợi
    q->A = ptr;
    
    //Gán giá trị front của hàng đợi =0
    q->front = 0;
}

//Hàm kiểm tra hàng đợi có rỗng hay không
int IsEmpty(QUEUE q)
{
    //Nếu front == 0 có nghĩa không có giá trị trong hàng đợi
    if (q.front == 0){
        return 1;
    }else return 0;
}

//Hàm kiểm tra hàng đợi có đầy hay không ?
int IsFull (QUEUE q)
{
    //Nếu front == chiều dài của hàng đợi - 1 thì nó đầy (do front bắt đầu từ 0)
    if (q.front > q.size-1){
        return 1;
    }else return 0;
}

//Hàm thêm 1 giá trị vào hàng đợi
void enqueue (QUEUE *q, int x)
{
    //Nếu hàng đợi chưa đầy
    if (IsFull(*q)==0) 
    {       
        //Thêm giá trị vào cuối hàng đợi (chính là front sau khi đã tăng giá trị)
        q->A[q->front] = x;

        //Tăng front về phía trước sau khi đã tăng giá trị
        q->front++;
    }else printf("Hang doi day !\n");
}

//Hàm xóa 1 giá trị của hàng đợi
int dequeue(QUEUE *q)
{
    int x = '\0';
    //Nếu hàng đợi không rỗng
    if (!IsEmpty(*q)) 
    {
        //Gán giá trị bị xóa vào biến tạm
        x = q->A[0];

        //Bỏ giá trị đầu ra khỏi hàng đợi bằng cách cho giá trị sau nó lên đầu
        //Chạy từ đầu cho đến nhỏ hơn giá trị front đang đứng (front luôn đứng sau giá trị cuối cùng)
        for(int i = 0; i < q->front; i++)
        {
            q->A[i] = q->A[i+1];
        }
        //Giá trị của cuối hàng đợi
        q->A[q->front-1] = '\0';
        //Giảm front để biết đã xóa mất 1 giá trị
        q->front--;
        
    }
    else
    {//Ngược lại nếu hàng đợi rỗng: không có giá trị nào để xóa
        printf("Hang doi rong !\n");
    }
    return x;
}

//Xuất tất cả giá trị đang có trong hàng đợi
void Output(QUEUE q)
{
    //Nếu hàng đợi rỗng
    if (IsEmpty(q) == 1)
    {
        printf("Hang doi rong !\n");
    } else
    {
        //Xét từ đầu đến trước giá trị của front 1 đơn vị
        for(int i = 0; i <= q.front-1; i++)
        {
            printf("Q[%d] = %d\n",i,q.A[i]);
        }
    }
}

//Xuất ra giá trị đang ở đầu của hàng đợi
void front (QUEUE q)
{
    if (IsEmpty(q) == 1)
    {
        printf("Hang doi rong !\n");
    }else printf("Phan tu dau tien cua hang doi la: %d\n",q.A[0]);
}

//xuất ra giá trị đang ở cuối cùng của hàng đợi
void rear (QUEUE q)
{
    if (IsEmpty(q) == 1)
    {
        printf("Hang doi rong !\n");
    }else printf("Phan tu cuoi cung cua hang doi la: %d\n",q.A[q.front-1]);
}


int main(int argc, char const *argv[])
{
    //khai báo hàng đợi
    QUEUE q;

    //Khởi tạo hàng đợi
    Init(&q);     

    //Thêm giá trị cho hàng đợi  
    enqueue(&q,14);
    enqueue(&q,64);
    enqueue(&q,654);
    enqueue(&q,972);
    enqueue(&q,641);

    printf("Hang doi sau khi them phan tu \n");
    //Xuất tất cả giá trị trong hàng đợi sau khi thêm
    Output(q);
    front(q);
    rear(q);

    //Xóa đi giá trị
    printf("Xoa di gia tri cua hang doi...\n");
    printf("Gia tri bi xoa la: %d \n",dequeue(&q));
    printf("Gia tri bi xoa la: %d \n",dequeue(&q));
    //printf("Gia tri bi xoa la: %d \n",dequeue(&q));
    //printf("Gia tri bi xoa la: %d \n",dequeue(&q));


    //Xuất tất cả giá trị trong hàng đợi sau khi xóa
    printf("Hang doi sau khi xoa phan tu \n");
    Output(q);
    front(q);
    rear(q);

    //Thêm 1 giá trị
    enqueue(&q,999);
    printf("Hang doi sau khi them phan tu 999 \n");
    Output(q);
    front(q);
    rear(q);

    return 0;
}