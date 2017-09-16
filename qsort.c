#include <stdio.h>

void swap(int v[], int i, int j) {
	int tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void qsort(int v[], int left, int right) {
	int i, last;
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

int main(void) {
	int a[10] = {4, 23, 5, 17, 8, 22, 6, 229, 80, 723} ;
	qsort(a, 0, 9);
	for (int i = 0; i < 10; i++) printf("%d ", a[i]);
	printf("\n");
}


