#include <algorithm>
#include <iterator>
#include <deque>


#include "task_6.h"
#include "input.h"


namespace {

int ReadCount() {
    int count;
    while (true) {
        count = IntegerInput("[ВВОД] Введите четное кол-во "
                                "элементов дека: ");
        if (count > 0 && count % 2 == 0) {
            return count;
        }
        std::cerr << "[ОШИБКА] Кол-во элементов должно быть положительным"
                     " и четным.\n";
    }
}

std::deque<int> ReadDeque(int count) {
    std::deque<int> deque;

    for (int i = 0; i < count; ++i) {
        deque.push_back(IntegerInput("[ВВОД] Введите элемент дека: "));
    }

    return deque;
}

void CopyFirstHalf(std::deque<int>& deque, int count) {
    auto middle = deque.begin();
    std::advance(middle, count / 2);
    const std::deque<int> first_half(deque.begin(), middle);

    std::replace_copy_if(
        first_half.rbegin(), first_half.rend(), std::back_inserter(deque),
        [](int value) { return value < 0; }, 0);
}

void PrintDeque(const std::deque<int>& deque) {
    std::cout << "[РЕЗУЛЬТАТ] Дек после копирования первой половины "
                 "в обратном порядке с заменой отрицательных элементов "
                 "на нули:" << std::endl;

    for (auto it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << "\n";
}

} // namespace

void RunTask6() {
    int count = ReadCount();
    std::deque<int> deque = ReadDeque(count);

    CopyFirstHalf(deque, count);
    PrintDeque(deque);
}