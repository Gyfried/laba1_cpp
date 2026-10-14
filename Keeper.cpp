
#include "Keeper.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Keeper::Keeper() {
    capacity = 2;
    count = 0;
    animals = new Animal*[capacity];

    for (int i = 0; i < capacity; i++) {
        animals[i] = nullptr;
    }

    cout << "Keeper: конструктор без параметров" << endl;
}

Keeper::~Keeper() {
    cout << "Keeper: деструктор" << endl;

    for (int i = 0; i < count; i++) {
        delete animals[i];
    }

    delete[] animals;
}

void Keeper::increaseCapacity() {
    int newCapacity = capacity * 2;
    Animal** newAnimals = new Animal*[newCapacity];

    for (int i = 0; i < count; i++) {
        newAnimals[i] = animals[i];
    }

    for (int i = count; i < newCapacity; i++) {
        newAnimals[i] = nullptr;
    }

    delete[] animals;

    animals = newAnimals;
    capacity = newCapacity;

    cout << "Keeper: вместимость увеличена до "
         << capacity << endl;
}

void Keeper::add(Animal* animal) {
    if (animal == nullptr) {
        throw invalid_argument(
            "Нельзя добавить пустой указатель на животное."
        );
    }

    try {
        if (count == capacity) {
            increaseCapacity();
        }
    }
    catch (...) {
        delete animal;
        throw;
    }

    animals[count] = animal;
    count++;

    cout << "Keeper: животное добавлено." << endl;
}

void Keeper::remove(int index) {
    if (index < 1 || index > count) {
        throw out_of_range(
            "Животного с таким номером нет."
        );
    }

    int position = index - 1;

    delete animals[position];

    for (int i = position; i < count - 1; i++) {
        animals[i] = animals[i + 1];
    }

    count--;
    animals[count] = nullptr;

    cout << "Keeper: животное удалено." << endl;
}

void Keeper::showAll() const {
    if (count == 0) {
        cout << "Список животных пуст." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\n===== ЖИВОТНОЕ №"
             << i + 1 << " =====" << endl;

        cout << *animals[i] << endl;
    }
}

int Keeper::getCount() const {
    return count;
}
