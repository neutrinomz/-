#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main()
{
    //Создаем множество для хранения префиксов
    //в  данной задаче удобно работать с множеством
    //т.к. оно хранит только уникальные значения
    set<string>number;
    int n;
    cin >> n; cin.ignore();

    //Обрабатываем каждый номер
    for (int i = 0; i < n; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        for (int j = 1; j <= telephone.length(); j++) {
            //извлекаем подстроку от начала до j
            number.insert(telephone.substr(0,j));

        }
    }

    cout << number.size() << endl;
}