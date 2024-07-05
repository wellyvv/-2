#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUMBERS 20
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>



int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int find_lcm(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Ukr");
    int p;
    printf("Введiть кiлькiсть чисел: ");
    scanf("%d", &p);

    if (p < 2 || p > MAX_NUMBERS) {
        printf("Невiрний вхiд. Кiлькiсть чисел повинна бути в дiапазонi вiд 2 до %d.\n", MAX_NUMBERS);
        return 1;
    }

    int numbers[MAX_NUMBERS];
    printf("Введiть числа, роздiленi пробiлом: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &numbers[i]);
    }

    int result = find_lcm(numbers, p);
    printf("Найменше спiльне кратне заданих чисел: %d\n", result);

    return 0;
}
