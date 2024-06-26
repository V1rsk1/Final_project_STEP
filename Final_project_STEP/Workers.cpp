#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // ��� ���������� ������
#include <Windows.h>
#include <fstream> // ��� ������ � �������


//���� �����, ��� �������� ������� ������ �� ��� ������� ����
#include "Workers.h"
#include "Shop.h"
#include "Goods.h"
#include "Object.h"



void Workers::add_new_worker() {
    Workers worker;



    cout << endl << "��'�: ";
    cin >> worker.name;
    cout << endl << "���������:";
    cin >> worker.salary;
    cout << endl << "�������:";
    cin >> worker.position;
    cout << endl << "�����:";
    cin >> worker.experience;
    cout << endl << "��������:";
    cin >> worker.trait_of_char;




    ofstream file("Workers.txt", ios::app);
    if (file.is_open()) {
        file << endl << worker.name << '|' << worker.salary << '|' << worker.position << '|' << worker.experience << '|' << worker.trait_of_char;
        cout << "��� ������, �������� ESC ��� ������";


    }
    else {
        cout << "�������!";
    }
    file.close();

}



void Workers::out_all_workers(string name) {
    char button;
    string line;
    Shop shop;
    string name_;
    ifstream in1(name + ".txt"); // �������� ���� ��� ������
    if (in1.is_open())
    {

        while (getline(in1, line))
        {

            cout << get_object(line, 0) << '|' << get_object(line, 1) << '|' << get_object(line, 2) << '|' << get_object(line, 3) << '|' << endl;

        }
    }
    in1.close();
    button = _getch();  //�� ��������������� ��� ������������ �����
    if (button == 27) {
        system("cls");
        shop.Main_Menu();


    }
    if (button == 32) {
        system("cls");
        add_new_worker();
        shop.Main_Menu();

    }

}







