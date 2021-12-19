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
		printf("■무엇을 실행하시겠습니까?\n■"); 
		i=getche();
		i-=48;
		printf("\n");
		if('A'<=i){
			printf("■없는 실행입니다. 다시 입력해 주세요.\n");
		}
		switch(i)
		{
			case 1:
				printf("■숫자를 입력해주세요.\n■");
				scanf("%d", &n);
				insertNode(L, &n);
				break;
			case 2:
				printf("■찾으실 데이터를 입력해주세요.\n■");
				scanf("%d", &n);
				searchNode(L, &n);
				if(rt==-1)
					printf("■리스트가 비었습니다.\n");
				else if(rt)
					printf("■%d번째에 존재합니다.\n",rt);
				else if(rt==0)
					printf("■찾으시는 데이터가 없습니다.\n");
				break;
			case 3:
				printf("■지우실 데이터를 입력하세요.\n■");
				scanf("%d", &n);
				deleteNode(L, &n);
				if(rt==1)
					printf("■삭제했습니다.\n",rt);
				else if(rt==0)
					printf("■찾으시는 데이터가 없습니다.\n");
				else
					printf("■리스트가 비었습니다.\n");
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
				printf("■프로젝트를 종료합니다.\n"); 
				return 0;
			default:
				printf("■없는 실행입니다. 다시 입력해 주세요.\n");
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
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	for (i=1;i<39;i++){
		gotoxy(0,i);
		printf("■");
		gotoxy(98,i);
		printf("■");
	}
	gotoxy(0,39);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

}
void size2(void){
	int i;
	gotoxy(0,0);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	for (i=1;i<40;i++){
		gotoxy(0,i);
		printf("■");
	}
	
}

void use(void){
	SetConsoleTitle("숫자 검색 프로그램 1410송주영 1417최재영"); 
	gotoxy(40,5); 
	printf("사용법");
	printf("\n\n\n\t\t\t\t1.숫자 입력");
	printf("\n\t\t\t\t2.숫자 검색");
	printf("\n\t\t\t\t3.숫자 삭제");
	printf("\n\t\t\t\t4.데이터 출력");
	printf("\n\t\t\t\t9.화면 초기화");
	printf("\n\t\t\t\t0.데이터 출력 후 종료");
	printf("\n\n\n\t\t\t\t사용하시려면 아무키나 눌러주세요...");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t※각 숫자를 입력하고 엔터를 눌러주세요");
	getch(); 
	system("cls");
	SetConsoleTitle("1.숫자 입력2.숫자 검색3.숫자 삭제4.데이터 출력9.화면 초기화0.데이터 출력 후 종료");
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
		printf("■데이터가 비었습니다.\n");
		return;
   }
   printf("■현재 데이터는 {");
   while (p != NULL){
      printf("%d", p -> data);
      p = p -> link;
      if (p != NULL) printf(",");
   }
	printf("}입니다.\n");
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
