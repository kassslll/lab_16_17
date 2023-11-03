#include <Windows.h>
#include <stdio.h>


#define COUNT_ELEMENT_IN_LISTS 100


int list[COUNT_ELEMENT_IN_LISTS];
int n = 0;
int index, el;


int start_programm();
int console();
void input_list();
void output_list();
void x10evenel();
int min_in_list();
void count_more_10();
void increase_even_x2();
void even_left_min();
void x10_min_right();
void min_to_max();
void negation_even();
void change_less_four();
void between_min_max();
void between_first_and_last_even();
void delete_el_in_list();
int paste_in_list();
void delete_min();
void insert_element();
void delete_all_even();
void doubled_even();
void append_min_in_begin();
void delete_less_four();


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	start_programm();
}


int console() {
	int result;
	printf("\n");
	printf("-----------------------------\n");
	printf("Содержимое массива: ");
	output_list();
	printf("Выберите нужную вам операцию:\n");
	printf("1: Ввести с клавиатуры массив.\n");
	printf("2: x10 для всех нечётных элементов.\n");
	printf("3: Найти минимальный элемент.\n");
	printf("4: Сколько элементов больше 10.\n");
	printf("5: X2 для последнего чётного.\n");
	printf("6: Сколько чётных левее минимального.\n");
	printf("7: Х10 для нечётных правее минимального.\n");
	printf("8: Переставить местами Min и Max.\n");
	printf("9: Все чётные элементы поменяют знак.\n");
	printf("10: Все элементы меньше 4 заменить на 4.\n");
	printf("11: Все элементы между Min и Max увеличить в 10.\n");
	printf("12: Все элементы между первым чётным и вторым чётным увеличить в 100.\n");
	printf("20: Удалить заданный элемент.\n");
	printf("30: Вставить заданный элемент.\n");
	printf("40: Удалить минимальный элемент.\n");
	printf("50: Вставить 0 перед минимальным элементом.\n");
	printf("60: Удалить все чётные элементы.\n");
	printf("70: Продублировать все чётные элементы.\n");
	printf("80: Добавить элемент равный минимальному.\n");
	printf("90: Удалить все элементы < 4.\n");
	printf("\n");
	printf("0: Выйти из программы\n");
	printf("Выбранная операция >>>>>>>> ");
	scanf_s("%d", &result);
	printf("\n");
	return result;
}


int start_programm() {
	int input = console();
	switch (input)
	{
	case 1:
		input_list();
		return start_programm();
		break;
	case 2:
		x10evenel();
		return start_programm();
		break;
	case 3:
		printf("min = %d",list[ min_in_list()]);
		return start_programm();
		break;
	case 4:
		count_more_10();
		return start_programm();
		break;
	case 5:
		increase_even_x2();
		return start_programm();
		break;
	case 6:
		even_left_min();
		return start_programm();
		break;
	case 7:
		x10_min_right();
		return start_programm();
		break;
	case 8:
		min_to_max();
		return start_programm();
		break;
	case 9:
		negation_even();
		return start_programm();
		break;
	case 10:
		change_less_four();
		return start_programm();
		break;
	case 11:
		between_min_max();
		return start_programm();
		break;
	case 12:
		between_first_and_last_even();
		return start_programm();
		break;
	case 20:
		delete_el_in_list();
		return start_programm();
		break;
	case 30:
		printf("\n");
		printf("Перед каким элементом нужно вставить новый? Индекс = ");
		scanf_s("%d", &index);
		printf("Значение, которое нужно вставить = ");
		scanf_s("%d", &el);
		paste_in_list();
		return start_programm();
		break;
	case 40:
		delete_min();
		return start_programm();
		break;
	case 50:
		insert_element();
		return start_programm();
		break;
	case 60:
		delete_all_even();
		return start_programm();
		break;
	case 70:
		doubled_even();
		return start_programm();
		break;
	case 80:
		append_min_in_begin();
		return start_programm();
		break;
	case 90:
		delete_less_four();
		return start_programm();
		break;
	case 0:
		return 0;
		break;
	default:
		break;
	}
}


void input_list() {
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &list[i]);
	}
}


void output_list() {
	if (n == 0) {
		printf("< >\n");
	}
	else {
		printf("< ");
		for (int i = 0; i < n; i++) {
			printf("%d ", list[i]);
		}
		printf(">\n");
	}
}


void x10evenel() {
	for (int i = 0; i < n; i++) {
		if (list[i] % 2 == 1) {
			list[i] = list[i] * 10;
		}
	}
}


int min_in_list() {
	int min = list[0], index = 0;
	for (int i = 0; i < n; i++) {
		if (min > list[i]) {
			min = list[i];
			index = i;
		}
	}
	return index;
}


