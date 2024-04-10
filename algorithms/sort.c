static void swap(int a[], unsigned int i, unsigned int j) {
    unsigned int temp = a[i];

    a[i] = a[j];
    a[j] = temp;
}

// ! QUICK_SORT
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;

    while (i <= j) {
        if (a[i] < a[ppiv]) { i++; }
        else if (a[ppiv] < a[j]) { j--; }
        else if (a[ppiv] < a[i] && a[j] < a[ppiv]) {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (izq < der) {
        unsigned int ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, (ppiv == 0u ? 0u : ppiv - 1));
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

// ! INSERTION_SORT
static void insert(int a[], unsigned int i) {
    unsigned int j = i;

    while (j > 0 && a[j] <= a[j - 1]) {
        swap(a, j - 1, j);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}