// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
// your includes here
#include "Board.hh"
#include "Player.hh"
#include "Box.hh"
#include "Box.cc"
#include "Board.cc"


TEST_CASE("1: Box")
{
  Box box1("box");
  box1.setPrice(10);
  CHECK(box1.getPrice() == 10);
  box1.setBoxNumber(1);
  CHECK(box1.getBoxNumber() == 1);
  box1.setOwner("player");
  CHECK(box1.getOwner() == "player");
  box1.setIsBought(true);
  CHECK(box1.getIsBought() == true);
  box1.setNbUpgrades(1);
  CHECK(box1.getNbUpgrades() == 1);
  box1.setRent(1);
  CHECK(box1.getRent() == 1);
}

TEST_CASE("2: Board")
{
  Board *board = new Board();
  board->nbPlayers = 2;
  CHECK(board->getNbPlayers() == 2);
  board->setMessage("message");
  CHECK(board->getMessage() == "message");
  board->setWhosPlaying(1);
  CHECK(board->getWhosPlaying() == 1);
  Player *player = new Player("Player");
  board->addPlayer(*player);
  CHECK(board->getPlayers().size() == 1);
}

TEST_CASE("3: Player")
{
  Player *player = new Player("player");
  player->setMoney(1000);
  CHECK(player->getMoney() == 1000);
  player->setActualPosition(1);
  CHECK(player->getActualPosition() == 1);
  player->setIsJailed(false);
  CHECK_FALSE(player->getIsJailed());
  player->setBankrupt(false);
  CHECK_FALSE(player->getIsBankrupt());
}
