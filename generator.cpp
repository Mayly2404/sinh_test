#include <bits/stdc++.h>
using namespace std;
int id = 0; pair <int, string> name_fold[10000001];
string aaaaaaa[10000001]; void process_subtask();
void dang_ki_subtask (int iTest, string subtask) {
    name_fold[++id] = {iTest, subtask}; return;}
#ifndef GENERATOR
string subtask = "";
int regis_subtask (string s){ subtask = s; return 0;}
#endif // GENERATOR
#include "template.h"
using namespace Templates;







namespace Gen
{
    void regis(void)
    {
        // Cho phép ghi chú lên thư mục test nếu có nhu cầu
        // Cấu trúc: dang_ki_subtask(x, s);
        // Ý nghĩa: từ testcase trước đó + 1 đến testcase thứ x có thư mục được ghi chú nội dung s.
        process_subtask();
    }
    // Viết các hàm liên quan tới hàm sinh tại đây

    void gen (int iTest)
    {
        Gen :: regis(); if (id > 0) regis_subtask(aaaaaaa[iTest]);
        // Code hàm sinh tại đây
        // Lưu ý: iTest là test thứ i
        // Bạn không được chỉnh sửa các dòng lệnh của chúng tôi đã cho trước vì có thể các dòng lệnh làm gián đoạn quá trình sinh.
    }
}



























































































































































































int freq_test[10000001];
void process_subtask()
{
    sort(name_fold + 1, name_fold + 1 + id);
    for (int i = 1, j = 1; i <= 10000001 && j <= id; ++i)
        if (i <= name_fold[j].first)
        {
            aaaaaaa[i] = name_fold[j].second;
            if (i == name_fold[j].first) ++j;
        }
}
#ifndef GENERATOR
#include "create.h"
using namespace Create;

string prob_name = "";
void xem_testcase(void)
{
    int iTest;
    cout << "Nhập số thứ tự bộ thử cần xem: ";
    cin >> iTest;

    while (iTest <= 0)
    {
        cout << "Không hợp lệ, vui lòng nhập lại: ";
        cin >> iTest;
    }

    if (freq_test[iTest] == 0)
    {
        cout << "Bộ thử thứ " << iTest << " không tồn tại.\n";
        cout << "Đã hoàn thành!\n";
        cerr << "--------------------------------------\n";
        return;
    }
    Gen :: regis(); if (id > 0) regis_subtask(aaaaaaa[iTest]);
    string folder_link = prob_name + "\\" + str(iTest);
    if (subtask != "") folder_link += "_" + subtask;

    cout << "In bộ thử ra file [sample > input.txt], [sample > output.txt] (Y/N): ";
    string _ok;
    cin >> _ok;

    while (_ok != "Y" and _ok != "N")
    {
        cout << "Không hợp lệ, vui lòng nhập lại (Y/N): ";
        cin >> _ok;
    }
    string cmd = "if exist \"sample\" (exit /b 1) else (exit /b 0)";

    if ( system(cmd.c_str()) )
        system("rmdir /s /q sample");

    if ( !system(cmd.c_str()) )
        system("mkdir sample");

    // cerr << folder_link << "\n";


    string path1 = folder_link + "\\" + prob_name + ".inp";
    string path2 = folder_link + "\\" + prob_name + ".out";
    // cout << path << "\n";
    if (_ok != "Y")
    {
        // system("del sample");
    }
    if (_ok != "Y") cout << "In bộ thử ở luồng ra tiêu chuẩn.\nBộ thử thứ " << iTest << ": \n";
    ofstream outout("sample\\input.txt");
    if (_ok != "Y") cout << "Input: \n";
    ifstream in(path1.c_str());
    string s;
    while (getline(in, s))
    {
        if (_ok != "Y") cout << s << "\n";
        else outout << s << "\n";
    }

    if (_ok != "Y") cout << "Output: \n";
    ifstream in1(path2.c_str());
    ofstream out("sample\\output.txt");
    while (getline(in1, s))
    {
        if (_ok != "Y") cout << s << "\n";
        else out << s << "\n";
    }

    cout << "Đã hoàn thành!" << "\n";
    cerr << "--------------------------------------" << "\n";

    // Gen::gen (iTest);
}

