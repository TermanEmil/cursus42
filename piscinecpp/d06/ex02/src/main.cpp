#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

typedef struct	s_data
{
	std::string s1;
	int n;
	std::string s2;
}				t_data;

void * serialize (void) {
	char * result = new char(20);
	for (int i = 0; i < 20; i++)
		result[i] = 42;//rand() % 10 + 48;
	result[7] = 0;
	result[19] = 0;
	return static_cast<void*> (result);
}

t_data * deserialize (void * raw) {
	unsigned char * raw_c = static_cast<unsigned char*> (raw);

	t_data * result = new t_data();

	result->s1 = reinterpret_cast<char*> (raw_c);
	result->n = *reinterpret_cast<int*> (raw_c + 8 * sizeof(char));
	result->s2 = reinterpret_cast<char*> (raw_c + 8 * sizeof(char) + sizeof(int));
	return result;
}

int main (void) {
	srand(time(NULL));

	t_data * rs = deserialize(serialize());
	std::cout << rs->s1 << std::endl;
	std::cout << rs->n << std::endl;
	std::cout << rs->s2 << std::endl;
	return 0;
}