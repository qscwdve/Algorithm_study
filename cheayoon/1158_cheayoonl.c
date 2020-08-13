#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

struct NODE {             // 연결 리스트의 노드 구조체
	struct NODE *next;    // 다음 노드의 주소를 저장할 포인터
	int data;             // 데이터를 저장할 멤버
};

int main()
{
	struct NODE *head;    // 머리 노드 생성
	struct NODE *t = malloc(sizeof(struct NODE));	//노드 t 생성
	
	int n, k;
	scanf("%d %d", &n, &k);






	t->data = 1;
	head = t;

	for (int i = 2; i <= n; i++) {	//1부터 n까지 원형 리스트 만들어주기
		t->next = malloc(sizeof(struct NODE));
		t = t->next;
		t->data = i;
	}

	t->next = head;    // 마지막 t를 처음 h로 연결시켜준다.

	t = head;

	printf("<");
	while (t != t->next) {
		if (k == 1) {
			for (int p = 0; p < n - 1; p++) {
				printf("%d, ", t->data);

				t = t->next;
			}
			break;
		}
		else {

			for (int j = 1; j < k - 1; j++) {
				t = t->next;
			}

			printf("%d, ", t->next->data);

			struct NODE *s;	//제거
			s = t->next;
			t->next = t->next->next;

			free(s);	//메모리를 위해

			t = t->next;
		}
	}
	printf("%d", t->data);
	printf(">");


	return 0;
}
