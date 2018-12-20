#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"
#include <vector>
using namespace std;

class Menu {
private:
    int history_index;
    vector<Command*> history;
    
public:
    Menu() {
        history_index = 0;
    };
    void execute() {
        if(history_index == 0)
            cout << history_index << endl;
        else
        {
            cout << history.at(history_index - 1)->execute() << endl;
        }
    };
    bool initialized() {
        if (history_index == 0)
            return false;
        else
            return true;
    };
    
    void add_command(Command* cmd) {
        history.push_back(cmd);
        history_index += 1;
    };
    
    Command* get_command() {
        return history.at(history_index-1);
    };
    void undo() {
        if (history_index == 0)
            return;
        else
            history_index -= 1;
    };
    void redo() {
        if (history_index == 0)
            return;
	else if (history_index >= history.size())
		return;
        else
            history_index += 1;
    };
};

#endif //__MENU_CLASS__

