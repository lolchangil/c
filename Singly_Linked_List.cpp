#include <stdio.h>
#include<stdlib.h>
typedef int Data;
typedef struct Node {
    Data data;
    struct Node* next;
} NODE;
typedef struct {
	Node* head; 
	int size; 
} SLL;
//size만큼 돌면 원하는 마지막 노드의 next를 가리키게 됨
//index-1만큼 돌면 원하는 노드의 그전 노드를 가리키게 됨
SLL * SLL_List_Init() {
    SLL * newList;
    newList = (SLL*)malloc(sizeof(SLL));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}
Node* SLL_Node_Init(Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // 새로운 노드의 포인터를 NULL로 지정
    newNode->next = NULL;
    return newNode;
}
void SLL_addNodeLast(SLL * s,Data data) {
    Node * newNode = SLL_Node_Init(data);
    Node * select = s->head;
    if (s->head == NULL) {
        s->head = newNode;
    }
    else {
        Node* select = s->head;
        for (int i = 0; i < s->size-1; i++) {
            select = select->next;
        }
        select->next = newNode;
    }
    s->size++;
    return;
}
void SLL_addNodeFirst(SLL *s, Data data) {
    Node* newNode = SLL_Node_Init(data);
    newNode->next = s->head;
    s->head = newNode;
    s->size++;
    return;
}
void SLL_addNodeAt(SLL *s, Data data, int index) {
    if(s->size == 0) {
        puts("노드에 아무값도 들어가있지 않습니다");
    }
    else if (index < 0) {
        puts("인덱스가 음수입니다");
    }
    else if (s->size - 1 < index) {
        puts("올바르지 않은 인덱스입니다");
    }
    else {
        Node * newNode = SLL_Node_Init(data);
        if (index == 0) {
            newNode->next = s->head;
            s->head = newNode;
        }
        else {
            Node* select = s->head;
            for (int i = 0; i < index - 1; i++) {
                select = select->next;
            }
            newNode->next = select->next;
            select->next = newNode;
        }
        s->size++;
    }
    return;
}
void SLL_removeNodeFirst(SLL* s) {
    if (s->size == 0) {
        puts("노드에 아무것도 들어가있지 않습니다");
    }
    else {
        Node* select = s->head;
        s->head = s->head->next;
        select->data = 0;
        free(select);
        s->size--;
    }
    return;
}
void SLL_removeNodeLast(SLL *s) {
    if (s->size==0) {
        puts("노드에 아무것도 들어가있지 않습니다");
    }
    else if (s->size == 1) {
        s->head->data = 0;
        free(s->head);
        s->head = NULL;
        s->size--;
    }
    else {
        Node* select = s->head;
        for (int i = 0; i < s->size - 2; i++) {
            select = select->next;
        }
        select->next->data = 0;
        free(select->next);
        select->next = NULL;
        s->size--;
    }
    return;
}
void SLL_removeNodeAt(SLL *s, int index) {
    if (s->size == 0) {
        puts("노드에 아무값도 들어가있지 않습니다");
    }
    else if (index < 0) {
        puts("인덱스가 음수입니다");
    }
    else if (s->size - 1 < index) {
        puts("올바르지 않은 인덱스입니다");
    }
    else {
        Node* select = s->head;
        if (index == 0) {
            s->head = s->head->next;
            select->data = 0;
            free(select);
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                select = select->next;
            }
            Node* nnext = select->next->next;
            select->next->data = 0;
            free(select->next);
            select->next = nnext;
        }
        s->size--;
    }
    return;
}
void SLL_destroy(SLL *s) {
    if (s->size == 0) {
        puts("아무것도 없다!");
    }
    else {
        Node* select = s->head;
        for (int i = 0; i < s->size; i++) {
            s->head = select->next;
            select->data = 0;
            free(select);
            select = s->head;
        }
    }
    s->size = 0;
    return;
}
void SLL_printNodeAt(SLL *s, int index) {
    if (s->size == 0) {
        puts("노드에 아무값도 들어가있지 않습니다");
    }
    else if (index < 0) {
        puts("인덱스가 음수입니다");
    }
    else if (s->size - 1 < index) {
        puts("올바르지 않은 인덱스입니다");
    }
    else {
        Node* select = s->head;
        for (int i = 0; i < index; i++) {
            select = select->next;
        }
        printf("data : %d", select->data);
        putchar('\n');
    }
}
void SLL_printNodeAll(SLL * s) {
    Node* select = s->head;
    if (s->size == 0) {
        puts("아무것도 없다, 이자슥아!");
    }
    else {
        printf("list-> ");
        for (int i = 0; i < s->size; i++) {
            printf("%d ", select->data);
            select = select->next;
        }
        putchar('\n');
    }
    return;
}
Data SLL_returnNodeAt(SLL * s,int index) {
    if (s->size == 0) {
        puts("노드에 아무값도 들어가있지 않습니다");
        return -1;
    }
    else if (index < 0) {
        puts("인덱스가 음수입니다");
        return -1;
    }
    else if (s->size - 1 < index) {
        puts("올바르지 않은 인덱스입니다");
        return -1;
    }
    else {
        Node* select = s->head;
        for (int i = 0; i < index; i++) {
            select = select->next;
        }
        return select->data;
    }
}
Data* SLL_returnNodeAll(SLL *s) {
    Node* select = s->head;
    Data* r_data = (Data*)malloc(sizeof(Data) * s->size);
    for (int i = 0; i < s->size; i++) {
        *(r_data + i) = select->data;
        select = select->next;
    }
    return r_data;
}
int SLL_findElement(SLL* s, Data d) {
    Node* select = s->head;
    for (int i = 0; i < s->size;i++) {
        if (select->data == d) {
            return i;
        }
        else {
            select = select->next;
        }
    }
    return -1;
}
int SLL_ElementCount(SLL* s, Data d) {
    int count = 0;
    Node* select = s->head;
    for (int i = 0; i < s->size; i++) {
        if (select->data == d) {
            count++;
        }
        else {
            select = select->next;
        }
    }
    return count;
}
int main(void) {
    SLL* s = SLL_List_Init();
    for (int i = 0; i < 4; i++) {
        SLL_addNodeLast(s, i);
    }
    SLL_addNodeAt(s, 13, 0);
    SLL_addNodeFirst(s, 14);
    printf("size = %d\n", s->size);
    SLL_printNodeAll(s);
    int n = s->size;
    SLL_removeNodeFirst(s);
    printf("size = %d\n", s->size);
    SLL_printNodeAll(s);
    SLL_printNodeAt(s, 0);
    printf("사용자 출력: %d\n", SLL_returnNodeAt(s, 0));
    Data* data = SLL_returnNodeAll(s);
    printf("returnAll : ");
    for (int i = 0; i < _msize(data) / sizeof(Data); i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');
    puts("-------------------------------------------------------------");
    SLL_destroy(s);
    SLL_addNodeLast(s, 10101);
    SLL_printNodeAll(s);
    puts("-------------------------------------------------------------");
    SLL_destroy(s);
    for (int i = 0; i < 5; i++) {
        SLL_addNodeLast(s, i);
    }
    printf("index : %d\n", SLL_findElement(s, 5));
    puts("-------------------------------------------------------------");
    SLL_destroy(s);
    for (int i = 0; i < 5; i++) {
        SLL_addNodeLast(s, 3);
    }
    printf("index count : %d\n", SLL_ElementCount(s, 3));
    puts("-------------------------------------------------------------");
    SLL_destroy(s);
    SLL_removeNodeFirst(s);
    for (int i = 0; i < 5; i++) {
        SLL_addNodeLast(s, i);
    }
    SLL_printNodeAll(s);
    SLL_removeNodeFirst(s);
    SLL_printNodeAll(s);
	return 0;
}
