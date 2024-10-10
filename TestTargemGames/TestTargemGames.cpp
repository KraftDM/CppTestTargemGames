// TestTargemGames.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "String.h"

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<const char*> base_strings = { "Pie is delicious", "Apple", "Purple", "Red", "Circle", "Salt", "arc", "ara", "art", "artificial"};

    std::vector<String> strings;
    for (const char* str : base_strings) {
        strings.push_back(String(str));
    }

    std::sort(strings.rbegin(), strings.rend());
    for (String str : strings) {
        str.Print();
    }

    system("pause 0");
}
