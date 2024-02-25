#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
long long result1 = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0;
long double result2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
int remainder_result1 = 0, remainder_result2 = 0, remainder_result3 = 0, remainder_result4 = 0, remainder_result5 = 0, remainder_result6 = 0;
int remainder_num1 = 0, remainder_num2 = 0, remainder_num3 = 0, remainder_num4 = 0;
int calculationType = 0;
char op = 0;
enum {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VIOLET,
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
void printWelcomeMessage();
int getIntInput(const char* message);
long long getInt64Input(const char* message);
long double getDoubleInput(const char* message);
char getCharInput(const char* message);
void printCalculationResult(char op, long long result);
void printErrorMessage(const char* message);
void clearBuffer();
void printWelcomeMessage() {
    system("color 7");
    SetConsoleTitle(TEXT("C Language arithmetic calculator"));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
    printf("��Ģ���� ���� �Դϴ�\n");
    printf("���������� '1'��, �Ǽ������� '2'��,������������ '3'�� �Է����ּ���\n(������ ������ ������ �����մϴ�)\n������ �� �� �Է� �ؾ߸� �ϴ� ���ڴ� �� 4���Դϴ�");
    FILE* prrecord = fopen("calculation_record.txt", "r");
    printf("\n������� 10�� ������ ����˴ϴ�\n------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    Sleep(100);
}
long long clearNumVariable() {
    result1 = NULL, n1 = NULL, n2 = NULL, n3 = NULL, n4 = NULL;
    return result1, n1, n2, n3, n4;
}
long double clearFloatVariable() {
    result2 = NULL, f1 = NULL, f2 = NULL, f3 = NULL, f4 = NULL;
    return result2, f1, f2, f3, f4;
}
int clearRemainderVariable() {
    remainder_result1 = NULL, remainder_result2 = NULL, remainder_result3 = NULL, remainder_result4 = NULL, remainder_result5 = NULL, remainder_result6 = NULL;
    remainder_num1 = NULL, remainder_num2 = NULL, remainder_num3 = NULL, remainder_num4 = NULL;
    return remainder_result1, remainder_result2, remainder_result3, remainder_result4, remainder_result5, remainder_result6, remainder_num1, remainder_num2, remainder_num3, remainder_num4;
}
char clearOpVariable() {
    op = NULL;
    return op;
}
int clearcalculationType() {
    calculationType = NULL;
    return calculationType;
}
int getIntInput(const char* message) {
    int input;
    printf("%s", message);
    scanf("%d", &input);
    clearBuffer();
    return input;
}
long long getInt64Input(const char* message) {
    long long input;
    printf("%s", message);
    scanf("%lld", &input);
    clearBuffer();
    return input;
}
long long printResultNumber(char op,long long result1) {
    printf("%d", result1);
    return result1;
}
long double getDoubleInput(const char* message) {
    long double input;
    printf("%s", message);
    scanf("%lf", &input);
    clearBuffer();
    return input;
}
char getCharInput(const char* message) {
    char input;
    printf("%s", message);
    scanf(" %c", &input);
    clearBuffer();
    return input;
}
void printCalculationResult(char op, long long result) {
    printf("%d %c %d %c %d %c %d = %lld\n", n1, op, n2, op, n3, op, n4, result);
}
void printErrorMessage(const char* message) {
    printf("** ����: %s\n", message);
}
void clearBuffer() {
    while (getchar() != '\n');
}
int main(){
    printWelcomeMessage();
    while (true) {
        calculationType = getIntInput("��� ������ �����ϼ��� (1: ����, 2: �Ǽ�, 3: ������): ");
        if (calculationType < 1 || calculationType > 3) {
            printErrorMessage("�߸��� ��� ������ �����߽��ϴ�.");
            continue;
        }
        else {
            switch (calculationType) {
            case 1:
                n1 = getInt64Input("ù ��° ���ڸ� �Է��ϼ���: ");
                n2 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");
                n3 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");
                n4 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");
                op = getCharInput("�����ڸ� �Է��ϼ��� (+, -, *, /): ");
                switch (op) {
                case '+':
                    result1 = n1 + n2 + n3 + n4;
                    printCalculationResult;
                    printResultNumber;
                    printf("%d %c %d %c %d %c %d = %lld\n", n1, op, n2, op, n3, op, n4, result1);
                    clearNumVariable;
                    clearOpVariable;
                    clearcalculationType;
                    continue;
                case '-':
                    result1 = n1 - n2 - n3 - n4;
                    printCalculationResult;
                    printResultNumber;
                    printf("%d %c %d %c %d %c %d = %lld\n", n1, op, n2, op, n3, op, n4, result1);
                    clearNumVariable;
                    clearOpVariable;
                    clearcalculationType;
                    continue;
                case '*':
                    result1 = n1 * n2 * n3 * n4;
                    printCalculationResult;
                    printResultNumber;
                    printf("%d %c %d %c %d %c %d = %lld\n", n1, op, n2, op, n3, op, n4, result1);
                    clearNumVariable;
                    clearOpVariable;
                    clearcalculationType;
                    continue;
                case '/':
                    if (n2 == 0 || n3 == 0 || n4 == 0) {
                        printErrorMessage("0���� ���� �� �����ϴ�.");
                        continue;
                    }
                    result1 = n1 / n2 / n3 / n4;
                    printCalculationResult;
                    printResultNumber;
                    printf("%d %c %d %c %d %c %d = %lld\n", n1, op, n2, op, n3, op, n4, result1);
                    clearNumVariable;
                    clearOpVariable;
                    clearcalculationType;
                    continue;
                default:
                    printErrorMessage("�߸��� �����ڸ� �Է��߽��ϴ�.");
                    continue;
                    printCalculationResult(op, result1);
                    break;
                }
            case 2:
                f1 = getDoubleInput("ù ��° ���ڸ� �Է��ϼ���: ");
                f2 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
                f3 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
                f4 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
                op = getCharInput("�����ڸ� �Է��ϼ��� (+, -, *, /): ");
                switch (op) {
                case '+':
                    result2 = f1 + f2 + f3 + f4;
                    printCalculationResult;
                    printf("%d %c %d %c %d %c %d = %lld\n", n1, op, n2, op, n3, op, n4, result1);
                    clearFloatVariable;
                    clearOpVariable;
                    clearcalculationType;
                    continue;
                case '-':
                    result2 = f1 - f2 - f3 - f4;
                    break;
                case '*':
                    result2 = f1 * f2 * f3 * f4;
                    break;
                case '/':
                    if (f2 == 0.0 || f3 == 0.0 || f4 == 0.0) {
                        printErrorMessage("0���� ���� �� �����ϴ�.");
                        continue;
                    }
                    result2 = f1 / f2 / f3 / f4;
                    break;
                default:
                    printErrorMessage("�߸��� �����ڸ� �Է��߽��ϴ�.");
                    continue;
                    printCalculationResult(op, result2);
                    break;
                }
            case 3:
                remainder_num1 = getIntInput("ù ��° ���ڸ� �Է��ϼ���: ");
                remainder_num2 = getIntInput("�� ��° ���ڸ� �Է��ϼ���: ");
                remainder_num3 = getIntInput("�� ��° ���ڸ� �Է��ϼ���: ");
                remainder_num4 = getIntInput("�� ��° ���ڸ� �Է��ϼ���: ");
                op = getCharInput("�����ڸ� �Է��ϼ��� (%): ");
                remainder_result1 = n1 % n2;
                remainder_result2 = n1 % n3;
                remainder_result3 = n1 % n4;
                remainder_result4 = n2 % n3;
                remainder_result5 = n2 % n4;
                remainder_result6 = n3 % n4;
                printf("%d %% %d = %d\n", n1, n2, remainder_result1);
                printf("%d %% %d = %d\n", n1, n3, remainder_result2);
                printf("%d %% %d = %d\n", n1, n4, remainder_result3);
                printf("%d %% %d = %d\n", n2, n3, remainder_result4);
                printf("%d %% %d = %d\n", n2, n4, remainder_result5);
                printf("%d %% %d = %d\n", n3, n4, remainder_result6);
                break;
            }
        }
    }
}