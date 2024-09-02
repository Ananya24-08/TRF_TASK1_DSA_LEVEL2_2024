# TRF_TASK1_DSA_LEVEL2_2024


Submit Your Task In Any Preffered Programming Language.  
Submit your program file Folders With Name as TRF_LEVEL_2_<Your_name>   

  
You are given two non-empty linked lists representing two non-negative integers.   
The digits are stored in reverse order, and each of their nodes contains a single digit.   
Add the two numbers and return the sum as a linked list.  

You may assume the two numbers do not contain any leading zero, except the number 0 itself.  

![image](addtwonumber1.jpg)

Example 1:

Input:   
l1 = [2,4,3],   
l2 = [5,6,4]  
Output: [7,0,8]  
Explanation: 342 + 465 = 807.  
  
Example 2:  
 
Input:  
l1 = [0],  
l2 = [0]  
Output: [0]  

Example 3:  

Input:  
l1 = [9,9,9,9,9,9,9],  
l2 = [9,9,9,9]  
Output: [8,9,9,9,0,0,0,1] 
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
