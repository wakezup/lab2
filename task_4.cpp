#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>


#include "input.h"
#include "task_4.h"


namespace {

std::string ReadNumbers() {
    std::string line;
    while (true) {
        std::cout << "[ВВОД] Введите вещественные числа "
                     "через пробел (минимум 2 числа): " << std::endl;

        std::getline(std::cin >> std::ws, line);

        std::istringstream check_stream(line);
        int count = 0;

        bool ok = std::all_of(
            std::istream_iterator<std::string>(check_stream),
            std::istream_iterator<std::string>(),
            [&count](const std::string& value) {
                if (IsReal(value)) {
                    ++count;
                    return true;
                }
                return false;
            });

        if (ok && count >= 2) {
            break;
        }
        std::cerr << "[ОШИБКА] Некорректный ввод.\n";
    }
    return line;
}

void SelectEvenOrderNumbers(const std::string& line) {
    std::istringstream numbers_stream(line);
    int index = 0;

    std::remove_copy_if(
        std::istream_iterator<double>(numbers_stream),
        std::istream_iterator<double>(),
        std::ostream_iterator<double>(std::cout, " "),
        [&index](double) { return index++ % 2 == 0; });
}

} // namespace

void RunTask4() {
    const std::string line = ReadNumbers();
    std::cout << "[РЕЗУЛЬТАТ] Числа с четными порядковыми номерами:\n";
    SelectEvenOrderNumbers(line);
    std::cout << '\n';
}
