#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // для зчитування кнопок
#include <Windows.h>
#include <fstream> // для роботи з файлами
#include <stdlib.h>//для переведення типів даних(бібліотека ще з мови програмування с)

//Наші класи, для зручного виклику методів та для доступу полів
#include "Workers.h"
#include "Shop.h"
#include "Goods.h"
#include "Object.h"

using namespace std;









string Object::get_object(string line, int num) { //Отримання будь-якого об'єкту з рядку за номером наприклад: об'єкт0|об'єкт1|об'єкт2)
    int i = 0;


    string tmp = "";
    vector<string>vec;
    while (i < line.length()) {
        while (line[i] != '|' && i < line.length()) {

            tmp += line[i];
            i++;


        }

        vec.push_back(tmp);
        tmp = "";

        i++;

    }

    return vec[num];


}

