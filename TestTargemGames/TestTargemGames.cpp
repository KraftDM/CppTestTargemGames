// TestTargemGames.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "String.h"

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<String> strings = { "Pie is delicious", "Apple", "Purple", "Red", "Circle", "Salt", "arc", "red", "art", "artificial", "Red"};

    std::sort(strings.rbegin(), strings.rend());
    for (String str : strings) {
        str.Print();
    }

    system("pause 0");
}
