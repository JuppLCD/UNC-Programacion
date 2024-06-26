#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;

    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) { i++; }
        else if (goes_before(a[ppiv], a[j])) { j--; }
        else if (goes_before(a[ppiv], a[i]) && goes_before(a[j], a[ppiv])) {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    if (izq < der) {
        unsigned int ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, (ppiv == 0u ? 0u : ppiv - 1));
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


static unsigned int partition_len(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;

    while (i <= j) {
        if (fstring_length(a[i]) <= fstring_length(a[ppiv])) { i++; }
        else if (fstring_length(a[ppiv]) <= fstring_length(a[j])) { j--; }
        else if (fstring_length(a[ppiv]) <= fstring_length(a[i]) && fstring_length(a[j]) <= fstring_length(a[ppiv])) {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec_len(fixstring a[], unsigned int izq, unsigned int der) {
    if (izq < der) {
        unsigned int ppiv = partition_len(a, izq, der);
        quick_sort_rec_len(a, izq, (ppiv == 0u ? 0u : ppiv - 1));
        quick_sort_rec_len(a, ppiv + 1, der);
    }
}

void quick_sort_len(fixstring a[], unsigned int length) {
    quick_sort_rec_len(a, 0, (length == 0) ? 0 : length - 1);
}