/*
https://codeforces.com/problemset/problem/282/A

g++ -Wall -std=c++17 282_A.cpp -o ./main.out && ./main.out
*/

#include <bits/stdc++.h>

using namespace std;

char give_operation(char text[]){
    unsigned int count_add = 0;

    for (unsigned int i = 0; i < 3; i++)
    {
        count_add += text[i] == '+' ? 1 : 0;
    }

    return count_add == 2 ? '+' : '-';
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int x = 0;
    unsigned int number_of_operations = 0;

    int try_scanf = scanf("%u", &number_of_operations);
    if(try_scanf != 1){
        printf("Error reading number of operations\n");
        exit(EXIT_FAILURE);
    }

    if(150 < number_of_operations || number_of_operations < 1){
        printf("The number of problems must be in the range 1 ≤ n ≤ 150\n");
        exit(EXIT_FAILURE);
    }

    char operation_text[3];
    for (unsigned int i = 0; i < number_of_operations; i++){
        int try_scanf = scanf("%s", operation_text);
        if(try_scanf != 1){
            printf("Error reading operation\n");
            exit(EXIT_FAILURE);
        }

        if(give_operation(operation_text) == '+'){
            x++;
        }else{
            x--;
        }
    }

    printf("%i\n", x);

    return EXIT_SUCCESS;
}