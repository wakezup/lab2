#include "main.h"
#include "input.h"
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
#include "task_5.h"
#include "task_6.h"
#include "task_7.h"
#include "task_8.h"
#include "task_9.h"
#include "task_10.h"


int main() {
    while (true) {
        int task = TaskInput(
            "[ВВОД] Введите номер задания (1-10) или 0 для выхода: ", 10);

        switch (task) {
            case 0:
                std::cout << "[ИНФО] Завершение программы...\n";
                return 0;
            case 1:
                RunTask1();
                break;
            case 2:
                RunTask2();
                break;
            case 3:
                RunTask3();
                break;
            case 4:
                RunTask4();
                break;
            case 5:
                RunTask5();
                break;
            case 6:
                RunTask6();
                break;
            case 7:
                RunTask7();
                break;
            case 8:
                RunTask8();
                break;
            case 9:
                RunTask9();
                break;
            case 10:
                RunTask10();
                break;
        }
    }
}