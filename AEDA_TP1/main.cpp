#include "IO_Files.h"
#include "UI.h"


using namespace std;

int main() {

	//UI ui = UI();

	//ui.init();

	IO io = IO();


	io.LoadData("test.txt");

	string x;
	cin >> x;

	return 0;
}
