#pragma once
#ifndef TITLESCREEN_H
#define TITLESCREEN_H
#include "Screen.h"
#include "ContentManager.h"
#include "SpriteBatch.h"
#include "InputHandler.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "Menu.h"
#include <SDL.h>
struct MessageBox;
struct LevelObject;

class TitleScreen : public Screen
{
    public:
        TitleScreen();
        ~TitleScreen();
        void draw(SpriteBatch* _sb, ContentManager* cm);
        void update(SDL_Event const &_ih);
        void processInput(SDL_Event const &_ih);
    protected:
    private:
        void loadTitleLevel();
        bool titleLevelExists();
        void drawOldTitleScreen(SpriteBatch* _sb, ContentManager* cm);
        void drawTitleCopyrightEtc(SpriteBatch* _sb, ContentManager* cm);
        void drawOptions(SpriteBatch* _sb, ContentManager* cm);
        std::vector<Menu*> menuOptions;
        int totalOptions, currentSelection;
        bool upPressed, downPressed, showTestMessage, hasRead = false;
        MessageBox* testMessage = 0;
        LevelObject* levelObject = 0;
};

#endif // TITLESCREEN_H
