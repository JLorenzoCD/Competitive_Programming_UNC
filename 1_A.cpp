/*
https://codeforces.com/problemset/problem/1/A

g++ -Wall -std=c++17 1_A.cpp -o ./main.out && ./main.out
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE pow(10, 9)
#define MIN_VALUE 1

unsigned int division_with_rounding_up(unsigned int x, unsigned int y){
    unsigned int module_y = x % y;

    return x / y + (module_y != 0 ? 1 : 0);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


// La entrada contiene tres números enteros positivos en la primera línea: n,  m y a (1 ≤  n, m, a ≤ 10**9).

    unsigned int n = 0;
    unsigned int m = 0;
    unsigned int a = 0;

    int try_scanf = scanf("%u %u %u", &n, &m, &a);
    if(try_scanf != 3){
        printf("Error reading measurements\n");
        exit(EXIT_FAILURE);
    }

    if(
           (MAX_VALUE < n || n < MIN_VALUE)
        || (MAX_VALUE < m || m < MIN_VALUE)
        || (MAX_VALUE < a || a < MIN_VALUE)
    ){
        printf("The number of problems must be in the range 1 ≤ n ≤ 1000\n");
        exit(EXIT_FAILURE);
    }

    unsigned int flagstone_x = division_with_rounding_up(n, a);
    unsigned int flagstone_y =division_with_rounding_up(m, a);

    printf("%u\n", flagstone_x * flagstone_y);

    return EXIT_SUCCESS;
}