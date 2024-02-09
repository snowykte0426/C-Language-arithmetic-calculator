#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
int main(){
	enum {              //색상값들
		BLACK,
		DARK_BLUE,
		DARK_GREEN,
		DARK_SKYBLUE,
		DARK_RED,
		DARK_VOILET,
		DAKR_YELLOW,
		GRAY,
		DARK_GRAY,
		BLUE,
		GREEN,
		SKYBLUE,
		RED,
		VIOLET,
		YELLOW,
		WHITE,
	};
	system("color 7");
	system("mode con:cols=70 lines=10");
	SetConsoleTitle(TEXT("C Language arithmetic calculator"));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
	printf("사칙연산 계산기 입니다\n");
    reprograms:
	printf("정수연산은 '1'을, 실수연산은 '2'를,나머지연산은 '3'을 입력해주세요\n(나머지 연산은 정수만 지원합니다)\n연산을 할 때 입력 해야만 하는 숫자는 총 4개입니다\n------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	Sleep(100);
	char intandflart = NULL, brk = NULL;
	char a1 = NULL;
	scanf("%d", &intandflart);
	long long n1 = NULL, n2 = NULL, n3 = NULL, n4 = NULL, finn = NULL;
	long double f1 = NULL, f2 = NULL, f3 = NULL, f4 = NULL, finf = NULL;
	while (intandflart == 1)
	{
		printf("연산을 할 숫자를 입력해주세요\n4개\nex)10 20 0 0\n");
		scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
		printf("연산자를 입력해주세요\n(+ - * /)\n");
		atreturn:
		scanf("%c", &a1);
		switch (a1) {
		case '+':
			finn = n1 + n2 + n3 + n4;
			printf("계산결과는 '%d'입니다", finn);
			finn = NULL;
			printf("\n계속하시겠습니까?(Y/N)\n");
			scanf("%c", &brk);
			if (brk == 'Y' || brk == 'y')
				goto reprograms;
			if (brk == 'N' || brk == 'n') {
				Sleep(1000);
				printf("프로그램을 종료합니다\n");
				exit(0);
			}
			else {
				printf("잘못된 값을 입력하셨습니다\n'N'을 입력한걸로 간주하고 프로그램을 종료합니다\n");
				exit(0);
			}
		case '-':
			finn = n1 - n2 - n3 - n4;
			printf("계산결과는 %d 입니다", finn);
			finn = NULL;
			printf("\n계속하시겠습니까?(Y/N)\n");
			scanf("%c", &brk);
			if (brk == 'Y' || brk == 'y') {
				intandflart = NULL;
				goto reprograms;
			}
			else if (brk == 'N' || brk == 'n') {
				Sleep(1000);
				printf("프로그램을 종료합니다\n");
				exit(0);
			}
			else {
				printf("잘못된 값을 입력하셨습니다\n'N'을 입력한걸로 간주하고 프로그램을 종료합니다\n");
				exit(0);
			}
		case '*':
			finn = n1 * n2 * n3 * n4;
			printf("계산결과는 %d 입니다", finn);
			finn = NULL;
			printf("\n계속하시겠습니까?(Y/N)\n");
			scanf("%c", &brk);
			if (brk == 'Y' || brk == 'y')
				goto reprograms;
			else if (brk == 'N' || brk == 'n') {
				Sleep(1000);
				printf("프로그램을 종료합니다\n");
				exit(0);
			}
			else {
				printf("잘못된 값을 입력하셨습니다\n'N'을 입력한걸로 간주하고 프로그램을 종료합니다\n");
				exit(0);
			}
		case '/':
			finn = n1 / n2 / n3 / n4;
			printf("계산결과는 %d 입니다", finn);
			finn = NULL;
			printf("\n계속하시겠습니까?(Y/N)\n");
			scanf("%c", &brk);
			if (brk == 'Y' || brk == 'y')
				goto reprograms;
			else if (brk == 'N' || brk == 'n') {
				Sleep(1000);
				printf("프로그램을 종료합니다\n");
				exit(0);
			}
			else {
				printf("잘못된 값을 입력하셨습니다\n'N'을 입력한걸로 간주하고 프로그램을 종료합니다\n");
				exit(0);
			}
		default:
			printf("연산자를 잘못 입력했습니다");
			goto atreturn;
		}
		
	}
	return 0;
}