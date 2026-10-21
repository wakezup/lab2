#include <iterator>
#include <list>
#include <numeric>
#include <vector>


#include "task_8.h"
#include "input.h"


namespace {

int ReadCount() {
    while (true) {
        int count = IntegerInput("[ВВОД] Введите кол-во элементов списка: ");
        if (count >= 2) {
            return count;
        }
        std::cerr << "[ОШИБКА] Кол-во элементов должно быть "
                     "положительным и больше или равно двум.\n";
    }
}

std::list<int> ReadList(int count) {
    std::list<int> list;

    for (int i = 0; i < count; ++i) {
        list.push_back(IntegerInput("[ВВОД] Введите элемент списка: "));
    }

    return list;
}

struct ArithmeticMean {
    double operator()(double current, double previous) const {
        return static_cast<double>(current + previous) / 2.0;
    }
};

std::vector<double> GetNeighborMeans(const std::list<int>& list) {
    std::vector<double> means;

    std::adjacent_difference(
        list.begin(), list.end(), std::back_inserter(means), ArithmeticMean());

    if (!means.empty()) {
        means.erase(means.begin());
    }

    return means;
}

void PrintMeans(const std::vector<double>& means) {
    std::cout << "[РЕЗУЛЬТАТ] Средние арифметические соседних элементов:\n";
    
    for (auto it = means.begin(); it != means.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << '\n';
}

}  // namespace

void RunTask8() {
    const int count = ReadCount();
    const std::list<int> list = ReadList(count);
    PrintMeans(GetNeighborMeans(list));
}
