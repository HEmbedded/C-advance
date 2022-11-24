// Cây nhị phân
#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc 1 node của cây
struct node
{
    int data;               // dữ liệu chứa trong 1 node
    struct node *left;      // con trỏ chứa địa chỉ node bên trái
    struct node *right;     // con trỏ chứa địa chỉ node bên phải
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
    newnode->left = NULL; //phải truyền con trỏ bên trái vào NULL do node vừa tạo do chưa có liên kết đến node tiếp theo
    newnode->right = NULL; //phải truyền con trỏ bên phải vào NULL do node vừa tạo do chưa có liên kết đến node tiếp theo
    return newnode;
}


// Hàm sắp xếp phần tử vào cây: lẻ trái, chẵn phải
void insertTree (NODE **root, int value)
{ 
    NODE *temp = *root; //tạo 1 con trỏ tạm, tránh mất địa chỉ con trỏ đầu của cây
    NODE *newnode = createNODE(value); //tạo một node mới với giá trị được truyền vào
    if ((*root) == NULL) //Nếu là giá trị đầu của cây thì cho địa chỉ của cây = với địa chỉ của node vừa tạo
    {
        *root = newnode;

    } 
    //Còn nếu cây đã có gốc
    //Nếu là số lẻ (chia dư cho 2 khác 0)
    else if (value%2 != 0)
    {
        while (temp->left != NULL)     //Cho chạy từ địa chỉ bên trái của gốc đến địa chỉ bên trái của node kế tiếp đến khi gặp NULL  
        {                             
            temp = temp->left;         //Chưa gặp NULL thì gắn địa chỉ bên trái hiện tại = địa chỉ bên trái kế tiếp
        }
        temp->left = newnode;        //Khi đã gặp node cuối thì ta cho địa chỉ của node vừa tạo bằng với địa chỉ của node cuối cùng
    } 
    //Gặp số chẵn thì tương tự bên trên.
    else
    {
        while (temp->right != NULL)      
        {                              
            temp = temp->right;
        }
        temp->right = newnode;        
    }   
}

void display(NODE *tree)
{
    NODE *temp = tree;    //tạo 1 con trỏ tạm, tránh mất địa chỉ con trỏ đầu của cây
    //Nếu cây chưa có giá trị
    if (temp == NULL)
    {
        printf("Cay khong co gia tri\n");
    }
    else
    {
        
        printf("\t\t\t\t\t\t\t\t");
        printf("%d\n",temp->data);          //in giá trị của gốc
        NODE *tempL,*tempR;                 //Tạo 2 node tạm chứa địa chỉ của node trái,phải mỗi nhánh
        tempL = temp->left;
        tempR = temp->right;
        int i,j,k=6,h=1;                    //Tạo hiệu ứng in cây
        while (tempL != NULL || tempR != NULL)      //Xuất hết giá trị của cây cho đến khi cả 2 nhánh đều = NULL
        {
            //Tạo hiệu ứng in cây
            for (i = 0; i <= k; i++)
            {
                printf("\t");
            }
            k--;

            //Nếu node bên trái chưa bằng NULL thì cứ xuất tiếp
            if (tempL != NULL )
            {
                printf("%d",tempL->data);
                tempL = tempL->left;        //Gán địa chỉ kế tiếp vào con trỏ tạm
            }

            //Tạo hiệu ứng in cây
            printf("\t");
            for (j = 0; j < h; j++)
                {
                    printf("\t");
                }
                h = h+2;

            //Nếu node bên phải chưa bằng NULL thì cứ xuất tiếp
            if (tempR != NULL )
            {
                
                printf("%d",tempR->data);
                tempR = tempR->right;       //Gán địa chỉ kế tiếp vào con trỏ tạm
            }

            printf("\n");        
        }   
    }    
}

int main(int argc, char const *argv[])
{
    //Tạo 1 gốc với con trỏ đầu và cho = null
    NODE *root = NULL ;     //Gốc chẳn lẻ bằng nhau
    NODE *root2 = NULL ;    //Gốc chỉ có chẳn
    NODE *root3 = NULL ;    //Gốc chỉ có lẻ
    NODE *root4 = NULL ;    //Gốc 3 lẻ 2 chẳn

    //Cây có số chẵn lẻ bằng nhau
    for (int i = 0; i < 9; i++)
    {
        insertTree(&root,i);
    }
    printf("Cay co so le va chan bang nhau...\n");
    display(root);

    //Cây có mỗi số chẳn
    for (int i = 0; i < 5; i++)
    {
        insertTree(&root2,i*2);
    }
    printf("Cay co moi so chan...\n");
    display(root2);

    //Cây có mỗi số lẻ
    insertTree(&root3,1);
    insertTree(&root3,3);
    insertTree(&root3,5);
    insertTree(&root3,7);
    insertTree(&root3,9);
    printf("Cay co moi so le...\n");
    display(root3);

    //Cây tổng hợp
    insertTree(&root4,1);
    insertTree(&root4,2);
    insertTree(&root4,3);
    insertTree(&root4,4);
    insertTree(&root4,7);
    insertTree(&root4,9);
    printf("Cay co 3 so le va 2 so chan...\n");
    display(root4);
    return 0;
}


