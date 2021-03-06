#pragma once
#ifndef LEVELBACKGROUND_H
#define LEVELBACKGROUND_H

#include <SDL.h>
#include <string>
#include "_vector2i.h"

struct SpriteBatch;
struct _color;
struct ContentManager;

class LevelBackground
{
    public:
        LevelBackground();
        LevelBackground(int l_width, int l_height);
        ~LevelBackground();
        void draw(SpriteBatch* _sb, ContentManager* cm);
        void draw(SpriteBatch *_sb, ContentManager *cm, SDL_Rect* area);

        //there comes a certain part in your life where you say fuck it
        //and you make all your properties public
        int width, height; //the w/h of the original background area
        int lwidth, lheight; //the w/h of the level and which the background will be tiled to contain.
        int id, framecount, frameupdate; //int id, amount of frames, the frame update interval
        bool topBottom; //if it's a top/bottom background
        bool animated; //if it's animated
        //SDL_Texture *topArea; //eh
        //SDL_Texture *bottomArea; //eh
        std::string sheetname, bgname; //the name of the sheet it comes from and the friendly name of the background
        _vector2i *singleFrame; //one single lonely frame

        //other crap
        int xoffset, yoffset;
        _color *backgroundColor;
    protected:
    private:
        SDL_Texture* localTexture;
        SDL_Texture* generateTextureFromWidthAndHeight(SpriteBatch *_sb, ContentManager* cm); //objective c style function names are great
        void backgroundTile(SpriteBatch* sb, ContentManager* cm, SDL_Rect* area); //This is used for tiling a square background for example
        void backgroundTileX(SpriteBatch* sb, ContentManager* cm, SDL_Rect* area);
};

#endif // LEVELBACKGROUND_H
