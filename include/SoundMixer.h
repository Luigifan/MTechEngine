#pragma once
#ifndef SOUNDMIXER_H
#define SOUNDMIXER_H
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <map>

class SoundMixer
{
    public:
        SoundMixer(std::string resPath);
        virtual ~SoundMixer();
        void playSong();
        void playSoundEffect(int index);
        void loadMusic();
        void loadSound(std::string resPath);
    protected:
    private:
        bool init();
        bool loadFile();
        bool loadTestFile(std::string resPath);
        std::map<int, Mix_Music*> musicList;
        std::map<int, Mix_Chunk*> soundEffectsList;
};

#endif // SOUNDMIXER_H