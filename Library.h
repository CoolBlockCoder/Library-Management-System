#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Member{
    long id;
    short age;
    std::string name, book;
};

void display_menu(std::string msg, std::vector<std::string> ops){
    std::cout << msg << std::endl << std::endl;
    for (auto op: ops){
        std::cout << op << std::endl;
    }
}

void display_member(Member m){
    std::cout << std::endl << m.id << " | " << m.name << " | " << m.age << " | " << m.book << std::endl;
}

int input_option(std::string msg){
    int inp;
    std::cout << msg;
    std::cin >> inp;
    return inp;
}

std::string input_option_s(std::string msg){
    std::string inp;
    std::cout << msg;
    std::cin >> inp;
    return inp;
}

void c_handling(int inp, bool &ended, std::vector<Member> &mems){
    switch(inp){
        case 1:{
            long id = input_option("ID: ");
            short age = input_option("Age: ");
            std::string name = input_option_s("Name: "), book = input_option_s("Book: ");
            Member m;
            m.id = id;
            m.age = age;
            m.name = name;
            m.book = book;
            mems.push_back(m);

            std::cout << "New member added!" << std::endl;
            break;}
        case 2:{
            std::vector<std::string> opts = {"1. By ID", "2. By Name", "3. By Age", "4. By Book"};
            display_menu("", opts);
            int inp2 = input_option("Enter your choice: ");
            switch(inp2){
                case 1:{
                    long tid = input_option("ID: ");
                    for(auto m: mems){
                        if(m.id == tid){
                            display_member(m);
                        }
                    }
                    break;}
                case 2:{
                    std::string tn = input_option_s("Name: ");
                    for(auto m: mems){
                        if(m.name == tn){
                            display_member(m);
                        }
                    }
                    break;}
                case 3:{
                    short ta = input_option("Age: ");
                    for(auto m: mems){
                        if(m.age == ta){
                            display_member(m);
                        }
                    }
                    break;}
                case 4:{
                    std::string tb = input_option_s("Book: ");
                    for(auto m: mems){
                        if(m.book == tb){
                            display_member(m);
                        }
                    }
                    break;}
                default:
                    break;
            }
            break;}
        case 3:
            ended = true;
            break;
        default:
            break;
    }
}
