#include <iostream>
#include "vectorN.h"

using namespace std;

int main() {
    setlocale(LC_ALL,"RU");
    VectorN v1(2);
    VectorN v2(5);
    VectorN v3(3);

    int temp = 1;
    double temp_d = 0;
    char continueOp = 'y';
    int op = 0;

    v3 = v2 - v1;
    cout << v3;

    v3 = v1 - v2;
    cout << v3;

    v3.setCord(1, 5);
    v3.setCord(2, 5);
    v3.setCord(3, 5);
    v3.setCord(4, 5);
    v3.setCord(5, 5);
    v3.setCord(6, 5);
    v3.setN(0);          
    v3.setN(2);

    cout << v3.getCord();
    
    cout << v3;

    v3.setN(10);

    cout << v3;
    double* arr = new double[5];
    for (int i = 0; i < 5; ++i) 
    {
        arr[i] = i;
    }

    VectorN v4(5, arr);
    cout << v4 << endl;

    while (continueOp == 'y' || continueOp == 'Y')
    {
        cout << "1 - Ввести координаты для вектора\n2 - Вывести вектор\n3 - Сложить два вектора\n4 - Вычесть два вектора\n5 - Сравнить два вектора\n6 - Умножить ветор на скаляр\n7 - Расширить вектор (измерения)\n8 - Уменшить вектор (измерения)\n9 - Завершить работу\nВведите желаемую операцию: ";
        cin >> op;
        
        switch (op)
        {
        case(1):
            cout << "Введите вектор, для которого хотите ввести координаты (1 или 2):\n";
            cin >> temp;
            if (temp != 1 && temp != 2)
                cout << "Нет такого вектора\n";
            else
                cout << "Введите координаты для вектора:\n";
            if (temp == 1)
                cin >> v1;
            if (temp == 2)
                cin >> v2;
            break;
        case(2):
            cout << "Введите вектор, для которого хотите вывести координаты (1 или 2 или 3):\n";
            cin >> temp;
            if (temp != 1 && temp != 2 && temp != 3)
                cout << "Нет такого вектора\n";
            if (temp == 1)  
                cout << v1;
            if (temp == 2)
                cout << v2;
            if (temp == 3)
                cout << v3;
            break;
        case(3):
            v3 = v1 + v2;
            cout << "Итоговый вектор: " << v3 << endl;
            break;
        case(4):
            v3 = v1 - v2;
            cout << "Итоговый вектор: " << v3 << endl;
            break;
        case(5):
            v1 == v2 ? cout << "Векторы равны\n" : cout << "Векторы не равны\n";
            break;
        case(6):
            cout << "Введите вектор, который хотите умножить на скаляр (1 или 2):\n";
            cin >> temp;
            if (temp != 1 && temp != 2)
            {
                cout << "Нет такого вектора\n";
                break;
            }
            cout << "Введите число, на которое хотите умножить: " << endl;
            cin >> temp_d;
            if (temp == 1)
                v1.multip(temp_d);
            if (temp == 2)
                v2.multip(temp_d);
            break;
        case(7):
            cout << "Введите вектор, у которого хотите увеличить размерность (1 или 2):\n";
            cin >> temp;
            cout << "Введите число, которое хотите добавить: " << endl;
            cin >> temp_d;
            if (temp == 1)
                v1.incDim(temp_d);
            if (temp == 2)
                v2.incDim(temp_d);
            break;
        case(8):
            cout << "Введите вектор, у которого хотите уменьшить размерность (1 или 2):\n";
            cin >> temp;
            if (temp == 1)
                v1.decDim();
            if (temp == 2)
                v2.decDim();
            break;
        case(9):
            exit(0);
        default:
            cout << "Такой операции не существует\n";
            break;
        }

        cout << "\nЧтобы продолжить введите y/Y ,иначе n/N\n";
        cin >> continueOp;
        system("cls");
    }
    return 0;
}
 