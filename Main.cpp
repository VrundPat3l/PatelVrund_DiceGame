#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include <vector>
using namespace std;

// Declaring variables

int BankedScore1, BankedScore2, RoundScore1 = 0, RoundScore2 = 0, RollADie, DiceNeeded, NumberofSides, Choice, InitialScore1 = 0, InitialScore2 = 0, NumberofSides2, ComputerRoll, ComputerScore;
bool Player1Turn = true;

// constant variables for switch case
constexpr char PVP_CHOICE = '1';
constexpr char PVC_CHOICE = '2';
constexpr char EXIT_CHOICE = '4';
constexpr char CHOICE = '3';

// string variables for player's names
string Player1Name, Player2Name;
// integer variable for player's score
int Player1Score, Player2Score;



// Creating struct to store player names and scores

struct Player
{
	std::string name;
	int score;
};

std::vector<Player> leaderboard;

// Asking them to enter their names

void GetPlayerNames() {
	cout << "Enter Player 1's name: ";
	cin >> Player1Name;
	cout << "Enter Player 2's name: ";
	cin >> Player2Name;
}

// adding name and score to struct(leaderboard)
void AddToLeaderboard(std::string playerName, int score)
{
	bool playerFound = false;          // Declaring bool variable with false value
	for (Player& player : leaderboard) 
	{
		if (player.name == playerName)          // if same player is playing/name is same then add score to leaderboard
		{
			player.score += score;
			playerFound = true;
			break;
		}
	}
	if (!playerFound)                          // if new player/name is playing then add name and score to leaderboard
	{
		Player player;
		player.name = playerName;              // adding new name 
		player.score = score;                  // adding new score
		leaderboard.push_back(player);
	}
}

// Displaying the leaderboard
void DisplayLeaderboard()
{
	if (leaderboard.empty())
	{
		std::cout << "Leaderboard is empty.\n";
	}
	else
	{
		std::cout << "Leaderboard:\n";
		for (const Player& player : leaderboard)
		{
			std::cout << "Name: " << player.name << " - Score: " << player.score << " points\n";
		}
	}
}






// Function for Player 1 
void Player1()
{
	InitialScore1 += RollADie;                                                    // adding initial score to number on dice generated
	RoundScore1 = InitialScore1;
	cout <<  Player1Name << " your Score is " << RoundScore1 << "\n";                      // printing player's score is
}

// Function for Player 2 
void Player2()
{

	InitialScore2 += RollADie;                                                    // adding initial score to number on dice generated
	RoundScore2 = InitialScore2;
	cout << Player2Name << " your Score is " << RoundScore2 << "\n\n";                      // printing player's score is
}

// Function for computer 
void Computer()
{
	ComputerRoll = rand() % 6 + 1;
	ComputerScore += ComputerRoll;
	cout << "Computer rolled a Die " << ComputerRoll << "\n";                     // Printing the number computer rolled

	if (ComputerScore == 10)
	{
		cout << "Computer's score is equal to 10\n";
		ComputerScore = 0;
		cout << "Computer's round score is " << ComputerScore << "\n\n";
		Player1Turn = true;
	}
	else
	{
		cout << "Computer's round score is " << ComputerScore << "\n\n";
	}
}

