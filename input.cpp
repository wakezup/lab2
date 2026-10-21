#include "input.h"


bool IsInteger(const std::string& str) {
    if (str.empty()) return false;
    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    for (size_t i = start; i < str.size(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

bool IsReal(const std::string& str) {
    if (str.empty()) return false;
    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    bool decimalPointFound = false;
    for (size_t i = start; i < str.size(); ++i) {
        if (str[i] == '.') {
            if (decimalPointFound) return false;
            decimalPointFound = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool IsEnglishCapsWord(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    for (char ch : str) {
        if (ch < 'A' || ch > 'Z') {
            return false;
        }
    }

    return true;
}

int IntegerInput(const std::string& prompt) {
    std::string input = "";

    std::cout << prompt;

    while (true) {
        std::cin >> input;

        if (!IsInteger(input)) {
            std::cerr << "[ОШИБКА] Введеное значение не является целым числом."
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(1'000'000, '\n');
            std::cout << prompt;
        } else {
            return std::stoi(input);
        }
    }
}

int TaskInput(const std::string& prompt, int task_count) {
    int task;

    while (true) {
        task = IntegerInput(prompt);

        if (task < 0 || task > task_count) {
            std::cerr << "[ОШИБКА] Такой задачи не существует." << std::endl;
        } else {
            return task;
        }
    } 
}

double RealInput(const std::string& prompt) {
    std::string input = "";

    std::cout << prompt;

    while (true) {
        std::cin >> input;
        if (!IsReal(input)) {
            std::cerr << "[ОШИБКА] Введеное значение не является "
                         "действительным числом." << std::endl;
            std::cin.clear();
            std::cin.ignore(1'000'000, '\n');
            std::cout << prompt;
        } else {
            return std::stod(input);
        }
    }
}

std::string EnglishCapsWordInput(const std::string& prompt) {
    std::string input;

    std::cout << prompt;

    while (true) {
        std::cin >> input;
        if (!IsEnglishCapsWord(input)) {
            std::cerr << "[ОШИБКА] Введеное значение не является "
                         "английским словом с заглавными буквами." << std::endl;
            std::cin.clear();
            std::cin.ignore(1'000'000, '\n');
            std::cout << prompt;
        } else {
            return input;
        }
    }
}