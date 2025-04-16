#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node* node;

node create(void);
int count(node);
void add_first(node*);
void add_last(node);
void insert_index(node*, int);
void remove_first(node*);
void remove_last(node*);
void remove_index(node*, int);
void reverse(node*);
int search(node, int);

int main(void)
{
    
}

node create() 
{
    int data;
    scanf("%d", &data);
    node temp = (node)malloc(16);
    if(temp == NULL)
    {
        printf("Cap phat failed");
        return 0;
    }else
    {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}

// int count(node head)
// {
//     int cnt = 1;
//     while(head->next != NULL) 
//     {
//         cnt++;
//         head = head->next;
//     }
//     return cnt;
// }

int count(node head)
{
    int cnt = 0;
    while(head != (void*)0)
    {
        ++cnt;
        head=head->next;
    }
    return cnt;
}

void add_first(node *head) 
{
    node temp = create();
    if(temp == NULL) printf("Cap phat failed");
    else 
    {
        temp->next = *head;
        *head = temp;
    }
}

void add_last(node head)
{
    node temp = create();
    if(temp == NULL) printf("Cap phat failed");
    else
    {
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = temp;
    }
}

void insert_index(node *head, int index)
{
    if(index == 0)
    {
        add_first(head);
        return;
    }else if(index == (count(*head) - 1))
    {
        add_last(*head);
        return;
    }
    node temp = *head;
    node ChiD = create();
    while(--index)
    {
        temp = temp->next;
    }
    ChiD->next = temp->next;
    temp->next = ChiD;
}

void remove_first(node *head)
{
    if(*head == NULL) printf("ERROR!");
    else
    {
        node temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}

void remove_last(node *head)
{
    if(*head == NULL) printf("ERROR!");
    else if((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        node temp = *head;
        while(temp->next->next != NULL)    
        {
            temp = temp->next;
        }  
        free(temp->next);
        temp->next = NULL;
    }
}

void remove_index(node *head, int index)
{
    if(index == 0) 
    {
        remove_first(head);
        return;
    }else if(index == count(*head)-1)
    {
        remove_last(head);
        return;
    }
    node temp = *head;
    while(--index)
    {
        temp = temp->next;
    }
    node tmp = temp->next->next;
    temp->next = tmp;
    free(tmp);
}

void reverse(node *head)
{
    node temp = *head;
    node tmp = temp->next;
    temp->next = NULL;
    while(tmp->next != NULL)
    {
        node x = tmp;
        tmp = tmp->next;
        x->next = temp;
        temp = x;
    }
    *head = tmp;
    (*head)->next = temp;
}

int search(node head, int x)
{
    int index = 0;
    while(head != NULL)
    {
        if(head->data == x) break;
        index++;
        head = head->next;
    }
    return index;
}




