#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, string>mime_dict;
int main()
{
    int n; 
    cin >> n; cin.ignore();
    int q;
    cin >> q; cin.ignore();

    for (int i = 0; i < n; i++) {
        string ext; // file extension
        string mt; // MIME type.
        cin >> ext >> mt; cin.ignore();
        //приводим расширение к нижему регистру для 4 теста
        for (char &e : ext) { //проходимся по каждуму элементу строки расширения ext и меняем на нижний регистр

            e = tolower(e);
        }
         //Создаем словарь где ключ = расширение, значение Mime type
        mime_dict[ext] = mt;
    }

    for (int i = 0; i < q; i++) {
        int ind;
        string fname;
        getline(cin, fname); 
        //находим индекс точки с конца, чтобы далее сделать срез
        ind = fname.rfind(".");
        //Если индекс не найден, значит расширение не указано, переходим к следующей итерации
        if (ind == -1) {
            cout << "UNKNOWN\n";
            continue;
        }
        //Делаем срез после знака ".", чтобы получить расширение
        string key = fname.substr(ind + 1);
        //Приводим расширение к нижнему регистру для теста 4
        for (char &k : key) {
            k = tolower(k);
        }
        //Если ключ существует в созданном словаре, выводим MIME type
        if (mime_dict.find(key) != mime_dict.end()) {
            cout << mime_dict[key] << endl;
        } else {
            cout << "UNKNOWN\n";
        }
    }  
}