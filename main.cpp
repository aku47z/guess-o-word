#include<iostream>
#include<string>
#define GREEN 0
#define YELLOW 1
#define RED 2
//not using namespace std kinaki its not good practice re

class wordle
{
    private:
        std::string guess; //stores guessed word
        const std::string selected_word = "hello"; 
        //aile ko laagi hello, import file and add random word etaa pachi

        char illegal_letters[24]; // stores illegal letters
        short illegal_count; //stores no. of illegal letters
        short color[5]{RED}; //all color values initialized to 2

    public:
        void set_guess(std::string a)
        {
            guess = a;
        }
        
        bool check_exist() //function to check if word exists
        {
            //sammy ko search algorithm here 
            
            /*
            if exists
            {
                return true;
            }
            else
            {
                return false;
            }    
            */
        }

        bool check_legal() //function to check if word contains illegal letters
        {   
            for(short i = 0; i < 5; i++)
            {
                for(short j = 0; j < illegal_count; j++)
                {
                    if(guess[i] == illegal_letters[j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        bool check_win() //function to check if word is right
        {
            return (guess == selected_word);
        }

        void compare()
        {
            //this loop should find the color values of the guess
            for (short i = 0; i < 5; i++)
            {
                if (guess[i] == selected_word[i])
                {
                    color[i] = GREEN;
                }
                else
                {
                    for (short j = 0; j < 5; j++)
                    {
                        if (guess[i] == selected_word[j])
                        {
                            color[i] = YELLOW;
                            break;
                        }
                        else
                        {   
                            color[i] = RED;                            
                        } 
                    }
                }
            }
            //this loop finds the illegal letters
            for(short i = 0; i < 5; i++)
            {
                if(color[i] == RED)
                {
                    illegal_letters[illegal_count] = guess[i];
                    illegal_count++;
                }
            }
        }
        
        void redisplay()
        {
            for (short i = 0; i < 5; i++)
            {
                std::cout << '\b'; //delete monochrome input to give colored colors
            }
            for (short i = 0; i < 5; i++)
            {
                std::cout << color[i]; //display with color
            }             
            std::cout << "\n\n";
        }

        void display_correct()
        {
            std::cout << selected_word << '\n';
        }
};

int main() 
{
    //game loop
    wordle x;
    std::string guess;
    
    for(short attempt_count = 1; attempt_count <= 6; attempt_count++)
    {
        std::cout << "Guess " << attempt_count << ":\t";
        std::cin >> guess;
        x.set_guess(guess);
        x.check_legal();
        x.check_exist();
        x.compare();
        x.redisplay();

        if (x.check_win())
        {   
            std::cout << "YOU WIN!!\n"; //display winning message
            return 0;
        }
    }
    std::cout << "YOU LOSE!!\n"; // display losing message
    x.display_correct();
    return 1;
}

