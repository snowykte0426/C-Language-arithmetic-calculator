#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ���� ����
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
// �Լ� ����
void printWelcomeMessage() {
    printf("��Ģ���� ���� �Դϴ�\n");
}
int getIntInput(const char* message);
long long getInt64Input(const char* message);
long double getDoubleInput(const char* message);
char getCharInput(const char* message);
void printCalculationResult(char op, long long result);
void printErrorMessage(const char* message);
void clearBuffer();
// ���α׷� ����
int main()
{
    long long result1 = NULL, n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    long double result2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    int remainder_result1 = 0, remainder_result2 = 0, remainder_result3 = 0, remainder_result4 = 0, remainder_result5 = 0, remainder_result6 = 0;
    int remainder_num1 = 0, remainder_num2 = 0, remainder_num3 = 0, remainder_num4 = 0;
    char op = 0;
    // ȯ�� �޽��� ���
    printWelcomeMessage();
    // ��� ���� ����
    while (true) {
        int calculationType = getIntInput("��� ������ �����ϼ��� (1: ����, 2: �Ǽ�, 3: ������): ");
        if (calculationType < 1 || calculationType > 3) {
            printErrorMessage("�߸��� ��� ������ �����߽��ϴ�.");
            continue;
        }
        // ��� ����
        switch (calculationType) {
        case 1:
            // ���� ����
           n1 = getInt64Input("ù ��° ���ڸ� �Է��ϼ���: ");
           n2 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");
           n3 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");
           n4 = getInt64Input("�� ��° ���ڸ� �Է��ϼ���: ");

           op = getCharInput("�����ڸ� �Է��ϼ��� (+, -, *, /): ");
           

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
                    printErrorMessage("0���� ���� �� �����ϴ�.");
                    continue;
                }
                result1 = n1 / n2 / n3 / n4;
                break;
            default:
                printErrorMessage("�߸��� �����ڸ� �Է��߽��ϴ�.");
                continue;
                printCalculationResult(op, result1);
                break;
            }
        case 2:
            // �Ǽ� ����
            f1 = getDoubleInput("ù ��° ���ڸ� �Է��ϼ���: ");
            f2 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
            f3 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
            f4 = getDoubleInput("�� ��° ���ڸ� �Է��ϼ���: ");
            op = getCharInput("�����ڸ� �Է��ϼ��� (+, -, *, /): ");
            

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
            // ������ ����
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
