#pragma once

#include <iostream>
#include <string>
#include <vector>

// 학습 목표 : [Room - User System] 자료구조를 사용해서 클래스를 만들겠다.
// 1. List <사용자 정의형 클래스> iList; <= 자료구조에 새로운 클래스 타입을 저장한다.
// 2. class GameRoom{private: vector m_Vector}

// 방에 들어온 유저의 정보
// (private)필드 : name : std::string, id : int, level : int
// (public)	기능 : getName(), getId(), getLevel(), GetUserInfo()

// GameRoom 유저를 저장하는 클래스
// UserInfo - 배열, 가변배열, 연결형 리스트로 저장
// AddPlayer, DeletePlayer, ShowPlayerList, BanPlayer(추가 정보)

struct UserInfo
{
private:
	std::string name;
	int id;
	int level;
public:
	UserInfo() {}
	UserInfo(std::string name, int id, int level) :name(name), id(id), level(level) {}

	void getName()
	{
		std::cout << "유저 이름 : " << name << std::endl;
	}
	void getId()
	{
		std::cout << "유저 아이디 : " << id << std::endl;
	}
	void getLevel()
	{
		std::cout << "유저 레벨 : " << level << std::endl;
	}
	void ShowInfo()
	{
		getName();
		getId();
		getLevel();
	}
};

// 연결형 리스트 vs 가변 배열
// GameRoom - User.
// 중간 삽입, 삭제 - UserInfo
// 랜덤 접근

class GameRoom
{
	// UserInfo 저장하는 자료구조... 배열, 가변 배열, 연결형 리스트
	// 배열로 UserInfo를 표현했을때 문제점
	// 6인모드, 12인모드.. <- 나오지 않을거라는 확신이 있으면 배열로 만들어도 된다.
	// 배열은 적합하지 않다.

	// 가변 배열 std::vector

private:
	std::vector<UserInfo> users;
	int maxCount;		// 방 최대 인원수
	int userCount;		// 현재 방 인원수
public:
	// 생성자

	GameRoom(int max = 8)
	{
		maxCount = max;
		userCount = 0;
	}

	// 기능
	void AddPlayer(UserInfo& user)
	{
		// vector<UserInfo> pushback
		// if - bool IsFull - 방이 가득 찼을때
		if (!IsFull())
		{
			users.push_back(user);
			userCount++;
		}
		else
		{
			std::cout << "방이 가득 찼습니다." << std::endl;
		}
	}

	//RemovePlayer()

	void BanPlayer(int order)	// 0 ~ 7 순서.. order 2 -> 3번째 users[2] 삭제
	{
		if (0 <= order <= users.size())
		{
			users[order].getName();
			std::cout << "을(를) 추방했습니다." << std::endl;

			users.erase(users.begin() + order);

			userCount--;
		}
		else
		{
			std::cout << "인덱스가 유효하지 않습니다." << std::endl;
		}
	}

	void ShowListPlayer()
	{
		if (IsEmpty())
		{
			std::cout << "방에 사람이 없습니다." << std::endl;
			return;
		}

		// 시작 부터 ~ 마지막 까지
		for(int i=0; i<userCount; i++)
		{
			users[i].ShowInfo();
		}
	}

	bool IsEmpty()
	{
		return userCount <= 0 ? true : false;
	}

	bool IsFull()
	{
		return userCount >= maxCount ? true : false; // userCount >= maxCount 가득참(true) : false
	}

	void IsClear()	// 방이 없어지는 함수
	{
		while (!IsEmpty())
		{
			users.pop_back();	// 끝에서부터 하나씩 지워준다.
			userCount--;
		}
	}

	void IsClear2()
	{
		users.erase(users.begin(), users.end());
		userCount = 0;
	}

};


void IGameRoomExample()
{
	std::cout << "GameRoom 예시입니다." << std::endl;

	// 가상의 유저 3명을 생성해본다.
	UserInfo user1("A", 1000, 10);
	user1.ShowInfo();
	UserInfo user2("B", 1001, 15);
	user2.ShowInfo();
	UserInfo user3("C", 1002, 15);
	user3.ShowInfo();

	GameRoom room(2);
	room.AddPlayer(user1);
	room.AddPlayer(user2);
	room.AddPlayer(user3);
	room.BanPlayer(1);
	room.ShowListPlayer();

	room.IsClear();
	room.ShowListPlayer();

}

