//
//  main.cpp
//  Comp 1602 assignment2
//
//  Created by Marishel Lochan on 3/15/24.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Puzzle{
    string category;
    char puzzle[80];
};

int readCategories(string categories[]){
    
    ifstream inputfile;
    char line[80];
    string sentence;
    int count =0;
    
    inputfile.open("Categories.txt");
    
    while(!inputfile.is_open()){
        cout << "Error in categories file. Aborting...."<<endl;
        exit(1);
    }
    
    inputfile.getline(line,80);
    sentence= line;
    
    
    while(count < 50 && sentence != "\0"){
        
        //inputfile.getline(line,80);
        categories[count]=sentence;
        //cout << categories[count]<<endl;
        count++;
        
        inputfile.getline(line,80);
        sentence= line;
    
    }
    
    //cout << count;
    return count;
}

int readPuzzles(Puzzle puzzles[]){
    ifstream inputfile;
    char line[80];
    string sentence;
    int count =0;
    
    inputfile.open("WOF-Puzzles.txt");
    
    if(!inputfile.is_open()){
        cout <<"Error in puzzles file. Aborting..."<<endl;
        exit(1);
    }
    
    inputfile.getline(line,80);
    sentence= line;
    
    while(count <1500 && sentence != "\0"){
        
        puzzles[count].category=sentence;
        inputfile.getline(line,80);
        strcpy(puzzles[count].puzzle,line);
        
        count ++;
        inputfile.getline(line,80);
        sentence= line;
        
    }
    
    //cout << count <<endl;
    return count;
    
}
int chooseCategory(string categories[], int count ){
    
    int random_category1;
    int random_category2;
    int random_category3;
    int choice;
    
    //srand((time(NULL));
    
    random_category1= 4; //rand()%count;
    random_category2= 0; //rand()%count;
    random_category3= 3;//rand()%count;
    
    while(random_category1 == random_category2 || random_category1 == random_category3 || random_category2 == random_category3 ){
        
        random_category1= rand()%count;
        random_category2= rand()%count;
        random_category3= rand()%count;
    }
    
    cout << "Please choose from one of the following categories:" <<endl <<endl;
    
    cout << "Category 1: "<< categories[random_category1] << endl;
    cout << "Category 2: "<< categories[random_category2] << endl;
    cout << "Category 3: "<< categories[random_category3] << endl;
    
    cout << endl << "Your choice? ";
    cin >> choice;
    
    if(choice == 1){
        
        cout << "Category chosen for bonus round is: " << categories[random_category1] <<endl <<endl;
        return random_category1;
    }
    else if(choice ==2){
        
        cout << "Category chosen for bonus round is: " << categories[random_category2] <<endl <<endl;
        return random_category2;
    }else{
        
        cout << "Category chosen for bonus round is: " << categories[random_category3] <<endl <<endl;
        return random_category3;
    }
    
    
}

void blankoutPuzzle( char puzzle[]){
    
    char copy[50];
    int count = 0;

    
    while(puzzle[count] != '\0'){
        
        if((puzzle[count]>= 'A') && (puzzle[count]<= 'Z')){
            copy[count]= '#';
        }else{
            copy[count]=puzzle[count];
        }
        
        count++;
    }
    copy[count]='\0';
    
    cout << endl<< "The puzzle to start with is: " << copy <<endl<<endl;
    
    
}

char lowertoUpper( char letter){
    
    if(letter >= 'a' && letter <= 'z')
    {
        letter = letter -32;
    }
    
    return letter;
}


void revealLetter(char puzzle[]){
    
    char c1, c2, c3, c4;
    char v;
    bool wildcard = 0;
    char line[80];
    int count=0;
    
    cout << endl << "Please enter 3 consonants and a vowel: ";
    cin >> c1 >> c2 >> c3 >> v;
    
    c1 = lowertoUpper(c1);
    c2 = lowertoUpper(c2);
    c3 = lowertoUpper(c3);
    v = lowertoUpper(v);
    

    cout << "Do you have the wildcard? (0-No, 1-Yes) " << endl;
    cin >>wildcard;
   
    
    if(wildcard == true){
        cout << "Since you have the wildcard, please enter another consonant";
        cin >> c4;
        c4 = lowertoUpper(c4);
        
        while(puzzle[count] !='\0'){
            
            if(puzzle[count] >='A' && puzzle[count]<='Z'){
                
                if(puzzle[count]!='R' && puzzle[count]!='S' && puzzle[count]!='T' && puzzle[count]!='L' &&
                   puzzle[count]!='N' && puzzle[count]!='E'  && puzzle[count]!=c1  && puzzle[count]!=c2  && puzzle[count]!=c3 && puzzle[count]!=c4  && puzzle[count]!=v ){
                    
                    line[count]='#';
                }
                else{
                    line[count]=puzzle[count];
                }
            }else{
                line[count]=puzzle[count];
            }
            count ++;
        }
        
        line[count]='\0';
        
        
    }else{
        
        while(puzzle[count] !='\0'){
            
            if(puzzle[count] >='A' && puzzle[count]<='Z'){
                
                if(puzzle[count]!='R' && puzzle[count]!='S' && puzzle[count]!='T' && puzzle[count]!='L' &&
                   puzzle[count]!='N' && puzzle[count]!='E'  && puzzle[count]!=c1  && puzzle[count]!=c2  && puzzle[count]!=c3 && puzzle[count]!=v ){
                    
                    line[count]='#';
                }
                else{
                    line[count]=puzzle[count];
                }
            }else{
                line[count]=puzzle[count];
            }
            count ++;
        }
        
        line[count]='\0';
    }
    
    cout << "The puzzle is now: " << line;
    cout <<endl <<endl;
    
    
}

