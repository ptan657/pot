#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pow(int b) {
	for (int k = 0; k <= 60; k++) {
		printf("-");
	}
	up:
	printf("\n");
	printf("강화 상태를 입력하시오.: ");
	scanf("%d", &b);
	if (b >= 25 || b < 0) {
		goto up;
	}
	return b;
}

double star(int c, double d);
double soccess(int b, double d, int n);
double soccess_1(int b, double d, int n, int m);
double soccess_2(int b, double d, int n);
double soccess_3(int b, double d, int n, int m);

void main() {
	srand((unsigned)time(NULL)*getpid()*getpid());
	int b = 0,h=0;
	char ga;
	start:
	int a = pow(b);
	double d = rand() / (double)RAND_MAX * 100;
	
	a = star(a, d);
	if (a == 0) {
		goto start;
	}
	printf("\n현재 강화상태는 %d강입니다", a);
back:
	printf("\n");
	for (int k = 0; k <= 60; k++) {
		printf("-");
	}
	printf("\n강화를 계속 진행합니까? (숫자면 진행, 문자면 종료) : ");
	getchar();
	scanf("%c", &ga);

		if (ga >= 'a' && ga <= 'z') {
			printf("\n새 장비를 강화하겠습니까?(y면 새 장비 강화) : ");
			getchar();
			scanf("%c", &h);
			if (h == 'y' || h == 'Y') {
				goto start;
			}
			exit(0);
		}
		else {
			d = rand() / (double)RAND_MAX * 100;
			printf("\n현재 강화상태는 %d강입니다\n", a);
			a = star(a, d);
			goto back;
		}
}
double star(int b, double d) {
	int a,h=0;
	if (b >= 25||b<0) {
		printf("존재하지 않는 강화 수치입니다.\n");
		printf("새 장비를 강화하겠습니까?(y면 새 장비 강화) : ");	
		getchar();
		scanf("%c", &h);
		if (h == 'y' || h == 'Y') {
			return 0;
		}

		else exit(0);
	}
	switch (b) {
	case 0:
		a = soccess(b, d, 5);
		return a;
		break;
	case 1:
		a = soccess(b, d, 10);
		return a;
		break;
	case 2:
		a = soccess(b, d, 15);
		return a;
		break;
	case 3:
		a = soccess(b, d, 15);
		return a;
		break;
	case 4:
		a = soccess(b, d, 20);
		return a;
		break;
	case 5:
		a = soccess(b, d, 25);
		return a;
		break;
	case 6:
		a = soccess(b, d, 30);
		return a;
		break;
	case 7:
		a = soccess(b, d, 35);
		return a;
		break;
	case 8:
		a = soccess(b, d, 40);
		return a;
		break;
	case 9:
		a = soccess(b, d, 45);
		return a;
		break;
	case 10:
		a = soccess(b, d, 50);
		return a;
		break;
	case 11:
		a = soccess_2(b, d, 55);
		return a;
		break;
	case 12:
		a = soccess_1(b, d, 0.6, 60);
		return a;
		break;
	case 13:
		a = soccess_1(b, d, 1.3, 65);
		return a;
		break;
	case 14:
		a = soccess_1(b, d, 1.4, 70);
		return a;
		break;
	case 15:
		a = soccess_3(b, d, 2.1, 70);
		return a;
		break;
	case 16:
		a = soccess_1(b, d, 2.1, 70);
		return a;
		break;
	case 17:
		a = soccess_1(b, d, 2.1, 70);
		return a;
		break;
	case 18:
		a = soccess_1(b, d, 2.8, 70);
		return a;
		break;
	case 19:
		a = soccess_1(b, d, 2.8, 70);
		return a;
		break;
	case 20:
		a = soccess_3(b, d, 7, 70);
		return a;
		break;
	case 21:
		a = soccess_1(b, d, 7, 70);
		return a;
		break;
	case 22:
		a = soccess_1(b, d, 19.4, 97);
		return a;
		break;
	case 23:
		a = soccess_1(b, d, 29.4, 98);
		return a;
		break;
	case 24:
		a = soccess_1(b, d, 39.6, 99);
		return a;
		break;
	}
}
double soccess(int b, double d, int n) {//10성까지
	int e;
	printf("스타캐치를 합니까?(0이면 해제) : \n");
	getchar();
	scanf("%d", &e);
	if (e == 0) {
		printf("스타캐치 해제\n");
	}
	else printf("스타캐치 체크\n");

	if (e != 0) {
		d = d * 1.05;
	}
	if (d < n) {
		printf("강화 실패");
	}
	else {
		printf("강화 성공");
		b++;
	}
	return b;
}

double soccess_1(int b, double d, int n, int m) {//하락 존재, 파괴 존재
	int e = 0;
	printf("스타캐치를 합니까?(0이면 해제) :");
	getchar();
	scanf("%d", &e);
	if (e == 0) {
		printf("스타캐치 해제\n");
	}
	else printf("스타캐치 체크\n");

	if (e != 0) {
		d = d * 1.05;
	}
	if (d < n) {
		printf("장비 파괴");
		b = 12;
	}
	else if (d < m) {
		printf("강화 실패");
		b--;
	}
	else {
		printf("강화 성공");
		b++;
	}
	return b;

}
double soccess_2(int b, double d, int n) {// 11성 파괴 없음
	int e = 0;
	printf("스타캐치를 진행합니까?");
	getchar();
	scanf("%d", &e);
	if (e == 0) {
		printf("스타캐치 해제\n");
	}
	else printf("스타캐치 체크\n");

	if (e != 0) {
		d = d * 1.05;
	}
	if (d < n) {
		printf("강화 실패");
		b--;
	}
	else {
		printf("강화 성공");
		b++;
	}
	return b;
}

double soccess_3(int b, double d, int n, int m) {//15,20성 하락 없음
	int e;
	printf("스타캐치를 합니까?(0이면 해제) :");
	getchar();
	scanf("%d", &e);
	if (e == 0) {
		printf("스타캐치 해제\n");
	}
	else printf("스타캐치 체크.\n");

	if (e != 0) {
		d = d * 1.05;
	}
	if (d < n) {
		printf("장비 파괴");
		b = 12;
	}
	else if (d < m) {
		printf("강화 실패");
		b;
	}
	else {
		printf("강화 성공");
		b++;
	}
	return b;
}
