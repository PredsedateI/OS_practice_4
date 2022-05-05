#include <fstream>
#include <time.h>

short basic;
long long b;
long long c;

extern "C"
{
	long long f(long long, long long, long long, long long);
}

int main() {
	long long result, i;
	std::ifstream fin("langs/temp/hub.txt");
	fin >> basic >> b >> c >> i;
	fin.close();

	long ts, te;
	ts = clock();
	result = f(basic, b, c, i);
	te = clock();
	float dt = ((float)(te - ts)) / CLOCKS_PER_SEC;

	std::ofstream fout("langs/temp/assembler.txt");
	fout << result << ' ' << dt;
	fout.close();
	return 0;
}