#include "Game2D.h"
#include "Bonobono.h"
#include <memory>
#include "tank.h"

namespace jm
{
	class Mouse : public Game2D
	{
	public:
		void update() override
		{
			const vec2 mouse_pos = getCursorPos(true);

			translate(mouse_pos);
			drawFilledCircle(Colors::blue, 0.1f);
		}
	};
}
int main(void)
{
	//jm::Bonobono().run();
	//jm::Tank().run();

	jm::Mouse().init("This si my digital canvas!", 1000, 1000, false).run();

	return 0;
}