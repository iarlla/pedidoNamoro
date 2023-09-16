//gcc -o namoro namoro.c -lSDL2

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 400;
const int BUTTON_WIDTH = 80;
const int BUTTON_HEIGHT = 40;

bool is_inside_button(int x, int y, int button_x, int button_y) {
    return (x >= button_x && x <= button_x + BUTTON_WIDTH) && (y >= button_y && y <= button_y + BUTTON_HEIGHT);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Pedido de Namoro", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    srand(time(NULL));

    int button_x = SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2;
    int button_y = SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2;

    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        int x, y;
        SDL_GetMouseState(&x, &y);

        if (is_inside_button(x, y, button_x, button_y)) {
            button_x = rand() % (SCREEN_WIDTH - BUTTON_WIDTH);
            button_y = rand() % (SCREEN_HEIGHT - BUTTON_HEIGHT);
        }

        SDL_SetRenderDrawColor(renderer, 255, 200, 221, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 179, 193, 255);
        SDL_Rect buttonRect = { button_x, button_y, BUTTON_WIDTH, BUTTON_HEIGHT };
        SDL_RenderFillRect(renderer, &buttonRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
