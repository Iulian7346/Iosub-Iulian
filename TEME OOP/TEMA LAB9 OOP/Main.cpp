#include <iostream>
using namespace std;

template<typename K, typename V>
class Map {
private:
    struct Triplet {
        size_t index;
        K key;
        V value;
    };

    Triplet* elements;
    size_t capacitate;
    size_t size;

public:

    Map() : elements(nullptr), capacitate(0), size(0) {}

    ~Map() {
        delete[] elements;
    }

    void insert(const K& key, const V& value) {
        if (size == capacitate) {
            size_t new_capacitate = (capacitate == 0) ? 1 : capacitate * 2;
            Triplet* new_elements = new Triplet[new_capacitate];

            for (size_t i = 0; i < size; ++i) {
                new_elements[i] = elements[i];
            }

            delete[] elements;
            elements = new_elements;
            capacitate = new_capacitate;
        }

        elements[size] = { size, key, value };
        size++;
    }


    V& operator[](const K& key) {

        for (size_t i = 0; i < size; ++i) {
            if (elements[i].key == key) {
                return elements[i].value;
            }
        }


        insert(key, V());
        return elements[size - 1].value;
    }

    bool Get(const K& key, V& value)
    {
        int OK = 0;

        int i;
        for (i = 0; i < size; ++i) {
            if (elements[i].key == key) {
                OK = 1;
                break;
            }
        }

        if (OK == 0)
            return false;

        value = this->elements[i].value;

        return true;

    }

    void Set(const K& key, V& value)
    {
        (*this)[key] = value;
    }

    int Count()
    {
        return size;
    }

    bool Delete(const K& key)
    {
        int OK = 0;

        int i;
        for (i = 0; i < size; ++i) {
            if (elements[i].key == key) {
                OK = 1;
                break;
            }
        }

        if (OK == 0)
            return false;


        for (int j = i; j < size - 1; j++) {
            elements[j] = elements[j + 1];
            elements[j].index--;
        }


        size--;

        Triplet* new_elements = new Triplet[size];//sa nu ramana ultimul element ca garbage memory 
        for (int i = 0; i < size; ++i) {
            new_elements[i] = elements[i];
        }
        delete[] elements;
        elements = new_elements;

        return true;
    }

    void Clear() {
        delete[] elements;
        size = 0;
        capacitate = 0;
        elements = nullptr;
    }

    bool Includes(const Map<K, V>& map)
    {
        int i, j, exista;

        for (i = 0; i <= this->size - 1; i++)
        {
            exista = 0;
            for (j = 0; j <= map.size - 1; j++)
            {
                if (map.elements[j].key == this->elements[i].key && map.elements[j].value == this->elements[i].value)
                    exista = 1;
            }
            if (exista == 0)
                return false;
        }
        return true;
    }

    class Iterator {
    private:
        Triplet* ptr;
    public:
        Iterator(Triplet* p) : ptr(p) {}

        Triplet& operator*() const {
            return *ptr;
        }

        Triplet* operator->() const {
            return ptr;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };


    Iterator begin() {
        return Iterator(elements);
    }

    Iterator end() {
        return Iterator(elements + size);
    }

};

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [index, key, value] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";

    for (auto [index, key, value] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    //-----pe astea le am adaugat eu ca sa testez si restul cerintelor------

    //pentru metoda Set 

    const char* str = "letstry";
    m.Set(40, str);
    str = "hmmm";
    m.Set(20, str);
    for (auto [index, key, value] : m) {
        printf("Index:%zu, Key=%d, Value=%s\n", index, key, value);
    }

    //Count
    cout << "Count: " << m.Count() << endl;

    //pentru metoda Delete

    bool test = m.Delete(30);

    for (auto [index, key, value] : m) {
        printf("Index:%zu, Key=%d, Value=%s\n", index, key, value);
    }

    //pentru metoda Get

    Map<int, int> m1;

    m1[1] = 2; m1[100] = 700; m1[70] = 69; m1[4] = 32;

    cout << endl;

    int value;
    if (m1.Get(100, value)) {
        cout << "Value associated with key 5: " << value << endl;
    }
    else {
        cout << "Key 5 does not exist in the map" << endl;
    }

    //testare Include
    Map<int, int> m2;

    m2[1] = 2; m2[100] = 700; m2[53] = 8888; m2[70] = 69; m2[62] = 1; m2[4] = 32; m2[314] = 31459;

    if (m1.Includes(m2))
        cout << "m1 este inclus in m2" << endl;
    else
        cout << "m1 NU este inclus in m2" << endl;

    //Clear
    m2.Clear();

    return 0;
}
