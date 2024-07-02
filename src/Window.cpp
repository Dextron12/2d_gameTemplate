
#include "Window.hpp"


Window::Window(const char* windowTitle, int windowWidth, int windowHeight) : windowTitle(windowTitle), windowWidth(windowWidth), windowHeight(windowHeight){
    //1. Initialize SDL2
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Couldn't Initialize SDL2. Aborting...\n" << SDL_GetError() << std::endl;
        windowState = false;
    }

    //2. Create Window
    window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE);
    if (window == NULL){
        std::cout << "failed to create window: " << SDL_GetError() << std::endl;
        windowState = false;
    }
    //3. Create Renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL){
        std::cout << "failed to create a renderer: " << SDL_GetError() << std::endl;
        windowState = false;
    }
    //4. Initalise SDL_Image
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) <= 0){
        std::cout << "Failed to load Image Library: " << SDL_GetError() << std::endl;
        windowState = false;
    }
    //5. Initialise SDL_ttf
    if (TTF_Init() < 0){
        std::cout << "Failed to load TTF Library: " << SDL_GetError() << std::endl;
        windowState = false;
    }
}

Window::~Window(){
    //call destructor functions for SDL_Image & TTF_Image
    IMG_Quit();
    TTF_Quit();
}

Events::Events(const char* wTitle, int wWidth, int wHeight) : Window(wTitle, wWidth, wHeight){
    // Intialize deltaTime
    NOW = SDL_GetPerformanceCounter();
    LAST = 0;
}

void Events::updateEvents(){
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            windowState = false;
        }

        if (event.key.keysym.sym == SDLK_ESCAPE){
            m_keyEsc = true;
        }

        
        switch (event.key.keysym.sym) {
            
        case SDLK_ESCAPE:
            m_keyEsc = true;
            break;

        case SDLK_w:
            m_keyW = true;
            break;
        case SDLK_a:
            m_keyA = true;
            break;
        case SDLK_s:
            m_keyS = true;
            break;
        case SDLK_d:
            m_keyD = true;
            break;
        
        case SDLK_UP:
            m_keyUp = true;
            break;
        case SDLK_DOWN:
            m_keyDown = true;
            break;
        case SDLK_RIGHT:
            m_keyRight = true;
            break;
        case SDLK_LEFT:
            m_keyLeft = true;
            break;
        
        default:
            break;
        }
    }

    //Update deltaTime
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();
    deltaTime = ((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency());
    
}

void Events::flushEvents(){
    
    //key events;
    m_keyEsc = false;

    //WASD Keys
    m_keyW = false;
    m_keyA = false;
    m_keyS = false;
    m_keyD = false;

    //Arrow keys
    m_keyUp = false;
    m_keyDown = false;
    m_keyRight = false;
    m_keyLeft = false;
}
