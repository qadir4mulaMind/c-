/*
 * Single Number Guessing Game
 *
 * This program implements a simple number guessing game using
 * three classes:
 *
 * 1. Guesser
 *    - Takes a number from the guesser.
 *
 * 2. Player
 *    - Takes a number from each of the three players.
 *
 * 3. Umpire
 *    - Collects the number guessed by the guesser.
 *    - Collects numbers guessed by all three players.
 *    - Compares the players' guesses with the guesser's number.
 *    - Determines which player(s) have won or whether all players lost.
 *
 * Game Flow:
 *
 * Guesser -> chooses a number
 *
 * Player 1 -> chooses a number
 * Player 2 -> chooses a number
 * Player 3 -> chooses a number
 *
 * Umpire -> compares all player guesses with guesser's number
 *
 * Example:
 *
 * Guesser -> 2
 * Player 1 -> 2
 * Player 2 -> 2
 * Player 3 -> 2
 *
 * Output:
 * All 3 have won the game.
 */


#include <iostream>
using namespace std;


/*
 * ---------------------------------------------------------
 *                      Guesser Class
 * ---------------------------------------------------------
 *
 * Responsibility:
 * Takes a number from the guesser and stores it.
 */
class Guesser {

  private:

    // Stores the number guessed by the guesser
    int guessedNumber;


  public:

    /*
     * takeGuesserInput()
     *
     * Takes input from the guesser and stores it
     * in guessedNumber.
     *
     * Returns:
     * The number guessed by the guesser.
     */
    int takeGuesserInput() {

      int x;

      cout << "Get the number for guesser: ";
      cin >> x;

      guessedNumber = x;

      return guessedNumber;
    }
};


/*
 * ---------------------------------------------------------
 *                      Player Class
 * ---------------------------------------------------------
 *
 * Responsibility:
 * Takes a number from a player and stores it.
 */
class Player {

  private:

    // Stores the number guessed by the player
    int playerNumber;


  public:

    /*
     * takePlayerNumber()
     *
     * Takes input from a player.
     *
     * Parameter:
     * pNum -> Represents the player number (1, 2 or 3)
     *
     * Returns:
     * The number guessed by the player.
     */
    int takePlayerNumber(int pNum) {

      int p;

      cout << "Give the number for the player "
           << pNum << " : ";

      cin >> p;

      playerNumber = p;

      return playerNumber;
    }
};


/*
 * ---------------------------------------------------------
 *                      Umpire Class
 * ---------------------------------------------------------
 *
 * Responsibility:
 *
 * 1. Get the number from the Guesser.
 * 2. Get numbers from all three Players.
 * 3. Compare players' numbers with the guesser's number.
 * 4. Print the result of the game.
 */
class Umpire {

  private:

    // Stores the number guessed by the guesser
    int g;

    // Stores the numbers guessed by the three players
    int p1Num, p2Num, p3Num;


  public:

    /*
     * getNumberFromGuesser()
     *
     * Creates a Guesser object and gets the number
     * guessed by the guesser.
     */
    void getNumberFromGuesser() {

      Guesser g1;

      g = g1.takeGuesserInput();

      cout << "Number guessed by the guesser "
           << g << endl;
    }


    /*
     * getNumberFromPlayers()
     *
     * Creates three Player objects.
     *
     * Each player provides a number, which is stored
     * separately in p1Num, p2Num and p3Num.
     */
    void getNumberFromPlayers() {

      Player p1, p2, p3;

      // Get number from Player 1
      p1Num = p1.takePlayerNumber(1);

      // Get number from Player 2
      p2Num = p2.takePlayerNumber(2);

      // Get number from Player 3
      p3Num = p3.takePlayerNumber(3);
    }


    /*
     * printResult()
     *
     * Compares the guesser's number with the numbers
     * guessed by all three players.
     *
     * Possible cases:
     *
     * 1. All three players match
     * 2. Player 1 and Player 2 match
     * 3. Player 1 and Player 3 match
     * 4. Player 1 alone matches
     * 5. Player 2 and Player 3 match
     * 6. Player 2 alone matches
     * 7. Player 3 alone matches
     * 8. No player matches
     */
    void printResult() {

      // Compare guesser's number with Player 1
      if (g == p1Num) {

        // Player 1 matched.
        // Now check whether Player 2 also matched.
        if (g == p2Num) {

          // Player 1 and Player 2 matched.
          // Now check whether Player 3 also matched.
          if (g == p3Num) {

            // All three players matched.
            cout << "All 3 have won the game." << endl;

          }
          else {

            // Only Player 1 and Player 2 matched.
            cout << "Player 1 and 2 have won the game." << endl;
          }
        }

        // Player 1 matched, Player 2 did not.
        // Check whether Player 3 matched.
        else if (g == p3Num) {

          // Player 1 and Player 3 matched.
          cout << "Player 1 and 3 have won the game." << endl;
        }

        else {

          // Only Player 1 matched.
          cout << "Player 1 has won the game." << endl;
        }
      }


      // Player 1 did not match.
      // Check Player 2.
      else if (g == p2Num) {

        // Player 2 matched.
        // Check whether Player 3 also matched.
        if (g == p3Num) {

          // Player 2 and Player 3 matched.
          cout << "Player 2 and 3 have won the game." << endl;
        }

        else {

          // Only Player 2 matched.
          cout << "Player 2 has won the game." << endl;
        }
      }


      // Player 1 and Player 2 did not match.
      // Check Player 3.
      else if (g == p3Num) {

        // Only Player 3 matched.
        cout << "Player 3 has won the game." << endl;
      }


      // None of the three players matched.
      else {

        cout << "All players have lost the game." << endl;
      }
    }
};


/*
 * ---------------------------------------------------------
 *                         main()
 * ---------------------------------------------------------
 *
 * Program execution starts from here.
 *
 * Steps:
 *
 * 1. Create an Umpire object.
 * 2. Get the number from the guesser.
 * 3. Get numbers from all three players.
 * 4. Print the result.
 * 5. End the game.
 */
int main() {

  cout << "----------------Let's start the game------------------------"
       << endl;


  // Step 1:
  // Create an object of the Umpire class.
  Umpire u;


  // Step 2:
  // Umpire gets the number from the guesser.
  u.getNumberFromGuesser();


  // Step 3:
  // Umpire gets numbers from all three players.
  u.getNumberFromPlayers();


  // Step 4:
  // Umpire compares the numbers and prints the result.
  u.printResult();


  // Step 5:
  // Game ends.
  cout << "----------------Game is Ended here--------------------------"
       << endl;


  return 0;
}
