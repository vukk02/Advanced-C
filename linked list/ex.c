#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node* next;
}node;


node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}

void push_front(node **array, int value) // them 1 node vao phia truoc
{
    node* temp, *p;
    temp= createNode(value);
    p = *array;
    *array = temp;
    temp->next = p;
}

void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}

void pop_front(node **array) // xoa node dau tien
{
    node* p, *temp;
    p = *array;
    temp = p->next;
    *array = temp;
    free(p);
}

int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

int front(node *array) // lay gia tri cua node dau tien
{
    int value = array->value;
    return value;
}

int back(node *array) // lay gia tri cua node cuoi cung
{
    int i = 0;
    while (array->next != NULL)
    {
        array = array->next;
        i++;
    }
    int value = array->value;
    return value;
}

void insert(node **array, int value, int pos) // them 1 node vao mot vi tri bat ky
{
    node* p, * temp, * p1;
    int i = 0;
    temp = createNode(value);
    p = *array;
    while (p->next != NULL && i != pos-1)
    {
        p = p->next;
        i++;
    }
    if (pos != i+1)
    {
        printf("Error: List has less element\n");
        return ;
    }
    p1 = p->next;
    p->next = temp;
    temp->next = p1;

}

void delete_list(node **array, int pos) // xoa 1 node tai mot vi tri bat ky
{
    node* p, * temp, * p1;
    int i = 0;
    p = *array;
    while (p->next->next != NULL && i != pos-1)
    {
        p = p->next;
        i++;
    }
    if (pos != i+1)
    {
        printf("Error: List has less element\n");
        return ;
    }
    p1 = p->next;
    temp = p1->next;
    p->next = temp;
    free(p1);
}

int size(node *array) // lay kich thuoc cua list
{
    int i = 1;
    while (array->next != NULL)
    {
        array = array->next;
        i++;
    }
    return i;
}

bool empty(node *array) // kiem tra list co rong hay khong
{
    if (array == NULL)
    {
        return true;
    }
    else return false;
}

int main()
{
    node* arr = NULL;
    node* a = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);
    push_front(&arr, 9);
    pop_front(&arr);
    insert(&arr, 12, 2);
    delete_list(&arr, 2);
    if (empty(a))
    {
        printf("array is empty\n");
    }
    else
    {
        printf("array has element\n");
    }

    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));
    printf("Value front: %d\n", front(arr));
    printf("Value back: %d\n", back(arr));
    

	return 0;
}

