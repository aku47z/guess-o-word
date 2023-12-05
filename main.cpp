#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#define GREEN 0
#define YELLOW 1
#define RED 2
//not using namespace std kinaki its not good practice re

class wordle
{
    private:
        std::string guess; //stores guessed word
        std::string selected_word; 
        std::vector<std::string> wordlist; //stores the list of possible words

        char illegal_letters[24]{'0'}; // stores illegal letters
        short illegal_count = 0; //stores no. of illegal letters
        short color[5]{RED}; //all color values initialized to 2

    public:
        void set_answer()
        {
            //open text file
            std::ifstream all_words("possiblewords.txt");

            //check if file opened
            if (all_words.is_open())
            {
                //copy words from the file to an array
                std::string tempword;
                while (all_words>>tempword)
                {
                    wordlist.push_back(tempword);
                }
                
                //Close file
                all_words.close();   

                //Select random word
                std::srand(std::time(nullptr));
                int randomIndex = rand() % wordlist.size();
                selected_word= wordlist[randomIndex];
            }
            else
            {
                std::cout<<"Error opening file! Terminating program";
                exit(EXIT_FAILURE);
            }
        }

        void set_guess(std::string a)
        {
            //capitalize all guesses
            for (size_t i = 0; i < a.length(); ++i) 
            {
                a[i] = toupper(a[i]);
            }
            guess = a;
        }
        
        bool check_exist() //function to check if word exists
        {
            //sammy ko search algorithm here 

            int left = 0;
            int right = wordlist.size() - 1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;

                if (wordlist[mid] == guess)
                {
                    return true;
                }

                if (wordlist[mid] < guess)
                {
                    left = mid + 1;
                }

                if (wordlist[mid] > guess)
                {
                    right = mid - 1;
                }
            }
            return false;
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
                if (color[i] == RED)
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
    x.set_answer();
    
    for(short attempt_count = 1; attempt_count <= 6; attempt_count++)
    {
        do
        {
            std::cout << "Guess " << attempt_count << ":\t";
            std::cin >> guess;
            x.set_guess(guess);
            if (attempt_count > 1)
            {
                if (!x.check_legal())
                {
                    std::cout << "Illegal letters! Guess again.\n\n";
                    continue;
                }
            }
            if (!x.check_exist())
            {
                std::cout << "Word does not exist! Guess again.\n\n";
                continue;
            }
            break;    
        } while (true);

        x.compare();
        x.redisplay();

        if (x.check_win())
        {   
            std::cout << "YOU WIN!!\n"; //display winning message
            return 0;
        }
    }
    std::cout << "YOU LOSE!!\nTHE CORRECT WORD IS "; // display losing message
    x.display_correct();
    return 1;
}
