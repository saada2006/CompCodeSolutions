#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

void PrintDirectory(const std::vector<std::string>& Dir) {
    for(const std::string& Str : Dir){
        std::cout << '/' << Str;
    }
    std::cout << "/\n";
}

void UpdateDirectory(std::vector<std::string>& Dir, const std::string& Path){
    int Start = 0;

    if(Path[0] == '/') {
        Dir.clear();
        Start = 1;
    }

    for(int i = Start; i < Path.size(); i++){
        const char c = Path[i];

        if(c == '/' || i + 1 == Path.size()){
            std::string Folder = Path.substr(Start, ((i + 1 == Path.size()) ? std::string::npos : i - Start));

            if(!Folder.compare("..")){
                Dir.pop_back();
            } else {
                Dir.push_back(Folder);
            }
            Start = i + 1;
        }

    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    #endif

    int NumCommands;
    std::cin >> NumCommands;
    std::cin.ignore();

    std::vector<std::string> Directory;
    for(int i = 0; i < NumCommands; i++) {
        std::string Command;
        std::getline(std::cin, Command);
        
        if(Command[0] == 'p') {
            PrintDirectory(Directory);
        } else {
            UpdateDirectory(Directory, Command.substr(3));
        }
    }

    return 0;
}