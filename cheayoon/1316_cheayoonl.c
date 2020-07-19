#include<stdio.h>
#pragma warning (disable:4996)



int main() {

	int num;
	int set = 0;
	char str[100];
	scanf("%d", &num);	//단어의 개수

	for (int i = 0; i < num; i++) {
		scanf("%s", str);


		for (int j = 0; j < 100; j++) {	//단어들 한글자씩을 보면서 확인


			if (str[j] != str[j - 1]) {	//현재 글자가 바로전 글자와 다르다면



				for (int h = 0; h < j ; h++) {	//다음 글자들과 비교하며 이전에 쓰인적이 없다면

					if (str[j] != str[j-1] && str[j] == str[h]) {	//만약 비교 글자중 같은 글자가 있다면 그룹단어아님.

						
						h = 100;
						j = 100;
						break;
						
				
					}
					
					

				}
			}
			if (str[j + 1] == 0) {	//마지막까지 점검을 다 했을때..
				set++;
				j = 100;
				break;
			}
		}





		
	}
	printf("%d", set);	//그룹단어



	return 0;
}

