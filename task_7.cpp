#include <algorithm>
#include <deque>


#include "task_7.h"
#include "input.h"


namespace {

int ReadCount() {
    while (true) {
        int count = IntegerInput("[ВВОД] Введите кол-во элементов дека: ");
        if (count >= 1) {
            return count;
        }
        std::cerr << "[ОШИБКА] Кол-во элементов должно быть "
                    "положительным.\n";
    }
}

struct SignGroupLess {
    int Group(int value) const {
        if (value < 0) {
            return 0;
        }
        if (value == 0) {
            return 1;
        }
        return 2;
    }

    bool operator()(int left, int right) const {
        return Group(left) < Group(right);
    }
};

std::deque<int> ReadDeque(int count) {
    std::deque<int> deque;

    for (int i = 0; i < count; ++i) {
        deque.push_back(IntegerInput("[ВВОД] Введите элемент дека: "));
    }

    return deque;
}

void SortDeque(std::deque<int>& deque) {
    std::stable_sort(deque.begin(), deque.end(), SignGroupLess());
}

void PrintDeque(const std::deque<int>& deque) {
    std::cout << "[РЕЗУЛЬТАТ] Дек после группировки отрицательных, нулевых "
                "и положительных элементов:" << std::endl;;

    for (auto it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << "\n";
}

} // namespace

void RunTask7() {
    int count = ReadCount();
    std::deque<int> deque = ReadDeque(count);

    SortDeque(deque);
    PrintDeque(deque);
}
