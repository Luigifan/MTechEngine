#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "../SpriteBatch.h"
#include "InputHandler.h"

class Screen
{
    public:
        virtual void draw(SpriteBatch *_sb) = 0;
        virtual void update(InputHandler *_ih) = 0;
    protected:
    private:
        //NOTE: use std::vector for controls when you start to implement them
};

#endif // SCREEN_H