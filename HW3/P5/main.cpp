#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	string str;
	stack<char> s;
	int res = 0;
	getline(cin, str);
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(' || str[i] == '[')
			s.push(str[i]);
		else if (str[i] == ')' && s.top() == '(')
		{
			s.pop();
			res += 2;
		}
			
		else if (str[i] == ']' && s.top() == '[')
		{
			s.pop();
			res += 3;
		}
		else
		{
			res = 0;
			break;
		}
	}
	if (!s.empty()) res = 0;
	cout << boolalpha << res << endl;
	return 0;
}

