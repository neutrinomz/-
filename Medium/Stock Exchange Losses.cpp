#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{   
    int n;
    cin >> n; cin.ignore();
    vector<int>list_int(n);
    //список со всеми ценами
    for (int i = 0; i<n;i++) {
        cin >> list_int[i];
    }
    //Устанавливаем текущее максимальное значение цены
    int maxpr = list_int[0];
    //максимальное значение падения устанавливаем равным 0
    int m = 0;
    for (int j = 1; j<n;j++) {
        //Находим разницу между максимальным и текущим значением
        int l = maxpr - list_int[j];
        //если разница больше, перезаписываем максимальную разницу
        if (l > m) {
            m = l;
        }
        //Если текущий элемент больше текущего максимума, обновляем максимум
        if (list_int[j] > maxpr) {
            maxpr = list_int[j];
        }
    }
    cout << -m;
}


