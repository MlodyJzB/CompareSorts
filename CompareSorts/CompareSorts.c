#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "../CompareSorts/SortingAlgorithms.h"

#define ARRSIZE 30000

int* initArray(int size);

double quickSortTime(int arr[], int arrSize);

double qSortTime(int arr[], int arrSize);

int qSortCmp(const void* a, const void* b);

double bubbleSortTime(int arr[], int arrSize);

double shakerSortTime(int arr[], int arrSize);

void fprintFormattedTime(FILE* fptr, int sec);

int main() {
	int* initArr = initArray(ARRSIZE);
	int* arr = (int*)malloc(ARRSIZE * sizeof(int));

	FILE* fptr;
	fopen_s(&fptr, "results.txt", "w");
	
	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double quickTime1 = quickSortTime(arr, ARRSIZE);
	fprintf(fptr, "quick1: ");
	fprintFormattedTime(fptr, (int)quickTime1);

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double quickTime2 = quickSortTime(arr, ARRSIZE);
	fprintf(fptr, "quick2: ");
	fprintFormattedTime(fptr, (int)quickTime1);

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double quickTime3 = quickSortTime(arr, ARRSIZE);
	fprintf(fptr, "quick3: ");
	fprintFormattedTime(fptr, (int)quickTime1);

	fprintf(fptr, "quickAvg: ");
	fprintFormattedTime(fptr, (int)((quickTime1 + quickTime2 + quickTime3) / 3));
	printf("\n");
	
	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double qTime1 = qSortTime(arr, ARRSIZE);
	fprintf(fptr, "q1: ");
	fprintFormattedTime(fptr, (int)qTime1);

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double qTime2 = qSortTime(arr, ARRSIZE);
	fprintf(fptr, "q2: ");
	fprintFormattedTime(fptr, (int)qTime2);

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double qTime3 = qSortTime(arr, ARRSIZE);
	fprintf(fptr, "q3: ");
	fprintFormattedTime(fptr, (int)qTime3);

	fprintf(fptr, "qAvg: ");
	fprintFormattedTime(fptr, (int)((qTime1 + qTime2 + qTime3) / 3));
	printf("\n");

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double bubbleTime1 = bubbleSortTime(arr, ARRSIZE);
	fprintf(fptr, "bubble1: ");
	fprintFormattedTime(fptr, (int)bubbleTime1);

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double bubbleTime2 = bubbleSortTime(arr, ARRSIZE);
	fprintf(fptr, "bubble2: ");
	fprintFormattedTime(fptr, (int)bubbleTime2);

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double bubbleTime3 = bubbleSortTime(arr, ARRSIZE);
	fprintf(fptr, "bubble3: ");
	fprintFormattedTime(fptr, (int)bubbleTime3);

	fprintf(fptr, "bubbleAvg: ");
	fprintFormattedTime(fptr, (int)((bubbleTime1 + bubbleTime2 + bubbleTime3) / 3));
	printf("\n");

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double shakerTime1 = shakerSortTime(arr, ARRSIZE);
	fprintf(fptr, "shaker1: ");
	fprintFormattedTime(fptr, (int)shakerTime1);

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double shakerTime2 = shakerSortTime(arr, ARRSIZE);
	fprintf(fptr, "shaker2: ");
	fprintFormattedTime(fptr, (int)shakerTime2);

	memcpy(arr, initArr, ARRSIZE * sizeof(int));
	double shakerTime3 = shakerSortTime(arr, ARRSIZE);
	fprintf(fptr, "shaker3: ");
	fprintFormattedTime(fptr, (int)shakerTime3);

	fprintf(fptr, "shakerAvg: ");
	fprintFormattedTime(fptr, (int)((shakerTime1 + shakerTime2 + shakerTime3) / 3));

	free(initArr);
	free(arr);
	fclose(fptr);
}

int* initArray(int size) {
	time_t t;
	srand((unsigned)time(&t));

	int* arr = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		arr[i] = rand();
	}
	return arr;
}

double quickSortTime(int arr[], int arrSize) {
	time_t start;
	time(&start);
	quickSort(arr, arrSize);
	time_t end;
	time(&end);
	return difftime(end, start);
}

double qSortTime(int arr[], int arrSize) {
	time_t start;
	time(&start);
	qsort(arr, arrSize, sizeof(int), qSortCmp);
	time_t end;
	time(&end);
	return difftime(end, start);
}

int qSortCmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

double bubbleSortTime(int arr[], int arrSize) {
	time_t start;
	time(&start);
	bubbleSort(arr, arrSize);
	time_t end;
	time(&end);
	return difftime(end, start);
}

double shakerSortTime(int arr[], int arrSize) {
	time_t start;
	time(&start);
	shakerSort(arr, arrSize);
	time_t end;
	time(&end);
	return difftime(end, start);
}

void fprintFormattedTime(FILE* fptr, int sec) {
	int h = sec / 3600;
	int m = (sec - h * 3600) / 60;
	int s = sec - h * 3600 - m * 60;
	fprintf(fptr, "%.2d:%.2d:%.2d\n", h, m, s);
}