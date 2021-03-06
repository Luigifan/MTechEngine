TEMPLATE = app
CONFIG += c++11 static
#shared
CONFIG -= app_bundle
CONFIG -= qt


#
QMAKE_TARGET_COMPANY = "Mike Santiago Ltd"
QMAKE_TARGET_DESCRIPTION = "MTechEngine: A 2D Game Engine with Lua Scripting"
QMAKE_TARGET_COPYRIGHT = "2016 (c)"
QMAKE_TARGET_PRODUCT = "MTechEngine"
VERSION=0.0.5.1
#

INCLUDEPATH += $$PWD/include

win32:RC_FILE += application.rc

win32: {
QMAKE_CXXFLAGS -= -Wno-narrowing -Wno-return-local-addr

LIBS += -L$$PWD/.Libraries/Win32/Stripped/lib -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -llua5.1
INCLUDEPATH += $$PWD/.Libraries/Win32/Stripped/include/SDL2
INCLUDEPATH += $$PWD/.Libraries/Win32/Stripped/include/lua
}


linux-g++: {
# NOTE: this configuration is based off my Debian system and you may have to change it for your platform!
# Please use SDL2 and Lua 5.1
QMAKE_CXXFLAGS += -std=c++11 -g -fexceptions -Wno-narrowing -Wno-return-local-addr

LIBS += -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -llua5.1
INCLUDEPATH += /usr/include/SDL2/
INCLUDEPATH += /usr/include/lua5.1/
}


macx: {
#becuase you're probably using clang or llvm and this is probably really annoying
QMAKE_CXXFLAGS += -std=c++11 -g -fexceptions -Wno-narrowing -Wno-return-local-addr -Wno-error=mismatched-tags
#nothing for now
LIBS += -L/usr/local/lib

LIBS += -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -llua

INCLUDEPATH += /usr/local/Cellar/sdl2/2.0.4/include/SDL2
INCLUDEPATH += /usr/local/Cellar/sdl2_image/2.0.1/include/SDL2
INCLUDEPATH += /usr/local/Cellar/sdl2_ttf/2.0.13/include/SDL2
INCLUDEPATH += /usr/local/Cellar/sdl2_mixer/2.0.1/include/SDL2
INCLUDEPATH += /usr/local/include
}

SOURCES += main.cpp \
    src/_color.cpp \
    src/_vector2i.cpp \
    src/Camera2d.cpp \
    src/ContentManager.cpp \
    src/GameWindow.cpp \
    src/global_vars.cpp \
    src/InputHandler.cpp \
    src/LevelBackground.cpp \
    src/LevelObject.cpp \
    src/LuaBlockConfigLoader.cpp \
    src/LuaBlockWrapper.cpp \
    src/LuaCameraWrapper.cpp \
    src/LuaContentManager.cpp \
    src/LuaEventHandlerWrapper.cpp \
    src/LuaSDL_Texture.cpp \
    src/LuaSpriteBatch.cpp \
    src/Menu.cpp \
    src/MessageBox.cpp \
    src/ScreenManager.cpp \
    src/SoundMixer.cpp \
    src/Sprite.cpp \
    src/SpriteBatch.cpp \
    src/Tile.cpp \
    src/Screens/SplashScreen.cpp \
    src/Screens/TestLevelScreen.cpp \
    src/Screens/TestScreen.cpp \
    src/Screens/TitleScreen.cpp \
    src/configfile.cpp \
    src/IO/serializationwriter.cpp \
    src/IO/serializationreader.cpp \
    src/IO/serializationconstants.cpp \
    baseengine.cpp \
    enginestaticvariables.cpp \
    include/standardcolors.cpp \
    src/keyboardmonitor.cpp

HEADERS += \
    include/_color.h \
    include/_vector2i.h \
    include/array.h \
    include/Camera2d.h \
    include/ContentManager.h \
    include/GameWindow.h \
    include/global_vars.h \
    include/InputHandler.h \
    include/LevelBackground.h \
    include/LevelObject.h \
    include/LuaBlockConfigLoader.h \
    include/LuaBlockWrapper.h \
    include/LuaCameraWrapper.h \
    include/LuaContentManager.h \
    include/LuaEventHandlerWrapper.h \
    include/LuaSDL_Texture.h \
    include/LuaSpriteBatch.h \
    include/luna.h \
    include/MathsStuff.h \
    include/Menu.h \
    include/MessageBox.h \
    include/Res.h \
    include/Screen.h \
    include/ScreenManager.h \
    include/SoundMixer.h \
    include/SplashScreen.h \
    include/Sprite.h \
    include/SpriteBatch.h \
    include/StandardColors.h \
    include/TestLevelScreen.h \
    include/TestScreen.h \
    include/Tile.h \
    include/TitleScreen.h \
    src/configfile.h \
    src/customalgorithms.h \
    src/IO/serializationwriter.h \
    src/IO/serializationreader.h \
    src/IO/serializationconstants.h \
    mtechapplication.h \
    baseengine.h \
    src/luaobjectbindingbase.h \
    enginestaticvariables.h \
    src/Screens/keyboardmonitor.h \
    src/keyboardmonitor.h

install_it.path = $$DESTDIR/res
install_it.files = $$PWD/res/*
mkdir.path = $$OUT_PWD/res
INSTALLS += \
    mkdir
    install_it

DISTFILES += \
    icon.ico \
    application.rc
