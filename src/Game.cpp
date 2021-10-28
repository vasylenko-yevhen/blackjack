#include <iostream>
#include "config.h"
#include "utils.h"
#include "Game.h"
#include "Dealer.h"
#include "Player.h"


Game::Game() {
    dealer = new Dealer();
    player = new Player();
    casino = new Player();
}


void Game::dealPlayerCards() {
    bool more = true;
    while(more) {
        std::cout << "Your cards are: ";
        player->printCards(true);
        std::cout << ". Score is " << player->getActualScore(player->getMaxScore()) << ". Take more? (y/n) ";
        std::string input;
        std::cin >> input;
        toLower(input);
        if(input == "y" || input == "yes") {
            more = dealer->dealCard(player, false);
        } else {
            more = false;
        }
    }
    std::cout << "Your final cards are: ";
    player->printCards(true);
    std::cout << std::endl;
}


void Game::singleGame() {
    unsigned short initialCards = 2;
    for (unsigned short i = 0; i < initialCards; i++) {
        dealer->dealCard(player, false);
        dealer->dealCard(casino, false);
    }
    std::cout << "Computer's first card is ";
    casino->printCards(false);
    std::cout << std::endl;
    dealPlayerCards();
    dealer->dealCardsToCasino(casino);
    unsigned short playerTotalScore = player->getActualScore(player->getMaxScore());
    if (playerTotalScore > BLACKJACK_SCORE) {
        std::cout << "Your total score is " << playerTotalScore << ", you lose.\n";
        return;
    }
    std::cout << "Computer cards are: ";
    casino->printCards(true);
    std::cout << std::endl;

    unsigned short casinoTotalScore = casino->getActualScore(casino->getMaxScore());
    std::cout << "Your total score: " << playerTotalScore << ", casino: " << casinoTotalScore << ".\n";
    if (casinoTotalScore > BLACKJACK_SCORE || playerTotalScore > casinoTotalScore) {
        std::cout << "You win!\n";
        return;
    } else if (playerTotalScore == casinoTotalScore) {
        std::cout << "Draw.\n";
    } else {
        std::cout << "You lose.\n";
    }
}


void Game::playLoop() {
    std::cout << "Welcome to Poker Game.\n\n";
    std::string userInput;
    while(true) {
        singleGame();
        reset();
        std::cout << "Another game? ";
        std::cin >> userInput;
        std::cout << std::endl;
        toLower(userInput);
        if(userInput != "y" && userInput != "yes") {
            break;
        }
    }
}


void Game::reset() {
    dealer->reset();
    player->reset();
    casino->reset();
}


int main (){
    auto game = new Game();
    game->playLoop();
}
