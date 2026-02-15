/*
特别说明：本文件由Gemini生成
使用说明：请直接单独运行本文件，它会自动生成所有子目录下的.hpp、.cpp、CMakeLists.txt文件
使用便利：在添加多个异常时可以一键生成所有文件，省去了手动创建的麻烦
创建者：逍遥风鉴事
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <windows.h> // 使用 Windows 原生 API 解决兼容性
#include <sys/stat.h>

using namespace std;

// 检查文件或路径是否存在
bool file_exists(const string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

// 提取文件夹名：1.abcd -> abcd
pair<bool, string> get_clean_name(const string &raw_name)
{
    // 正则：以数字开头，跟着一个点，后面是具体名字
    regex re("^\\d+\\.(.+)");
    smatch match;
    if (regex_search(raw_name, match, re) && match.size() > 1)
    {
        return {true, match.str(1)};
    }
    return {false, ""};
}

void process_folder(const string &folder_name)
{
    auto [is_match, clean_name] = get_clean_name(folder_name);
    if (!is_match)
        return;

    string prefix = folder_name + "\\"; // Windows 路径使用反斜杠
    string hpp_path = prefix + clean_name + ".hpp";
    string cpp_path = prefix + clean_name + ".cpp";
    string cmake_path = prefix + "CMakeLists.txt";

    cout << "---> 正在检查目录: " << folder_name << endl;

    // 1. 生成 .hpp
    if (!file_exists(hpp_path))
    {
        ofstream f(hpp_path.c_str());
        f << "#pragma once\n\n// " << clean_name << " header\n";
        cout << "   [OK] " << clean_name << ".hpp" << endl;
    }

    // 2. 生成 .cpp
    if (!file_exists(cpp_path))
    {
        ofstream f(cpp_path.c_str());
        f << "#include \"" << clean_name << ".hpp\"\n\n";
        cout << "   [OK] " << clean_name << ".cpp" << endl;
    }

    // 3. 生成 CMakeLists.txt
    if (!file_exists(cmake_path))
    {
        ofstream f(cmake_path.c_str());
        f << "target_sources(game_start PRIVATE\n"
          << "    ${CMAKE_CURRENT_SOURCE_DIR}/" << clean_name << ".hpp\n"
          << "    ${CMAKE_CURRENT_SOURCE_DIR}/" << clean_name << ".cpp\n"
          << ")\n\n"
          << "target_include_directories(game_start PRIVATE \n"
          << "${CMAKE_CURRENT_SOURCE_DIR})\n";
        cout << "   [OK] CMakeLists.txt" << endl;
    }
}

int main()
{
    WIN32_FIND_DATA findData;
    // 查找当前目录下所有内容
    HANDLE hFind = FindFirstFile(".\\*", &findData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        cerr << "无法打开当前目录！" << endl;
        return 1;
    }

    do
    {
        // 检查是否为文件夹，且排除 "." 和 ".."
        if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
            strcmp(findData.cFileName, ".") != 0 &&
            strcmp(findData.cFileName, "..") != 0)
        {

            process_folder(findData.cFileName);
        }
    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
    cout << "\n所有操作已完成。" << endl;
    system("pause"); // 方便在 Dev-CPP 中查看运行结果
    return 0;
}