#ifndef BOID_H
#define BOID_H

#include <iostream>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>
#include "vectormath.h"
#include "obstacle.h"

class Boid
{
    public:
        Boid();

        Boid(sf::Texture * argtex, float x, float y, float a, int w, int h, const std::vector<std::vector<sf::IntRect>>& rects);
        Boid(sf::Texture& argtex, sf::Vector2f v);

        bool sameRect(const Boid& b);
        sf::Vector2i quickRectPos(const std::vector<std::vector<sf::IntRect>>& rects);

        bool rectContainsBoid(int i, int j);

        void draw(sf::RenderTarget& window);
        void update(float dt, sf::RenderWindow& window, const std::vector<Boid>& boids, const std::vector<Boid>& sharks,
                    const std::vector<Obstacle> obstacles, const std::vector<std::vector<sf::IntRect>>& rects);

        void borders();

        sf::Vector2f separation(const std::vector<Boid>& boids, const std::vector<Obstacle> obstacles);
        sf::Vector2f sharkSeparation(const std::vector<Boid>& boids);
        sf::Vector2f cohesion(const std::vector<Boid>& boids);
        sf::Vector2f alignment(const std::vector<Boid>& boids);

        sf::Vector2f seek(sf::Vector2f target);

        void trailUpdate(float dt);

        void setTrail(sf::Texture * argtex);

        void sharkify();

        std::string toString();

        virtual ~Boid();

        sf::Vector2i rectPos;
        sf::Vector2f vel;

    protected:
    private:
        bool shark;
        sf::Sprite sprite;
        std::vector<sf::Sprite> trail;

        sf::Texture * spriteTex;
        sf::Texture * trailTex;

        sf::Vector2f pos;

        sf::Vector2f acc;
        float maxSpeed, xSpeed;
        float maxForce, xForce;
        float sepDist;
        float alignDist;
        float cohDist;

        int worldWidth;
        int worldHeight;
        int size;

        bool sharkFlag;

        bool trailOn;
        int trailIdx;
};

#endif // BOID_H