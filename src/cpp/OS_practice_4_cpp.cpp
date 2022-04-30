#include <fstream>

short basic;
long long b;
long long c;

long long f(long long i) {
	if (i == basic) return 0;
	long long temp = 0;
	for (int n = 1; n <= 100000000; n++) {
		temp += 2 * b + c - i;
	}
	return f(i - 1) + temp;
}

int main() {
	long long result, i;
	std::ifstream fin("langs/temp/hub.txt");
	fin >> basic >> b >> c >> i;
	fin.close();

	clock_t ts, te;
	ts = clock();
	result = f(i);
	te = clock();
	float dt = ((float)(te - ts)) / CLOCKS_PER_SEC;

	std::ofstream fout("langs/temp/cpp.txt");
	fout << result << ' ' << dt;
	fout.close();
	return 0;
}