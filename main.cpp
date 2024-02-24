#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
long long result1 = NULL, n1 = 0, n2 = 0, n3 = 0, n4 = 0;
long double result2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
int remainder_result1 = 0, remainder_result2 = 0, remainder_result3 = 0, remainder_result4 = 0, remainder_result5 = 0, remainder_result6 = 0;
int remainder_num1 = 0, remainder_num2 = 0, remainder_num3 = 0, remainder_num4 = 0;
char op = 0;
// 색상 값들
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
// 함수 선언
void printWelcomeMessage();
int getIntInput(const char* message);
long long getInt64Input(const char* message);
long double getDoubleInput(const char* message);
char getCharInput(const char* message);
void printCalculationResult(char op, long long result);
void printErrorMessage(const char* message);
void clearBuffer();
// 함수 정의
// 환영 메시지 출력
void printWelcomeMessage() {
    system("color 7");
    SetConsoleTitle(TEXT("C Language arithmetic calculator"));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
    printf("사칙연산 계산기 입니다\n");
    printf("정수연산은 '1'을, 실수연산은 '2'를,나머지연산은 '3'을 입력해주세요\n(나머지 연산은 정수만 지원합니다)\n연산을 할 때 입력 해야만 하는 숫자는 총 4개입니다");
    FILE* prrecord = fopen("calculation_record.txt", "r");
    printf("\n계산기록은 10개 까지만 저장됩니다\n------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    Sleep(100);
}
// 정수 입력 함수
int getIntInput(const char* message) {
    int input;
    printf("%s", message);
    scanf("%d", &input);
    clearBuffer();
    return input;
}
// 64비트 정수 입력 함수
long long getInt64Input(const char* message) {
    long long input;
    printf("%s", message);
    scanf("%lld", &input);
    clearBuffer();
    return input;
}
// 실수 입력 함수
long double getDoubleInput(const char* message) {
    long double input;
    printf("%s", message);
    scanf("%lf", &input);
    clearBuffer();
    return input;
}
// 문자 입력 함수
char getCharInput(const char* message) {
    char input;
    printf("%s", message);
    scanf(" %c", &input); // 공백을 추가하여 앞에 남아있는 문자를 무시
    clearBuffer();
    return input;
}
// 계산 결과 출력 함수
void printCalculationResult(char op, long long result) {
    printf("%d %c %d %c %d %c %d = %lld\n", n1, op, n2, op, n3, op, n4, result);
}
// 오류 메시지 출력 함수
void printErrorMessage(const char* message) {
    printf("** 오류: %s\n", message);
}
// 버퍼 지우기 함수
void clearBuffer() {
    while (getchar() != '\n');
}
// 프로그램 시작
int main()
{ // 환영 메시지 출력
    printWelcomeMessage();
    // 계산 종류 선택
    while (true) {
        int calculationType = getIntInput("계산 종류를 선택하세요 (1: 정수, 2: 실수, 3: 나머지): ");
        if (calculationType < 1 || calculationType > 3) {
            printErrorMessage("잘못된 계산 종류를 선택했습니다.");
            continue;
        }
        // 계산 수행
        switch (calculationType) {
        case 1:
            // 정수 연산
           n1 = getInt64Input("첫 번째 숫자를 입력하세요: ");
           n2 = getInt64Input("두 번째 숫자를 입력하세요: ");
           n3 = getInt64Input("세 번째 숫자를 입력하세요: ");
           n4 = getInt64Input("네 번째 숫자를 입력하세요: ");
           op = getCharInput("연산자를 입력하세요 (+, -, *, /): ");
           switch (op) {
            case '+':
                result1 = n1 + n2 + n3 + n4;
                break;
            case '-':
                result1 = n1 - n2 - n3 - n4;
                break;
            case '*':
                result1 = n1 * n2 * n3 * n4;
                break;
            case '/':
                if (n2 == 0 || n3 == 0 || n4 == 0) {
                    printErrorMessage("0으로 나눌 수 없습니다.");
                    continue;
                }
                result1 = n1 / n2 / n3 / n4;
                break;
            default:
                printErrorMessage("잘못된 연산자를 입력했습니다.");
                continue;
                printCalculationResult(op, result1);
                break;
            }
        case 2:
            // 실수 연산
            f1 = getDoubleInput("첫 번째 숫자를 입력하세요: ");
            f2 = getDoubleInput("두 번째 숫자를 입력하세요: ");
            f3 = getDoubleInput("세 번째 숫자를 입력하세요: ");
            f4 = getDoubleInput("네 번째 숫자를 입력하세요: ");
            op = getCharInput("연산자를 입력하세요 (+, -, *, /): ");
            switch (op) {
            case '+':
                result2 = f1 + f2 + f3 + f4;
                break;
            case '-':
                result2 = f1 - f2 - f3 - f4;
                break;
            case '*':
                result2 = f1 * f2 * f3 * f4;
                break;
            case '/':
                if (f2 == 0.0 || f3 == 0.0 || f4 == 0.0) {
                    printErrorMessage("0으로 나눌 수 없습니다.");
                    continue;
                }
                result2 = f1 / f2 / f3 / f4;
                break;
            default:
                printErrorMessage("잘못된 연산자를 입력했습니다.");
                continue;
                printCalculationResult(op, result2);
                break;
            }
        case 3:
            // 나머지 연산
            remainder_num1 = getIntInput("첫 번째 숫자를 입력하세요: ");
            remainder_num2 = getIntInput("두 번째 숫자를 입력하세요: ");
            remainder_num3 = getIntInput("세 번째 숫자를 입력하세요: ");
            remainder_num4 = getIntInput("네 번째 숫자를 입력하세요: ");
            op = getCharInput("연산자를 입력하세요 (%): ");
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
