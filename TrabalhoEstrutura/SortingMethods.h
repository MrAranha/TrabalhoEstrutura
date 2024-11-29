#pragma once

class SortingMethods {
public:
	static void BubbleSort(unsigned int* vetor, unsigned int vetorSize);
	static void BubbleSortMelhorado(unsigned int* vetor, unsigned int vetorSize);
	static void QuickSort(unsigned int* vetor, unsigned int vetorSize);
	static void InsertionSort(unsigned int* vetor, unsigned int vetorSize);
	static void ShellSort(unsigned int* vetor, unsigned int vetorSize);
	static void SelectionSort(unsigned int* vetor, unsigned int vetorSize);
	static void HeapSort(unsigned int* vetor, unsigned int vetorSize);
	static void MergeSort(unsigned int* vetor, unsigned int vetorSize);
	static void RadixSort(unsigned int* vetor, unsigned int vetorSize);
	static void CountingSort(unsigned int* vetor, unsigned int vetorSize);
	static void BucketSort(unsigned int* vetor, unsigned int vetorSize);

    static void heapify(unsigned int* vetor, unsigned int n, unsigned int i) {
        unsigned int largest = i;
        unsigned int left = 2 * i + 1;
        unsigned int right = 2 * i + 2;

        if (left < n && vetor[left] > vetor[largest]) {
            largest = left;
        }
        if (right < n && vetor[right] > vetor[largest]) {
            largest = right;
        }
        if (largest != i) {
            unsigned int temp = vetor[i];
            vetor[i] = vetor[largest];
            vetor[largest] = temp;
            heapify(vetor, n, largest);
        }
    }

    static void mergeSort(unsigned int* vetor, unsigned int left, unsigned int right) {
        if (left < right) {
            unsigned int mid = left + (right - left) / 2;

            mergeSort(vetor, left, mid);
            mergeSort(vetor, mid + 1, right);

            merge(vetor, left, mid, right);
        }
    }

    static void merge(unsigned int* vetor, unsigned int left, unsigned int mid, unsigned int right) {
        unsigned int n1 = mid - left + 1;
        unsigned int n2 = right - mid;

        unsigned int* leftArray = new unsigned int[n1];
        unsigned int* rightArray = new unsigned int[n2];

        for (unsigned int i = 0; i < n1; i++) {
            leftArray[i] = vetor[left + i];
        }
        for (unsigned int j = 0; j < n2; j++) {
            rightArray[j] = vetor[mid + 1 + j];
        }

        unsigned int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                vetor[k] = leftArray[i];
                i++;
            }
            else {
                vetor[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            vetor[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            vetor[k] = rightArray[j];
            j++;
            k++;
        }

        delete[] leftArray;
        delete[] rightArray;
    }
};