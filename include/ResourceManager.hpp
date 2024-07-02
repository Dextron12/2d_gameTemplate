#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP


#include <string>
#include <map>
#include <Windows.h>
#include <filesystem>
#include <iostream>

#include "Window.hpp"

#include <SDL2\SDL.h>
#define STB_IMAGE_IMPLEMENTATION
#include <SDL2\SDL_image.h>


class Filesystem{
    private:
        std::basic_string<TCHAR> execPath;
        TCHAR filename[MAX_PATH + 1];

    public:
        std::string opPath;

        std::map<std::string, std::string> Paths;

        Filesystem();

        // joins a sub-path within the exec folder and binds it to pathID so it can be reffered to. 
        void join_to_path(std::string pathID, std::string filePath);

        std::string getPath(std::string filePath); // Searches for path within exec folder, if exists returns the path, if not returns nullptr


};

class Textures{
    private:
        SDL_Texture* m_loadTexture(Events* window, std::string path);

        std::map<std::string, SDL_Texture*> Textures;
    public:

        void loadTexture(Events* window, std::string textureID, std::string filePath);
        void renderTexture(Events* window, std::string textureID, SDL_Rect pos);
};

class Fonts {
    private:
        std::map<std::string, TTF_Font*> Fonts;

        TTF_Font* m_loadFont(std::string fontPath, int pxSize);

        SDL_Surface* texSurface;
        SDL_Texture* texTexture;

    public:
        ~Fonts();

        void loadFont(std::string fontID, std::string fontPath, int pxSize);
        void renderText(Events* window, std::string text, std::string fontID, SDL_Rect pos, SDL_Colour colour);

};

#endif