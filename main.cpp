#include <iostream>
#include <string>
#include <vector>

#include "Library.h"

/*
** Author: Jovan Petrov
** Date: 04.02.2021
*/

int main(){
    const std::string message = "\n*****MAIN MENU*****";
    std::vector<std::string> options = {"1. Add Member", "2. Get Member", "3. Quit"};

    bool ended = false;

    std::vector<Member> members;

    while(!ended){
        display_menu(message, options);
        int opt = input_option("Enter your chioce: ");
        c_handling(opt, ended, members);
    }
}
