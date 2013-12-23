#include "IO_Files.h"
#include "UI.h"


using namespace std;

int main(int argc, char* argv[]) {

	IO io = IO();
	Escola * escola = io.LoadData(argv[1]);

	UI ui = UI(escola);

	ui.init();

	string x;
	cin >> x;

	return 0;
}
