#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

string infixToPostfix(string& infix); // 중위표기법을 후위표기법으로 변환
int evalPostfix(string& postfix); // 후위표기법 계산
int isOperator(int op); // 연산자 여부 판별
int precedence(int op); // 연산자 우선순위 반환

int main(void)
{
	string infix, postfix;
	int res;
	cout << "수식입력: ";
	getline(cin, infix);
	postfix = infixToPostfix(infix);
	res = evalPostfix(postfix);
	cout << "\n후위표기법 변환: " << postfix << endl
		<< "연산 결과: " << res << endl
		<< "20191089김찬우\n";
	return 0;
}

string infixToPostfix(string& infix)
{
	stack<char> s;
	string postfix;

	for (int i = 0; i < infix.length(); ++i)
	{
		if (infix[i] == '(')
			s.push(infix[i]);
		else if (infix[i] == ')') // ( 가 나올 때 까지 스택 요소를 문자열에 입력
		{
			while (s.top() != '(')
			{
				postfix += s.top();
				s.pop();
				postfix += ' ';
			}
			s.pop();
		}
		else if (isOperator(infix[i]))
		{
			while (!s.empty() && (precedence(s.top()) >= precedence(infix[i]))) //우선순위가 높은 연산자가 나올 때 까지 스택 요소를 문자열에 입력
			{
				postfix += s.top();
				s.pop();
				postfix += ' ';
			}
			s.push(infix[i]);
		}
		else if (infix[i] >= '0' && infix[i] <= '9')
		{
			for (; infix[i] >= '0' && infix[i] <= '9'; ++i) //피연산자 입력
				postfix += infix[i];
			postfix += ' ';
			--i;
		}
		else if (infix[i] == ' ') continue;
		else
		{
			cout << "잘못된 수식!!!\n";
			exit(100);
		}
	}
	while (!s.empty())  //스택에 남은 요소 입력
	{
		postfix += s.top();
		s.pop();
		postfix += ' ';
	}

	return postfix; // 문자열 반환
}

int evalPostfix(string& postfix)
{
	stack<int> s;
	string temp;
	int op1, op2, res = 0;
	for (int i = 0; i < postfix.length(); ++i)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9') // 피연산자 정수형 변환 후 스택에 푸시
		{
			temp.clear();
			for (; postfix[i] >= '0' && postfix[i] <= '9'; ++i)
				temp += postfix[i];
			s.push(stoi(temp));
			--i;
		}
		else if (isOperator(postfix[i])) // 스택에서 두 수를 가져온후 연산자로 계산 후 푸시
		{
			op2 = s.top();	s.pop();
			op1 = s.top();	s.pop();
			switch (postfix[i])
			{
				case '+': s.push(op1 + op2); break;
				case '-': s.push(op1 - op2); break;
				case '*': s.push(op1 * op2); break;
				case '/': s.push(op1 / op2); break;
			}
		}
		else if (postfix[i] == ' ') continue;
		else
		{
			cout << "잘못된 수식!!!\n";
			exit(100);
		}
	}
	if (!s.empty())  //마지막에남은 스택 요소가 결과임.
		res = s.top();
	return res;
}

int isOperator(int op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}

int precedence(int op)
{
	if (op == '(')
		return 0;
	else if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else return 3;
}
