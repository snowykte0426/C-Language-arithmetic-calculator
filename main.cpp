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
long long getInt64Input(const char* message) { //정수연산입력용
    long long input1;
    printf("%s", message);
    scanf("%lld", &input1);
    clearBuffer();
    return input1;
}
long double getDoubleInput(const char* message) { //실수연산입력용
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
    printf("계산기록\n");
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
    printf("\n계산기록은 연산을 선택하는 화면에서 'list'명령어를 사용해주세요\n------------------\n");
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
            case '+': {
                result1 = n1 + n2 + n3 + n4;
                printf("계산결과는 '%d'입니다\n", result1);
                fprintf(prrecord, "%d\n", result1);
                Sleep(1000);
                rerollerror_num_p://Reroll Error Number Plus
                reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                if (reroll == 'Y') {
                    n1 = 0, n2 = 0, n3 = 0, n4 = 0, result1 = 0;
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
                    goto rerollerror_num_p;//Reroll Error Number Plus
                }
            }
            case '-': {
                if (msync == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n뺄셈은 첫번째 숫자부터 네번째 숫자까지 차례대로 계산됩니다\nEx)[숫자1] - [숫자2] - [숫자3] - [숫자4]\n------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    msync++;
                    goto danger_after_minus;
                }
                else {
                    danger_after_minus:
                    result1 = n1 - n2 - n3 - n4;
                    printf("계산결과는 '%d'입니다\n", result1);
                    fprintf(prrecord, "%d\n", result1);
                    Sleep(1000);
                    rerollerror_num_ma: //Reroll Error Number Minus
                    reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                    if (reroll == 'Y') {
                        n1 = 0, n2 = 0, n3 = 0, n4 = 0, result1 = 0;
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
                        goto rerollerror_num_ma;//Reroll Error Number Minus
                    }
                }

            }
            case '*': {
                result1 = n1 * n2 * n3 * n4;
                printf("계산결과는 '%d'입니다\n", result1);
                fprintf(prrecord, "%d\n", result1);
                Sleep(1000);
                rerollerror_num_mu://Reroll Error Number Multiplication
                reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                if (reroll == 'Y') {
                    n1 = 0, n2 = 0, n3 = 0, n4 = 0, result1 = 0;
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
                    goto rerollerror_num_mu;//Reroll Error Number Multiplication
                }
            }
            case'/': {
                if (dsync == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n나눗셈은 첫번째 숫자부터 네번째 숫자까지 차례대로 계산됩니다\nEx)[숫자1] ÷ [숫자2] ÷ [숫자3] ÷ [숫자4]\n------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    dsync++;
                    goto danger_after_division;
                }
                else {
                    danger_after_division:
                    result1 = n1 / n2 / n3 / n4;
                    printf("계산결과는 '%d'입니다\n", result1);
                    fprintf(prrecord, "%d\n", result1);
                    Sleep(1000);
                    rerollerror_num_d://Reroll Error Number Division
                    reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                    if (reroll == 'Y') {
                        n1 = 0, n2 = 0, n3 = 0, n4 = 0, result1 = 0;
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
                        goto rerollerror_num_d;//Reroll Error Float Division
                    }
                }
            }
            }
        }
        if (calculationType == 2) {
            f1 = getDoubleInput("첫 번째 숫자를 입력하세요: ");
            f2 = getDoubleInput("두 번째 숫자를 입력하세요: ");
            f3 = getDoubleInput("세 번째 숫자를 입력하세요: ");
            f4 = getDoubleInput("네 번째 숫자를 입력하세요: ");
            op = getCharInput("연산자를 입력하세요 (+, -, *, /): ");
            switch (op) {
            case '+': {
                result2 = f1 + f2 + f3 + f4;
                printf("계산결과는 '%lf'입니다\n", result2);
                fprintf(prrecord, "%lf\n", result2);
                Sleep(1000);
                rerollerror_fl_p://Reroll Error Float Plus
                reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                if (reroll == 'Y') {
                    f1 = 0, f2 = 0, f3 = 0, f4 = 0, result2 = 0;
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
                    goto rerollerror_fl_p;//Reroll Error Float Plus
                }
            }
            case '-': {
                if (msync == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n뺄셈은 첫번째 숫자부터 네번째 숫자까지 차례대로 계산됩니다\nEx)[숫자1] - [숫자2] - [숫자3] - [숫자4]\n------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    msync++;
                    goto danger_after_minus_2;
                }
                else {
                danger_after_minus_2:
                    result2 = f1 - f2 - f3 - f4;
                    printf("계산결과는 '%lf'입니다\n", result1);
                    fprintf(prrecord, "%lf\n", result1);
                    Sleep(1000);
                    rerollerror_fl_ma: //Reroll Error Float Minus
                    reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                    if (reroll == 'Y') {
                        f1 = 0, f2 = 0, f3 = 0, f4 = 0, result2 = 0;
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
                        goto rerollerror_fl_ma;//Reroll Error Float Minus
                    }
                }

            }
            case '*': {
                result2 = f1 * f2 * f3 * f4;
                printf("계산결과는 '%lf'입니다\n", result2);
                fprintf(prrecord, "%lf\n", result1);
                Sleep(1000);
                rerollerror_float_mu://Reroll Error Float Multiplication
                reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                if (reroll == 'Y') {
                    f1 = 0, f2 = 0, f3 = 0, f4 = 0, result2 = 0;
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
                    goto rerollerror_float_mu;//Reroll Error Float Multiplication
                }
            }
            case'/': {
                if (dsync == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                    printf("------------------\n나눗셈은 첫번째 숫자부터 네번째 숫자까지 차례대로 계산됩니다\nEx)[숫자1] ÷ [숫자2] ÷ [숫자3] ÷ [숫자4]\n------------------\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                    dsync++;
                    goto danger_after_division_2;
                }
                else {
                    danger_after_division_2:
                    result2 = f1 / f2 / f3 / f4;
                    printf("계산결과는 '%lf'입니다\n", result2);
                    fprintf(prrecord, "%lf\n", result2);
                    Sleep(1000);
                    rerollerror_float_d://Reroll Error Float Division
                    reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                    if (reroll == 'Y') {
                        f1 = 0, f2 = 0, f3 = 0, f4 = 0, result2 = 0;
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
                        goto rerollerror_float_d;//Reroll Error Float Division
                    }
                }

            }
            }
        }
                if (calculationType == 3) {
                    if (rsync == 1) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                        printf("------------------\n나머지연산은 첫번째 숫자부터 네번째 숫자까지 차례대로 계산됩니다\nEx)[숫자1] % [숫자2] % [숫자3] % [숫자4]\n------------------\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                        rsync++;
                        goto danger_after_reminder;
                    }
                    else {
                        danger_after_reminder:
                        remainder_num1 = getIntInput("첫번째 숫자를 입력해주세요: ");
                        remainder_num2 = getIntInput("두번째 숫자를 입력해주세요: ");
                        remainder_num3 = getIntInput("세번째 숫자를 입력해주세요: ");
                        remainder_num4 = getIntInput("네번째 숫자를 입력해주세요: ");
                        Sleep(1000);
                        remainder_result2 = remainder_num1% remainder_num2% remainder_num3% remainder_num4;
                        remainder_result1 = remainder_num1;
                        printf("계산결과는 '%d'입니다\n", remainder_num1);
                        fprintf(prrecord, "%d", remainder_result1);
                        Sleep(1000);
                        rerollerror_Remainder://Reroll Error Remainder
                        reroll = getCharInput("계속하시겠습니까?[Y/N]: ");
                        if (reroll == 'Y') {
                            remainder_num1 = 0, remainder_num2 = 0, remainder_num3 = 0, remainder_num4 = 0, remainder_result1 = 0, remainder_result2 = 0;
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
                            goto rerollerror_float_d;//Reroll Error Float Division
                        }
                    }
                }
                }
            
        return 0;
        }
    