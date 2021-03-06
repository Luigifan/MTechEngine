#ifndef CAMERA2D_H
#define CAMERA2D_H

struct SDL_Rect;

class Camera2d
{
    public:
        Camera2d();
        Camera2d(float x, float y);
        ~Camera2d();
        float getCameraX();
        float getCameraY();
        void setCameraX(float __x);
        void setCameraY(float __y);
        void setCameraPosition(float __x, float __y);
        SDL_Rect RectangleFromCamera();
    protected:
    private:
        float CamX, CamY;
};

#endif // CAMERA2D_H
