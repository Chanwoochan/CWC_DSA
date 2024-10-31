#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	string str;
	stack<char> s;
	bool res=true;
	getline(cin, str);
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')' && s.top() == '(')
			s.pop();
		else
		{
			res = false;
			break;
		}
	}
	if (!s.empty()) res = false;
	cout << boolalpha << res << endl;
	return 0;
}

