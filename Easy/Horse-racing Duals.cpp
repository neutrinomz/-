#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    vector<int> hour_list;
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi; cin.ignore();
        //Создаем список с силами лошадей 
        hour_list.push_back(pi);
    
    }

    //сортируем список, чтобы корректно сравнивать значения
    sort(hour_list.begin(), hour_list.end());
    
    int mini = 10000001; //минимальное значения исходя из условий задачи + 1 (0 < Pi ≤ 10000000)
    //Находим разницу между соседними элементами списка
    for (int i = 0; i < n - 1; i++) {
        int dif = hour_list[i + 1] - hour_list[i];
        //если текущая разница по силе между двумя лошадьми меньше, чем находили ранее, обновляем значение mini
        if (dif < mini) {
            mini = dif;
        }

    

    }
    cout << mini;
}