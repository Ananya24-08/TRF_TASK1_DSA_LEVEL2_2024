#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printlist(Node* head)
{
    while(head!=NULL){
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("NULL\n");

}

Node* sum(Node* l1 ,Node* l2)
{
    Node* result = NULL;
    Node* last = NULL;
    int carry=0;

    while(l1!=NULL || l2!=NULL)
    {
        int sum=carry;
        if(l1 != NULL){
            sum+=l1->data;
            l1=l1->next;
        }

        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        carry = sum / 10;
        Node* newNode = createNode(sum % 10);

        if(result == NULL){
            result = newNode;
        }else{
            last->next= newNode;
        }
        last = newNode;
    }
    return result;
}

int main()
{
    Node* l1=createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    Node* l2=createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    printlist(l1);
    printlist(l2);

    Node* result= sum(l1,l2);
    printlist(result);


}