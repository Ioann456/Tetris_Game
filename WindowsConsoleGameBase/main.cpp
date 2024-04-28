#include "Tetris.h"
#include "time.h"
using namespace std;

int main() {
	srand(time(NULL));
	Tetris game;
	return static_cast<int>(game.run());
}
