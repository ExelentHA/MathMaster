#pragma once

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <array>
#include <time.h>

#include "Window.hpp"
#include "Mouse.hpp"
#include "TextBox.hpp"
#include "Clock.hpp"

class Game
{
private:
  WindowRenderer *Window;
  const int WIDTH = 1280; // screen size
  const int HEIGHT = 720;

  TextBox btn_question1;
  TextBox btn_question2;
  TextBox btn_question3;
  TextBox btn_question4;

  TextBox question;
  
  TextBox tb_menu1;
  TextBox tb_menu2;

  Clock clock;
  Timer gtime;

  bool isAlreadyMenu = false; // flags to prevent one-time-call-functions from executing morethan once
  bool isAlreadyGame = false;
  
  SDL_Event event;

  enum state
  {
    menu = 0, game, gameover // change game state names
  };

  enum questionSet
  {
    add = 0, sub, mul, dvd
  };

  state gameState; // init inside the Init() function
  questionSet choosenSet; // set inside the LogicMenu()

  int level, score, streak, mistakes, corrects, noQuest, corrAnsBtn; // ingame point tracker
  bool gameOver;
  bool isGameQuestionStillUp = false; // this will tell if the current question is not yet solved

  // ingame variables
  int lval, rval, result;
  int min, max, tmp;
  std::string op;
  std::array<int, 4> ans = {0, 0, 0, 0};

public:
  Game();
  ~Game();

  void Init();

  // menu state
  void InitMenu(); // Set the Text to Menu Text
  void LogicMenu();

  // Events
  void Event();
  
  //in game state
  void InitInGame();

  void GenQuestion();
  void GenQAdd();
  void GenQSub();
  void GenQMul();
  void GenQDiv();

  // init question
  void InitQuestion();
  void Correct();
  void Mistake();
  void CheckButton();

  void GameOver();

  void Main();
};
