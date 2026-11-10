// Lab_08_1_string.cpp
// Фащевський Богдан
// Лабораторна робота № 8.1
// Варіант 28
// Пошук та заміна символів у літерному рядку

#include <iostream>
#include <string>
using namespace std;

// 1. Функція перевірки наявності всіх букв зі слова "while" за допомогою s.find()
bool Include(const string s)
{
    string cs = "while";                             // Створюю контрольний рядок із букв слова "while", наявність яких перевірятиметься
    bool r = true;                                   // Оголошую булевий прапорець r та ініціалізую його значенням true (припускаю, що всі букви є)
    for (size_t i = 0; i < cs.length(); i++)         // Ітераційний цикл перебирає кожен символ контрольного рядка cs за його індексом i
    {
        r = r && (s.find(cs[i]) != string::npos);   // Метод s.find() шукає символ cs[i] в рядку s, результат порівнюється з string::npos та накопичується через логічне "І"
    }
    return r;                                        // Повертаю результат r у місце виклику функції (true — якщо знайшов усі букви, false — якщо ні)
}

// 2. Функція заміни кожної групи букв "while" парою зірочок "**" за допомогою s.find() та s.replace()
string Change(string& s)
{
    size_t pos = 0;                                  // Оголошую змінну pos для збереження поточного індексу пошуку підрядка (починаю з індексу 0)
    while ((pos = s.find("while", pos)) != string::npos) // Цикл шукає входження підрядка "while", починаючи з pos, доки find не поверне string::npos
    {
        s.replace(pos, 5, "**");                    // Метод replace замінює 5 символів слова "while", починаючи з позиції pos, на подвійну зірочку "**"
        pos += 2;                                    // Зсуваю зміщення pos на 2 символи вправо (на довжину вставленого рядка "**"), щоб уникнути зациклення
    }
    return s;                                        // Повертаю вихідний модифікований рядок s
}

#ifndef UNIT_TESTING
int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    if (Include(str))
        cout << "String contains all letters from 'while'" << endl;
    else
        cout << "String DOES NOT contain all letters from 'while'" << endl;
    string dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
#endif