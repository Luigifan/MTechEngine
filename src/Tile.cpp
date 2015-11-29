#include "Tile.h"

Tile::Tile()
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}

/**
Getters
*/
int Tile::getWorldX()
{return worldX;}

int Tile::getWorldY()
{return worldY;}

int Tile::getWidth()
{return width;}

int Tile::getHeight()
{return height;}

std::string Tile::getSheetName()
{return sheetName;}

SDL_Rect Tile::getNonAnimatedArea()
{return area;}

bool Tile::getAnimated()
{return animated;}

int Tile::getFrameCount()
{return frameCount;}

int Tile::getFrameUpdateInterval()
{return frameUpdateInterval;}

int Tile::getCurrentFrame()
{return currentFrame;}

SDL_Rect **Tile::getAllFrames()
{return frames;}

std::string Tile::getBlockName()
{return blockName;}

/**
Setters
*/
void Tile::setWorldPosition(int x, int y)
{
    worldX = x;
    worldY = y;
}
void Tile::setBlockSize(int w, int h)
{
    width = w;
    height = h;
}
void Tile::setSheetName(std::string _sheetname)
{
    sheetName = _sheetname;
}
void Tile::setNonAnimatedArea(SDL_Rect _nanimarea)
{
    area = _nanimarea;
}
void Tile::setAnimated(bool __anim)
{
    animated = __anim;
}
void Tile::setFrameCount(int framec)
{
    frameCount = framec;
}
void Tile::setFrameUpdateInterval(int __interval)
{
    frameUpdateInterval = __interval;
}
void Tile::setCurrentFrame(int __curframe)
{
    currentFrame = __curframe;
}
void Tile::setAnimatedFrames(SDL_Rect** __frames)
{
    frames = __frames;
}
void Tile::setBlockName(std::string __bn)
{
    blockName = __bn;
}
