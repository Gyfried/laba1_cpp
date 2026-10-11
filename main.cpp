
#include <iostream>
#include <exception>

#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

using namespace std;

int main() {
    char breed[256];
    char color[256];
    char food[256];
    char habitat[256];
    char owner[256];
    char name[256];

    try {
        cout << "===== СОЗДАНИЕ РЫБЫ =====" << endl;

        cout << "Введите породу рыбы: ";
        cin.getline(breed, 256);

        cout << "Введите окрас рыбы: ";
        cin.getline(color, 256);

        cout << "Введите тип питания рыбы: ";
        cin.getline(food, 256);

        Fish fish(breed, color, food);

        cout << "\n===== ИНФОРМАЦИЯ О РЫБЕ =====" << endl;
        cout << fish << endl;

        cout << "===== СОЗДАНИЕ ПТИЦЫ =====" << endl;

        cout << "Введите породу птицы: ";
        cin.getline(breed, 256);

        cout << "Введите окрас птицы: ";
        cin.getline(color, 256);

        cout << "Чем питается птица: ";
        cin.getline(food, 256);

        cout << "Где обитает птица: ";
        cin.getline(habitat, 256);

        Bird bird(breed, color, food, habitat);

        cout << "\n===== ИНФОРМАЦИЯ О ПТИЦЕ =====" << endl;
        cout << bird << endl;

        cout << "===== СОЗДАНИЕ КОШКИ =====" << endl;

        cout << "Введите породу кошки: ";
        cin.getline(breed, 256);

        cout << "Введите окрас кошки: ";
        cin.getline(color, 256);

        cout << "Введите ФИО владельца: ";
        cin.getline(owner, 256);

        cout << "Введите кличку кошки: ";
        cin.getline(name, 256);

        Cat cat(breed, color, owner, name);

        cout << "\n===== ИНФОРМАЦИЯ О КОШКЕ =====" << endl;
        cout << cat << endl;

        cout << "===== ПРОВЕРКА КОНСТРУКТОРОВ КОПИРОВАНИЯ ====="
             << endl;

        Fish copiedFish(fish);
        Bird copiedBird(bird);
        Cat copiedCat(cat);

        cout << "\nКопия рыбы:" << endl;
        cout << copiedFish << endl;

        cout << "Копия птицы:" << endl;
        cout << copiedBird << endl;

        cout << "Копия кошки:" << endl;
        cout << copiedCat << endl;

        cout << "===== ПРОВЕРКА ОПЕРАТОРОВ ПРИСВАИВАНИЯ ====="
             << endl;

        Fish anotherFish;
        anotherFish = fish;

        Bird anotherBird;
        anotherBird = bird;

        Cat anotherCat;
        anotherCat = cat;

        cout << "\nРезультат присваивания кошки:" << endl;
        cout << anotherCat << endl;

        cout << "===== ПРОВЕРКА SET И GET =====" << endl;

        fish.setColor("Новый окрас");
        fish.setFoodType("Растительный");

        cout << "Новый окрас рыбы: "
             << fish.getColor() << endl;

        cout << "Тип питания рыбы: "
             << fish.getFoodType() << endl;

        cout << "\n===== ПРОГРАММА ЗАВЕРШЕНА =====" << endl;
        cout << "При выходе будут вызваны деструкторы." << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Неизвестная ошибка." << endl;
    }

    return 0;
}
