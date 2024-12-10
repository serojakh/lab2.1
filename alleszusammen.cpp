#include <iostream>
#include <string>

using namespace std;

class SIGN
{
private:
    string nas; 
    string zs;  
    int* date;  

public:
    void set_nas(string nas)
    {
        this->nas = nas;
    }

    void set_zs(string zs)
    {
        this->zs = zs;
    }

    void set_date(int day, int month, int year)
    {
        if (date == nullptr)
            date = new int[3];
        date[0] = day;
        date[1] = month;
        date[2] = year;
    }

    string get_nas() const
    {
        return nas;
    }

    string get_zs() const
    {
        return zs;
    }

    int* get_date() const
    {
        return date;
    }

    SIGN() : date(nullptr)
    {
        cout << "Default constructor" << endl;
    }

    SIGN(string nas, string zs, int day, int month, int year)
    {
        this->nas = nas;
        this->zs = zs;
        date = new int[3];
        date[0] = day;
        date[1] = month;
        date[2] = year;
        cout << "Constructor with parameters" << endl;
    }

    ~SIGN()
    {
        delete[] date;
        cout << "Destructor" << endl;
    }

    void display() const
    {
        cout << nas << " (" << (date[0] < 10 ? "0" : "") << date[0] << "."
             << (date[1] < 10 ? "0" : "") << date[1] << "." << date[2]
             << ") - " << zs << endl;
    }

    int getZodiacIndex() const
    {
        if (zs == "capricorn") return 0;
        if (zs == "aquarius") return 1;
        if (zs == "pisces") return 2;
        if (zs == "aries") return 3;
        if (zs == "taurus") return 4;
        if (zs == "gemini") return 5;
        if (zs == "cancer") return 6;
        if (zs == "leo") return 7;
        if (zs == "virgo") return 8;
        if (zs == "libra") return 9;
        if (zs == "scorpio") return 10;
        if (zs == "sagittarius") return 11;
        return -1;
    }

    friend ostream& operator<<(ostream& out, const SIGN& sign)
    {
        out << sign.nas << " (";
        if (sign.date)
        {
            out << (sign.date[0] < 10 ? "0" : "") << sign.date[0] << "."
                << (sign.date[1] < 10 ? "0" : "") << sign.date[1] << "."
                << sign.date[2];
        }
        else
        {
            out << "not set";
        }
        out << ") - " << sign.zs;
        return out;
    }

    friend istream& operator>>(istream& in, SIGN& sign)
    {
        cout << "Enter name and surname: ";
        in.ignore();
        getline(in, sign.nas);
        cout << "Enter zodiac sign: ";
        getline(in, sign.zs);

        int day, month, year;
        cout << "---Enter birth date---" << endl;
        cout << "Day: ";
        in >> day;
        while (day > 31)
        {
            cout << "Invalid day! Try again: ";
            in >> day;
        }

        cout << "Month: ";
        in >> month;
        while (month > 12)
        {
            cout << "Invalid month! Try again: ";
            in >> month;
        }

        cout << "Year: ";
        in >> year;

        sign.set_date(day, month, year);
        return in;
    }
};

void editObject(SIGN** objects, int size, int num)
{
    if (num < 1 || num > size)
    {
        cout << "Invalid object number!" << endl;
        return;
    }

    SIGN* obj = objects[num - 1];
    cout << "Which data do you want to edit?" << endl;
    cout << "1. Name and Surname" << endl;
    cout << "2. Zodiac sign" << endl;
    cout << "3. Birth date" << endl;

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        string nas;
        cout << "Enter new name and surname: ";
        cin.ignore();
        getline(cin, nas);
        obj->set_nas(nas);
    }
    else if (choice == 2)
    {
        string zs;
        cout << "Enter new zodiac sign: ";
        cin.ignore();
        getline(cin, zs);
        obj->set_zs(zs);
    }
    else if (choice == 3)
    {
        int day, month, year;
        cout << "---Enter new birth date (day, month, year)---" << endl;
        cout << "Day: ";
        cin >> day;
        while (day > 31)
        {
            cout << "Invalid day! Try again: ";
            cin >> day;
        }

        cout << "Month: ";
        cin >> month;
        while (month > 12)
        {
            cout << "Invalid month! Try again: ";
            cin >> month;
        }

        cout << "Year: ";
        cin >> year;

        obj->set_date(day, month, year);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}

void deleteObject(SIGN**& objects, int& size, int num)
{
    if (num < 1 || num > size)
    {
        cout << "Invalid object number!" << endl;
        return;
    }

    SIGN** temp = new SIGN*[size - 1];
    int index = 0;

    for (int i = 0; i < size; ++i)
    {
        if (i == num - 1)
        {
            delete objects[i];
            continue;
        }
        temp[index++] = objects[i];
    }

    delete[] objects;
    objects = temp;
    --size;

    cout << "Object deleted!" << endl << endl;
}

void sortObjects(SIGN** objects, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (objects[j]->getZodiacIndex() > objects[j + 1]->getZodiacIndex())
            {
                SIGN* temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }

    cout << "Objects have been sorted by zodiac signs." << endl << endl;
}

void filterByMonth(SIGN** objects, int size, int month)
{
    cout << "Objects born in month " << month << ":" << endl;
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        int* date = objects[i]->get_date();
        if (date && date[1] == month)
        {
            cout << i + 1 << ". " << *objects[i] << endl;
            ++count;
        }
    }

    if (count == 0)
    {
        cout << "No objects were born in the specified month." << endl;
    }
}

int main()
{
    int choice;
    SIGN** objects = nullptr;
    int size = 0;

    while (choice != 7)
    {
        cout << "---Menu---" << endl;
        cout << "1. Add object" << endl;
        cout << "2. Delete object" << endl;
        cout << "3. Edit object data" << endl;
        cout << "4. Sort objects by zodiac signs" << endl;
        cout << "5. Show objects" << endl;
        cout << "6. Show objects born in a specific month" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            SIGN** temp = new SIGN*[size + 1];
            for (int i = 0; i < size; ++i)
            {
                temp[i] = objects[i];
            }

            temp[size] = new SIGN();
            cin >> *temp[size];

            delete[] objects;
            objects = temp;
            ++size;

            cout << "Object added!" << endl << endl;
        }
        else if (choice == 2)
        {
            int num;
            cout << "Enter the object number to delete: ";
            cin >> num;
            deleteObject(objects, size, num);
        }
        else if (choice == 3)
        {
            int num;
            cout << "Enter the object number to edit: ";
            cin >> num;
            editObject(objects, size, num);
        }
        else if (choice == 4)
        {
            sortObjects(objects, size);
        }
        else if (choice == 5)
        {
            for (int i = 0; i < size; ++i)
            {
                cout << i + 1 << ". " << *objects[i] << endl;
            }
        }
        else if (choice == 6)
        {
            int month;
            cout << "Enter the month number: ";
            cin >> month;
            filterByMonth(objects, size, month);
        }
    }

    for (int i = 0; i < size; ++i)
    {
        delete objects[i];
    }
    delete[] objects;

    return 0;
}

