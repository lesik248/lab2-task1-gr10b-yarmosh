#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для проверки, является ли число палиндромом
int is_palindrome(int num) {
		int reversed = 0, original = num, digit;
		while (num > 0) {
				digit = num % 10;
				reversed = reversed * 10 + digit;
				num /= 10;
		}
		return original == reversed;
}

int main(int argc, char *argv[]) {
		if (argc != 2) {
				printf("Использование: %s <размер массива>\n", argv[0]);
				return 1;
		}

		int n = atoi(argv[1]);
		if (n <= 0) {
				printf("Размер массива должен быть положительным числом.\n");
				return 1;
		}

		int arr[n];
		srand(time(NULL));

		// Заполнение массива случайными числами от 10 до 99999
		printf("Массив: ");
		for (int i = 0; i < n; i++) {
				arr[i] = rand() % 99990 + 10; // Генерация числа в диапазоне [10, 99999]
				printf("%d ", arr[i]);
		}
		printf("\n");

		// Подсчет палиндромов
		int palindrome_count = 0;
		for (int i = 0; i < n; i++) {
				if (is_palindrome(arr[i])) {
						palindrome_count++;
				}
		}

		printf("Количество палиндромов: %d\n", palindrome_count);
		return 0;
}
