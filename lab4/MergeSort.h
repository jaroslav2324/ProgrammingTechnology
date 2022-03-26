#include "cstring"

template <typename T>
void mergeSort(T* array, int firstIndex, int lastIndex){
    
    if (firstIndex < lastIndex){

        MergeSort(array, firstIndex, firstIndex + (lastIndex - firstIndex) / 2);
        MergeSort(array, firstIndex + (lastIndex - firstIndex) / 2 + 1, lastIndex);

        Merge(array, firstIndex, lastIndex);
    }
}


template <typename T>
void Merge(T* array, int firstIndex, int lastIndex){

    int m = firstIndex + (lastIndex - firstIndex) / 2;

    int i, j, s;
    int n1 = m - firstIndex + 1;
    int n2 = lastIndex - m;

    T leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = array[firstIndex + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = array[m + 1 + j];


    i = 0;
    j = 0;
    s = firstIndex;
    while (i < n1 && j < n2){
        if (leftArr[i] <= rightArr[j]){
            array[s] = leftArr[i];
            i++;
        }
        else{
            array[s] = rightArr[j];
            j++;
        }
        s++;
    }

    while (i < n1){
        array[s] = leftArr[i];
        i++;
        s++;
    }

    while (j < n2){
        array[s] = rightArr[j];
        j++;
        s++;
    }
}

template <>
void Merge<char*>(char** array, int firstIndex, int lastIndex){

    int m = firstIndex + (lastIndex - firstIndex) / 2;

    int i, j, s;
    int n1 = m - firstIndex + 1;
    int n2 = lastIndex - m;

    char* leftArr[n1], *rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = array[firstIndex + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = array[m + 1 + j];


    i = 0;
    j = 0;
    s = firstIndex;
    while (i < n1 && j < n2){
        if (strcmp(leftArr[i], rightArr[j]) >= 0){
            array[s] = leftArr[i];
            i++;
        }
        else{
            array[s] = rightArr[j];
            j++;
        }
        s++;
    }

    while (i < n1){
        array[s] = leftArr[i];
        i++;
        s++;
    }

    while (j < n2){
        array[s] = rightArr[j];
        j++;
        s++;
    }
}

