#include <stdio.h>
#include <stdlib.h>

#include "../CompareSorts/SortingAlgorithms.h"

void quickSortR(int arr[], int start, int end);

void quickSort(int arr[], int arrSize) {
	time_t t;
	srand((unsigned)time(&t));
	quickSortR(arr, 0, arrSize - 1);
	return;
}

void quickSortR(int arr[], int start, int end) {
	if (start >= end)
		return 0;

	int* pivotI = (int*)malloc(sizeof(int));
	*pivotI = (rand() % (end - start + 1)) + start;

	int* swapTemp = (int*)malloc(sizeof(int));
	*swapTemp = arr[*pivotI];

	arr[*pivotI] = arr[end];
	arr[end] = *swapTemp;

	int boarder = start;

	for (int i = start; i < end; i++) {
		if (arr[i] < arr[end]) {
			*swapTemp = arr[i];
			arr[i] = arr[boarder];
			arr[boarder] = *swapTemp;
			boarder++;
		}
	}

	*swapTemp = arr[boarder];
	arr[boarder] = arr[end];
	arr[end] = *swapTemp;

	free(swapTemp);
	free(pivotI);

	if (boarder - start < end - boarder) {
		quickSortR(arr, start, boarder - 1);
		quickSortR(arr, boarder + 1, end);
	}
	else {
		quickSortR(arr, boarder + 1, end);
		quickSortR(arr, start, boarder - 1);
	}
	return;
}

void bubbleSort(int arr[], int arrSize) {
	int top = arrSize - 1;
	while (top > 0) {
		int highestSwapI = 0;
		for (int i = 0; i < top; i++) {
			if (arr[i] > arr[i + 1]) {
				int elementCopy = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = elementCopy;
				highestSwapI = i;
			}
		}
		top = highestSwapI;
	}
	return;
}

void shakerSort(int arr[], int arrSize) {
	int top = arrSize - 1;
	int bottom = 0;
	while (top != bottom) {
		int highestSwapI = bottom;
		for (int i = bottom; i < top; i++) {
			if (arr[i] > arr[i + 1]) {
				int elementCopy = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = elementCopy;
				highestSwapI = i + 1;
			}
		}
		top = highestSwapI;
		int lowestSwapI = top;

		for (int i = top; i > bottom; i--) {
			if (arr[i] < arr[i - 1]) {
				int elementCopy = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = elementCopy;
				lowestSwapI = i - 1;
			}
		}
		bottom = lowestSwapI;

	}
	return;
}

void sortBySelection(int arr[], int arrSize) {
	for (int i = 0; i < arrSize - 1; i++) {
		int maxIndex = i;
		int j;
		for (j = i + 1; j < arrSize; j++) {
			if (arr[j] < arr[maxIndex]) {
				maxIndex = j;
			}
		}
		int elementCopy = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = elementCopy;
	}
	return;
}