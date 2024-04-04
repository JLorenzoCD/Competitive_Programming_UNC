/*
https://codeforces.com/problemset/problem/231/A

g++ -Wall -std=c++17 231_A.cpp -o ./main.out && ./main.out
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    unsigned int number_of_problems = 0;

    int try_scanf = scanf("%u", &number_of_problems);
    if(try_scanf != 1){
        printf("Error reading number of issues\n");
        exit(EXIT_FAILURE);
    }

    if(1000 < number_of_problems || number_of_problems < 1){
        printf("The number of problems must be in the range 1 ≤ n ≤ 1000\n");
        exit(EXIT_FAILURE);
    }

    int problems_to_solve, petya_confidence, vasya_confidence, tonya_confidence;
    problems_to_solve = 0;
    for (unsigned int i = 0; i < number_of_problems; i++){
        int try_scanf = scanf("%i %i %i", &petya_confidence, &vasya_confidence, &tonya_confidence);
        if(try_scanf != 3){ // scanf returns the number of values read
            printf("Error reading trust to solve the problem of Petya, Vasya and Tonya\n");
            exit(EXIT_FAILURE);
        }

        problems_to_solve += petya_confidence + vasya_confidence + tonya_confidence >= 2 ? 1 : 0;
    }

    printf("%i\n", problems_to_solve);

    return EXIT_SUCCESS;
}