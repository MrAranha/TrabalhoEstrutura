#include "SortingMethods.h"

void SortingMethods::BubbleSort(unsigned int* vetor, unsigned int vetorSize)
{
    unsigned int aux = 0;
    for (int i = 0; i < vetorSize; i++) {
        for (int j = 0; j < vetorSize - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

}
void SortingMethods::BubbleSortMelhorado(unsigned int* vetor, unsigned int vetorSize)
{
    unsigned int aux = 0;
    bool swapped;

    for (unsigned int i = 0; i < vetorSize - 1; i++) {
        swapped = false;

        // Últimos i elementos já estão ordenados, então não os verificamos
        for (unsigned int j = 0; j < vetorSize - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                swapped = true;
            }
        }

        // Se não houve trocas, o vetor já está ordenado
        if (!swapped) {
            break;
        }
    }
}

void SortingMethods::QuickSort(unsigned int* vetor, unsigned int vetorSize)
{
    int* stack = new int[vetorSize];
    int top = -1;
    stack[++top] = 0;
    stack[++top] = vetorSize - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];
        unsigned int pivot = vetor[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (vetor[j] < pivot) {
                i++;
                unsigned int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
        unsigned int aux = vetor[i + 1];
        vetor[i + 1] = vetor[high];
        vetor[high] = aux;
        int pi = i + 1;

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

void SortingMethods::InsertionSort(unsigned int* vetor, unsigned int vetorSize)
{
    for (unsigned int i = 1; i < vetorSize; i++) {
        unsigned int key = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = key;
    }
}

void SortingMethods::ShellSort(unsigned int* vetor, unsigned int vetorSize)
{
    for (unsigned int gap = vetorSize / 2; gap > 0; gap /= 2) {
        for (unsigned int i = gap; i < vetorSize; i++) {
            unsigned int temp = vetor[i];
            int j = i;
            while (j >= gap && vetor[j - gap] > temp) {
                vetor[j] = vetor[j - gap];
                j -= gap;
            }
            vetor[j] = temp;
        }
    }
}

void SortingMethods::SelectionSort(unsigned int* vetor, unsigned int vetorSize)
{
    for (unsigned int i = 0; i < vetorSize - 1; i++) {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < vetorSize; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }
        unsigned int temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
    }
}


void SortingMethods::HeapSort(unsigned int* vetor, unsigned int vetorSize)
{
    for (unsigned int i = vetorSize / 2 - 1; i != (unsigned int)(-1); i--) {
        heapify(vetor, vetorSize, i);
    }

    for (unsigned int i = vetorSize - 1; i > 0; i--) {
        unsigned int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        heapify(vetor, i, 0);
    }
}

void SortingMethods::MergeSort(unsigned int* vetor, unsigned int vetorSize)
{
    mergeSort(vetor, 0, vetorSize - 1);
}

void SortingMethods::RadixSort(unsigned int* vetor, unsigned int vetorSize)
{
    unsigned int max = vetor[0];
    for (unsigned int i = 1; i < vetorSize; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

    for (unsigned int exp = 1; max / exp > 0; exp *= 10) {
        unsigned int* output = new unsigned int[vetorSize];
        unsigned int count[10] = { 0 };

        for (unsigned int i = 0; i < vetorSize; i++) {
            count[(vetor[i] / exp) % 10]++;
        }

        for (unsigned int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = vetorSize - 1; i >= 0; i--) {
            unsigned int digit = (vetor[i] / exp) % 10;
            output[count[digit] - 1] = vetor[i];
            count[digit]--;
        }

        for (unsigned int i = 0; i < vetorSize; i++) {
            vetor[i] = output[i];
        }

        delete[] output;
    }
}

void SortingMethods::CountingSort(unsigned int* vetor, unsigned int vetorSize)
{
    unsigned int max = vetor[0];
    for (unsigned int i = 1; i < vetorSize; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

    unsigned int* count = new unsigned int[max + 1]();
    unsigned int* output = new unsigned int[vetorSize];

    for (unsigned int i = 0; i < vetorSize; i++) {
        count[vetor[i]]++;
    }

    for (unsigned int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = vetorSize - 1; i >= 0; i--) {
        output[count[vetor[i]] - 1] = vetor[i];
        count[vetor[i]]--;
    }

    for (unsigned int i = 0; i < vetorSize; i++) {
        vetor[i] = output[i];
    }

    delete[] count;
    delete[] output;
}
void SortingMethods::BucketSort(unsigned int* vetor, unsigned int vetorSize)
{
    unsigned int max = vetor[0];
    unsigned int min = vetor[0];

    for (unsigned int i = 1; i < vetorSize; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
        if (vetor[i] < min) {
            min = vetor[i];
        }
    }

    unsigned int bucketCount = vetorSize;
    unsigned int range = max - min + 1;
    unsigned int bucketSize = (range / bucketCount) + 1;

    unsigned int* count = new unsigned int[range]();
    unsigned int* output = new unsigned int[vetorSize];

    for (unsigned int i = 0; i < vetorSize; i++) {
        count[vetor[i] - min]++;
    }

    for (unsigned int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = vetorSize - 1; i >= 0; i--) {
        unsigned int num = vetor[i];
        output[count[num - min] - 1] = num;
        count[num - min]--;
    }

    for (unsigned int i = 0; i < vetorSize; i++) {
        vetor[i] = output[i];
    }

    delete[] count;
    delete[] output;
}
