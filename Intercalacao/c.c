#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned int n, m, i, j;
    scanf("%d", &n);
    scanf("%d", &m);

    int inputs[n+m];
    int l1[n];
    int l2[m];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &l1[i]);
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d", &l2[i]);
    }

    i = 0;
    j = 0;
    int outputs[n+m];
    while ( (i < n) && (j < m)){
        if(l1[i] < l2[j]){
            outputs[i+j] = l1[i];
            i++;
        } else {
            outputs[i+j] = l2[j];
            j++;
        }
    }

    while (i<n){
        outputs[i+j] = l1[i];
        i++;
    }

    while (j<m){
        outputs[i+j] = l2[j];
        j++;
    }



    for (i = 0; i < (n+m); i++)
    {
        printf("%d\n", outputs[i]);
    }

    return 0;
}