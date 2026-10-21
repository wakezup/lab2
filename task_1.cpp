#include <algorithm>
#include <cstddef>
#include <iterator>
#include <deque>
#include <list>
#include <string>
#include <vector>


#include "task_1.h"
#include "input.h"


namespace {

int ReadElementCount(const std::string& container_name) {
    while (true) {
        const int count = IntegerInput(
            "[ВВОД] Введите количество элементов " + container_name +
            " (четное положительное число): ");
        if (count > 0 && count % 2 == 0) {
            return count;
        }
        std::cerr << "[ОШИБКА] Количество должно быть "
                     "четным и положительным.\n";
    }
}

std::vector<int> ReadValues(int count) {
    std::vector<int> values;
    values.reserve(count);

    for (int i = 0; i < count; ++i) {
        values.push_back(IntegerInput("[ВВОД] Введите элемент: "));
    }

    return values;
}

std::vector<int> ReadVector() {
    const int count = ReadElementCount("вектора");
    const std::vector<int> values = ReadValues(count);
    return std::vector<int>(values.begin(), values.end());
}

std::deque<int> ReadDeque() {
    const int count = ReadElementCount("дека");
    const std::vector<int> values = ReadValues(count);
    return std::deque<int>(values.begin(), values.end());
}

std::list<int> ReadList() {
    const int count = ReadElementCount("списка");
    const std::vector<int> values = ReadValues(count);
    return std::list<int>(values.begin(), values.end());
}

void SwapMiddleElements(std::vector<int>& container) {
    std::vector<int>::iterator left_middle = container.begin();
    for (std::size_t i = 0; i < container.size() / 2 - 1; ++i) {
        ++left_middle;
    }
    std::vector<int>::iterator right_middle = left_middle;
    ++right_middle;
    std::swap(*left_middle, *right_middle);
}

void SwapMiddleElements(std::deque<int>& container) {
    std::deque<int>::iterator left_middle = container.begin();
    for (std::size_t i = 0; i < container.size() / 2 - 1; ++i) {
        ++left_middle;
    }
    std::deque<int>::iterator right_middle = left_middle;
    ++right_middle;
    std::swap(*left_middle, *right_middle);
}

void SwapMiddleElements(std::list<int>& container) {
    std::list<int>::iterator left_middle = container.begin();
    for (std::size_t i = 0; i < container.size() / 2 - 1; ++i) {
        ++left_middle;
    }
    std::list<int>::iterator right_middle = left_middle;
    ++right_middle;
    std::swap(*left_middle, *right_middle);
}

void PrintContainer(const std::vector<int>& container) {
    std::cout << "[РЕЗУЛЬТАТ] Вектор после перестановки "
                 "средних элементов:\n";
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

void PrintContainer(const std::deque<int>& container) {
    std::cout << "[РЕЗУЛЬТАТ] Дек после перестановки средних элементов:\n";
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

void PrintContainer(const std::list<int>& container) {
    std::cout << "[РЕЗУЛЬТАТ] Список после перестановки "
                 "средних элементов:\n";
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

} // namespace

void RunTask1() {
    std::vector<int> vector = ReadVector();
    std::deque<int> deque = ReadDeque();
    std::list<int> list = ReadList();

    SwapMiddleElements(vector);
    SwapMiddleElements(deque);
    SwapMiddleElements(list);

    PrintContainer(vector);
    PrintContainer(deque);
    PrintContainer(list);
}