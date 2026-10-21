#include <iostream>
#include <list>
#include <string>


#include "input.h"
#include "task_3.h"


namespace {

int ReadOddCount() {
    while (true) {
        const int count = IntegerInput(
            "[ВВОД] Введите нечетное количество элементов списка L1: ");
        if (count > 0 && count % 2 != 0) {
            return count;
        }
        std::cerr << "[ОШИБКА] Количество элементов L1 должно быть "
                     "положительным и нечетным.\n";
    }
}

int ReadNonNegativeCount() {
    while (true) {
        const int count = IntegerInput(
            "[ВВОД] Введите количество элементов списка L2: ");
        if (count >= 0) {
            return count;
        }
        std::cerr << "[ОШИБКА] Количество элементов L2 не может быть "
                     "отрицательным.\n";
    }
}

std::list<int> ReadList(int count, const std::string& list_name) {
    std::list<int> values;
    for (int i = 0; i < count; ++i) {
        values.push_back(
            IntegerInput("[ВВОД] Введите элемент списка "
                         + list_name + ": "));
    }
    return values;
}

void MoveMiddleToEnd(std::list<int>& list1, std::list<int>& list2,
                    int list1_size) {
    std::list<int>::iterator middle = list1.begin();
    for (int i = 0; i < list1_size / 2; ++i) {
        ++middle;
    }
    list2.splice(list2.end(), list1, middle);
}

void PrintList(const std::list<int>& values, const std::string& list_name) {
    std::cout << "[РЕЗУЛЬТАТ] Список " << list_name << ": ";
    for (auto it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

} // namespace

void RunTask3() {
    const int list1_size = ReadOddCount();
    std::list<int> list1 = ReadList(list1_size, "L1");

    const int list2_size = ReadNonNegativeCount();
    std::list<int> list2 = ReadList(list2_size, "L2");

    MoveMiddleToEnd(list1, list2, list1_size);

    PrintList(list1, "L1");
    PrintList(list2, "L2");
}
