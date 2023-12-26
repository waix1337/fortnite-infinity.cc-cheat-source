#include "util.hpp"
#include "cheat/actors/esp.hpp"
#include "cheat/actors/aimbot.hpp"
#include "cheat/kernel/driver.cpp"

Overlay::DXOverlay* pOverlay = nullptr;
HWND game_wndw;


int main() {
	SetConsoleTitleA("Infinity.cc Public");
	system("color 5");
	Sleep(1000);

	if (!driver.init())
	{
		Sleep(3500);
		exit(0);
	}

	process_id = _GetProcessId(("FortniteClient-Win64-Shipping.exe"));
	driver.attach(process_id);
	virtualaddy = driver.get_process_base(process_id);
	std::cout << "base address -> " << virtualaddy << "\n";
	system(("cls"));

	printf("\n [i] Waiting for FortniteClient-Win64-Shipping.exe");

	game_wndw = FindWindow(0, ("Fortnite  "));
	while (!game_wndw) {
		game_wndw = FindWindow(0, ("Fortnite  "));
		Sleep(400);
	}


	Overlay::DXOverlay::GetWindow(FindWindow(0, ("Fortnite  ")));
	auto InitOverlay = pOverlay->InitOverlay();

	std::cout << ("\n [i] Loading dependencies");
	std::thread t(cache_players);
	t.detach();

	std::cout << ("\n [i] Initializing overlay");
	Sleep(1000);
	printf("\n [+] Thank you for choosing Infinity.cc!");
	Sleep(3000);

	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	switch (InitOverlay)
	{
	case 0: { break; }
	case 1:
	{
		MouseController::Init();
		while (pOverlay->MainLoop(actor_loop)) {
		}
		break;
	}
	}

}