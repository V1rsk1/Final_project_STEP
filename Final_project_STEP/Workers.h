#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // ��� ���������� ������
#include <Windows.h>
#include <fstream> // ��� ������ � �������
#include <stdlib.h>//��� ����������� ���� �����(�������� �� � ���� ������������� �)

//���� �����, ��� �������� ������� ������ �� ��� ������� ����
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

