#pragma once

#include <string>
#include <stack>
#include <iostream>

// Game에서 최근 로그아웃한 시간을 출력하는 클래스를 직접 구현해보세요.

class GameData
{
private:
	std::string iDate;
public:
	GameData(std::string _date) :iDate(_date) {}

	std::string GetDate() { return iDate; }

	void Print()
	{
		std::cout << "로그아웃 한 시간 : " << iDate << std::endl;
	}
};

class GameHistory
{
	// 자료구조 : 클래스 구현할 때 가장 적합하게 데이터를 저장할 수 있는것을 배우는것.

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
// Print() {"게임 로그아웃한 시간 : " << iData }

// class GameHistory
// Stack<GameData>
// Pop, Push
// SaveLogoutTime(std::string 시간) Push
// PrintLogoutTime() pop

void iGameHistoryExample()
{
	// 로그아웃한 이력
	GameData data1("2024-09-20 / 17:00");
	GameData data2("2024-09-21 / 17:00");
	GameData data3("2024-09-22 / 17:00");
	GameData data4("2024-09-23 / 17:00");

	// 특정 유저가 로그아웃한 시간을 출력할 수 있는 기능

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