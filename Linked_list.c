#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc 1 node
struct node
{
    int data; // dữ liệu chứa trong 1 node
    struct node *next; // con trỏ chứa địa chỉ node tiếp theo
};

typedef struct node NODE; // thay thế struct node thành NODE

// Khỏi tạo 1 cái node
NODE* createNODE (int data)
{
    NODE* newnode = (NODE*)malloc(sizeof(NODE)); //cấp phát bộ nhớ cho con trỏ mới tạo
    //Nếu hết bộ nhớ
    if (newnode == NULL)
    {
        printf("Het bo nho de cap phat");
        return NULL;
    }
      
    newnode->data = data; //truyền giá trị vào cho node
    newnode->next = NULL; //phải truyền con trỏ vào NULL do node vừa tạo do chưa có liên kết đến node tiếp theo
    return newnode;
}
// Hàm in ra tất cả giá trị có trong linked list
void All_value_of_list(NODE *List){
    NODE* temp = List;  //Tạo con trỏ tạm để không mất địa chỉ đầu của list
    if (temp == NULL)
    {
        printf("Khong co phan tu nao trong danh sach");
    } 
    else
    {
        while(temp != NULL)
            {
                printf("%d ",temp->data);
                temp = temp->next;
            }
        printf("\n");
    }
}

// Hàm Để thêm một phần tử vào vị trí sau cùng
void push_back (NODE **List, int value)
{ 
    NODE *temp = *List; //tạo 1 con trỏ tạm, tránh mất địa chỉ con trỏ đầu của List
    NODE *newnode = createNODE(value); //tạo một node mới với giá trị được truyền vào
    if ((*List) == NULL) //Nếu là giá trị đầu của list thì cho địa chỉ của List = với địa chỉ của node vừa tạo
    {
        *List = newnode;
    }
    else
    {
        while (temp->next != NULL)     //Địa chỉ của node hiện tại có địa chỉ của node tiếp theo thì ta cho địa chỉ của biến tạm đó   
        {                              //bằng với địa chỉ của node tiếp theo cho đế khi gặp node cuối (gặp NULL)
            temp = temp->next;
        }
        temp->next = newnode;        //Khi đã gặp node cuối thì ta cho địa chỉ của node vừa tạo bằng với địa chỉ của node cuối cùng
    }
}

//Hàm bỏ đi phần tử cuối cùng trong list
void pop_pack(NODE **List)
{
    NODE *temp = *List; //tạo 1 con trỏ tạm, tránh mất địa chỉ con trỏ đầu của List
    if (temp == NULL)
    {
        printf("Khong co phan tu nao trong danh sach de xoa");
        exit(0);
    }else if (temp->next == NULL)
    {
        printf("Co 1 gia tri trong danh sach");
        free(*List);
        printf("Da xoa, khong con gia tri nao trong danh sach");
        exit(0);
    }else
    {
        while (temp->next->next != NULL)     //Xét địa chỉ của địa chỉ node tiếp theo (Xét địa chỉ next của node kế tiếp của node hiện tại)
        {                                    //Nếu bằng NULL thì ta có địa chỉ của NODE kế tiếp của cái đang dừng
            temp = temp->next;
        }
        free(temp->next);
        temp->next=NULL;                     //Cho địa chỉ next của Node hiện tại = NULL
    }  
}

//Hàm xóa 1 vị trí bất kì trong danh sách
void Delete_at(NODE **list, int position)
{
    
    //tạo 1 con trỏ tạm, tránh mất địa chỉ con trỏ đầu của List
    NODE* temp = *list;
    if (temp == NULL)
    {
        printf("Khong co phan tu nao trong danh sach de xoa");
        
    }
    
    // Nếu xóa ở vị trí đầu
    if (position == 0) 
    {
        
        printf("Ban dang xoa vi tri dau danh sach...\n");
        // Cho địa chỉ của list bằng với địa chỉ node kế tiếp
        *list = temp->next;
        
 
        // giải phóng địa chỉ lúc đầu của list, cũng chính là địa chỉ của biến tạm
        free(temp);

        
    }
    else
    {
        //Nếu không phải node đầu
        // Tìm node trước node cần được xóa
        for (int i = 0; temp != NULL && i < position - 1; i++)
        {
            temp = temp->next;
        }
        
 
        // Nếu vị trí tìm nằm ngoài số node hiện tại (Địa chỉ node hiện tại = NULL hoặc địa chỉ node kế tiếp bằng null)
        if (temp == NULL || temp->next == NULL)
        {
            printf("Vi tri nay khong co gia tri\n");
            return;
        }
        
        // Node temp->next : địa chỉ Node phía trước của địa chỉ node đang dừng cần được xóa
        // Tạo 1 node trung gian để lưu lại địa chỉ của node kế tiếp của kế tiếp
        NODE* next = temp->next->next;
        
        // Giải phóng node cần xóa (node kế kế của node đang tạm dừng)
        free(temp->next); // Free memory
 
        // Sửa địa chỉ của node kế tiếp của node hiện tại bằng node đã lưu tạm trước đó
        temp->next = next;
        
    }
  
}


