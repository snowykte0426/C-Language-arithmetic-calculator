#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
unsigned short a1 = 0, gal = 0;
FILE* prrecord = fopen("calculation_record.txt", "w");
static short a1null()
{
	a1 = NULL;
	return a1;
}
static int quitpro()
{
	fclose(prrecord);
	Sleep(100);
    exit(0);
}
int main() 
{

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
	system("mode con:cols=70 lines=10");
	while (true){
	    reprograms:
		system("color 7");
		SetConsoleTitle(TEXT("C Language arithmetic calculator"));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
		printf("��Ģ���� ���� �Դϴ�\n");
		printf("���������� '1'��, �Ǽ������� '2'��,������������ '3'�� �Է����ּ���\n(������ ������ ������ �����մϴ�)\n������ �� �� �Է� �ؾ߸� �ϴ� ���ڴ� �� 4���Դϴ�");
		printf("\n������� 10�� ������ ����˴ϴ�\n------------------\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		Sleep(100);
		int intandflart = NULL, brk = NULL;
		scanf("%d", &intandflart);
		long long n1 = NULL, n2 = NULL, n3 = NULL, n4 = NULL, finn = NULL;
		long double f1 = NULL, f2 = NULL, f3 = NULL, f4 = NULL, finf = NULL;
		while (intandflart == 1)
		{

			printf("������ �� ���ڸ� �Է����ּ���\n4��\nex)10 20 0 0\n");
			scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
			printf("�����ڸ� �Է����ּ���\n(+ - * /)\n");
		    short a1null();
		    atreturn:
			scanf("%c", &a1);
			if (a1 == '+') {
				finn = n1 + n2 + n3 + n4;
				printf("������� '%d'�Դϴ�", finn);
				fputs("%d\n", prrecord);
				finn = NULL;
				printf("\n����Ͻðڽ��ϱ�?(Y/N)\n");
				scanf("%c", &brk);
				if (brk == 'Y' || brk == 'y')
				gal = a1null();
				goto reprograms;
				if (brk == 'N' || brk == 'n') {
					Sleep(1000);
					printf("���α׷��� �����մϴ�\n");
					gal = quitpro();
				}
				else {
					printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'N'�� �Է��Ѱɷ� �����ϰ� ���α׷��� �����մϴ�\n");
					exit(0);
				}
			}
			if (a1 == '-') {
				finn = n1 - n2 - n3 - n4;
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
			}
			if (a1 == '*') {
				finn = n1 * n2 * n3 * n4;
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
			}
			if (a1 == '/') {
				finn = n1 / n2 / n3 / n4;
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
			}
			else {
				printf("�߸��� �����ڸ� �Է��ϼ̽��ϴ�\n�ٽ� �Է����ּ���(+ - * /)\n");
				short a1null();
				goto atreturn;
			}
			return 0;
		}
	}
}