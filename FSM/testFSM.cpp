#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum CD_STATE
{
	RUNNING = 0,
	PAUSE,
	STOP 
};

enum CD_EVENT
{
	PRESS_RUNNING =0,
	PRESS_PAUSE,
	PRESS_STOP
};

vector<string> state_to_str{ "RUNNING","PAUSE","STOP" };

// 初始状态
int current_state = CD_STATE::STOP;

void do_change_running()
{
	cout << "CD Status from " << state_to_str[current_state] << " to Running" << endl;
	current_state = CD_STATE::RUNNING;
}

void do_change_stop()
{
	cout << "CD Status from " << state_to_str[current_state] << " to STOP" << endl;
	current_state = CD_STATE::STOP;
}

void do_change_pause()
{
	cout << "CD Status from " << state_to_str[current_state] << " to PAUSE" << endl;
	current_state = CD_STATE::PAUSE;
}

void dispather(int current_state,int  event)
{
	switch (current_state)
	{
	case CD_STATE::RUNNING:
		switch (event)
		{
		case CD_EVENT::PRESS_RUNNING:
			do_change_running();
			break;
		case CD_EVENT::PRESS_PAUSE:
			do_change_pause();
			break;
		case CD_EVENT::PRESS_STOP:
			do_change_stop();
			break;
		default:
			break;
		}
		break;
	case CD_STATE::STOP:
		switch (event)
		{
		case CD_EVENT::PRESS_RUNNING:
			do_change_running();
			break;
		default:
			cout << "CD's state will not change!" << endl;
			break;
		}
		break;
	case CD_STATE::PAUSE:
		switch (event)
		{
		case CD_EVENT::PRESS_RUNNING:
			do_change_running();
			break;
		case CD_EVENT::PRESS_STOP:
			do_change_stop();
			break;
		default:
			cout << "CD's state will not change!" << endl;
			break;
		}
		break;
	default:
		break;
	}
}

int main()
{
	int current_event = 0;
	cout << "请输入数字操作CD机（0：Run,1:pause,2,stop） " << endl;

	while (cin >> current_event)
	{
		if (current_event < 0 || current_event >2)
		{
			cout << "数字不合法，请重新输入" << endl;
		}
		else
		{
			dispather(current_state, current_event);
		}
	}

	system("pause");
	return 0;
}