#pragma once

#include <string>
#include <stack>
#include <iostream>

// Game���� �ֱ� �α׾ƿ��� �ð��� ����ϴ� Ŭ������ ���� �����غ�����.

class GameData
{
private:
	std::string iDate;
public:
	GameData(std::string _date) :iDate(_date) {}

	std::string GetDate() { return iDate; }

	void Print()
	{
		std::cout << "�α׾ƿ� �� �ð� : " << iDate << std::endl;
	}
};

class GameHistory
{
	// �ڷᱸ�� : Ŭ���� ������ �� ���� �����ϰ� �����͸� ������ �� �ִ°��� ���°�.

	std::stack<GameData> GameDatas;

	// GameData*	m_data;
	// int			capacity;
	// int			top;

	// pop, push, 

	void SaveLogOutTime(GameData time)
	{
		GameDatas.push(time);
	}

	void PrintLogoutTime(GameData time)
	{
		GameData printData = GameDatas.top();
		printData.Print();
		GameDatas.pop();
	}
};

// GameData
// std::string iData; "2024.09.23
// Print() {"���� �α׾ƿ��� �ð� : " << iData }

// class GameHistory
// Stack<GameData>
// Pop, Push
// SaveLogoutTime(std::string �ð�) Push
// PrintLogoutTime() pop

void iGameHistoryExample()
{
	// �α׾ƿ��� �̷�
	GameData data1("2024-09-20 / 17:00");
	GameData data2("2024-09-21 / 17:00");
	GameData data3("2024-09-22 / 17:00");
	GameData data4("2024-09-23 / 17:00");

	// Ư�� ������ �α׾ƿ��� �ð��� ����� �� �ִ� ���

	GameHistory GameDatas;
	GameDatas.SaveLogOutTime(data1);
	GameDatas.SaveLogOutTime(data2);
	GameDatas.SaveLogOutTime(data3);
	GameDatas.SaveLogOutTime(data4);

	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();
	GameDatas.PrintLogoutTime();

}