#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	string str;
	stack<char> s;
	int tmp = 1;
	int res = 0;
	getline(cin, str);
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			tmp *= 2;
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				res = 0;
				break;
			}
			else if (str[i - 1] == '(')
			{
				res += tmp;
				tmp /= 2;
				s.pop();
			}
			else
			{
				tmp /= 2;
				s.pop();
			}
		}
		else if (str[i] == '[')
		{
			tmp *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				res = 0;
				break;
			}
			else if (str[i - 1] == '[')
			{
				res += tmp;
				tmp /= 3;
				s.pop();
			}
			else
			{
				tmp /= 3;
				s.pop();
			}
		}
	}
	if (!s.empty()) res = 0;
	cout << res << endl;
	return 0;
}

