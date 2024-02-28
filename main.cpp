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
long long getInt64Input(const char* message) {
    long long input;
    printf("%s", message);
    scanf("%lld", &input);
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

void SaveRusultPrint() {
    prrecord = fopen("calculation_record.txt", "r");
    fread(buffer, 1, MAX, prrecord);
    printf("%s\n", buffer);
    fclose(prrecord);
}
void printWelcomeMessage() {
    system("color 7");
    SetConsoleTitle(TEXT("C Language arithmetic calculator"));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
    printf("사칙연산 계산기 입니다\n");
    printf("정수연산은 '1'을, 실수연산은 '2'를,나머지연산은 '3'을 입력해주세요\n(나머지 연산은 정수만 지원합니다)\n연산을 할 때 입력 해야 하는 숫자는 총 4개입니다");
    prrecord = fopen("calculation_record.txt", "a");
    fclose(prrecord);
    printf("\n계산기록은 10개 까지만 저장됩니다\n------------------\n");
    Sleep(100);
}
int main() {
    printWelcomeMessage();
    SaveRusultPrint();
    printf("------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    fopen("calculation_record.txt", "r+");
    fseek(prrecord, 0L, SEEK_END);
    while (true) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
        printf("정수연산:1/실수연산:2/나머지연산:3\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        scanf_s("%d", &calculationType);
        if (calculationType == 1) {
            n1 = getInt64Input("첫 번째 숫자를 입력하세요: ");
            n2 = getInt64Input("두 번째 숫자를 입력하세요: ");
            n3 = getInt64Input("세 번째 숫자를 입력하세요: ");
            n4 = getInt64Input("네 번째 숫자를 입력하세요: ");
            op = getCharInput("연산자를 입력하세요 (+, -, *, /): ");
            switch (op) {
            case '+':
                result1 = n1 + n2 + n3 + n4;
                printf("계산결과는 '%d'입니다\n", result1);
                fprintf(prrecord, "%d\n", result1);
                Sleep(1000);
                rerollerror:
                reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                if (reroll == 'Y') {
                    n1 = 0, n2 = 0, n3 = 0, n4 = 0,result1 = 0;
                    calculationType = 0, op = 0, reroll = 0;
                    continue;
                }
                else if (reroll == 'N') {
                    printf("프로그램을 종료합니다\n");
                    fclose(prrecord);
                    exit(0);
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n");
                    printf("잘못된 값을 입력하셨습니다\n'Y'또는'N'를 입력해주세요\n(반드시 대문자 N,Y를 입력해주세요)\n");
                    printf("------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    reroll = 0;
                    goto rerollerror;
                }
            }
        }
    }
    return 0;
}