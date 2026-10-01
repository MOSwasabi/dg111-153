/*******************************************************************************************
 *
 *   raylib - classic game: space invaders
 *
 *   Sample game developed by Ian Eito, Albert Martos and Ramon Santamaria
 *
 *   This game has been created using raylib v1.3 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
 *
 *   Copyright (c) 2015 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h"
#include <time.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Some Defines
//----------------------------------------------------------------------------------
#define NUM_SHOOTS 60
#define NUM_MAX_ENEMIES 50
#define FIRST_WAVE 10
#define SECOND_WAVE 20
#define THIRD_WAVE 30

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum
{
    FIRST = 0,
    SECOND,
    THIRD
} EnemyWave;

typedef struct Player
{
    Rectangle rec;
    Vector2 speed;
    Color color;
} Player;

typedef struct Enemy
{
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Enemy;

typedef struct Shoot
{
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Shoot;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screenWidth = 450;
static const int screenHeight = 800;

static bool gameOver = false;
static bool pause = false;
static int score = 0;
static bool victory = false;

static Player player = {0};
static Enemy enemy[NUM_MAX_ENEMIES] = {0};
static Shoot shoot[NUM_SHOOTS] = {0};
static EnemyWave wave = {0};

static int shootRate = 0;
static float alpha = 0.0f;

static int activeEnemies = 0;
static int enemiesKill = 0;
static bool smooth = false;

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
static void InitGame(void);        // Initialize game
static void UpdateGame(void);      // Update game (one frame)
static void DrawGame(void);        // Draw game (one frame)
static void UnloadGame(void);      // Unload game
static void UpdateDrawFrame(void); // Update and Draw (one frame)

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "classic game: space invaders");

    InitGame();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update and Draw
        //----------------------------------------------------------------------------------
        UpdateDrawFrame();
        //----------------------------------------------------------------------------------
    }
#endif
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame(); // Unload loaded data (textures, sounds, models...)

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Module Functions Definitions (local)
//------------------------------------------------------------------------------------

// Initialize game variables
void InitGame(void)
{
    // Initialize game variables
    shootRate = 0;
    pause = false;
    gameOver = false;
    victory = false;
    smooth = false;
    wave = FIRST;
    activeEnemies = FIRST_WAVE;
    enemiesKill = 0;
    score = 0;
    alpha = 0;

    // Initialize player
    player.rec.x = 225;
    player.rec.y = 700;
    player.rec.width = 20;
    player.rec.height = 20;
    player.speed.x = 5;
    player.speed.y = 5;
    player.color = BLACK;

    // Initialize enemies
    for (int i = 0; i < NUM_MAX_ENEMIES; i++)
    {
        enemy[i].rec.width = 25;
        enemy[i].rec.height = 25;
        enemy[i].rec.x = GetRandomValue(screenWidth, screenWidth + 1000);
        enemy[i].rec.y = GetRandomValue(0, screenHeight - 500 - enemy[i].rec.height);
        enemy[i].speed.x = 5;
        enemy[i].speed.y = 5;
        enemy[i].active = true;
        enemy[i].color = DARKGREEN;
    }

    // Initialize shoots
    for (int i = 0; i < NUM_SHOOTS; i++)
    {
        shoot[i].rec.x = player.rec.x + player.rec.width / 4;
        shoot[i].rec.y = player.rec.y;
        shoot[i].rec.width = 8;
        shoot[i].rec.height = 10;
        shoot[i].speed.x = 2;
        shoot[i].speed.y = 7;
        shoot[i].active = false;
        shoot[i].color = MAROON;
    }
}

// Update game (one frame)
void UpdateGame(void)
{
    if (!gameOver)
    {
        if (IsKeyPressed('P'))
            pause = !pause;

        if (!pause)
        {
            switch (wave)
            {
            case FIRST:
            {
                if (!smooth)
                {
                    alpha += 0.02f;

                    if (alpha >= 1.0f)
                        smooth = true;
                }

                if (smooth)
                    alpha -= 0.02f;

                if (enemiesKill == activeEnemies)
                {
                    enemiesKill = 0;

                    for (int i = 0; i < activeEnemies; i++)
                    {
                        if (!enemy[i].active)
                            enemy[i].active = true;
                    }

                    activeEnemies = SECOND_WAVE;
                    wave = SECOND;
                    smooth = false;
                    alpha = 0.0f;
                }
            }
            break;
            case SECOND:
            {
                if (!smooth)
                {
                    alpha += 0.02f;

                    if (alpha >= 1.0f)
                        smooth = true;
                }

                if (smooth)
                    alpha -= 0.02f;

                if (enemiesKill == activeEnemies)
                {
                    enemiesKill = 0;

                    for (int i = 0; i < activeEnemies; i++)
                    {
                        if (!enemy[i].active)
                            enemy[i].active = true;
                    }

                    activeEnemies = THIRD_WAVE;
                    wave = THIRD;
                    smooth = false;
                    alpha = 0.0f;
                }
            }
            break;
            case THIRD:
            {
                if (!smooth)
                {
                    alpha += 0.02f;

                    if (alpha >= 1.0f)
                        smooth = true;
                }

                if (smooth)
                    alpha -= 0.02f;

                if (enemiesKill == activeEnemies)
                    victory = true;
            }
            break;
            default:
                break;
            }

            // Player movement
            if (IsKeyDown(KEY_RIGHT))
                player.rec.x += player.speed.x;
            if (IsKeyDown(KEY_LEFT))
                player.rec.x -= player.speed.x;

            // Player collision with enemy
            for (int i = 0; i < activeEnemies; i++)
            {
                if (CheckCollisionRecs(player.rec, enemy[i].rec))
                    gameOver = true;
            }

            // Enemy behaviour

            for (int i = 0; i < activeEnemies; i++)
            {
                if (enemy[i].active)
                {
                    enemy[i].rec.y += enemy[i].speed.y;

                    if (enemy[i].rec.y > screenHeight)
                    {
                        enemy[i].rec.y = GetRandomValue(0, -1000 - enemy[i].rec.height);
                        enemy[i].rec.x = GetRandomValue(0, screenWidth - enemy[i].rec.width);
                    }
                }
            }

            // Wall behaviour
            if (player.rec.x <= 0)
                player.rec.x = 0;
            if (player.rec.x + player.rec.width >= screenWidth)
                player.rec.x = screenWidth - player.rec.width;
            if (player.rec.y <= 0)
                player.rec.y = 0;
            if (player.rec.y + player.rec.height >= screenHeight)
                player.rec.y = screenHeight - player.rec.height;

            // Shoot initialization
            if (IsKeyDown(KEY_SPACE))
            {
                shootRate += 1;

                for (int i = 0; i < NUM_SHOOTS; i++)
                {
                    if (!shoot[i].active && shootRate % 5 == 0)
                    {
                        shoot[i].rec.x = player.rec.x + player.rec.width / 4;
                        shoot[i].rec.y = player.rec.y + player.rec.height;
                        shoot[i].active = true;
                        break;
                    }
                }
            }

            // Shoot logic
            for (int i = 0; i < NUM_SHOOTS; i++)
            {
                if (shoot[i].active)
                {

                    // Movement
                    shoot[i].rec.y -= shoot[i].speed.y;

                    // Collision with enemy
                    for (int j = 0; j < activeEnemies; j++)
                    {
                        if (enemy[j].active)
                        {
                            if (CheckCollisionRecs(shoot[i].rec, enemy[j].rec))
                            {
                                shoot[i].active = false;
                                enemy[j].rec.x = GetRandomValue(screenWidth, screenWidth + 1000);
                                enemy[j].rec.y = GetRandomValue(0, screenHeight - enemy[j].rec.height);
                                shootRate = 0;
                                enemiesKill++;
                                score += 100;
                            }

                            if (shoot[i].rec.x + shoot[i].rec.width >= screenWidth)
                            {
                                shoot[i].active = false;
                                shootRate = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            gameOver = false;
        }
    }
}

// Draw game (one frame)
void DrawGame(void)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    if (!gameOver)
    {
        DrawRectangleRec(player.rec, player.color);

        if (wave == FIRST)
            DrawText("FIRST WAVE", screenWidth / 2 - MeasureText("FIRST WAVE", 40) / 2, screenHeight / 2 - 40, 40, Fade(BLACK, alpha));
        else if (wave == SECOND)
            DrawText("SECOND WAVE", screenWidth / 2 - MeasureText("SECOND WAVE", 40) / 2, screenHeight / 2 - 40, 40, Fade(BLACK, alpha));
        else if (wave == THIRD)
            DrawText("THIRD WAVE", screenWidth / 2 - MeasureText("THIRD WAVE", 40) / 2, screenHeight / 2 - 40, 40, Fade(BLACK, alpha));

        for (int i = 0; i < activeEnemies; i++)
        {
            if (enemy[i].active)
                DrawRectangleRec(enemy[i].rec, enemy[i].color);
        }

        for (int i = 0; i < NUM_SHOOTS; i++)
        {
            if (shoot[i].active)
                DrawRectangleRec(shoot[i].rec, shoot[i].color);
        }

        DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);

        if (victory)
            DrawText("YOU WIN", screenWidth / 2 - MeasureText("YOU WIN", 40) / 2, screenHeight / 2 - 40, 40, BLACK);

        if (pause)
            DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
    }
    else
        DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);

    EndDrawing();
}

// Unload game variables
void UnloadGame(void)
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
}

// Update and Draw (one frame)
void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}