void rstLne(char puzzle[]){
    
    int count =0;
    char line[80];
    
    cout << "Revealing R, S, T, L, N, E ..." <<endl <<endl;
    while(puzzle[count] != '\0'){
        
        if(puzzle[count] >='A' && puzzle[count]<='Z'){
            
            if(puzzle[count]!='R' && puzzle[count]!='S' && puzzle[count]!='T' && puzzle[count]!='L' &&
               puzzle[count]!='N' && puzzle[count]!='E'){
                
                line[count]='#';
            }
            else{
                line[count]=puzzle[count];
            }
        }else{
            line[count]=puzzle[count];
        }
        count ++;
    }
    
    line[count]='\0';
    
    cout<< "The puzzle is now: " << line <<endl <<endl;
    
    
}

void generatePrize(){
    char prize1[80] ="It is ..... $40,000.00!";
    char prize2[80] ="It is ..... a Car !";
    char prize3[80] = "It is ..... $45,000.00!";
    char prize4[80] = "It is ..... JACKPOT of $100,000.00!";
    int prize_rand;
    
    srand((time(NULL)));
    prize_rand= 1 + rand()%25;
    
    if(prize_rand <=3){
        cout << prize1;
    }else if( prize_rand <= 22){
        cout << prize2;
    }else if(prize_rand <=24){
        cout << prize3;
    }else{
        cout << prize4;
    }

}

bool compare(char puzzle[], char guess[]){
    bool correct = true;
    
    int i=0;
    while(puzzle[i] != '\0' && guess[i] != '\0'){
        if(puzzle[i] != guess[i]){
            correct = false;
            break;
        }
        i++;
    }
    
    return correct;
}



void makeGuess(char puzzle[]){
    char guess[80];
    int chances=3;
    bool correct = false;
   
    
    
    cin.ignore(INT_MAX, '\n');
    
    while (chances >0 && correct != true ){
        
        cout << "Make a guess: "<<endl;
        cin.getline(guess,80);
        //size_t length = strlen(guess);e
        int count=0;
        while(guess[count] != '\0'){
            guess[count]=lowertoUpper(guess[count]);
            count++;
        }
        
        //int comparison= strcmp(puzzle,guess);
        
        correct = compare(puzzle,guess);
       
        
        //cout << comparison <<endl;
        
        if(correct == false){
            cout << endl<< "Sorry. "<< guess <<" is not correct"<<endl;
            chances--;
            cout <<"You have " << chances << " tries left."<<endl<<endl;
        }
        
    }
    
    if(correct == true){
        
        cout << "Congratulations! You got it out!"<<endl;
        cout << "OK, let's see your prize."<<endl;
        generatePrize();
    }else{
        cout << "I am sorry. You will not get a prize."<<endl;
        cout << "The puzzle is " << puzzle <<endl;
    }
}
    

void decryptPuzzle( char puzzle[]){
    
    int count=0;
    char decrypted[80];

    
    while(puzzle[count] != '\0'){
        
        if(puzzle[count] >='A' && puzzle[count]<='Z'){
            decrypted[count] = puzzle[count]-5;
            
            if(decrypted[count] < 'A'){
                
                decrypted[count] = ('Z'-('A'-decrypted[count]))+1;
            }
        }else{
            decrypted[count]= puzzle[count];
        }
        
        count ++;
    }
    
    decrypted[count]='\0';
    
    //cout << "Decrypted : " << decrypted << endl;
    
    blankoutPuzzle(decrypted);
    rstLne(decrypted);
    revealLetter(decrypted);
    makeGuess(decrypted);
}

int choosePuzzle(Puzzle puzzles[], int count, string choice){
    
    int random;
    
    srand((time(NULL)));
    
    random= rand()%count;
    
    while( puzzles[random].category != choice ){
        
        random= rand()%count;
    }
    
    //cout << "Puzzle : " << puzzles[random].puzzle <<endl;
    
    return random;
    
}
int main() {
    
    Puzzle puzzles[1500];
    string categories[50];
    
    int choice;
    int puzzle_random;
    
    int category_count=readCategories(categories);
    int puzzle_count=readPuzzles(puzzles);
    //char puzzle_decrypted[80];
    
    
    cout << "# of categories read from the file: "<< category_count<< endl<< endl;
    cout << "# of categories read from the file: "<< puzzle_count<< endl<< endl;
    
    
    
    choice= chooseCategory(categories,category_count);
    
    puzzle_random=choosePuzzle(puzzles,puzzle_count,categories[choice]);
    
    decryptPuzzle(puzzles[puzzle_random].puzzle);
    
    cout <<endl;
    
    
    return 0;
}
