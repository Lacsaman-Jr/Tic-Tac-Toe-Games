#include <iostream>
#include <ctime>

using namespace std;

void board(char *spaces);
void useplayer(char *spaces, char player);
void comp(char *spaces, char computer);
bool winner(char *spaces, char player, char computer);
bool tie(char *spaces);



int main()
{

    char spaces[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool run = true;

    board(spaces);

    while(run){
    	
        useplayer(spaces, player);
        board(spaces);
        if(winner(spaces, player, computer)){
            run = false;
            break;
        }
        else if(tie(spaces)){
            run = false;
            break;
        }

        comp(spaces, computer); 
        board(spaces);
         if(winner(spaces, player, computer)){
            run = false;
            break;
        }
        else if(tie(spaces)){
            run = false;
            break;
        }
        
    }
    cout << "THANKS FOR PLAYING!";
    
    return 0;
}

void board(char *spaces){
system("cls");
cout << '\n';
cout << "     |     |     " << '\n';
cout << " " << spaces[0] << "   |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
cout << "_____|_____|_____" << '\n';
cout << "     |     |     " << '\n';
cout << " " << spaces[3] << "   |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
cout << "_____|_____|_____" << '\n';
cout << "     |     |     " << '\n';
cout << " " << spaces[6] << "   |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
cout << "_____|_____|_____" << '\n';
cout << '\n';





}
void useplayer(char *spaces, char player)
{
    int num;

    do{
        cout << "ENTER CHOSEN SPOT (1-9)\n";
        cin >> num;
        num--;
        if(spaces[num] == ' '){
            spaces[num] = player;
            break;
        }
    }while(num > 0 || num < 9);


}
void comp(char *spaces, char computer){

    int number;

    srand(time(0));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    } 

}
bool winner(char *spaces, char player, char computer){
    
    if(spaces[0] != ' ' && spaces [0] ==  spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOST\n";
    }
    else if(spaces[3] != ' ' && spaces [3] ==  spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? cout << "YOU WON!\n" : cout << "YOU LOST\n";
    }
    else if(spaces[6] != ' ' && spaces [6] ==  spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? cout << "YOU WON!\n" : cout << "YOU LOST\n";
    }
    else if(spaces[0] != ' ' && spaces [0] ==  spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOST\n";
    }
    else if(spaces[1] != ' ' && spaces [1] ==  spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? cout << "YOU WON!\n" : cout << "YOU LOST\n";
    }
    else if(spaces[2] != ' ' && spaces [2] ==  spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? cout << "YOU WON!\n" : cout << "YOU LOST\n";
    }
    else if(spaces[0] != ' ' && spaces [0] ==  spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? cout << "YOU WON!\n" : cout << "YOU LOST\n";
    }
    else if(spaces[2] != ' ' && spaces [2] ==  spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? cout << "YOU WON!\n" : cout << "YOU LOST\n";
    }
    else{
        return false;
    }


    return true;
}
bool tie(char *spaces){
    
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    
    return true;
}
