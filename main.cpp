#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int GRID_SIZE = 8;
const int TILE_SIZE = SCREEN_WIDTH / GRID_SIZE;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

int size_of_grid, cnt = 0;
int arr[128][128];

void place(int x1, int y1, int x2, int y2, int x3, int y3) {
    cnt++;
    arr[x1][y1] = cnt;
    arr[x2][y2] = cnt;
    arr[x3][y3] = cnt;
    SDL_RenderPresent(gRenderer); // Refresh the screen
    SDL_Delay(100); // Delay for visualization
}

int tile(int n, int x, int y) {
    int r, c;
    if (n == 2) {
        cnt++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[x + i][y + j] == 0) {
                    arr[x + i][y + j] = cnt;
                    SDL_RenderPresent(gRenderer); // Refresh the screen
                    SDL_Delay(100); // Delay for visualization
                }
            }
        }
        return 0;
    }

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[i][j] != 0)
                r = i, c = j;
        }
    }

    if (r < x + n / 2 && c < y + n / 2)
        place(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2);

    else if (r >= x + n / 2 && c < y + n / 2)
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);

    else if (r < x + n / 2 && c >= y + n / 2)
        place(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2 - 1);

    else if (r >= x + n / 2 && c >= y + n / 2)
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1);

    tile(n / 2, x, y + n / 2);
    tile(n / 2, x, y);
    tile(n / 2, x + n / 2, y);
    tile(n / 2, x + n / 2, y + n / 2);

    return 0;
}

bool initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gWindow = SDL_CreateWindow("Tiling Problem Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    return true;
}

void closeSDL() {
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    IMG_Quit();
    SDL_Quit();
}

void drawTile(int x, int y, int color, int shade) {
    SDL_Rect rect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
    SDL_Color tileColor = {static_cast<Uint8>(color), static_cast<Uint8>(color), static_cast<Uint8>(color), 255};
    SDL_SetRenderDrawColor(gRenderer, tileColor.r - shade, tileColor.g - shade, tileColor.b - shade, 255);
    SDL_RenderFillRect(gRenderer, &rect);
}

void handleMouseClick(int x, int y) {
    int gridX = x / TILE_SIZE;
    int gridY = y / TILE_SIZE;

    if (arr[gridX][gridY] == 0) {
        arr[gridX][gridY] = -1; // Set the clicked cell to black (empty tile)
        cnt = 0;
        tile(size_of_grid, 0, 0); // Recalculate tiling
    }
}

int main() {
    if (!initSDL()) {
        std::cerr << "SDL initialization failed." << std::endl;
        return 1;
    }

    size_of_grid = 8;
    memset(arr, 0, sizeof(arr));

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    handleMouseClick(mouseX, mouseY);
                }
            }
        }

        SDL_RenderClear(gRenderer);

        for (int i = 0; i < size_of_grid; i++) {
            for (int j = 0; j < size_of_grid; j++) {
                if (arr[i][j] == -1) {
                    drawTile(i, j, 0, 0); // Black for the blank tile
                } else {
                    int shade = arr[i][j] * 10; // Shade based on tile value
                    drawTile(i, j, 255, shade); // White color with shading
                }
            }
        }

        SDL_RenderPresent(gRenderer);
    }

    closeSDL();
    return 0;
}
