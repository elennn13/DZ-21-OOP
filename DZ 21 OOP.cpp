#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

class ViolationRecord { // для представления базы данных ГАИ.
public:
    // Метод addViolation добавляет новое правонарушение в базу данных. 
    // Если номер автомашины еще не существует, он создает новый узел
    // в дереве и инициализирует список правонарушений. Если номер уже
    // существует, он добавляет новое правонарушение в соответствующий
    // список.
    void addViolation(unsigned int carNumber, const string& violation) {
        if (database.find(carNumber) == database.end()) {
            database[carNumber] = list<string>();
        }
        database[carNumber].push_back(violation);
    }
    // Метод printDatabase выводит всю базу данных, отображая номера автомашин
    // и связанные с ними правонарушения.
    void printDatabase() {
        for (auto it = database.begin(); it != database.end(); ++it) {
            cout << "Car number: " << it->first << endl;
            for (const auto& violation : it->second) {
                cout << "- " << violation << endl;
            }
            cout << endl;
        }
    }
    // Внутри класса используется map<unsigned int, list<string>> для хранения данных.
    //  Ключом является номер автомашины (unsigned int), 
    // а значением - список правонарушений (list<string>).
private:
    map<unsigned int, list<string>> database;
};

int main() {
    setlocale(LC_ALL, "ru");
    ViolationRecord db;

    db.addViolation(1234, "Speeding");
    db.addViolation(5678, "Illegal parking");
    db.addViolation(1234, "Running a red light");
    db.addViolation(9012, "Driving without a license");

    db.printDatabase();

    return 0;
}