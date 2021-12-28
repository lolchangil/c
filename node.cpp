#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node * p_next;
}NODE;
void DeleteNode(NODE** pp_head, NODE** pp_tail);
void AddData(NODE** pp_head, NODE** pp_tail, int data);
void clearBuffer(void);
int strlen(char* str);
int main(void) {
	NODE* p_head=NULL;
	NODE* p_tail=NULL;
	char buf[10];
	while (1) {
		printf("숫자를 입력하세요: ");
		fgets(buf, sizeof(buf), stdin);
		if (buf[0] == 'q') break;
		if (buf[strlen(buf) - 1] == '\n') {
			buf[strlen(buf) - 1] = '\0';
		}
		else {
			clearBuffer();
		}
		AddData(&p_head, &p_tail, atoi(buf));
	}
	NODE * p = p_head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->p_next;
	}
	putc('\n', stdout);
	DeleteNode(&p_head, &p_tail);
}
void AddData(NODE** pp_head, NODE** pp_tail, int data) {
	if (*pp_head != NULL) {
		(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE));
		*pp_tail = (*pp_tail)->p_next;
	}
	else {
		*pp_head = (NODE*)malloc(sizeof(NODE));
		*pp_tail = *pp_head;
	}
	(*pp_tail)->data = data;
	(*pp_tail)->p_next = NULL;
}
void DeleteNode(NODE** pp_head, NODE** pp_tail) {
	NODE* p = *pp_head;
	while (*pp_head != NULL) {
		p = (*pp_head)->p_next;
		free(*pp_head);
		*pp_head = p;
	}
	*pp_tail = *pp_head;
}
int strlen(char* str) {
	int i = 0;
	while (*(str + i) != '\0') {
		i++;
	}
	return i;
}
void clearBuffer(void) {
	while (getchar() != '\n');
}