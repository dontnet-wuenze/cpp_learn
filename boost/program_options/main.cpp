#include <iostream>
#include <boost/program_options.hpp>
#include <string>
 
int main (int argc, char *argv[]) {
    // 步骤一：构造命名空间
    namespace bpo = boost::program_options;
 
    // 步骤二：构造选项描述器
    bpo::options_description opts("all options");
    // 步骤二：构造选项存储器，用法和map类似
    bpo::variables_map vm;
 
    // 步骤三：为选项描述器添加选项
    opts.add_options ()
        ("help,h", "produce help message")
        ("compression,c", bpo::value<int>(), "set compression level")
        ("filename,f", bpo::value<std::string>(), "the file name which want to be found");
 
    // 步骤四：对命令行输入参数做解析，并存入选项存储器中
    // 捕获异常
    try {
        bpo::store(bpo::parse_command_line(argc, argv, opts), vm);
    } catch (...) {
        std::cout << "input undecleare options!" << std::endl;
    }
 
    // 步骤五：notify更新所有外部变量
    bpo::notify(vm);
 
    // 步骤六：对解析完的参数处理
    // count用来判断在选项存储器中是否存在这个选项
    if (vm.count("help")) {
        std::cout << opts << std::endl;
    }
    if (vm.count("filename")) {
        // 取出后的类型是boost::any，需要通过模板成员函数as<type>()做类型转换，才能获取具体值
        std::cout << "find: " << vm["filename"].as<std::string>() << std::endl;
    }
    if (vm.empty()) {
        std::cout << "input is empty!" << std::endl;
    }
 
    return 0;
}

