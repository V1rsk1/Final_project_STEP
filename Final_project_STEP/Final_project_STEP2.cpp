#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <fstream>

#include <stdlib.h>

using namespace std;


class Shop{

public:
    string Name;
    int balance;
    int amount_of_goods = 0;
    int amount_of_providers = 0;


    void set_name(string a) {
        Name = a;


    }
    string get_name() {
        return Name;
    }

    virtual void show_all() {
        cout << endl << Name << endl << balance << endl << amount_of_goods << endl << amount_of_providers<<endl;


    }

};

class Goods : public Shop {
public:
    string name;
    int number;
    float price;
    float weight;
    bool discount_b;
    int discount;



    virtual void show_all() {
        cout << endl << name << endl << number << endl << price << endl << weight << discount_b <<endl<< discount<<endl;


    }


};


class Workers{
public:
    string name;
    float salary;
    string position;
    string experience;
    string trait_of_char;
  
};

class Providers {
public:
    string company;
    string type_of_goods;
    int rating;

};






void Main_Menu();



string for_goods(string line, int num) {
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



void out_al_promotions(string name) {
    char button;
    string line;
    string name_;
    ifstream in1(name + ".txt"); 
    if (in1.is_open())
    {

        while (getline(in1, line))
        {

            cout << for_goods(line, 0) << '|' << for_goods(line, 1) << '|' << for_goods(line, 2) << endl;

        }
    }
    in1.close();
    button = _getch();
    if (button == 27) {
        system("cls");
        Main_Menu();


    }

}

void add_new_worker() {
     Workers worker;
 
    

    cout << endl << "Ім'я: ";
    cin >> worker.name;
    cout << endl << "Зарплатня:";
    cin >> worker.salary;
    cout << endl << "Позиція:";
    cin >> worker.position;
    cout << endl << "Досвід:";
    cin >> worker.experience;
    cout << endl << "Характер:";
    cin >> worker.trait_of_char;


    

    ofstream file("Workers.txt", ios::app);
    if (file.is_open()) {
        file << endl <<worker.name << '|' << worker.salary << '|' << worker.position << '|' << worker.experience << '|' << worker.trait_of_char;
        cout << "Все гаразд, натисніть ESC для виходу";


    }
    else {
        cout << "Помилка!";
    }
    file.close();

}

void add_new_provider() {
    Providers provider;



    cout << endl << "Назва: ";
    cin >> provider.company;
    cout << endl << "Товари:";
    cin >> provider.type_of_goods;
    cout << endl << "Рейтинг:";
    cin >> provider.rating;
    




    ofstream file("Providers.txt", ios::app);
    if (file.is_open()) {
        file << endl << provider.company << '|' << provider.type_of_goods << '|' << provider.rating;
        cout << "Все гаразд, натисніть ESC для виходу";


    }
    else {
        cout << "Помилка!";
    }
    file.close();

}



void add_new_good() {

    Goods good;


    cout <<endl<< "Назва товару: ";
    cin >> good.name;
    cout << endl << "Кількість:";
    cin >> good.number;
    cout << endl << "Ціна:";
    cin >> good.price;
    ofstream file("Goods.txt", ios::app);
    if (file.is_open()) {
        file << endl<< good.name << '|' << good.number << '|' << good.price ;
        cout << "Все гаразд, натисніть ESC для виходу";


    }
    else {
        cout << "Помилка!";
    }
    file.close();

}

void del_good() {

    Goods good;
    int num;
  
    string line;
   

    vector<string>vec;


    
    cout << "Номер товару: " << endl;
    cin >> num;
    ifstream file2("Goods.txt");
    if (file2.is_open()) {

        while (getline(file2, line))
        {
           

            vec.push_back(line);
            



        }
        

    }
    else {
        cout << "Помилка!";
    }



    file2.close();
    int pos;

    pos = vec.size() - num+1;


    vec.erase(vec.end()-pos);

    cout << num << pos << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;


   }


    ofstream file("Goods.txt");
    if (file.is_open()) {

        for (int i = 0; i < vec.size(); i++) {

            file << vec[i] << endl;
        }
        
        

        cout << "Все гаразд, натисніть ESC для виходу";
    }
    
    else {
        cout << "Помилка!";
    }
    file.close();

}


void out_all_goods(string name) {
    string line;
    string name_;
    Shop shop;
    char button;
    int count=1;

    ifstream in1(name+".txt"); 
    system("cls");
   
    cout << "\t\t\t\t\t\t\t\t" << "Всі товари"<<endl;
    cout << "Якщо треба додати товар власноруч натисніть пробіл" << endl;
    cout << "Якщо треба видалити товар натисніть q" << endl;
    if (in1.is_open())
    {

        while (getline(in1, line))
        {

           cout << count <<") " << for_goods(line, 0) << '|' << for_goods(line, 1) << '|' << for_goods(line, 2) << endl;
           count++;
            
        }
    }
    in1.close();
    button = _getch();
    if (button == 27) {
        system("cls");
        Main_Menu();


    }
    else if (button == 32) {
        add_new_good();



    }
    else if (button == 'q') {
        del_good();
    }
    button = _getch();
    if (button == 27) {
        system("cls");
        Main_Menu();


    }
}

void out_all_goods_s(string name) {
    Shop shop;
    string line;
    string name_;
    
    char button;
 

    ifstream in1(name + ".txt"); 
    system("cls");
    
    if (in1.is_open())
    {

        while (getline(in1, line))
        {
            shop.amount_of_goods++;
            

        }
    }
    in1.close();
    

    ofstream in2("Amount_Goods.txt");
    in2 << shop.amount_of_goods;
    in2.close();

   
}


