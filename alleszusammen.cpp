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

    while (choice != 7)
    {
        cout << "---Меню---" << endl;
        cout << "1. Добавить объект" << endl;
        cout << "2. Удалить объект" << endl;
        cout << "3. Изменить данные объекта" << endl;
        cout << "4. Упорядочить объекты по знакам зодиака" << endl;
        cout << "5. Показать объекты" << endl;
        cout << "6. Вывести объекты, родившиеся в определенном месяце" << endl;
        cout << "7. Выход из меню" << endl;

        cout << "Введите желаемое действие: ";
        cin >> choice;

        if (choice == 1)
        {
            string nas;
            cout << "Введите имя и фамилию объекта: ";

        }

        else if (choice == 2)
        {
            int num;
            cout << "Введите порядковый номер объекта, который хотите удалить: ";
            cin >> num;
            //
        }

        else if (choice == 3)
        {
            cout << "Какие данные вы хотите изменить?" << endl;
            cout << "1. Имя и Фамилию" << endl;
            cout << "2. Знак зодиака" << endl;
            cout << "3. Дату рождения" << endl;

            int choice2;
            cout << "Введите выбор: " << endl;
            //
        }

        else if (choice == 4)
        {
            cout << "Объекты были упорядочены по знакам зодиака" << endl;
            //
        }

        else if (choice == 5)
        {
            cout << "Объекты:" << endl;
            //
        }

        else if (choice == 6)
        {
            int month;
            cout << "1. Январь" << endl;
            cout << "2. Февраль" << endl;
            cout << "3. Март" << endl;
            cout << "4. Апрель" << endl;
            cout << "5. Май" << endl;
            cout << "6. Июнь" << endl;
            cout << "7. Июль" << endl;
            cout << "8. Август" << endl;
            cout << "9. Сентябрь" << endl;
            cout << "10. Октябрь" << endl;
            cout << "11. Ноябрь" << endl;
            cout << "12. Декабрь" << endl;
            cout << "Введите порядковый номер месяца: ";
            cin >> month;
            //
        }

    }
    return 0;
}