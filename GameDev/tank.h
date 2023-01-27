#pragma once
#include "Game2D.h"
namespace jm
{
	class MyTank
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);

		void draw()
		{
			beginTransformation();
			{
				translate(center);
				drawFilledBox(Colors::bonobonoblue, 0.25f, 0.1f);
				translate(-0.02f, 0.1f);
				drawFilledBox(Colors::black, 0.15f, 0.09f);
				translate(0.15f, 0.0f);
				drawFilledBox(Colors::green, 0.15f, 0.03f);
			}
			endTransformation();
		}
	};

	class MyBullet
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);

		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::yellow, 0.02f, 8);
			drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
			endTransformation();
		}

		void update(const float& dt)
		{
			center += velocity * dt;
		}
	};

	class Tank : public Game2D
	{
	public:
		MyTank tank;

		std::vector<MyBullet*> bullets;

	public:
		Tank()
			: Game2D("This is my digital canvas!", 1024, 768, false, 2)
		{}
		~Tank()
		{

		}
		void update() override
		{
			if (isKeyPressed(GLFW_KEY_LEFT))	tank.center.x -= 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_RIGHT))	tank.center.x += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_UP))		tank.center.y += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_DOWN))	tank.center.y -= 0.5f * getTimeStep();

			if (isKeyPressed(GLFW_KEY_A))
			{
				bullets.push_back(new MyBullet);
				bullets.back()->center = tank.center;
				bullets.back()->center.x += 0.2f;
				bullets.back()->center.y += 0.1f;
				bullets.back()->velocity = vec2(2.0f, 0.0f);
				printf("%d\n", bullets.size());
			}

			if (!bullets.empty())
			{
				for (int i = 0; i < bullets.size(); i++)
				{
					bullets.at(i)->update(getTimeStep());
					bullets.at(i)->draw();
				}
			}


			tank.draw();

			if (!bullets.empty())
			{
				for (int i = 0; i < bullets.size(); i++)
				{
					if (bullets[i]->center.x > 1.5f)
					{
						delete bullets[i];
						bullets.erase(bullets.begin() + i);
					}
				}
			}
		}


	};
}