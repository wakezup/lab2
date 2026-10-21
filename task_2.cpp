#include <vector>


#include "input.h"
#include "task_2.h"


namespace {

int ReadEvenCount() {
    while (true) {
        const int count = IntegerInput(
            "[ВВОД] Введите количество элементов вектора (четное число): ");
        if (count > 0 && count % 2 == 0) {
            return count;
        }
        std::cerr << "[ОШИБКА] Количество должно быть "
                     "четным и положительным.\n";
    }
}

std::vector<int> ReadVector(int count) {
    std::vector<int> values;
    values.reserve(count);
    for (int i = 0; i < count; ++i) {
        values.push_back(IntegerInput("[ВВОД] Введите элемент: "));
    }
    return values;
}

void PrintVector(const std::vector<int>& values) {
    std::cout << "[РЕЗУЛЬТАТ] Вектор после вставки "
                 "пяти нулей в середину:\n";
    for (auto it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

} // namespace

void RunTask2() {
    const int count = ReadEvenCount();
    std::vector<int> values = ReadVector(count);

    values.insert(values.begin() + count / 2, 5, 0);

    PrintVector(values);
}
