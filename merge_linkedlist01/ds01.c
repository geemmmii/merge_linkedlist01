#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

void Append_Node(Node** head, Node* node) {
    if (*head == NULL) {
        *head = node;
    }
    else {
        Node* p = *head;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = node;
    }
}

Node* Create_Node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    return node;
}

void Print_Linked_List(Node* head) {
    Node* p = head;
    int index = 0;
    while (p != NULL) {
        printf("N[%d]:%d ", index, p->data);
        p = p->link;
        index++;
        if (p != NULL) { // 수정된 부분
            printf(" -> ");
        }
    }
    printf("\n");
}




Node* Merge_List(Node* head_a, Node* head_b) {
    Node* head_c = NULL;
    while (head_a != NULL && head_b != NULL) {
        if (head_a->data < head_b->data) {
            Append_Node(&head_c, Create_Node(head_a->data));
            head_a = head_a->link;
        }
        else {
            Append_Node(&head_c, Create_Node(head_b->data));
            head_b = head_b->link;
        }
    }

    while (head_a != NULL) {
        Append_Node(&head_c, Create_Node(head_a->data));
        head_a = head_a->link;
    }

    while (head_b != NULL) {
        Append_Node(&head_c, Create_Node(head_b->data));
        head_b = head_b->link;
    }

    return head_c;
}

int main(void) {
    Node* head_a = NULL
        ;
    Node* head_b = NULL
        ;
    Node* head_c = NULL
        ;
    //a 연결리스트 구성
    Append_Node(&head_a, Create_Node(10));
    Append_Node(&head_a, Create_Node(20));
    Append_Node(&head_a, Create_Node(30));
    //b 연결리스트 구성
    Append_Node(&head_b, Create_Node(15));
    Append_Node(&head_b, Create_Node(25));
    Append_Node(&head_b, Create_Node(27));
    Append_Node(&head_b, Create_Node(28));
    //a,b 연결리스트 출력
    Print_Linked_List
    (head_a);
    Print_Linked_List
    (head_b);
    //연결리스트 합병 함수 호출
    head_c = Merge_List
    (head_a, head_b);
    //합병된 연결리스트 출력
    Print_Linked_List
    (head_c);
    return 0;
}