// Function for player vs player
void PVP()
{

	std::string playerName;
	int score{};
	srand((unsigned)time(nullptr));                                                            // seed the random generator
	do
	{
		cout << "---------------------------------------------------* " << (Player1Turn ? Player1Name : Player2Name) << "'s Turn**---------------------------------------------------\n";
		cout << "Number of sides of dice you need\n";
		cin >> (Player1Turn ? NumberofSides : NumberofSides2);


		cout << "Player " << (Player1Turn ? Player1Name : Player2Name) << " Round Score is "
			<< (Player1Turn ? InitialScore1 : InitialScore2) << "\n\n";                                 // Printing player one / playuer two intial score / starting score

		cout << "Rolling.....\n";                                                                      // Printiing Dice is rolling

		RollADie = rand() % (Player1Turn ? NumberofSides : NumberofSides2) + 1;                        // Genrating random number on basis of sides user selects

		cout << "Player " << (Player1Turn ? Player1Name : Player2Name) << " Rolled a Die " << RollADie << "\n";    // Printing the number come on a die

		if (Player1Turn)
		{
			Player1();

			if (RoundScore1 > 10)                                                                          // Condition if score is greater than 10
			{
				cout << "Your Scroe is greater than 10 \n";                                                // Printing your score is greater than 10 if cobdition is true
				RoundScore1 = 0;
				BankedScore1 = 0;
				InitialScore1 = 0;                                                                           // his score will reset to initial score = 0
				cout << "Your round Score is " << '0' << "\n \n";                                  // printing his new score
				cout << "Now its player two's turn \n";
				cout << "Press Any choice to Continue...... \n";
				Player1Turn = false;
			}
			else
			{
				cout << "Player " << (Player1Turn ? Player1Name : Player2Name) << ", If you want to continue Press Any choice.......\n";
				cout << "Or Press 'a' to Bank your score\n";
			}

		}
		else
		{
			Player2();

			if (RoundScore2 > 10)                                                                          // Condition if score is greater than 10
			{
				cout << "Your Scroe is greater than 10 \n";                                                // Printing your score is greater than 10 if cobdition is true
				RoundScore2 = 0;
				BankedScore2 = 0;
				InitialScore2 = 0;                                                                           // his score will reset to initial score = 0
				cout << "Your round Score is " << "0" << "\n\n";                                   // printing his new score
				cout << "Now its player one's turn \n";
				cout << "Press Any choice to Continue...... \n";
				Player1Turn = true;
			}
			else
			{
				cout << "Player " << (Player1Turn ? "1" : "2") << ", If you want to continue Press Any choice.......\n";
				cout << "Or Press 'a' to Bank your score\n";
			}
		}

		// created if condition for banking the score
		if (_getch() == 'a')
		{

			cout << "Player " << (Player1Turn ? Player1Name : Player2Name) << " chooses to bank the score\n";      // printing 
			if (Player1Turn)
			{
				BankedScore1 += RoundScore1;
				cout << Player1Name <<" Banked Score : " << BankedScore1 << " and " << Player1Name << " Banked Score : " << BankedScore2 << "\n";
				InitialScore1 = 0;
			}
			else
			{
				BankedScore2 += RoundScore2;
				cout << Player1Name << " Banked Score : " << BankedScore1 << " and " << Player1Name << " Banked Score : " << BankedScore2 << "\n";
				InitialScore2 = 0;
			}

			if (BankedScore1 >= 50)
			{
				system("cls");
				"\n\n";
				cout << "*******************************************Congratulations! " << (Player1Turn ? Player1Name : Player2Name) << " Wins!*********************************************\n\n\n";
			}
			else if (BankedScore2 >= 50)
			{
				system("cls");
				"\n\n";
				cout << "*******************************************Congratulations! " << (Player1Turn ? Player1Name : Player2Name) << " Wins!***********************************************\n\n\n";
			}


			// Switch to the other player's turn (player 2)
			Player1Turn = !Player1Turn;                    // player1turn = false 

			// If the game-ending condition is met, loop will break
			if (BankedScore1 >= 50 || BankedScore2 >= 50)
			{
				break;
			}
		}

	} while (true);                                                                                        // Continue the game until a condition is met
}

