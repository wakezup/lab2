#include <algorithm>
#include <list>


#include "task_5.h"
#include "input.h"


namespace {

int ReadCount() {
    while (true) {
        int count = IntegerInput("[ВВОД] Введите кол-во "
                                 "элементов в списке: ");

        if (count > 0) {
            return count;
        } else {
            std::cerr << "[ОШИБКА] Кол-во элементов "
                         "должно быть положительным.\n";
        }
    }
}

std::list<int> ReadList(int count) {
    std::list<int> list;

    for (int i = 0; i < count; ++i) {
        list.push_back(IntegerInput("[ВВОД] Введите элемент списка: "));
    }

    return list;
}

void PrintList(const std::list<int>& list) {
    std::cout << "[РЕЗУЛЬТАТ] Список после удаления "
                "первого и последнего нулевых элементов:" << std::endl;

    bool empty = true;

    for (auto it = list.begin(); it != list.end(); ++it) {
        if (empty) {
            empty = false;
        }
        std::cout << *it << ' ';
    }

    if (empty) {
        std::cout << "пусто...";
    }

    std::cout << "\n";
}

void DeleteFirstAndLastZeros(std::list<int>& list) {
    auto first_zero = std::find(list.begin(), list.end(), 0);

    if (first_zero == list.end()) {
        std::cout << "[ИНФО] В списке не было найдено нулевых элементов."
                << std::endl;
    } else {
        list.erase(first_zero);
    }

    auto last_zero = std::find(list.rbegin(), list.rend(), 0);

    if (!(last_zero == list.rend())) {
        list.erase((++last_zero).base());
    }
}

} // namespace

void RunTask5() {
    int count = ReadCount();
    std::list<int> list = ReadList(count);

    DeleteFirstAndLastZeros(list);
    PrintList(list);
}