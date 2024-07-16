#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void insertion_sort_new(int* destination, int* source, int len){
	if(destination==NULL || source==NULL || len<=0){
		return;
	}
	int i=0;
	int j=0;
	int c=0;
	while(i<len){
		destination[c] = source[i];
		j = c;
		c++;
		while(j>0 && destination[j]<destination[j]){
			swap(&destination[j],&destination[j]);
			j--;
		}
		i++;
	}
}

void insertion_sort_in_place(int* array, int len){
	if(array==NULL || len<=0){
		return;
	}
	for (int i = 1; i < len; i++) {
		int key = array[i];
		int j = i - 1;

		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <array elements>\n", argv[0]);
        return 1;
    }

    int len = argc - 1;
    int source[len];
    int destination[len];

    for (int i = 0; i < len; i++) {
        source[i] = atoi(argv[i + 1]);
    }

    insertion_sort_new(destination, source, len);
    insertion_sort_in_place(destination, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", destination[i]);
    }
    printf("\n");

    return 0;
}