// Hàm xóa hết tất cả phần tử của danh sách
void clear_list (NODE **List)
{
    if (List == NULL)
    {
        printf("Khong co phan tu de xoa");
    }
    else
    {
        NODE *temp = *List;          //Tạo con trỏ tạm để lưu địa chỉ của node kế tiếp
        while (temp != NULL)        //Xét từ node đầu đến node cuối
        {
            temp = temp->next;      //Cho địa chỉ con trỏ tạm = địa chỉ con trỏ của node kế tiếp
            free(*List);             //Giải phóng node
            *List = temp;            //Cho list = với địa chỉ của node kế tiếp đến khi gặp node cuối cùng thì sẽ bằng NULL
        }                           //ta sẽ không mất đi địa chỉ của List
                      
    }   
}

// Hàm lấy giá trị đầu tiên của danh sách
int front(NODE *List)
{
    return List->data;
}

// Hàm lấy giá trị cuối cùng của danh sách
int back(NODE *List)
{
    NODE *temp = List;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    return temp->data;
}

// Hàm lấy giá trị thứ n của danh sách
int at(NODE *List, int position)
{
    NODE *temp = List;
    int i = 0;
    while (i != position)
    {
        temp = temp->next;
        i++;
    }
    
    return temp->data;
}

// Hàm xuất số lượng phần tử của danh sách
int size(NODE *List)
{
    NODE *temp = List;
    int i = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    
    return i;
}

//Hàm kiểm tra danh sách có phần tử hay không ? có trả về 1 và ngược lại
int empty(NODE *List)
{   
    if (List == NULL)
    {
        return 1;
    }else return 0;
       
}

int main(int argc, char const *argv[])
{
    NODE *list1 = NULL ; //Tạo 1 danh sách với bằng con trỏ đầu và cho = null

    //Thêm giá trị cho danh sách
    push_back(&list1,10);
    push_back(&list1,6);
    push_back(&list1,5);
    push_back(&list1,4);
    push_back(&list1,2);
    push_back(&list1,7);

    //Kiểm tra hàm có phần tử hay không ?
    if (empty(list1) == 1)
    {
        printf("Khong co phan tu nao trong danh sach\n");
    }else if (empty(list1) == 0)
    {
        printf("Co phan tu trong danh sach\n");
    }

    //Các giá trị sau khi thêm
    printf("Cac gia tri cua danh sach:\n");
    All_value_of_list(list1);
    
    //Kiểm tra các hàm
    printf("Gia tri dau tien cua danh sach la: %d\n",front(list1));
    printf("Gia tri cuoi cung cua danh sach la: %d\n",back(list1));
    printf("Gia tri thu %d (dem tu 0) cua danh sach la: %d\n",4,at(list1,4));
    printf("So luong phan tu cua danh sach la: %d\n",size(list1));

    
    //Thử hàm pop_back  
    printf("Cac gia tri cua danh sach sau khi xoa 1 phan tu cuoi:\n");
    pop_pack(&list1);
    All_value_of_list(list1);

    //Thử hàm xóa tại 1 vị trí bất kì của danh sách
    printf("Xoa gia tri thu %d (dem tu 0) cua danh sach\n",2);
    Delete_at(&list1,2);
    All_value_of_list(list1);

    //Thử hàm xóa tất cả các danh sách
    printf("Xoa tat ca phan tu trong danh sach...\n");
    clear_list(&list1);
    
    printf("Thu xoa 1 phan tu trong danh sach sau khi da xoa tat ca...\n");
    pop_pack(&list1);
    
    
    return 0;
}


