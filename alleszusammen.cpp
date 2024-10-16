#include <iostream>

using namespace std;

class SIGN
{
    private:
    string nas;
    string zs;
    //int *date;

    public:

    void set_nas(string nas)
    {
        this->nas = nas;
    }

    void set_zs(string zs)
    {
        this->zs = zs;
    }
    
    //сеттер для даты рождения

    string get_nas()
    {
        return nas;
    }

    string get_zs()
    {
        return zs;
    }

    //геттер для даты рождения

    SIGN ()
    {
        nas = "";
        zs = "";

        cout << "Конструткор по умолчанию" << endl;
    }

    SIGN (string nas, string zs)
    {
        this->nas = nas;
        this->zs = zs;
    }

    ~SIGN ()
    {
        cout << "Деструктор" << endl;
    }
};

int main()
{
    int choice;

    while (choice != 6)
    {
        cout << "---Меню---" << endl;
        cout << "1. Добавить объект" << endl;
        cout << "2. Удалить объект" << endl;
        cout << "3. Изменить данные объекта" << endl;
        cout << "4. Упорядочить объекты по знакам зодиака" << endl;
        cout << "5. Вывести объекты, родившиеся в определенном месяце" << endl;
        cout << "6. Выход из меню" << endl;

        cout << "Введите желаемое действие: ";
        cin >> choice;

        if (choice == 1)
        {
            string nas;
            cout << "Введите имя и фамилию объекта: ";
            cin.ignore();
            getline(cin, nas);

        }

        if (choice == 2)
        {
            
        }

        if (choice == 3)
        {
            
        }

        if (choice == 4)
        {
            
        }

        if (choice == 5)
        {
            
        }
    }



    return 0;
}