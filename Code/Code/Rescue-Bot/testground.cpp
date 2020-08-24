/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string>

using namespace std;
int position[2] = {28,1};
char turn;
char map[30][30] = {
        {'R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R'},
        {'R','G','G','G','R','R','R','R','R','G','G','G','G','R','R','R','G','G','G','G','G','G','G','G','G','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','O','G','R'},
        {'R','G','O','O','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','O','O','G','G','G','G','O','G','R'},
        {'R','G','O','O','G','G','G','G','O','O','O','G','G','O','O','O','O','O','O','O','O','O','O','G','G','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','O','O','O','G','G','O','O','O','O','O','O','O','O','O','O','G','G','G','O','G','G','R'},
        {'R','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','R'},
        {'R','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','R'},
        {'R','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','R','R'},
        {'R','G','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','R','R'},
        {'R','G','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','R','R'},
        {'R','G','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','R','R'},
        {'R','G','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','G','R'},
        {'R','R','R','G','G','G','G','G','G','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','G','G','G','G','R'},
        {'R','R','R','G','G','G','G','G','G','G','G','G','G','W','W','W','W','W','W','W','G','G','G','G','G','G','G','G','G','R'},
        {'R','R','R','G','G','G','G','G','G','G','G','G','G','W','W','W','W','W','W','W','G','G','G','G','G','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','G','G','G','W','W','W','W','W','W','W','W','W','G','G','G','G','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','G','G','G','W','W','O','W','W','W','W','W','W','G','G','G','G','G','G','G','G','R'},
        {'R','G','G','G','G','G','G','G','G','G','G','W','W','W','W','W','W','W','W','W','W','W','G','G','G','G','G','G','G','R'},
        {'R','G','G','G','G','R','R','R','R','R','R','W','W','W','W','W','W','W','W','W','W','W','G','G','R','G','G','G','G','R'},
        {'R','G','G','G','G','R','R','R','R','R','R','W','W','W','W','W','W','W','W','W','W','W','R','R','R','R','G','G','R','R'},
        {'R','G','G','G','G','R','R','R','R','R','R','G','W','W','O','W','W','W','W','W','W','R','R','R','R','R','R','G','R','R'},
        {'R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R'},
};


class Testground {
    public:
        //void move_turn();
        void move_straight();
        int* location();
        char currendlook();
        void setturn(char u) {
        turn = u;
        }
        void setorientation(char o) {
        orientation = o;
      }
        char orientation;
};

int* Testground::location(){
    return position;
}

char Testground::currendlook(){
        switch(orientation){
        case 'N':
        return map[position[0]][position[1]];
        break;
        case 'S':
        return map[position[0]][position[1]];
        break;
        case 'E':
        return map[position[0]][position[1]];
        break;
        case 'W':
        return map[position[0]][position[1]];
        break;
    }
}      
void Testground::move_straight(){
        switch(orientation){
        case 'N':
        if (map[position[0]-1][position[1]] != 'R'){
        position[0] = position[0]-1;
        cout << "Position des Roboters: " << position[0] << ", " << position[1] << "\n";
        } 
        else{
            cout << "Kollision" << "\n";
        }
        break;
        case 'S':
        if (map[position[0]+1][position[1]] != 'R'){
        position[0] = position[0]+1;
        cout << "Position des Roboters: " << position[0] << ", " << position[1] << "\n";
        } 
        else{
            cout << "Kollision" << "\n";
        }
        break;
        case 'E':
        if (map[position[0]][position[1]+1] != 'R'){
        position[1] = position[1]+1;
        cout << "Position des Roboters: " << position[0] << ", " << position[1] << "\n";
        } 
        else{
            cout << "Kollision" << "\n";
        }
        break;
        case 'W':
        if (map[position[0]][position[1]-1] != 'R'){
        position[1] = position[1]-1;
        cout << "Position des Roboters: " << position[0] << ", " << position[1] << "\n";
        } 
        else{
            cout << "Kollision" << "\n";
        }
        default:
        cout << "No orientation" << "\n";
        }
}
/*
char Testground::move_turn(){
    switch(orientation){
        case 'N':
        if(turn == 'R'){
            orientation = 'E';
            return map[position[0]][position[1]+1];
        }
        else if(turn == 'L'){
            orientation = 'W';
            return map[position[0]][position[1]-1];
        }
        else{
            return '!';
        }
        break;
        case 'S':
        if(turn == 'R'){
            orientation = 'W';
            return map[position[0]][position[1]-1];
        }
        else if(turn == 'L'){
            orientation = 'E';
            return map[position[0]][position[1]+1];
        }
        else{
            return '!';
        }
        break;
        case 'E':
        if(turn == 'R'){
            orientation = 'S';
            return map[position[0]+1][position[1]];
        }
        else if(turn == 'L'){
            orientation = 'N';
            return map[position[0]-1][position[1]];
        }
        else{
            return '!';
        }
        break;
        case 'W':
        if(turn == 'R'){
            orientation = 'N';
            return map[position[0]-1][position[1]];
        }
        else if(turn == 'L'){
            orientation = 'S';
            return map[position[0]+1][position[1]];
        }
        else{
            return '!';
        }
        break;
    }
}
*/

/*int main()
{
    Testground Test;
    int *a = Test.location();
    cout<<"Position:\n" << a[0] << " " << a[1];
    return 0;
}
*/
