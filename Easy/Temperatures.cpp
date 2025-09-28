#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{   
    //Задаем минимальное значение (по условию задачи -273 to 5526)
    int mini = 5527;
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    //Если температур нет, возвращаем 0, функция завершается
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    //Обрабатываем каждую температуру
    for (int i = 0; i < n; i++) {
    int t; // a temperature
    cin >> t; cin.ignore();

    //если текущая температура по модулю ближе к 0, запоминаем значение
    if (abs(t) < abs(mini)) {
        mini = t;
    }
    //если температуры одинаково близки, сохраняем положительное значение
    else if ((abs(t) == abs(mini)) & (t > mini)) {
        mini = t;

    }

    }
cout << mini << endl;
}