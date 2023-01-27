#pragma once

#include "Game2D.h"

namespace jm
{
	class Bonobono : public Game2D
	{
	public:
		void update() override
		{
			beginTransformation();
			const vec2 p0(-0.10f, -0.12f);
			const vec2 p1(-0.17f, -0.10f);
			const vec2 p2(-0.10f, -0.14f);
			const vec2 p3(-0.17f, -0.14f);
			const vec2 p4(-0.10f, -0.16f);
			const vec2 p5(-0.17f, -0.18f);
			const vec2 q0(0.10f, -0.12f);
			const vec2 q1(0.17f, -0.10f);
			const vec2 q2(0.10f, -0.14f);
			const vec2 q3(0.17f, -0.14f);
			const vec2 q4(0.10f, -0.16f);
			const vec2 q5(0.17f, -0.18f);
			drawFilledCircle(Colors::bonobonoblue, 0.5f);
			beginTransformation();
			translate(-0.32f, 0.10f);
			drawFilledCircle(Colors::black, 0.01f);
			endTransformation();
			beginTransformation();
			translate(0.32f, 0.10f);
			drawFilledCircle(Colors::black, 0.01f);
			endTransformation();
			beginTransformation();
			translate(0.07f, -0.16f);
			drawFilledRegularConvexPolygon(Colors::white, 0.08f, 40.0f, 20);
			endTransformation();
			beginTransformation();
			translate(-0.07f, -0.16f);
			drawFilledRegularConvexPolygon(Colors::white, 0.08f, 40.0f, 20);
			endTransformation();
			beginTransformation();
			translate(0.0f, -0.11f);
			drawFilledCircle(Colors::black, 0.05f);
			endTransformation();
			beginTransformation();
			drawLine(Colors::black, p4, Colors::black, p5);
			drawLine(Colors::black, p2, Colors::black, p3);
			drawLine(Colors::black, p1, Colors::black, p0);
			drawLine(Colors::black, q4, Colors::black, q5);
			drawLine(Colors::black, q2, Colors::black, q3);
			drawLine(Colors::black, q1, Colors::black, q0);
			endTransformation();
			endTransformation();
		}
	};
}