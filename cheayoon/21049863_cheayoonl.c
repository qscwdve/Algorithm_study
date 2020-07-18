#include<stdio.h>
#pragma warning (disable:4996)



int main() {

	//문자열 받음
	char str[100];
	int i = 0;
	int j = 0;

	scanf("%s", str);	// 1 ~ 100 사이의 수.
	
	while (1) {
		

		//만약 문자열 끝에 오면 종료
		if (str[i] == 0) break;

		
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'z') {
		
			if (str[i + 1] == '=') {
				i++;

			}
			
		}

		if (str[i] == 'c' || str[i] == 'd') {
			if (str[i + 1] == '-') {
				i++;
			}
		}

		if (str[i] == 'l' || str[i] == 'n') {
			if (str[i + 1] == 'j') {
				i++;
			}
		}

		if (str[i] == 'd') {
			if (str[i + 1] == 'z') {
				if (str[i + 2] == '=') {
					i++;
					i++;
				}
			}
		}
		


		j++;
		i++;
	}


	printf("%d", j);
	


	return 0;
}

