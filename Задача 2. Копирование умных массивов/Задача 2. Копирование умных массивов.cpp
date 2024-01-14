// Задача 2. Копирование умных массивов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class smart_array
{
public:
	smart_array(int size);
	~smart_array();

	void add_element(int value) {
		if (count >= size)
		{
			throw std::out_of_range("Новый элемент выходит за пределы массива!");
		}
		else {
			arr[count] = value;
			count++;
		}
	}

	int get_element(int index) {
		if (index < 0 || !(index < size)) {
			throw std::out_of_range("Индекс находится за пределами массива!");
		}
		else { return arr[index]; }
	}

	void print_arr() {
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	smart_array(const smart_array &other) {
		this->size = other.size;
		this->count = other.count;

		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = other.arr[i];
		}
	}

	smart_array & operator = (smart_array & other) {
		this->size = other.size;
		this->count = other.count;

		delete[] this->arr;

		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = other.arr[i];
		}

		return *this;

	}

private:
	int size = 0;
	int* arr = 0;
	int count = 0;
};

smart_array::smart_array(int size)
{
	this->size = size;
	arr = new int[size] {};
}

smart_array::~smart_array()
{
	delete[] arr;
}


int main()
{
	setlocale(LC_ALL, "ru");

	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;


}