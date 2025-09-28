#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int currentX = initialTX;
    int currentY = initialTY;

    // Цикл выполняется пока не достиигнем цели или не закончится энергия
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        //вычисляем разницу между текущим положением и целью
        int diffX = lightX - currentX;
        int diffY = lightY - currentY;

        string direction = "";

        //Сначала определяем движение по вертикали, т.к. направление движения
        //формируется по Y и меняем текущее положение
        if (diffY > 0) {
            direction += "S";
            currentY++;
        } else if (diffY < 0) {
            direction += "N";
            currentY--;
        }
        //Определяем движение по горизонтали
        if (diffX > 0) {
            direction += "E";
            currentX++;
        } else if (diffX < 0) {
            direction += "W";
            currentX--;
        }

        
        cout << direction << endl;
    }
}