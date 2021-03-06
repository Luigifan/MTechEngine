#pragma once
#ifndef TESTSCREEN_H
#define TESTSCREEN_H
#include "Screen.h"
#include "Sprite.h"
#include "StandardColors.h"
extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include <SDL.h>

#define lua_open() luaL_newstate()

//int lbDrawText(lua_State *L);

class TestScreen : public Screen
{
    public:
        TestScreen(ContentManager *___cm);
        ~TestScreen();
        void draw(SpriteBatch *_sb);
        void update(SDL_Event const &_ih);
        void finalInitLua();
        void report_errors(lua_State *L, int status);
        void onLoopFunction();
        void onInputFunction(SDL_Keycode keycode);
        void onUpdateFunction();
        void onLoadFunction();
        bool doQuit;
    protected:
    private:
        SpriteBatch *_localSb;
        ContentManager *_cm;
        Sprite *testSprite;
        StandardColors clr;
        lua_State *L;
        int s;
};

#endif // TESTSCREEN_H
