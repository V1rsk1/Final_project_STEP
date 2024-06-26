#pragma once
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

class Workers:  public Object
{
public:
    string name;
    float salary;
    string position;
    string experience;
    string trait_of_char;

    void add_new_worker();
    
    void out_all_workers(string name);






};

