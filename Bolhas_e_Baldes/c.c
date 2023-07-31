#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long inv_count = 0;
 
    i = left; /* índice inicial para a primeira metade */
    j = mid; /* índice inicial para a segunda metade */
    k = left; /* índice inicial para o array temporário */
 
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
 
    /* Copia os elementos restantes da primeira metade, se houver */
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
 
    /* Copia os elementos restantes da segunda metade, se houver */
    while (j <= right) {
        temp[k++] = arr[j++];
    }
 
    /* Copia o array temporário de volta para o array original */
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
 
    return inv_count;
}

long long merge_sort(int arr[], int temp[], int left, int right) {
    int mid;
    long long inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
 
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid + 1, right);
 
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    int n, *arr, *temp, i;
    long long inv_count;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        arr = (int *)malloc(n * sizeof(int));
        temp = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        inv_count = merge_sort(arr, temp, 0, n - 1);
        if (inv_count % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
        free(arr);
        free(temp);
    }
    return 0;
}



