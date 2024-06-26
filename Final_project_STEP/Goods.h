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

class Goods : public Object{
public:
    string name;
    int number;
    float price;
    


   



    void out_all_goods(string name);
    

    void add_new_good();

    void del_good();

    void out_all_goods_s(string name);




};


