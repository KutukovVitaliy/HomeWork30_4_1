#include <iostream>
#include <cpr/cpr.h>

class MyCpr {
    cpr::Response r;
    std::string key {"City"};
    std::string value {"Stavropol"};
public:
    bool DecodeCommand(std::string inCommand){
        if(inCommand == "exit"){
            return  false;
        }
        else if(inCommand == "post"){
            r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                       cpr::Payload({{key, value}}));
            std::cout << r.text << std::endl;
       }
        else if(inCommand == "put"){
            r = cpr::Put(cpr::Url("http://httpbin.org/put"),
                          cpr::Payload({{key, value}}));
            std::cout << r.text << std::endl;
        }
        else if(inCommand == "patch"){
            r = cpr::Patch(cpr::Url("http://httpbin.org/patch"),
                          cpr::Payload({{key, value}}));
            std::cout << r.text << std::endl;
        }
        else if(inCommand == "delete"){
            r = cpr::Delete(cpr::Url("http://httpbin.org/delete"),
                          cpr::Payload({{key, value}}));
            std::cout << r.text << std::endl;
        }
        else if(inCommand == "get"){
            r = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout << r.text << std::endl;
       }
        else{
            std::cout << "Bad command! Try again." << std::endl;
        }

        return true;
    }
};

int main() {
    MyCpr test;
    std::string command;
    do{
        std::cout << "Enter the command: ";
        std::cin >> command;
    }while(test.DecodeCommand(command));
    return 0;
}
