#include "IO_Files.h"
#include "UI.h"
#include <dos.h>
#include <windows.h>


using namespace std;

int main(int argc, char* argv[]) {

	IO io = IO();
	Escola * escola = io.LoadData(argv[1]);

	UI ui = UI(escola);

	ui.init();
	
	io.SaveData(escola, argv[1]);

	Sleep(1000);

	return 0;
}