void read_data()
{
    ifstream in("temp.txt");
    in >> prob_name;
    int testnum;
    in >> testnum;
    memset(freq_test, 0, sizeof(freq_test));
    for (int i = 1; i <= testnum; ++i)
        freq_test[i] = 1;
    save_tmp(testnum);
}
bool trust = false;

void add_test()
{
    int i;
    cerr << "Vui lòng nhập bộ thử bạn muốn thêm: "; cin >> i;

    ofstream out("logs_new.txt");
    {
        ofstream fout(prob_name + ".inp");
        streambuf* old_buf = cout.rdbuf();
        cout.rdbuf(fout.rdbuf());
        // freopen ((prob_name + ".inp").c_str (), "w", stdout);

        int input_gen_time, solution_exec_time;
        clock_t start_time;
        cerr << time() << " ";
        cerr << "Test #" << i << ":\n";
        start_time = clock ();
        Gen::gen (i);
        input_gen_time = 1000.0 * (clock() - start_time) / CLOCKS_PER_SEC;

        // fclose (stdout);

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
        cout.rdbuf(old_buf);
        freq_test[i] = 1;
        trust = true;
        return;
    }

}

void cop(string source_file, string target_file)
{
    ifstream cin(source_file);
    ofstream cout(target_file);
    string s;
    while(getline(cin, s)) cout << s << '\n';
}

int main ()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    read_data();
    cout << "Tính năng quản lí bộ thử" << "\n";
    // int cnttry = 1e7;
    while (true)
    {
        if (trust)
        {
            system("python process_log.py");
            system("del logs_new.txt");
            trust = false;
        }
        int check = 0;
        cout << "[1]. Xem bộ thử." << "\n";
        cout << "[2]. Thêm bộ thử mới." << "\n";
        cout << "[3]. Đóng gói các bộ kiểm (zip)." << "\n";
        cout << "[4]. Kết thúc chương trình." << "\n";
        cout << "--------------------------------------" << "\n";
        cout << "Vui lòng nhập 1 số tương đương với tính năng bạn chọn: ";
        cin >> check;
        while (check <= 0 || check > 4)
        {
            cout << "Không hợp lệ, vui lòng nhập lại: ";
            cin >> check;
        }
        if (check == 4) break;
        else if (check == 2) add_test();
        else if (check == 3)
        {
            system("python process_log.py");
            cop("logs.txt", prob_name + "\\logs.txt");
            string path = "zip -r " + prob_name + ".zip " + prob_name;
            // cout << path << "\n";
            //string path = "tar -a -c -f data" + prob_name + ".zip -C " + prob_name;
            system(path.c_str());
            cout << "Đã hoàn thành việc đóng gói bộ kiểm." << "\n";
            cout << "--------------------------------------" << "\n";
        }
        else xem_testcase();

    }
    string path;
    path = "del " + prob_name + ".inp";
    system(path.c_str());
    path = "del " + prob_name + ".out";
    system(path.c_str());
    path = "del temp.txt";
    system(path.c_str());
    system("rmdir /s /q sample");
    path = "del logs_new.txt";
    system(path.c_str());
    system("cls");
    cop("logs.txt", prob_name + "\\logs.txt");
    path = "del logs.txt";
    system(path.c_str());
    cerr << "Đã tạo thành công bộ testcase, vui lòng thoát ra để xem kết quả. Kết thúc chương trình." << "\n";
    cerr << "Bạn có thể tắt chương trình ngay bây giờ, chương trình sẽ tự động tắt sau 60 giây nữa." << "\n";

}
#endif // GENERATOR
