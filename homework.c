#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
 
int rt;

typedef struct arr{
	int data;
	struct arr *link;
}arr;

typedef struct {
   arr * head;
}linkedList_h;

void gotoxy(int x,int y);

void size(void);
void size2(void);

void use(void);

linkedList_h *createLinkedList_h(void);
void freeLinkedList_h(linkedList_h* L);
void printList(linkedList_h *L);
void insertNode( linkedList_h *L, int *x);
arr *searchNode(linkedList_h *L, int *x);
arr *deleteNode(linkedList_h *L, int *x);


int main(void){
	system("mode con cols=100 lines=40");
	size(); 
	linkedList_h * L;
	arr * p;
	int i, n; 
	use();
	size2();
	gotoxy(0,1);
	L = createLinkedList_h();
	while (true)
	{
		printf("�ṫ���� �����Ͻðڽ��ϱ�?\n��"); 
		i=getche();
		i-=48;
		printf("\n");
		if('A'<=i){
			printf("����� �����Դϴ�. �ٽ� �Է��� �ּ���.\n");
		}
		switch(i)
		{
			case 1:
				printf("����ڸ� �Է����ּ���.\n��");
				scanf("%d", &n);
				insertNode(L, &n);
				break;
			case 2:
				printf("��ã���� �����͸� �Է����ּ���.\n��");
				scanf("%d", &n);
				searchNode(L, &n);
				if(rt==-1)
					printf("�Ḯ��Ʈ�� ������ϴ�.\n");
				else if(rt)
					printf("��%d��°�� �����մϴ�.\n",rt);
				else if(rt==0)
					printf("��ã���ô� �����Ͱ� �����ϴ�.\n");
				break;
			case 3:
				printf("������� �����͸� �Է��ϼ���.\n��");
				scanf("%d", &n);
				deleteNode(L, &n);
				if(rt==1)
					printf("������߽��ϴ�.\n",rt);
				else if(rt==0)
					printf("��ã���ô� �����Ͱ� �����ϴ�.\n");
				else
					printf("�Ḯ��Ʈ�� ������ϴ�.\n");
				break;
			case 4:
				printList( L );
				break; 
			case 9:
				system("cls");
				size2();
				gotoxy(0,1);
				break;
			case 0:
				printList( L );
				freeLinkedList_h(L);
				printf("��������Ʈ�� �����մϴ�.\n"); 
				return 0;
			default:
				printf("����� �����Դϴ�. �ٽ� �Է��� �ּ���.\n");
				break; 
		}
	}
}

void gotoxy(int x,int y) {  
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void size(void){
	int i;
	gotoxy(0,0);
	printf("���������������������������������������������������");
	for (i=1;i<39;i++){
		gotoxy(0,i);
		printf("��");
		gotoxy(98,i);
		printf("��");
	}
	gotoxy(0,39);
	printf("���������������������������������������������������");

}
void size2(void){
	int i;
	gotoxy(0,0);
	printf("���������������������������������������������������");
	for (i=1;i<40;i++){
		gotoxy(0,i);
		printf("��");
	}
	
}

void use(void){
	SetConsoleTitle("���� �˻� ���α׷� 1410���ֿ� 1417���翵"); 
	gotoxy(40,5); 
	printf("����");
	printf("\n\n\n\t\t\t\t1.���� �Է�");
	printf("\n\t\t\t\t2.���� �˻�");
	printf("\n\t\t\t\t3.���� ����");
	printf("\n\t\t\t\t4.������ ���");
	printf("\n\t\t\t\t9.ȭ�� �ʱ�ȭ");
	printf("\n\t\t\t\t0.������ ��� �� ����");
	printf("\n\n\n\t\t\t\t����Ͻ÷��� �ƹ�Ű�� �����ּ���...");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t�ذ� ���ڸ� �Է��ϰ� ���͸� �����ּ���");
	getch(); 
	system("cls");
	SetConsoleTitle("1.���� �Է�2.���� �˻�3.���� ����4.������ ���9.ȭ�� �ʱ�ȭ0.������ ��� �� ����");
}

linkedList_h *createLinkedList_h(void){
   linkedList_h* L;
   L = (linkedList_h*)malloc(sizeof(linkedList_h));
   L -> head = NULL;
   return L;
}

void freeLinkedList_h(linkedList_h* L){
   arr* p;
   while(L -> head != NULL){
      p = L -> head;
      L -> head = L -> head -> link;
      free(p);
      p = NULL;
   }
}

void printList(linkedList_h *L){
   arr* p;
   p = L -> head;
   if(p == NULL) {
		printf("�ᵥ���Ͱ� ������ϴ�.\n");
		return;
   }
   printf("������ �����ʹ� {");
   while (p != NULL){
      printf("%d", p -> data);
      p = p -> link;
      if (p != NULL) printf(",");
   }
	printf("}�Դϴ�.\n");
}

void insertNode( linkedList_h *L, int *x){
   arr *newNode;
   arr *temp;
   newNode = (arr*)malloc(sizeof(arr));
   newNode -> data = *x;
   newNode -> link = NULL;
   if(L -> head == NULL){
      L -> head = newNode;
      return;
   }
   temp = L -> head;
   while (temp -> link != NULL) temp = temp -> link;
   temp -> link = newNode;
}   

arr *searchNode(linkedList_h *L, int *x){
	arr *temp;
	rt=1;
	temp = L -> head;
	if(temp == NULL){
		rt = -1;
		return;
	}
	while (temp != NULL){
    	if (temp -> data ==*x){ 
			return;
		}
    	else{
    		rt++;
			temp = temp -> link;
		}
	}
	rt = 0;
}
arr *deleteNode(linkedList_h *L, int *x){
	arr *temp;
	arr *pre;
	rt=1;
	pre = L -> head;
	if(L -> head==NULL){
		rt = 2;
		return; 
	}
	temp = L -> head -> link;
	pre = L -> head;
	if(pre -> data == *x){
		L -> head = pre -> link;
		return;
	}
	while (temp != NULL){
    	if (temp -> data ==*x){ 
    		pre -> link = temp ->link;
    		free(temp);
			return;
		}
    	else{
    		pre = pre -> link;
			temp = temp -> link;
		}
	}
	rt = 0;
}
