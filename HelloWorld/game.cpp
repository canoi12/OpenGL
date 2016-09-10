#include "game.h"
#include "resource_manager.h"

Game::Game(GLuint width, GLuint height) 
        : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
    
}

Game::~Game()
{

}

SpriteRenderer *Renderer;

void Game::Init()
{
    ResourceManager::LoadShader("shader.vs", "shader.frag", NULL, "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width),static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);

    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);


    Shader myShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(myShader);

    ResourceManager::LoadTexture("assets/ground2.png", GL_TRUE, "ground");  
    ResourceManager::LoadTexture("assets/block.png", GL_FALSE, "block");
    ResourceManager::LoadTexture("assets/block_solid.png", GL_FALSE, "block_solid");

    GameLevel one; one.Load("assets/one.lvl", this->Width, this->Height * 0.5);

    this->Levels.push_back(one);
    this->Level = 1;



}

void Game::Update(GLfloat dt)
{

}

void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
    if (this->State == GAME_ACTIVE)
    {
        Texture2D myTex = ResourceManager::GetTexture("ground");
        Renderer->DrawSprite(myTex,glm::vec2(400,200),glm::vec2(224,280),0,glm::vec3(1.0f, 1.0f, 1.0f));
    }

    this->Levels[this->Level].Draw(*Renderer);
}