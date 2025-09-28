#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    string lon;
    cin >> lon; cin.ignore();
    string lat;
    cin >> lat; cin.ignore();
    int n;
    cin >> n; cin.ignore();

    //В строчках с координатами пользователя заменяем запятые на точнки
    //для преобразования координат в числа с плавающей точкой
    for (int i = 0; i < lon.length(); i++) {
        if (lon[i] == ',') {
            lon[i] = '.';
        }
    }

    for (int i = 0; i < lat.length(); i++) {
        if (lat[i] == ',') {
            lat[i] = '.';
        }
    }
    double mini = 1000000000; //для поиска минимума

    double uLon = stod(lon);
    double uLat = stod(lat);
    string cAddr = "";
    for (int i = 0; i < n; i++) {
        string defib;
        getline(cin, defib);
        vector<string>list_inf;
        string st;

        //Создание списка с описанием дифибриллятора
        for (char c: defib) {
            if (c == ';') {
                list_inf.push_back(st);
                st = "";
            } else {
                st += c;
            }
        }
        //добавляем последнюю часть, так как в конце нет ;
        list_inf.push_back(st);

        //из списка достаем нужные данные
        string pLon = list_inf[4];
        string pLat = list_inf[5];
        string addr = list_inf[1];
        
		//для пребразования координат дефибриллятора в числа
        for (int i = 0; i < pLon.length(); i++) {
            if (pLon[i] == ',') {
                pLon[i] = '.';
                }
            }

        for (int i = 0; i < pLat.length(); i++) {
            if (pLat[i] == ',') {
                pLat[i] = '.';
            }
        }

        //преобразуем координаты дефибриллятора в числа
        double pdLon = stod(pLon);
        double pdLat = stod(pLat);

        //вычисляем расстояние между дефибриллятором и пользователем
        double x = (pdLon - uLon)* cos((pdLat+uLat)/2);
        double y = pdLat - uLat;
        double d = sqrt(x*x + y*y) * 6371;

        //проверяем, является ли данный дефибриллятор ближайшим,
        //  если да, то запоминаем название
        if (d<mini) {
            mini = d;
            cAddr = addr;
        }
    }
    cout << cAddr << endl;
}