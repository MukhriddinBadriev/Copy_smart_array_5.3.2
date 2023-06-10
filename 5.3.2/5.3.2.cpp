#include <iostream>
#include <exception>

class smart_array {
public:
	smart_array(int size) {
		s_m = new int[size];
		capacity = size;
	}

	int add_element(int element) {
		if (i == capacity) {
			capacity *= 2;
			int* tmp = new int[capacity];
			for (int j = 0; j < i; j++) {
				tmp[j] = s_m[j];
			}
			delete[]s_m;
			s_m = tmp;
		}
		if (i < capacity) {
			s_m[i] = element;
			i++;
		}

		return element;
	}

	smart_array& operator=(const smart_array& other) {
		if (this != &other) {
			delete s_m;
			if (other.s_m == nullptr) s_m = nullptr;
			else {
				capacity = other.capacity;
				s_m = new int[capacity]; 
				for (int j = 0; j < capacity; j++) {
					s_m[j] = other.s_m[j];
				}
			}
		}
		return *this;
	}
	smart_array(const smart_array& other) {
		*this = other;
	}

	int get_element(int id) {
		if (id >= capacity) {
			throw std::exception("Wrong index");
		}
		return s_m[id];
	}

	~smart_array() {
		delete[] s_m;
	}
private:
	int* s_m = nullptr;
	int capacity = 0;
	int i = 0;
};

int main() {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);


		arr = new_array;

		smart_array arr1(5);
		arr1.add_element(100);

		smart_array arr2(arr1);
		std::cout << arr2.get_element(0);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
