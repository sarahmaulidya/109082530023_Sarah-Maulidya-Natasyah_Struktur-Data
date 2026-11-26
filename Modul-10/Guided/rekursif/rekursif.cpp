#include "rekursif.h"

int pangkat_2(int x) {
    if (x == 0) {
        return 1;
    } else {
        return 2 * pangkat_2(x -1);
    }
}