void out_all_providers(string name) {
    char button;
    string line;
    string name_;
    ifstream in1(name + ".txt"); // окрываем файл для чтения
    if (in1.is_open())
    {

        while (getline(in1, line))
        {

            cout << for_goods(line, 0) << '|' << for_goods(line, 1) << '|' << for_goods(line, 2) << endl;

        }
    }
    in1.close();
    button = _getch();//це використовується для застосування клавіш
    if (button == 27) {
        system("cls");
        Main_Menu();


    }
    else if (button == 32) {
        
        add_new_provider();
        system("cls");
        Main_Menu();

    }
}

void out_all_workers(string name) {
    char button;
    string line;
    string name_;
    ifstream in1(name + ".txt"); // окрываем файл для чтения
    if (in1.is_open())
    {

        while (getline(in1, line))
        {

            cout << for_goods(line, 0) << '|' << for_goods(line, 1) << '|' << for_goods(line, 2) <<'|'<<for_goods(line,3)<< '|' << endl;

        }
    }
    in1.close();
    button = _getch();
    if (button == 27) {
        system("cls");
        Main_Menu();


    }
    if (button == 32) {
        system("cls");
        add_new_worker();
        Main_Menu();

    }

}


void Main_Info() {


    Shop shop;
    Goods goods;
    Workers workers;
    string line;
    out_all_goods_s("Goods");
    ifstream in1("Shop_Name.txt"); 
    if (in1.is_open())
    {

        while (getline(in1, line))
        {
            shop.Name = line;
        }
    }
    in1.close();


    ifstream in4("Amount_Goods.txt");
    if (in4.is_open())
    {

        while (getline(in4, line))
        {
            shop.amount_of_goods = stoi(line);
        }
    }
    in4.close();



    ifstream in3("Balance.txt");
    if (in3.is_open())
    {

        while (getline(in3, line))
        {
            shop.balance = stoi(line);
        }
    }
    in3.close();



    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char tmp[24];
    vector<string>info_variants;
    int cursor = 0;
    bool enter = false;
    char button;
    info_variants = { "Змінити назву","К-сть товарів: ", "К-сть постачальників: ", "Баланс: " };
    while (enter == false) {
        cout << "\t\t\t\t\t\t\t\t" << "Основні відомості про магазин" << endl;

        for (int i = 0; i < info_variants.size(); i++) {
            if (i != cursor ) {
                if (i == 1) {
                    cout << info_variants[i] <<shop.amount_of_goods << endl;
                }
                else if (i == 2) {
                    cout << info_variants[i] << shop.amount_of_providers << endl;


                }
                else if (i == 3) {
                    cout << info_variants[i] << shop.balance << '$' << endl;

                }


                else {
                    cout << info_variants[i] << endl;


                }

                
                

            }
            
            
            else {
                cout << '*' << info_variants[i] << '*' << endl;
            }



        }
        button = _getch();
       
        if (button == 13) {
            enter = true;
            system("cls");
        }
        else if (button == 27) {
            system("cls");
            Main_Menu();


        }
        else {
            system("cls");
        }
        
    }
    cout << "\t\t\t\t\t\t\t\t" << "Зміна назви" << endl;
    cout << "Яку назву ви хочите?" << endl;
    cout << "Введіть: ";
    cin.get(tmp, 24);
    shop.set_name(tmp);

    ofstream in2("Shop_Name.txt"); 
    if (in2.is_open())
    {
        in2 << tmp << endl;

        
    }
    in2.close();
    cout << "Ваше нова назва: " << shop.get_name();
    button = _getch();

     if (button == 27) {
        system("cls");
        Main_Menu();


    }
    

    
}

void Main_Menu() {
    

    Shop shop;
    Goods goods;
    Workers workers;
    string line;

    ifstream in("Shop_Name.txt"); 
    if (in.is_open())
    {

        while (getline(in, line))
        {
            shop.Name = line;
        }
    }
    in.close();

    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    vector<string>menu_variants;
    int cursor = 0;
    bool enter = false;
    char button;
    menu_variants = { "Основні відомості про магазин","Товари",  "Постачальники", "Робітники"};
    while (enter == false) {

        cout << "\t\t\t\t\t\t" << "Головне меню магазину " << shop.Name << endl;
        for (int i = 0; i < menu_variants.size(); i++) {
            if (i != cursor) {
                cout << menu_variants[i] << endl;


            }
            else {


                cout << '*' << menu_variants[i] << '*' << endl;
            }



        }
        button = _getch();
        //cout << button;
        if (button == 'P') {


            system("cls");
            if (cursor + 1 == menu_variants.size()) {
                cursor = 0;
            }
            else {
                cursor++;
            }




        }
        else if (button == 'H') {


            system("cls");
            if (cursor - 1 < 0) {
                cursor = menu_variants.size() - 1;
            }
            else {
                cursor--;
            }


        }
        else if (button == 13) {
            enter = true;
        }
        else {
            system("cls");
        }

    }

    switch (cursor) {
    case 0:
        system("cls");
        Main_Info();
        system("cls");
        break;

    case 1:
        system("cls");
        out_all_goods("Goods");
        system("cls");
        
        break;

   

    case 2:
        system("cls");
        out_all_providers("Providers");
        system("cls");
        break;
   
    case 3:
         system("cls");
         out_all_workers("Workers");
         system("cls");
         break;
    }
    

}
int main()
{
    Main_Menu();
}


