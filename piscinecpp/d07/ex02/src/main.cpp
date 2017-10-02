#include "Array.tpp"

int main (void) {
	Array<int> a(10);

	for (int i = 0; i < 10; i++) {
		a[i] = i;
		std::cout << a[i] << std::endl;
	}
	std::cout << a << std::endl;
	return 0;
}