// Function for player vs computer
void PVC()
{

	cout << "Rules: First to score 10 wins\n";
	cout << "Rules: Its on luck If you score exactly 10 your score resets\n";
	system("pause");
	system("cls");

	srand((unsigned)time(nullptr));                     // seed the random generator

	// creating loop for player and computer's turn
	do
	{
		if (Player1Turn)         // condition if its player's turn 
		{
			cout << "---------------------------------------------------*Player's Turn**---------------------------------------------------\n";
			cout << "Number of sides of dice you need: ";
			cin >> NumberofSides;
			cout << "Player's Round Score is " << RoundScore1 << "\n";
			cout << "Rolling...\n";

			RollADie = rand() % NumberofSides + 1;
			cout << "You rolled a " << RollADie << "\n";

			InitialScore1 += RollADie;                                                    // adding initial score to number on dice generated
			RoundScore1 = InitialScore1;
			cout << "Player's Score is \n" << RoundScore1 << "\n";                      // printing player's score is

			if (RoundScore1 == 10)
			{
				cout << "Your Score is equal to 10\n";
				RoundScore1 = 0;
				InitialScore1 = 0;
				cout << "Your round Score is " << RoundScore1 << "\n\n";
				cout << "Now it's the computer's turn\n";
				Player1Turn = false;
			}

		}
		else         // else its computer's turn
		{
			cout << "---------------------------------------------------*Computer's Turn*----------------------------------------------------\n";
			Computer();

			if (ComputerScore == 10)
			{
				cout << "Computer's Score is greater than 10\n";
				ComputerScore = 0;
				cout << "Computer's round Score is " << ComputerScore << "\n\n";
				cout << "Now it's your turn\n";
				Player1Turn = true;
			}
		}
		// Switch to the computer's turn 
		Player1Turn = !Player1Turn;         // player1turn = false


		if (RoundScore1 > 10)
		{
			system("cls");
			"\n\n";
			cout << "*****************************************************Player Wins!******************************************************\n\n\n";
		}
		else if (ComputerScore > 10)
		{
			system("cls");
			"\n\n";
			cout << "****************************************************Computer Wins!*****************************************************\n\n\n";
		}
	} while (RoundScore1 < 10 && ComputerScore < 10);     // loop condition :- until player or computer score more than 10 
}


void Menu()
{
	cout << "With whom you wanna play?\n";
	cout << "1) Player Vs Player\n";
	cout << "2) Player Vs Computer\n";

	cout << "\n";


	// using switch statement to choose from the given options
	switch (Choice = _getch())
	{
	case PVP_CHOICE:
	{
		system("cls");
		cout << "----------------------------------------------------*You choose PVP*----------------------------------------------------\n";
		GetPlayerNames();
		PVP();
		Player1Score = BankedScore1;
		Player2Score = BankedScore2;
		AddToLeaderboard(Player1Name, Player1Score);
		AddToLeaderboard(Player2Name, Player2Score);
		DisplayLeaderboard();
		break;

	}

	case PVC_CHOICE:
	{
		system("cls");
		cout << "---------------------------------------------*You choose Player Vs Computer*--------------------------------------------\n";
		PVC();                                                                                                                                   // calling player vs computer function
		break;
	}


	default:
		cout << "Choose Proper value 1, 2 or 4\n";
		break;
	}

}








// ******* Main Function *******
int main()
{
	// creating loop until player didn't choose any of the option to play
	do
	{
		

		Menu();

		if (Choice == PVP_CHOICE || Choice == PVC_CHOICE)
		{
			break;
		}


	} while (true);



	// creating do while loop until player wants to exit the Game
	do
	{
		cout << "Do you want to play again?\n";
		cout << "3) Yes\n";
		cout << "4) No\n";


		BankedScore1 = 0;
		BankedScore2 = 0;
		RoundScore1 = 0;
		RoundScore2 = 0;
		ComputerScore = 0;
		InitialScore1 = 0;

		// using switch statement to choose from the given options
		switch (Choice = _getch())
		{
		case CHOICE:
		{

			system("cls");
			cout << "Same Players are playing or you want to change Names?\n";
			cout << "1) Same Players\n";
			cout << "2) Want to change names\n";

			constexpr char CHOICE2 = '1';
			constexpr char CHOICE3 = '2';

			// nested switch case for getting new players name or same players are playing
			switch (Choice = _getch())
			{
			case CHOICE2:
			{
				break;
			}
			case CHOICE3:
			{
				GetPlayerNames();
				break;
			}
			}

			Menu();
			break;

		}

		case EXIT_CHOICE:
		{
			system("cls");
			cout << "Thank you!, Any time you can come back to play\n";
			break;
		}
		default:
			cout << "Choose Proper value 1 or 2\n";
			break;
		}
	} while (Choice != EXIT_CHOICE);   // loop condition if player choose case 3 to exit loop will break/end

	return 0;
}