#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
int main(){
	enum {              //���󰪵�
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
	printf("��Ģ���� ���� �Դϴ�\n");
    reprograms:
	printf("���������� '1'��, �Ǽ������� '2'��,������������ '3'�� �Է����ּ���\n(������ ������ ������ �����մϴ�)\n������ �� �� �Է� �ؾ߸� �ϴ� ���ڴ� �� 4���Դϴ�\n------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	Sleep(100);
	char intandflart = NULL, brk = NULL;
	char a1 = NULL;
	scanf("%d", &intandflart);
	long long n1 = NULL, n2 = NULL, n3 = NULL, n4 = NULL, finn = NULL;
	long double f1 = NULL, f2 = NULL, f3 = NULL, f4 = NULL, finf = NULL;
	while (intandflart == 1)
	{
		printf("������ �� ���ڸ� �Է����ּ���\n4��\nex)10 20 0 0\n");
		scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
		printf("�����ڸ� �Է����ּ���\n(+ - * /)\n");
		atreturn:
		scanf("%c", &a1);
		switch (a1) {
		case '+':
			finn = n1 + n2 + n3 + n4;
			printf("������� '%d'�Դϴ�", finn);
			finn = NULL;
			printf("\n����Ͻðڽ��ϱ�?(Y/N)\n");
			scanf("%c", &brk);
			if (brk == 'Y' || brk == 'y')
				goto reprograms;
			if (brk == 'N' || brk == 'n') {
				Sleep(1000);
				printf("���α׷��� �����մϴ�\n");
				exit(0);
			}
			else {
				printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'N'�� �Է��Ѱɷ� �����ϰ� ���α׷��� �����մϴ�\n");
				exit(0);
			}
		case '-':
			finn = n1 - n2 - n3 - n4;
			printf("������� %d �Դϴ�", finn);
			finn = NULL;
			printf("\n����Ͻðڽ��ϱ�?(Y/N)\n");
			scanf("%c", &brk);
			if (brk == 'Y' || brk == 'y') {
				intandflart = NULL;
				goto reprograms;
			}
			else if (brk == 'N' || brk == 'n') {
				Sleep(1000);
				printf("���α׷��� �����մϴ�\n");
				exit(0);
			}
			else {
				printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'N'�� �Է��Ѱɷ� �����ϰ� ���α׷��� �����մϴ�\n");
				exit(0);
			}
		case '*':
			finn = n1 * n2 * n3 * n4;
			printf("������� %d �Դϴ�", finn);
			finn = NULL;
			printf("\n����Ͻðڽ��ϱ�?(Y/N)\n");
			scanf("%c", &brk);
			if (brk == 'Y' || brk == 'y')
				goto reprograms;
			else if (brk == 'N' || brk == 'n') {
				Sleep(1000);
				printf("���α׷��� �����մϴ�\n");
				exit(0);
			}
			else {
				printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'N'�� �Է��Ѱɷ� �����ϰ� ���α׷��� �����մϴ�\n");
				exit(0);
			}
		case '/':
			finn = n1 / n2 / n3 / n4;
			printf("������� %d �Դϴ�", finn);
			finn = NULL;
			printf("\n����Ͻðڽ��ϱ�?(Y/N)\n");
			scanf("%c", &brk);
			if (brk == 'Y' || brk == 'y')
				goto reprograms;
			else if (brk == 'N' || brk == 'n') {
				Sleep(1000);
				printf("���α׷��� �����մϴ�\n");
				exit(0);
			}
			else {
				printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'N'�� �Է��Ѱɷ� �����ϰ� ���α׷��� �����մϴ�\n");
				exit(0);
			}
		default:
			printf("�����ڸ� �߸� �Է��߽��ϴ�");
			goto atreturn;
		}
		
	}
	return 0;
}