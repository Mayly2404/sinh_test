#include <bits/stdc++.h>
#define GENERATOR
#include "generator.cpp"
#include "create.h"

using namespace std;

int main ()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int testnum;
    cout << "Nhập số lượng bộ kiểm cần tạo: ";
    cin >> testnum;

    save_tmp(testnum);
    string prob_name;
    cout << "Nhập mã bài (không bao gồm phần mở rộng): ";
    cin >> prob_name;

    using namespace Create;
    create_root (prob_name);
    compile_solution ();

    cerr << "Bắt đầu tạo bộ kiểm" << "\n";
    cerr << "--------------------------------------" << "\n";
    ofstream kem("temp.txt");
    kem << prob_name << "\n";
    kem << testnum << "\n";
    ofstream out("logs.txt");

    for (int i = 1; i <= testnum; i ++)
    {
        freopen ((prob_name + ".inp").c_str (), "w", stdout);

        int input_gen_time, solution_exec_time;
        clock_t start_time;
        cerr << time() << " ";
        cerr << "Test #" << i << ":\n";
        start_time = clock ();
        Gen::gen (i);
        input_gen_time = 1000.0 * (clock() - start_time) / CLOCKS_PER_SEC;

        fclose (stdout);

        cerr << "Đã tạo ra file input. Đang chạy file lời giải.\n";

        start_time = clock ();
        system ("solution.exe");
        solution_exec_time = 1000.0 * (clock() - start_time) / CLOCKS_PER_SEC;

        cerr << "Đã tạo ra file output.\n";

        copy_test (prob_name, subtask, i);
        cerr << "Kết thúc quá trình tạo bộ thử #" << i << ".\n";
        cerr << "Thời gian tạo file input: " << input_gen_time << " ms.\n";
        cerr << "Thời gian tạo file output: " << solution_exec_time << " ms.\n";
        cerr << "--------------------------------------" << "\n";

        // logs.txt
        out << time() << " Đã sinh bộ kiểm #" << i << "\n";
        out << "Thời gian tạo file input: " << input_gen_time << " ms.\n";
        out << "Thời gian tạo file output: " << solution_exec_time << " ms.\n";
        out << "--------------------------------------" << "\n";

    }
    return 0;
}
