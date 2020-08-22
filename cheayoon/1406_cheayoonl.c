#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct NODE {             // 연결 리스트의 노드 구조체
	struct NODE *next;    // 다음 노드의 주소를 저장할 포인터
	struct NODE* prev;	//이전 노드의 주소를 저장할 포인터
	int data;             // 데이터를 저장할 멤버
};

int main()
{
	struct NODE *head = malloc(sizeof(struct NODE));    // 머리 노드 생성
	head->data;
	head->prev = head->next = NULL;
	struct NODE *cur = head;

	char t;		//첫 줄의 문자열
	while ((t = getchar()) != '\n') {	//줄바꿈 전 까지 실행
		struct NODE* newnode = malloc(sizeof(struct NODE));	//새로운 노드를 만들어서
		newnode->data = t;	//받아온 문자열을 데이터에 저장
		newnode->prev = cur;	//이전을 커서가 있는 부분에 연결
		newnode->next = NULL;	//다음을 NULL로 지정
		cur->next = newnode;	//커서가 있는 부분의 다음은 새로운 노드에 연결
		cur = newnode;
	}
	int n;	//입력할 명령어의 개수
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		char c;
		scanf(" %c", &c);
		switch (c) {

			//커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
		case 'L': {
			if (cur->prev) cur = cur->prev;	//커서가 가리키는 곳의 왼쪽으로 이동
			break;
		}

			//	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
		case 'D': {
			if (cur->next) cur = cur->next;	//커서가 가리키는 곳의 오른쪽으로 이동
			break;
		}

			//커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
			//삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
		case 'B': {
			if (cur->prev == NULL) continue;
			struct NODE* del = malloc(sizeof(struct NODE));
			del = cur;	//del노드에 cur노드를 대입시킨다.
			cur = del->prev;	//커서를 왼쪽으로 옮긴다.
			if (del->next) {
				cur->next = del->next;
				del->next->prev = cur;
				del->prev = NULL;
			}
			else { cur->next = NULL; }
			free(del);	//메모리를 해제한다. 메모리 낭비 방지를 위하여.
			break;
		}


			//$라는 문자를 커서 왼쪽에 추가함
		case 'P': {
			char tmp;
			scanf(" %c", &tmp);
			struct NODE* newnode = malloc(sizeof(struct NODE));	//새로운 노드 생성
			newnode->data = tmp;	//입력한 문자를 새로운 노드 데이터에 삽입.
			newnode->prev = cur;
			if (cur->next) {
				newnode->next = cur->next;
				cur->next->prev = newnode;
			}
			else {
				newnode->next = NULL;
			}
			cur->next = newnode;
			cur = cur->next;
			break;
		}
		}
	}
	head = head->next;
	while (head) {
		printf("%c", head->data);
		head = head->next;
	}
	return 0;
}
