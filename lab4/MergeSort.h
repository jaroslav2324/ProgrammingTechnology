#include <cstring>

template <typename T>
void merge(T* array, int firstIndex, int lastIndex);

template <>
void merge<char*>(char** array, int firstIndex, int lastIndex);

template <typename T>
void mergeSort(T* array, int firstIndex, int lastIndex){
    
    if (firstIndex < lastIndex){

        mergeSort<T>(array, firstIndex, firstIndex + (lastIndex - firstIndex) / 2);
        mergeSort<T>(array, firstIndex + (lastIndex - firstIndex) / 2 + 1, lastIndex);

        merge<T>(array, firstIndex, lastIndex);
    }
}


template <typename T>
void merge(T* array, int firstIndex, int lastIndex){

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
void merge<char*>(char** array, int firstIndex, int lastIndex){

    int m = firstIndex + (lastIndex - firstIndex) / 2;

    int i, j, s;
    int n1 = m - firstIndex + 1;
    int n2 = lastIndex - m;

    char** leftArr = new char*[n1];
    char** rightArr = new char*[n2];
    char** outArr = new char*[n1 + n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = array[firstIndex + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = array[m + 1 + j];


    i = 0;
    j = 0;
    s = 0;
    while (i < n1 && j < n2){
        if (strlen(leftArr[i]) < strlen(rightArr[j])){
            outArr[s] = leftArr[i];
            s++;
            i++;
            continue;
        }
        if (strlen(leftArr[i]) > strlen(rightArr[j])){
            outArr[s] = rightArr[j];
            s++;
            j++;
            continue;
        }
        if (strcmp(leftArr[i], rightArr[j]) >= 0){
            outArr[s] = leftArr[i];
            i++;
        }
        else{
            outArr[s] = rightArr[j];
            j++;
        }
        s++;
    }

    while (i < n1){
        outArr[s] = leftArr[i];
        i++;
        s++;
    }

    while (j < n2){
        outArr[s] = rightArr[j];
        j++;
        s++;
    }

    for (int i = 0, j = firstIndex; j <= lastIndex; i++, j++)
        array[j] = outArr[i];

    delete leftArr;
    delete rightArr;
    delete outArr;
    //delete leftArr;
    //delete rightArr;
}

