#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<string>table;
    int width; 
    cin >> width; cin.ignore();
    int height;
    cin >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
        //Формируем таблицу построчно
        table.push_back(line);
    }

    //Проходимся по всем клеткам поля
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            //Проверяем содержит ли текущая клетка 0
            if (table[y][x] == '0') {
                int st_x = -1;
                int st_y = -1;
                //ищем ближайшую не пустую клетку по горизонтали вправо
                for (int s_x = x + 1; s_x < width; s_x++) {
                    if (table[y][s_x] == '0') {
                        st_x = s_x;
                        st_y = y;

                        break; //Прерываем ближайший цикл for,
                        //дальше проверять бессмысленно, т.к. нужно найти ближайшую клетку
                    }
                }
                int str_x = -1;
                int str_y = -1;
                //ищем ближайшую не пустую клетку по вертикали вниз
                for (int stroka_y = y + 1; stroka_y < height; stroka_y++) {
                    if (table[stroka_y][x] == '0') {
                        str_x = x;
                        str_y = stroka_y;
                        break;
                    }
                }
                cout << x << " " << y << " " << st_x << " " << st_y << " " << str_x << " " << str_y << endl;
            }
        }
    }
}