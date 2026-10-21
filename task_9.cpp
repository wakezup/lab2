#include <algorithm>
#include <set>
#include <vector>


#include "task_9.h"
#include "input.h"


namespace {

int ReadCount(const std::string& prompt, std::string& error) {
    while (true) {
        int count = IntegerInput(prompt);

        if (count > 0) {
            return count;
        }

        std::cerr << error << std::endl;
    }
}

std::vector<int> ReadVector(int count, std::string& vector_name) {
    std::vector<int> vector;
    vector.reserve(count);

    for (int i = 0; i < count; ++i) {
        vector.push_back(IntegerInput("[ВВОД] Введите элемент вектора "
                                      + vector_name + ": "));
    }

    return vector;
}

}  // namespace

void RunTask9() {
    std::string base_vector_name = "V0";

    std::string vector_count_error = "[ОШИБКА] Количество векторов "
                                     "должно быть положительным.";
    
    std::string vector_size_error = "[ОШИБКА] Кол-во элементов вектора "
                                    "должно быть положительным";

    const int vector_count = ReadCount(
        "[ВВОД] Введите количество векторов N: ", vector_count_error);

    const int base_size = ReadCount(
        "[ВВОД] Введите размер вектора " + base_vector_name
        + ": ", vector_size_error);

    const std::vector<int> base_values = ReadVector(base_size,
                                                    base_vector_name);

    const std::multiset<int> base(
        base_values.begin(), base_values.end());

    int containing_vectors = 0;
    for (int i = 0; i < vector_count; ++i) {
        int current_size;
        std::string current_vector_name = "V" + std::to_string(i + 1);

        while (true) {
            current_size = ReadCount(
                "[ВВОД] Введите размер вектора "
                + current_vector_name + ": ", vector_size_error);

            if (current_size >= base_size) {
                break;
            }

            std::cerr << "[ОШИБКА] Размер вектора не может быть меньше "
                         "размера V0.\n";
        }

        const std::vector<int> current_values = ReadVector(
            current_size, current_vector_name);

        const std::multiset<int> current(
            current_values.begin(), current_values.end());

        if (std::includes(current.begin(), current.end(),
                          base.begin(), base.end())) {
            ++containing_vectors;
        }
    }

    std::cout << "[РЕЗУЛЬТАТ] Количество векторов, содержащих все элементы "
                 "V0 с учетом повторений: "
              << containing_vectors << '\n';
}
