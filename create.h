#include<windows.h>
#include<bits/stdc++.h>
using namespace std;


// tên thư mục có T chữ số...
int T = 4;
// có thể chỉnh sửa




void save_tmp(int TestNum)
{
    return;
    T = 0;
    while (TestNum)
    {
        ++T;
        TestNum /= 10;
    }
}

namespace Create
{
    string time()
    {
        time_t raw = ::time(nullptr);
        raw += 7 * 3600;

        tm* t = gmtime(&raw);

        int hour24 = t->tm_hour;
        int hour12 = hour24 % 12;
        if (hour12 == 0 && hour24 >= 12)
            hour12 = 12;
        const char* period = (hour24 < 12) ? "AM" : "PM";

        ostringstream oss;
        oss << "["
            << setfill('0') << setw(2) << t->tm_mday << "/"
            << setw(2) << t->tm_mon + 1  << "/"
            << t->tm_year + 1900         << " "
            << setw(2) << hour12         << ":"
            << setw(2) << t->tm_min      << ":"
            << setw(2) << t->tm_sec      << " "
            << period
            << "]";

        return oss.str();
    }
    string str (long long a)
    {
        if(a == 0) return "0";
        if(a < 0) return "-" + str(-a);
        string ans = "";
        for(int i = 1; i <= T; i ++)
        {
            ans = "0" + ans;
            ans[0] = (a % 10) + '0';
            a /= 10;
        }
        return ans;
    }

    void copy_test (string prob_name, string subtask, int iTest)
    {
        cerr << "Đang tạo bộ thử #" << iTest << ".\n";

        string folder_link = prob_name + "\\" + str(iTest);
        if (subtask != "") folder_link += "_" + subtask;
        string cmd = "if exist \"" + folder_link + "\\\" (exit /b 1) else (exit /b 0)";

        if (system (cmd.c_str ()))
            system(("rmdir /s /q " + folder_link).c_str());

        system(("mkdir " + folder_link).c_str());

        cerr << "Đang chuyển bộ thử vào đúng vị trí.\n";

        cmd = "copy \"" + prob_name + ".inp\" \"" + folder_link + "\" >nul";
        system (cmd.c_str ());

        cmd = "copy \"" + prob_name + ".out\" \"" + folder_link + "\" >nul";
        system (cmd.c_str ());

        cerr << "Đã chuyển thành công.\n";
    }

    void create_root (string prob_name)
    {
        string cmd = "if exist \"" + prob_name + "\\\" (exit /b 1) else (exit /b 0)";
        if (system (cmd.c_str ()))
        {
            cerr << "Xóa bộ thử cũ? (Y/N): ";
            string _ok;
            cin >> _ok;

            while (_ok != "Y" and _ok != "N")
            {

                cerr << "Không hợp lệ, vui lòng nhập lại (Y/N): ";
                cin >> _ok;
            }

            if (_ok == "Y")
            {
                system(("rmdir /s /q " + prob_name).c_str());
                cerr << "Đã xóa bộ thử cũ.";
            }
            else
                cerr << "Bộ thử mới sẽ được ghi thêm vào hoặc đè lên bộ thử cũ.";
            cerr << '\n';
        }

        if (!system (cmd.c_str ())) system(("mkdir " + prob_name).c_str());
    }

    void compile_solution ()
    {
        cerr << "Đang biên dịch file lời giải.\n";
        system("g++ -g -pipe -O2 -s -static -lm -DTHEMIS -Wl,--stack,66060288 solution.cpp -o solution.exe");
        // system("g++ -g -pipe -O2 -s -static -lm -DTHEMIS -Wl, --stack, 66060288 solution.cpp -o solution.exe");
    }
}
