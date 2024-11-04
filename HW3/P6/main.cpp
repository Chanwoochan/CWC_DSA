#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool strToQueue(queue<int>& prioritis);
int solution(queue<int> prioritis, int location);
int max_element(queue<int> q);
void PRINT(queue<int> q);

int main(void)
{
	queue<int> prioritis;
	int location;
	if (!strToQueue(prioritis)) return -1;
	PRINT(prioritis);
	cin >> location;
	if (location < 0 || location >= prioritis.size())
	{
		cout << "입력이 잘못되었습니다.\n";
		return -1;
	}

	cout << solution(prioritis, location) << endl;

	return 0;
}

bool strToQueue(queue<int>& prioritis)
{
	string str;
	getline(cin, str);
	int n;
	bool flag = false;
	for (int i = 0; i < str.size(); ++i)
	{
		if (i == 0)
		{
			if (str[i] == '[')
				n = 0;
			else
			{
				cout << "입력이 잘못되었습니다.\n";
				return false;
			}
		}
		else
		{
			if (str[i] == ',')
			{
				if (n == 0)
				{
					cout << "입력이 잘못되었습니다.\n";
					return false;
				}
				prioritis.push(n);
				n = 0;
			}
			else if (str[i] == ' ');
			else if (str[i] == ']')
			{
				flag = true;
				if (n == 0)
				{
					cout << "입력이 잘못되었습니다.\n";
					return false;
				}
				prioritis.push(n);
				break;
			}
			else if (str[i] >= '1' && str[i] <= '9')
				n = (int)str[i] - (int)'0';
			else
			{
				cout << "입력이 잘못되었습니다.\n";
				return false;
			}
		}
	}
	if (!flag)
	{
		cout << "입력이 잘못되었습니다.\n";
		return false;
	}
	return true;
}

int solution(queue<int> prioritis, int location)
{
	int temp[2];
	queue<int> q;
	int count = 0;
	int psize = prioritis.size();
	for (int i = 0; i < psize; ++i)
		q.push(i);
	while (!prioritis.empty())
	{
		temp[0] = prioritis.front();
		temp[1] = q.front();
		prioritis.pop();
		q.pop();
		if (max_element(prioritis) > temp[0])
		{
			prioritis.push(temp[0]);
			q.push(temp[1]);
		}
		else
		{
			++count;
			if (temp[1] == location)
				return count;
		}
	}
	return count;
}

int max_element(queue<int> q)
{
	int max=0;
	while (!q.empty())
	{
		if (q.front() > max)
			max = q.front();
		q.pop();
	}
	return max;
}

void PRINT(queue<int> q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
