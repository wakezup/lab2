#include <algorithm>
#include <map>
#include <string>
#include <vector>


#include "task_10.h"
#include "input.h"


namespace {

int ReadCount() {
    while (true) {
        const int count = IntegerInput("[ВВОД] Введите кол-во слов: ");
        if (count > 0) {
            return count;
        }
        std::cerr << "[ОШИБКА] Количество слов должно быть "
                     "положительным.\n";
    }
}

std::vector<std::string> ReadVector(int count) {
    std::vector<std::string> vector;
    vector.reserve(count);

    for (int i = 0; i != count; ++i) {
        vector.push_back(EnglishCapsWordInput(
            "[ВВОД] Введите английское слово заглавными буквами: "));
    }

    return vector;
}

std::multimap<char, std::string> GroupWords(
    const std::vector<std::string>& words) {

    std::multimap<char, std::string> multimap;
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        multimap.emplace((*it).back(), *it);
    }

    return multimap;
}

void PrintMultiMap(const std::multimap<char, std::string>& multimap) {
    std::cout << "[РЕЗУЛЬТАТ] Слова, сгруппированные по последней букве:\n";

    for (auto it = multimap.begin(); it != multimap.end(); ++it) {
        std::cout << (*it).first << " -> " << (*it).second << '\n';
    }
}

}  // namespace

void RunTask10() {
    int count = ReadCount();
    std::vector<std::string> words = ReadVector(count);
    const std::multimap<char, std::string> grouped_words = GroupWords(words);
    PrintMultiMap(grouped_words);
}
