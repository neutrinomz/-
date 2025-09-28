#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // game loop
    while (1) {
        //формируем список для хранения высоты гор
        int mountain[8];
        for (int i = 0; i < 8; i++) {
            cin >> mountain[i]; cin.ignore();
        }
        
        int maxi = 0;
        int index;
        //Находим самую высокую гору и запоминаем ее индекс
        for (int i = 0; i < 8; i++) {
            if (mountain[i] > maxi) {
                maxi = mountain[i];
                index = i;

            }

        }

        cout << index << endl; 
        }
}