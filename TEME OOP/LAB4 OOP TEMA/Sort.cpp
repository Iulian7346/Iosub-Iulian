#include "Sort.h"

Sort::Sort(int lungime, int min, int max)
{
    this->n = lungime;
    this->vec = new int[n];
    srand(time(NULL));
    for (int i = 0; i < lungime; i++) 
        vec[i]=rand() % ((max - min + 1) + min);
}
Sort::Sort(const initializer_list<int> list) 
{
    this->n = list.size();
    this->vec = new int[n];
    int i = 0;
    for (int value : list)
    {
        this->vec[i] = value;
        i++;
    }
 }
Sort::Sort(int v[], int lung)
{
    this->n = lung;
    this->vec = new int[n];
    for (int i = 0; i < lung; i++)
        vec[i] = v[i];

}
Sort::Sort(int lung, ...)
{

    this->n = lung;
    this->vec = new int[n];
    va_list args;
    va_start(args, lung);

    for (int i = 0; i < lung; i++) {
        int value = va_arg(args, int);
        vec[i] = value;
    }

    va_end(args);
}

Sort::Sort(char text[]) {
    int count = 0;
    char text1[200];
    strcpy(text1, text);
    char *p = strtok(text, ",");
    while (p) {
        count++;
        p = strtok(NULL, ",");
    }
    this->n = count;
    this->vec = new int[this->n];
    char *q;
    q = strtok(text1, ",");
    int i = 0;
    while (q) {
        this->vec[i] = atoi(q);
        i++;
        q = strtok(NULL, ",");
    }
    
}
void Sort::Print()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << this->vec[i] << " ";
    }
    cout << endl;
}

int Sort::partition(int low, int high, bool ascendent) {
    int pivot = vec[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if ((!ascendent && vec[j] >= pivot) || (ascendent && vec[j] <= pivot)) {
            i++;
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    int temp = vec[i + 1];
    vec[i + 1] = vec[high];
    vec[high] = temp;
    return (i + 1);
}

void Sort::QuickSort(bool ascendent) {
    QuickSortHelper(0, n - 1, ascendent);
}

void Sort::QuickSortHelper(int low, int high, bool ascendent) {
    if (low < high) {
        int pi = partition(low, high, ascendent);
        QuickSortHelper(low, pi - 1, ascendent);
        QuickSortHelper(pi + 1, high, ascendent);
    }
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascendent && vec[j] > vec[j + 1]) || (!ascendent && vec[j] < vec[j + 1])) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < n; ++i) {
        int cheie = vec[i];
        int j = i - 1;
        while (j >= 0 && ((ascendent && vec[j] > cheie) || (!ascendent && vec[j] < cheie))) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = cheie;
    }
}

int Sort::GetElementsCount()
{
    return this->n;
}

int Sort::GetElementFromIndex(int index)
{
    return this->vec[index];
}

