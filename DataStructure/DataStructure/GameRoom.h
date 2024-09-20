#pragma once

#include <iostream>
#include <string>
#include <vector>

// �н� ��ǥ : [Room - User System] �ڷᱸ���� ����ؼ� Ŭ������ ����ڴ�.
// 1. List <����� ������ Ŭ����> iList; <= �ڷᱸ���� ���ο� Ŭ���� Ÿ���� �����Ѵ�.
// 2. class GameRoom{private: vector m_Vector}

// �濡 ���� ������ ����
// (private)�ʵ� : name : std::string, id : int, level : int
// (public)	��� : getName(), getId(), getLevel(), GetUserInfo()

// GameRoom ������ �����ϴ� Ŭ����
// UserInfo - �迭, �����迭, ������ ����Ʈ�� ����
// AddPlayer, DeletePlayer, ShowPlayerList, BanPlayer(�߰� ����)

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
		std::cout << "���� �̸� : " << name << std::endl;
	}
	void getId()
	{
		std::cout << "���� ���̵� : " << id << std::endl;
	}
	void getLevel()
	{
		std::cout << "���� ���� : " << level << std::endl;
	}
	void ShowInfo()
	{
		getName();
		getId();
		getLevel();
	}
};

// ������ ����Ʈ vs ���� �迭
// GameRoom - User.
// �߰� ����, ���� - UserInfo
// ���� ����

class GameRoom
{
	// UserInfo �����ϴ� �ڷᱸ��... �迭, ���� �迭, ������ ����Ʈ
	// �迭�� UserInfo�� ǥ�������� ������
	// 6�θ��, 12�θ��.. <- ������ �����Ŷ�� Ȯ���� ������ �迭�� ���� �ȴ�.
	// �迭�� �������� �ʴ�.

	// ���� �迭 std::vector

private:
	std::vector<UserInfo> users;
	int maxCount;		// �� �ִ� �ο���
	int userCount;		// ���� �� �ο���
public:
	// ������

	GameRoom(int max = 8)
	{
		maxCount = max;
		userCount = 0;
	}

	// ���
	void AddPlayer(UserInfo& user)
	{
		// vector<UserInfo> pushback
		// if - bool IsFull - ���� ���� á����
		if (!IsFull())
		{
			users.push_back(user);
			userCount++;
		}
		else
		{
			std::cout << "���� ���� á���ϴ�." << std::endl;
		}
	}

	//RemovePlayer()

	void BanPlayer(int order)	// 0 ~ 7 ����.. order 2 -> 3��° users[2] ����
	{
		if (0 <= order <= users.size())
		{
			users[order].getName();
			std::cout << "��(��) �߹��߽��ϴ�." << std::endl;

			users.erase(users.begin() + order);

			userCount--;
		}
		else
		{
			std::cout << "�ε����� ��ȿ���� �ʽ��ϴ�." << std::endl;
		}
	}

	void ShowListPlayer()
	{
		if (IsEmpty())
		{
			std::cout << "�濡 ����� �����ϴ�." << std::endl;
			return;
		}

		// ���� ���� ~ ������ ����
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
		return userCount >= maxCount ? true : false; // userCount >= maxCount ������(true) : false
	}

	void IsClear()	// ���� �������� �Լ�
	{
		while (!IsEmpty())
		{
			users.pop_back();	// ���������� �ϳ��� �����ش�.
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
	std::cout << "GameRoom �����Դϴ�." << std::endl;

	// ������ ���� 3���� �����غ���.
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

