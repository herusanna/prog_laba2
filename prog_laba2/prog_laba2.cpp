#include <iostream>
#include<string.h>
using namespace std;
struct name
{
    char F[56];
    char I[32];
    char O[32];
    void setName() {
        cout << "\nFirst name : ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(F, 56);

        cout << endl << "Second name : ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(I, 32);

        cin.ignore(cin.rdbuf()->in_avail());
        cout << endl << "Last name : ";
        cin.getline(O, 32);
    }
    void showName() {
        cout << "FIO: " << F << " " << I << " " << O << endl;
    }
};
struct adress
{
    int index;
    char country[30];
    char region[30];
    char district[30];
    char city[20];
    char street[20];
    int house;
    int apartment;
    void setAdress() {
        cout << endl << "Index: ";
        while (!(cin >> index))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Country:  ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(country, 30);

        cout << endl << "Region:";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(region, 30);

        cout << endl << "District: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(district, 30);

        cout << endl << "City: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(city, 20);

        cout << endl << "Street: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(city, 20);

        cout << endl << "House: ";
        while (!(cin >> house))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Apartment: ";
        while (!(cin >> apartment))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }
    }
    void showAdress() {
        cout << "Index: " << index << endl;
        cout << "Country: " << country << endl;
        cout << "Region: " << region << endl;
        cout << "District: " << district << endl;
        cout << "City: " << city << endl;
        cout << "Street: " << street << endl;
        cout << "House: " << house << endl;
        cout << "Apartment: " << apartment << endl;
    }
};
struct hospital
{
    int NumHosp;
    char Department[30];
    int NumCard;
    char Diagnosis[30];
    int BloodType;
    void setHospital()
    {
        cout << endl << "Hospital number: ";
        while (!(cin >> NumHosp))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Hospital department: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Department, 30);

        cout << endl << "Medical card number: ";
        while (!(cin >> NumCard))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Patient's diagnosis: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Diagnosis, 30);

        cout << endl << "Patient's blood type: ";
        while (!(cin >> BloodType))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }
    }
    void showHospital()
    {
        cout << endl << "Hospital's number: " << NumHosp;
        cout << endl << "Hospital department: " << Department;
        cout << endl << "Medical card number: " << NumCard;
        cout << endl << "Patient's diagnosis: " << Diagnosis;
        cout << endl << "Patient's blood type: " << BloodType;
    }
};
struct patient
{
    name person;
    adress home;
    hospital Data;
    long Tele;
    char Sex[30];
    char Nationality[30];
    int Height;
    int Weight;
    void setInfo() {
        person.setName();
        home.setAdress();
        Data.setHospital();

        cout << endl << "Telephon number: ";
        cin >> Tele;

        cout << endl << "Sex: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Sex, 8);

        cout << endl << "Nationality: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Nationality, 30);

        cout << endl << "Height: ";
        cin >> Height;

        cout << endl << "Weight: ";
        cin >> Weight;
    }
    void showInfo() {
        person.showName();

        cout << "Telephon number: " << Tele << endl;

        home.showAdress();

        Data.showHospital();

        cout << "Sex: " << Sex << endl;
        cout << "Nationality: " << Nationality << endl;
        cout << "Height: " << Height << endl;
        cout << "Weight :" << Weight << endl;
    }
};
/*patient* addPerson(patient* Man, const int amount);
void InitPerson(patient* Man, const int amount);
void showPerson(const patient* Man, const int amount);

patient* AddPerson(patient* Man, const int amount) {

if (amount == 0)
{
Man = new patient[amount + 1];
}
else
{
patient* tempMan = new patient[amount + 1];

for (int i = 0; i < amount; i++)
{
tempMan[i] = Man[i];
// cin >> tempMan[i];
}
delete[] Man;
Man = tempMan;
}
return Man;
}*/

void  InitPerson(patient* Man, int* size)
{
    for (size_t i = 0; i < *size; i++)
    {
        (Man + i)->setInfo();
    }
}

void sortPerson(patient* Man, int* size) {

    for (int i = 0; i < *size; i++)
    {
        for (int j = 0; j < *size - 1; j++) {
            if (int((Man + j)->person.F[0]) > int((Man + j + 1)->person.F[0]))
            {
                swap((Man + j)->person, (Man + j + 1)->person);
                swap((Man + j)->Tele, (Man + j + 1)->Tele);
                swap((Man + j)->home, (Man + j + 1)->home);
                swap((Man + j)->Data, (Man + j + 1)->Data);
                swap((Man + j)->Sex, (Man + j + 1)->Sex);
                swap((Man + j)->Nationality, (Man + j + 1)->Nationality);
                swap((Man + j)->Height, (Man + j + 1)->Height);
                swap((Man + j)->Weight, (Man + j + 1)->Weight);
            }
        }
    }
}
void showPerson(patient* Man, int* size) {
    for (size_t i = 0; i < *size; i++)
    {
        (Man + i)->showInfo();
    }
}

void searchPerson(patient* Man, int num) {
    (Man + num - 1)->showInfo();
}

int main()
{

    int size;
    int num;
    cout << "Enter size of patients: ";
    cin >> size;
    int* tempSize = &size;
    patient* Man = new patient[size];
    InitPerson(Man, tempSize);
    sortPerson(Man, tempSize);
    int varForSwitch;
    cout << "What would you like to do:" << endl << "1. See patient's data" << endl << "2.Search patient's data by second name (F)" << endl << "3. Exit the program";
    cout << "Choose your action 1-3: ";
    cin >> varForSwitch;
    switch (varForSwitch)
    {
    case 1:
        for (int i = 0; i < size; i++)
        {
            cout << "Patient " << i + 1 << ":" << endl << endl;
            showPerson(Man, tempSize);
        }
        break;
    case 2:
        cout << "Enter number of patient" << endl;
        cin >> num;
        cout << "Patient " << num << ":" << endl;
        searchPerson(Man, num);
        break;
    case 3:
        break;
    default:
        cout << "Error 404! Action not found." << endl;
        break;
    }
    system("pause");
    return 0;
}