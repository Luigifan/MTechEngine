#include "global_vars.h"
#include "SoundMixer.h"
#include "MessageBox.h"
#include "SpriteBatch.h"
#include "MathsStuff.h"

MessageBox::MessageBox(std::string msg)
{
    message = msg;
    soundPlayed = false;
    showMessage = false;
    messageSplitToVector = vectorFromMessage(msg);
}

MessageBox::~MessageBox()
{
    //dtor
}

void MessageBox::setVisible(bool vis)
{
    showMessage = vis;
    if(!vis)
    {
        soundPlayed = false;
        frameCount = 0;
    }
}

void MessageBox::draw(SpriteBatch *_sb)
{
    if(showMessage)
    {
    frameCount += 7;
    if(!soundPlayed)
    {
        mainSoundMixer->playSoundEffect(3);
        soundPlayed = true;
    }

    SDL_Color white {255,255,255,255};
    SDL_Color black {0,0,0,255};

    int __max_height = (messageSplitToVector.size() * 20) < MAX_HEIGHT ? (messageSplitToVector.size() * 20) + 16 : MAX_HEIGHT + 16;
    int true_x = (__internal_width / 2) - ((MAX_WIDTH + 16) / 2);

    SDL_Rect msgBoxArea;
    msgBoxArea.w = MathsStuff::math_clamp((this->frameCount + 150), 0, MAX_WIDTH + 16);
    msgBoxArea.h = MathsStuff::math_clamp(this->frameCount, 0, __max_height);
    msgBoxArea.x = true_x;
    msgBoxArea.y = (__internal_height / 2) - (msgBoxArea.h / 2);

    SDL_Rect outlineArea;
    outlineArea.w = MAX_WIDTH;
    outlineArea.h = msgBoxArea.h;
    outlineArea.x = msgBoxArea.x + 4;
    outlineArea.y = msgBoxArea.y + 4;

    _sb->sbFillRect(&white,  &outlineArea);
    _sb->sbFillRect(&black, &msgBoxArea);

    if(frameCount > __max_height && frameCount+150 > MAX_WIDTH + 16)
    {
        int yMod = 10;
        for(std::string part : messageSplitToVector)
        {
            _sb->sbDrawFont(part, msgBoxArea.x + 4, msgBoxArea.y + (1 * yMod), white, 2.0f, false);
            yMod += 15;
        }
    }


    }
}

std::vector<std::string> MessageBox::vectorFromMessage(std::string msg)
{
    std::vector<std::string> messageVector;
    std::string tempMessage;
    int internalCharCounter = 0;

    for(unsigned int i = 0; i < message.length(); i++)
    {
        if(i == message.length() - 1)
        {
            tempMessage += message[i];
            messageVector.push_back(tempMessage);
            internalCharCounter = 0;
            tempMessage = "";
        }
        internalCharCounter++;
        char toAppend = message[i];
        tempMessage += toAppend;
        if(internalCharCounter > MAX_CHAR_PER_LINE)
        {
            messageVector.push_back(tempMessage);
            tempMessage = "";
            internalCharCounter = 0;
        }
    }

    return messageVector;
}