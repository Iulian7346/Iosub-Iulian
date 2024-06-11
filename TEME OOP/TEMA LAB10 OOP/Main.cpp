#include <iostream>
#include <exception>
using namespace std;

class OutOfBoundsException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Index out of bounds!";
    }
};

class NotSortedException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Nu se poate face binary search! Elementele nu sunt sortate!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class comparatie : public Compare
{
public:
    int CompareElements(void* e1, void* e2)
    {
        T* a = T * (e1);
        T* b = T * (e2);

        if (*a < *b)
            return 1;
        else
            if (*a > *b)
                return -1;
            else
                return 0;
    }
};

template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;
    T* CurrentPtr;// mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator()
    {
        Current = 0;
        CurrentPtr = nullptr;
    }

    ArrayIterator& operator ++ ()
    {
        Current++;
        return *this;
    }

    ArrayIterator& operator -- ()
    {
        Current--;
        return *this;
    }

    bool operator= (ArrayIterator<T>& other)
    {
        List = other.List;
        Current = other.Current;
    }

    bool operator!=(ArrayIterator<T> other)
    {
        if (Current != other.Current)
            return true;
        return false;
    }

    T* GetElement()
    {
        return List[Current];
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        this->List = nullptr;
        this->Capacity = 0;
        this->Size = 0;
    }
    ~Array() // destructor
    {
        delete[] List;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        List = new T*[capacity];
        this->Size = 0;
        this->Capacity = capacity;
    }
    Array(const Array<T>& otherArray) // constructor de copiere
    { 
        this->Capacity = other.Capacity;
        this->Size = other.Size;
        int i;
        for (i = 0; i < this->Size; i++)
        {
            this->List[i] = other.List[i];
        }
      
    }

    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        return this->List[index];
    }

    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {   
        if (this->Capacity == this->Size)
            this->Capacity = this->Capacity * 2;

        T* newList = new T[this->Capacity];
        
        int i;
        for (i = 0; i < this->Size; i++)
            newList[i] = this->List[i];
        newList[i] = newElem;

        delete[] this->List;

        this->List = newList;
        this->Size++;

        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size)
            throw OutOfBoundsException();
        
        if (this->Capacity == this->Size)
            this->Capacity = this->Capacity * 2;

        T* newList = new T[this->Capacity];

        int i;
        for (i = 0; i < this->Size; i++)
            newList[i] = this->List[i];

        for (i = this->Size; i > index; i--)
            newList[i] = newList[i - 1];

        newList[index] = newElem;
        delete[] this->List;

        this->List = newList;
        this->Size++;

        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size)
            throw OutOfBoundsException();
        
        while (this->Capacity < (otherArray.Size + this->Size))
        {
            this->Capacity = this->Capacity * 2;
        }

        T* newList = new T[this->Capacity];

        int i;
        for (i = 0; i < index; i++)
            newList[i] = this->List[i];

        for (i = index; i < index + otherArray.Size(); i++)
            newList[i] = otherArray.List[i - index];//inserarea listei noi

        for (i = index + otherArray.Size; i <= this->Size + otherArray.Size; i++)
            newList[i] = this->List[i - otherArray.Size];
 
        delete[] this->List;
        this->List = newList;
        this->Size+=otherArray.Size;

        return *this;

    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size)
            throw OutOfBoundsException();
        
        T* newList = new T[this->Capacity];
        int i;

        for (i = 0; i < this->Size; i++)
        {
            if (i != index)
                newList[i] = this->List[i];
        }

        delete[] this->List;
        this->List = newList;
        this->Size--;
        
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this->Size != otherArray.Size)
            return 0;
        else
        {
            int i;
            for (i = 0; i < this->Size; i++)
                if (this->List[i] != otherArray.List[i])
                    return 0;
            return 1;
        }
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        int i, j;
        T* aux;

        for (i = 0; i < Size; i++)
            for (j = i + 1; j < Size - 1; j++)
            {
                if (List[i] > List[j])
                {
                    aux = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
    }
    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        T* aux;
        for (int i = 0; i < Size; i++)
            for (int j = 0; j < Size - 1; j++)
                if (compare(List[i], List[j]) == 1)
                {
                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        T* aux;
        for (int i = 0; i < Size; i++)
            for (int j = 0; j < Size - 1; j++)
                if (comparator->CompareElements(List[i], List[j])==-1)
                {
                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }
    
    
    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        int st, dr, m;
        st = 0;
        dr = Size;

        int i = 0;
        for (i = 0; i < Size - 1; i++)
            if (List[i] > List[i + 1])
                throw NotSortedException();


        while (st <= dr)
        {
            m = (st + dr) / 2;

            if (List[m] == elem)
                return m;

            if (List[mid] < elem)
                st = m + 1;
            else
                dr = m - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
     
        int st, dr, m;
        st = 0;
        dr = Size;

        int i = 0;
        for (i = 0; i < Size - 1; i++)
            if (List[i] > List[i + 1])
                throw NotSortedException();

        while (st <= dr)
        {
            m = (st+dr) / 2;

            if (compare(List[m], elem) == -1)
                return m;

            if (compare(List[m], elem) == 0)
                st = m + 1;
            else
                dr = m - 1;
        }
        return -1;
  
    }

    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        int st, dr, m;
        st = 0;
        dr = Size;

        int i = 0;
        for (i = 0; i < Size - 1; i++)
            if (List[i] > List[i + 1])
                throw NotSortedException();

        while (st <= dr)
        {
            m = (st + dr) / 2;

            if (comparator->CompareElements(List[m], elem) == 0 )
                return m;

            if (comparator->(List[m], elem) == 1)
                st = m + 1;
            else
                dr = m - 1;
        }
        return -1;

    }


    int Find(const T& elem) // cauta un element in Array
    {
        for (int i = 0; i < Size; i++)
            if (List[i] == elem)
                return i;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for (int i = 0; i < Size; i++)
            if (compare(List[i], elem) == 0)
                return i;
    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], elem) == 0)
                return i;
    }
    int GetSize()
    {
        return this->Size;
    }
    int GetCapacity()
    {
        return this->Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        ArrayIterator<T> it;
        it.Current = 0;
        it.Currentptr = List[0];
        return it;
    }

    ArrayIterator<T> GetEndIterator()
    {
        ArrayIterator<T> it;
        it.Current = Size - 1;
        it.Currentptr = List[Size - 1];
        return it;
    }
};
