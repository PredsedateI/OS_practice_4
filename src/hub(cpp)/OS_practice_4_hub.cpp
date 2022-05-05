#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <process.h>
#include <iomanip>
#include <filesystem>
#include <Windows.h>

#define BASIC 0

void start_java();
void start_cpp();
void start_python();
void start_assembler();

std::mutex cout_guard;

int main() {
    long long b, c, i;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
    std::cout << "i = ";
    std::cin >> i;

    std::filesystem::create_directory("langs/temp");
    std::ofstream fout("langs/temp/hub.txt");
    fout << BASIC << ' ' << b << ' ' << c << ' ' << i;
    fout.close();

    std::cout << '\n' << std::setw(10) << "Language" << std::setw(21) << "Result" << std::setw(9) << "Time" << '\n';
    std::thread java_thread(start_java);
    std::thread cpp_thread(start_cpp);
    std::thread python_thread(start_python);
    std::thread assembler_thread(start_assembler);
    java_thread.join();
    cpp_thread.join();
    python_thread.join();
    assembler_thread.join();

    std::filesystem::remove_all("langs/temp");
    std::cout << "\nApp will automatically close in 20 seconds";
    Sleep(20000);
    return 0;
}

void start_java() {
    char path[] = "langs/OS_practice_4_java.exe";
    char* args[] = { path, NULL };
    _spawnv(_P_WAIT, args[0], args);

    long long res;
    long long t;
    std::ifstream fin("langs/temp/java.txt");
    fin >> res >> t;

    cout_guard.lock();
    std::cout << std::setw(10) << "java" << std::setw(21) << res << std::setw(9) << ((double)t)/1000 << '\n';
    cout_guard.unlock();
    return;
}

void start_cpp() {
    char path[] = "langs/OS_practice_4_cpp.exe";
    char* args[] = { path, NULL };
    _spawnv(_P_WAIT, args[0], args);

    long long res;
    double t;
    std::ifstream fin("langs/temp/cpp.txt");
    fin >> res >> t;

    cout_guard.lock();
    std::cout << std::setw(10) << "c++" << std::setw(21) << res << std::setw(9) << t << '\n';
    cout_guard.unlock();
    return;
}

void start_python() {
    char path[] = "langs/OS_practice_4_python.exe";
    char* args[] = { path, NULL };
    _spawnv(_P_WAIT, args[0], args);

    long long res;
    double t;
    std::ifstream fin("langs/temp/python.txt");
    fin >> res >> t;

    cout_guard.lock();
    std::cout << std::setw(10) << "python" << std::setw(21) << res << std::setw(9) << t << '\n';
    cout_guard.unlock();
    return;
}

void start_assembler() {
    char path[] = "langs/OS_practice_4_assembler.exe";
    char* args[] = { path, NULL };
    _spawnv(_P_WAIT, args[0], args);

    long long res;
    double t;
    std::ifstream fin("langs/temp/assembler.txt");
    fin >> res >> t;

    cout_guard.lock();
    std::cout << std::setw(10) << "assembler" << std::setw(21) << res << std::setw(9) << t << '\n';
    cout_guard.unlock();
    return;
}