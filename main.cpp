#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <fcntl.h>
#include <string.h>
#define MAX 1000
long long result1 = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0;
long double result2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
int remainder_result1 = 0, remainder_result2 = 0, remainder_result3 = 0, remainder_result4 = 0, remainder_result5 = 0, remainder_result6 = 0;
int remainder_num1 = 0, remainder_num2 = 0, remainder_num3 = 0, remainder_num4 = 0;
char op = 0, calculationType = 0, reroll = 0;
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
void clearBuffer() {
    while (getchar() != '\n');
}
FILE* prrecord = fopen("calculation_record.txt", "a");
char buffer[MAX] = { 0, };
long long getInt64Input(const char* message) { //���������Է¿�
    long long input1;
    printf("%s", message);
    scanf("%lld", &input1);
    clearBuffer();
    return input1;
}
long double getDoubleInput(const char* message) { //�Ǽ������Է¿�
    long double input2;
    printf("%s", message);
    scanf("%lf", &input2);
    clearBuffer();
    return input2;
}
int getIntInput(const char* message) {
    int input;
    printf("%s", message);
    scanf("%d", &input);
    clearBuffer();
    return input;
}
char getCharInput(const char* message) {
    char input0;
    printf("%s", message);
    scanf(" %c", &input0);
    clearBuffer();
    return input0;
}
void SaveRusultPrint() {
    prrecord = fopen("calculation_record.txt", "r");
    fread(buffer, 1, MAX, prrecord);
    printf("�����\n");
    printf("%s\n", buffer);
    fclose(prrecord);
}
void printWelcomeMessage() {
    system("color 7");
    SetConsoleTitle(TEXT("C Language arithmetic calculator"));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
    printf("��Ģ���� ���� �Դϴ�\n");
    printf("���������� '1'��, �Ǽ������� '2'��,������������ '3'�� �Է����ּ���\n(������ ������ ������ �����մϴ�)\n������ �� �� �Է� �ؾ� �ϴ� ���ڴ� �� 4���Դϴ�");
    prrecord = fopen("calculation_record.txt", "a");
    fclose(prrecord);
    printf("\n������� ������ �����ϴ� ȭ�鿡�� 'list'��ɾ ������ּ���\n------------------\n");
    Sleep(100);
}
int main() {
    printWelcomeMessage();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    fopen("calculation_record.txt", "r+");
    fseek(prrecord, 0L, SEEK_END);
    unsigned char  msync = 1, dsync = 1, rsync = 1;
    while (true) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
        printf("��������:1/�Ǽ�����:2/����������:3\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        scanf_s("%d", &calculationType);
        if (calculationType == 1) {
            n1 = getInt64Input("ù ��° ���ڸ� �Է��ϼ���: ");
            n2 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");
            n3 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");
            n4 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");
            op = getCharInput("�����ڸ� �Է��ϼ��� (+, -, *, /): ");
            switch (op) {
            case '+': {
                result1 = n1 + n2 + n3 + n4;
                printf("������� '%d'�Դϴ�\n", result1);
                fprintf(prrecord, "%d\n", result1);
                Sleep(1000);
                rerollerror_num_p://Reroll Error Number Plus
                reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                if (reroll == 'Y') {
                    n1 = 0, n2 = 0, n3 = 0, n4 = 0, result1 = 0;
                    calculationType = 0, op = 0, reroll = 0;
                    continue;
                }
                else if (reroll == 'N') {
                    printf("���α׷��� �����մϴ�\n");
                    fclose(prrecord);
                    exit(0);
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n");
                    printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                    printf("------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    reroll = 0;
                    goto rerollerror_num_p;//Reroll Error Number Plus
                }
            }
            case '-': {
                if (msync == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n������ ù��° ���ں��� �׹�° ���ڱ��� ���ʴ�� ���˴ϴ�\nEx)[����1] - [����2] - [����3] - [����4]\n------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    msync++;
                    goto danger_after_minus;
                }
                else {
                    danger_after_minus:
                    result1 = n1 - n2 - n3 - n4;
                    printf("������� '%d'�Դϴ�\n", result1);
                    fprintf(prrecord, "%d\n", result1);
                    Sleep(1000);
                    rerollerror_num_ma: //Reroll Error Number Minus
                    reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                    if (reroll == 'Y') {
                        n1 = 0, n2 = 0, n3 = 0, n4 = 0, result1 = 0;
                        calculationType = 0, op = 0, reroll = 0;
                        continue;
                    }
                    else if (reroll == 'N') {
                        printf("���α׷��� �����մϴ�\n");
                        fclose(prrecord);
                        exit(0);
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                        printf("------------------\n");
                        printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                        printf("------------------\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                        reroll = 0;
                        goto rerollerror_num_ma;//Reroll Error Number Minus
                    }
                }

            }
            case '*': {
                result1 = n1 * n2 * n3 * n4;
                printf("������� '%d'�Դϴ�\n", result1);
                fprintf(prrecord, "%d\n", result1);
                Sleep(1000);
                rerollerror_num_mu://Reroll Error Number Multiplication
                reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                if (reroll == 'Y') {
                    n1 = 0, n2 = 0, n3 = 0, n4 = 0, result1 = 0;
                    calculationType = 0, op = 0, reroll = 0;
                    continue;
                }
                else if (reroll == 'N') {
                    printf("���α׷��� �����մϴ�\n");
                    fclose(prrecord);
                    exit(0);
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n");
                    printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                    printf("------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    reroll = 0;
                    goto rerollerror_num_mu;//Reroll Error Number Multiplication
                }
            }
            case'/': {
                if (dsync == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n�������� ù��° ���ں��� �׹�° ���ڱ��� ���ʴ�� ���˴ϴ�\nEx)[����1] �� [����2] �� [����3] �� [����4]\n------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    dsync++;
                    goto danger_after_division;
                }
                else {
                    danger_after_division:
                    result1 = n1 / n2 / n3 / n4;
                    printf("������� '%d'�Դϴ�\n", result1);
                    fprintf(prrecord, "%d\n", result1);
                    Sleep(1000);
                    rerollerror_num_d://Reroll Error Number Division
                    reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                    if (reroll == 'Y') {
                        n1 = 0, n2 = 0, n3 = 0, n4 = 0, result1 = 0;
                        calculationType = 0, op = 0, reroll = 0;
                        continue;
                    }
                    else if (reroll == 'N') {
                        printf("���α׷��� �����մϴ�\n");
                        fclose(prrecord);
                        exit(0);
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                        printf("------------------\n");
                        printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                        printf("------------------\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                        reroll = 0;
                        goto rerollerror_num_d;//Reroll Error Float Division
                    }
                }
            }
            }
        }
        if (calculationType == 2) {
            f1 = getDoubleInput("ù ��° ���ڸ� �Է��ϼ���: ");
            f2 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
            f3 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
            f4 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
            op = getCharInput("�����ڸ� �Է��ϼ��� (+, -, *, /): ");
            switch (op) {
            case '+': {
                result2 = f1 + f2 + f3 + f4;
                printf("������� '%lf'�Դϴ�\n", result2);
                fprintf(prrecord, "%lf\n", result2);
                Sleep(1000);
                rerollerror_fl_p://Reroll Error Float Plus
                reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                if (reroll == 'Y') {
                    f1 = 0, f2 = 0, f3 = 0, f4 = 0, result2 = 0;
                    calculationType = 0, op = 0, reroll = 0;
                    continue;
                }
                else if (reroll == 'N') {
                    printf("���α׷��� �����մϴ�\n");
                    fclose(prrecord);
                    exit(0);
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n");
                    printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                    printf("------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    reroll = 0;
                    goto rerollerror_fl_p;//Reroll Error Float Plus
                }
            }
            case '-': {
                if (msync == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n������ ù��° ���ں��� �׹�° ���ڱ��� ���ʴ�� ���˴ϴ�\nEx)[����1] - [����2] - [����3] - [����4]\n------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    msync++;
                    goto danger_after_minus_2;
                }
                else {
                danger_after_minus_2:
                    result2 = f1 - f2 - f3 - f4;
                    printf("������� '%lf'�Դϴ�\n", result1);
                    fprintf(prrecord, "%lf\n", result1);
                    Sleep(1000);
                    rerollerror_fl_ma: //Reroll Error Float Minus
                    reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                    if (reroll == 'Y') {
                        f1 = 0, f2 = 0, f3 = 0, f4 = 0, result2 = 0;
                        calculationType = 0, op = 0, reroll = 0;
                        continue;
                    }
                    else if (reroll == 'N') {
                        printf("���α׷��� �����մϴ�\n");
                        fclose(prrecord);
                        exit(0);
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                        printf("------------------\n");
                        printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                        printf("------------------\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                        reroll = 0;
                        goto rerollerror_fl_ma;//Reroll Error Float Minus
                    }
                }

            }
            case '*': {
                result2 = f1 * f2 * f3 * f4;
                printf("������� '%lf'�Դϴ�\n", result2);
                fprintf(prrecord, "%lf\n", result1);
                Sleep(1000);
                rerollerror_float_mu://Reroll Error Float Multiplication
                reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                if (reroll == 'Y') {
                    f1 = 0, f2 = 0, f3 = 0, f4 = 0, result2 = 0;
                    calculationType = 0, op = 0, reroll = 0;
                    continue;
                }
                else if (reroll == 'N') {
                    printf("���α׷��� �����մϴ�\n");
                    fclose(prrecord);
                    exit(0);
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n");
                    printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                    printf("------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    reroll = 0;
                    goto rerollerror_float_mu;//Reroll Error Float Multiplication
                }
            }
            case'/': {
                if (dsync == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n�������� ù��° ���ں��� �׹�° ���ڱ��� ���ʴ�� ���˴ϴ�\nEx)[����1] �� [����2] �� [����3] �� [����4]\n------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    dsync++;
                    goto danger_after_division_2;
                }
                else {
                    danger_after_division_2:
                    result2 = f1 / f2 / f3 / f4;
                    printf("������� '%lf'�Դϴ�\n", result2);
                    fprintf(prrecord, "%lf\n", result2);
                    Sleep(1000);
                    rerollerror_float_d://Reroll Error Float Division
                    reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                    if (reroll == 'Y') {
                        f1 = 0, f2 = 0, f3 = 0, f4 = 0, result2 = 0;
                        calculationType = 0, op = 0, reroll = 0;
                        continue;
                    }
                    else if (reroll == 'N') {
                        printf("���α׷��� �����մϴ�\n");
                        fclose(prrecord);
                        exit(0);
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                        printf("------------------\n");
                        printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                        printf("------------------\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                        reroll = 0;
                        goto rerollerror_float_d;//Reroll Error Float Division
                    }
                }

            }
            }
        }
                if (calculationType == 3) {
                    if (rsync == 1) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                        printf("------------------\n������������ ù��° ���ں��� �׹�° ���ڱ��� ���ʴ�� ���˴ϴ�\nEx)[����1] % [����2] % [����3] % [����4]\n------------------\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                        rsync++;
                        goto danger_after_reminder;
                    }
                    else {
                        danger_after_reminder:
                        remainder_num1 = getIntInput("ù��° ���ڸ� �Է����ּ���: ");
                        remainder_num2 = getIntInput("�ι�° ���ڸ� �Է����ּ���: ");
                        remainder_num3 = getIntInput("����° ���ڸ� �Է����ּ���: ");
                        remainder_num4 = getIntInput("�׹�° ���ڸ� �Է����ּ���: ");
                        Sleep(1000);
                        remainder_result2 = remainder_num1% remainder_num2% remainder_num3% remainder_num4;
                        remainder_result1 = remainder_num1;
                        printf("������� '%d'�Դϴ�\n", remainder_num1);
                        fprintf(prrecord, "%d", remainder_result1);
                        Sleep(1000);
                        rerollerror_Remainder://Reroll Error Remainder
                        reroll = getCharInput("����Ͻðڽ��ϱ�?[Y/N]: ");
                        if (reroll == 'Y') {
                            remainder_num1 = 0, remainder_num2 = 0, remainder_num3 = 0, remainder_num4 = 0, remainder_result1 = 0, remainder_result2 = 0;
                            calculationType = 0, op = 0, reroll = 0;
                            continue;
                        }
                        else if (reroll == 'N') {
                            printf("���α׷��� �����մϴ�\n");
                            fclose(prrecord);
                            exit(0);
                        }
                        else {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                            printf("------------------\n");
                            printf("�߸��� ���� �Է��ϼ̽��ϴ�\n'Y'�Ǵ�'N'�� �Է����ּ���\n(�ݵ�� �빮�� N,Y�� �Է����ּ���)\n");
                            printf("------------------\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                            reroll = 0;
                            goto rerollerror_float_d;//Reroll Error Float Division
                        }
                    }
                }
                }
            
        return 0;
        }
    