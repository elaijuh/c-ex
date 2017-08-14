#include <stdio.h>

int shell_sort(int v[], int n);

int main() {
    int i, n = 9;
    int a[9] = {10, 2, 8, 3, 12, 11, 9, 6, 4};
    int b[9];

    for (i=0; i<n; i++) {
        b[i] = a[i];
    }
    shell_sort(b, n);
    for (i=0; i<n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

}

int shell_sort(int v[], int n) {
    int gap, i, j, tmp;
    for (gap=n/2; gap>0; gap/=2) {
        for (i=gap; i<n ; i++) {
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                tmp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = tmp;
            }
        }
    }
    return 1;
}
