#include <stdlib.h>
#include "utils.h"
#include "partition.h"


void quickSort(int *arr, int n, int type, int rec, int pChoose);
void _quickSortIndex(int *arr, int begin, int end, int pChoose);
void _quickSortTail(int *arr, int begin, int end);
void _quickSortPointer(int *begin, int *end);

void quickSort(int *arr, int n, int type, int rec, int pChoose) {

    if(type == INDEX) {
        if(rec == REC)
            _quickSortIndex(arr, 0, n-1, pChoose);
        else if(rec == TAIL)
            _quickSortTail(arr, 0, n-1);
    }
    else if(type == POINTER)
        _quickSortPointer(arr, arr+n-1);
};

void _quickSortTail(int *arr, int begin, int end) {

    while(begin < end) {
        int pivot = partitionLomutoIndex(arr, begin, end, -1);
        _quickSortTail(arr, begin, pivot-1);
        begin = pivot + 1;
    }
}

void _quickSortIndex(int *arr, int begin, int end, int pChoose) {

    if(begin < end) {
        int pivot = partitionLomutoIndex(arr, begin, end, pChoose);
        _quickSortIndex(arr, begin, pivot-1, pChoose);
        _quickSortIndex(arr, pivot+1, end, pChoose);
    }
}

void _quickSortPointer(int *begin, int *end) {

    if(begin < end) {
        int *pivot = partitionLomutoPointer(begin, end);

        if(pivot != begin)
            _quickSortPointer(begin, pivot-1);

        _quickSortPointer(pivot+1, end);
    }
};
