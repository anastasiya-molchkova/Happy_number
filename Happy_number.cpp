/* Напишите программу, которая определяет, является ли шестизначное число «счастливым» 
(сумма первых трёх цифр равна сумме последних трёх цифр). */

#include <iostream>

using std::cout; using std::cin; using std::endl;

// получаем от пользователя шестизначное число
unsigned int get_6_digits_number()
{
	cout << "Вводите шестизначное число: ";
	int answer;
	cin >> answer;
	while (cin.fail() || (answer < 100000) || (answer > 999999))
	{
		cout << "Попробуйте ввести шестизначное число ещё раз: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> answer;
	}
	return static_cast<unsigned int>(answer);
}

// возвращает сумму цифр трёхзначного числа
unsigned short summ_of_3_digits(const unsigned int three_digits_number)
{
	unsigned int first_digit = three_digits_number / 100;
	unsigned int second_digit = (three_digits_number / 10) - (first_digit*10);
	unsigned int last_digit = three_digits_number % 10;
	return (first_digit + second_digit + last_digit);
}

// проверяем шестизначное число на счастливость (сумма первых трёх цифр равна сумме вторых трёх цифр)
bool is_happy(const unsigned int six_digits_number)
{
	return (summ_of_3_digits(six_digits_number / 1000) == summ_of_3_digits(six_digits_number % 1000))? true: false;
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // подключаем кириллицу:

	cout << "Программа быстро проверяет введённое число на счастливость\n" << endl;

	while (true)
		if (is_happy(get_6_digits_number()))
			cout << "это счастливое число!" << endl;
		else 
			cout << "это обычное число" << endl;
}