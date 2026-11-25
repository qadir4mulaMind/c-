#include<iostream>

struct GameState{
   bool checkpoint;
   float score;
   short numberOfPlayers;
};

int main(){
  /*for(int i = 0; i < 100; i++){
    GameState* gs = new GameState;
  }*/

  GameState gs;
  std::cout << alignof(gs) << std::endl;

  //std::cout << sizeof(gs.checkpoint) << std::endl;
  //std::cout << sizeof(gs.score) << std::endl;
  //std::cout << sizeof(gs.numberOfPlayers) << std::endl;
  //std::cout << sizeof(gs) << std::endl;
  return 0;
}
