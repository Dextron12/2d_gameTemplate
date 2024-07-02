
#include "ResourceManager.hpp"

Filesystem::Filesystem(){
    if (GetModuleFileName(NULL, filename, MAX_PATH) != 0){
        execPath = filename;
    } else {
        std::cout << "failed to read executable path" << std::endl;
    }
    opPath = std::filesystem::path(execPath).string();

    opPath.erase(opPath.end()-8, opPath.end()); //removes the exec file from path

    Paths.insert_or_assign("Default", opPath);
}

void Filesystem::join_to_path(std::string pathID, std::string path){
    std::string nPath = Paths["Default"] + path;
    if (std::filesystem::exists(nPath) == true){
        //File exists, bind to Paths
        Paths.insert_or_assign(pathID, nPath);
    }
}

std::string Filesystem::getPath(std::string filePath){
    std::string nPath = Paths["Default"] + filePath;
    if (std::filesystem::exists(nPath) == true){
        return nPath;
    } else {
        return nullptr;
    }

}


SDL_Texture* Textures::m_loadTexture(Events* window, std::string path){
    SDL_Texture* nTexture;

    //Load image
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL){
        std::cout << "Failed to load texture: " << path << "\n" << SDL_GetError() << std::endl;
    } else {
        //Create texture from surface
        nTexture = SDL_CreateTextureFromSurface(window->renderer, loadedSurface);
    }
    SDL_FreeSurface(loadedSurface);
    return nTexture;
}


void Textures::loadTexture(Events* window, std::string textureID, std::string filePath){
    //Load Texture
    SDL_Texture* nTexture = m_loadTexture(window, filePath);
    if (nTexture == NULL){
        std::cout << "Failed to load texture" << std::endl;
    } else {
        //Push texture to stack
        Textures.insert_or_assign(textureID, nTexture);
    }
}

void Textures::renderTexture(Events* window, std::string textureID, SDL_Rect pos){
    if (Textures[textureID] == NULL){
        std::cout << "No texture stored under the ID of: " << textureID << std::endl;
    }
    SDL_RenderCopy(window->renderer, Textures[textureID], NULL, &pos);
}

Fonts::~Fonts(){
    for (auto i = Fonts.begin(); i != Fonts.end(); i++){
        TTF_CloseFont(i->second);
    }
}

TTF_Font* Fonts::m_loadFont(std::string fontPath, int pxSize){
    TTF_Font* nFont;
    nFont = TTF_OpenFont(fontPath.c_str(), pxSize);
    if (!nFont) {
        std::cout << "Failed to load font: " << fontPath << "\n" << SDL_GetError() << std::endl;
    }
    return nFont;
}

void Fonts::loadFont(std::string fontID, std::string fontPath, int pixelSize){
    TTF_Font* nFont = m_loadFont(fontPath, pixelSize);
    if (nFont){
        //Append to Fonts
        Fonts.insert_or_assign(fontID, nFont);
    }
}

void Fonts::renderText(Events* window, std::string text, std::string fontID, SDL_Rect pos, SDL_Colour colour){
    texSurface = TTF_RenderText_Solid(Fonts[fontID], text.c_str(), colour);
    if (!texSurface){
        std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
    }
    //Convert surface to texture
    texTexture = SDL_CreateTextureFromSurface(window->renderer, texSurface);
    //Assign new text width and height;
    pos.w = texSurface->w; pos.h = texSurface->h;
    //Render Texture
    SDL_RenderCopy(window->renderer, texTexture, NULL, &pos);
    //Destroy components
    SDL_FreeSurface(texSurface);
    SDL_DestroyTexture(texTexture);

}

