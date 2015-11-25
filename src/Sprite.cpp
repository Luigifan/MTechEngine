#include "Sprite.h"

Sprite::Sprite(SDL_Texture *tex)
{
    texture = tex;
    x = 0;
    y = 0;
}

Sprite::~Sprite()
{
    //dtor
}

void Sprite::draw(SpriteBatch *_sb)
{
    //if(!_sb->isDrawing())
    //    _sb->sbBegin();

    _sb->sbDrawTexture(texture, x, y);

    //if(_sb->isDrawing())
    //    _sb->sbEnd();
}

void Sprite::update(InputHandler *_ih)
{


    if(_ih->getEvent()->type == SDL_KEYDOWN)
    {
        switch(_ih->getEvent()->key.keysym.sym)
        {
            case SDLK_UP:
                y--;
                break;
            case SDLK_DOWN:
                y++;
                break;
            case SDLK_RIGHT:
                x++;
                break;
            case SDLK_LEFT:
                x--;
                break;
        }
    }
}