void count_more_10() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (list[i] >= 10) {
			count++;
		}
	}
	printf("%d элемента больше или равны 10\n", count);
}


void increase_even_x2() {
	int index;
	if (n != 0) {
		for (int i = 0; i < n; i++) {
			if (list[i] % 2 == 0) {
				index = i;
			}
		}
		list[index] = list[index] * 2;
	}
}


void even_left_min() {
	int index, min = list[0], count = 0;
	for (int i = 0; i < n; i++) {
		if (min >= list[i]) {
			min = list[i];
			index = i;
		}
	}
	if (index != 0) {
		for (int i = 0; i < index; i++) {
			if (list[i] % 2 == 0) {
				count++;
			}
		}
	}

	printf("Индекс минимального элемента = %d\n", index);
	printf("Левее минимального %d чётных элементов\n", count);
}


void x10_min_right() {

	int index, min = list[0], count = 0;
	for (int i = 0; i < n; i++) {
		if (min >= list[i]) {
			min = list[i];
			index = i;
		}
	}
	for (int i = index != n ? index + 1 : index; i < n; i++) {
		if (list[i] % 2 == 1) {
			list[i] = list[i] * 10;
		}
	}
}


void min_to_max() {
	int indexMin, indexMax, min = list[0], max = list[0];
	for (int i = 0; i < n; i++) {
		if (min >= list[i]) {
			min = list[i];
			indexMin = i;
		}
		if (max <= list[i]) {
			max = list[i];
			indexMax = i;
		}
	}
	int t = list[indexMin];
	list[indexMin] = list[indexMax];
	list[indexMax] = t;
}


void negation_even() {
	for (int i = 0; i < n; i++) {
		if (list[i] % 2 == 0) {
			list[i] = (-1) * list[i];
		}
	}
}


void change_less_four() {
	for (int i = 0; i < n; i++) {
		if (list[i] < 4) {
			list[i] = 4;
		}
	}
}


void between_min_max() {
	int indexMin, indexMax, min = list[0], max = list[0];
	for (int i = 0; i < n; i++) {
		if (min >= list[i]) {
			min = list[i];
			indexMin = i;
		}
		if (max <= list[i]) {
			max = list[i];
			indexMax = i;
		}
	}
	for (int i = indexMin + 1; i < indexMax; i++) {
		list[i] = list[i] * 10;
	}
}


void between_first_and_last_even() {
	int first = -1, last;
	for (int i = 0; i < n; i++) {
		if (list[i] % 2 == 0 && first == -1) {
			first = i;
		}
		if (list[i] % 2 == 0) {
			last = i;
		}
	}
	for (int i = first + 1; i < last; i++) {
		list[i] = list[i] * 100;
	}
}


void delete_el_in_list() {
	int index;
	printf("\n");
	printf("Введите индекс удаляемого элемента = ");
	scanf_s("%d", &index);
	if (index <= n) {
		for (int i = index; i < n; i++) {
			list[i] = list[i + 1];
		}
		n--;
	}
}


int paste_in_list() {
	for (int i = n + 1; i >= index + 1; i--) {
		list[i] = list[i - 1];
	}
	list[index] = el;
	n++;
	return 0;
}


void delete_min() {
	int min = list[0], index = 0;
	for (int i = 0; i < n; i++) {
		if (min > list[i]) {
			min = list[i];
			index = i;
		}
	}

	for (int i = index; i < n; i++) {
		list[i] = list[i + 1];
	}
	n--;
}


void insert_element() {
	el = 0;
	index = min_in_list();
	paste_in_list();
}


void delete_all_even() {
	for (int j = 0; j < n; j++) {
		if (list[j] % 2 == 0) {
			for (int i = j; i < n; i++) {
				list[i] = list[i + 1];
			}
			n--;
			j--;
		}
	}
}


void doubled_even() {
	for (int i = 0; i < n; i++) {
		if (list[i] % 2 == 0) {
			el = list[i];
			index = i;
			printf("n = %d ~~~~ i = %d ~~~~ index = %d ~~~~ el = %d\n", n, i, index, el);
			for (int j = n + 1; j >= index + 1; j--) {
				list[j] = list[j - 1];
			}
			list[index] = el;
			i++;
			n++;
		}
	}
}


void append_min_in_begin() {
	int indexMin = min_in_list();
	index = 0;
	el = list[indexMin];
	paste_in_list();
}


void delete_less_four() {
	for (int i = 0; i < n; i++) {
		if (list[i] < 4) {
			if (i <= n) {
				for (int j = i; j < n; j++) {
					list[j] = list[j + 1];
				}
				n--;
				i--;
			}
		}
	}
}