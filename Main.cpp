#include "FootPong.h"

int main()
{
	auto pong = std::make_shared<FootPong>();
	pong->run();
	return 0;
}