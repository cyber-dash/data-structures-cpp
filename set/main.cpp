#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
//using std::string;

int priority(char c)   //优先级
{
  switch(c)
  {
    case '+':
      return 1;
      break;
    case '-':
      return 1;
      break;
    case '*':
      return 2;
      break;
    case '/':
      return 2;
      break;
    default :
      return 0;
  }
}
string printStack(stack<char> str)
{
  string result;
  while(!str.empty())
  {
    result=str.top()+result;
    str.pop();
  }
  return result;
}
string Polish(string str)   //逆波兰表达式
{
  stack<char>S1;
  stack<char>S2;
  for(int i=0;i<str.length();i++)
  {
    char curChar=str[i];
    if((curChar>='0') && (curChar <='9'))                   //如果遇到的是数字，将数字压入S1中
    {
      S1.push(curChar);
    }
    else if(curChar=='(')   //如果遇到的是左括号，将左括号压入S2中
    {
      S2.push(curChar);
    }
    else if(!S2.empty() &&curChar==')')  //如果遇到的是右括号，将S2中的运算符一直出栈压入S1中，直到遇到左括号，但是该左括号出S2却不入S1；
    {
      while(S2.top()!='(')
      {
        S1.push(S2.top());
        S2.pop();
      }
      S2.pop();
    }
    else  //如果遇到的是运算符，按照如下规则操作
    {
      if(!S2.empty()) //如果S2不为空
      {
        if((priority(curChar)>=priority(S2.top())))  //当前遍历到的运算符优先级不小于S2栈顶运算符
          S2.push(curChar);                       //将当前遍历到的运算符压入S2
        else   //如果S2不为空，当前遍历到的运算符优先级小于S2栈顶运算符，将栈顶运算符一直出栈压入S1中，
        {      // //直到栈为空或遇到一个运算符优先级小于当前遍历到的运算符，此时将当前遍历到的运算符压入S2；
          while(!S2.empty())
          {
            if((priority(curChar)<=priority(S2.top())))
            {
              S1.push(S2.top());
              S2.pop();
            }
            else
              break;

          }
          S2.push(curChar);
        }
      }
      else
      {
        S2.push(curChar);   //如果S2为空，将运算符压入S2中
      }
    }

  }
  while(!S2.empty())  //直到遍历完整个中序表达式后，若S2中仍然存在运算符，将这些运算符依次出栈压入S1，直到S2为空；
  {
    S1.push(S2.top());
    S2.pop();
  }
  return  printStack(S1);
}


int cal(string S1)   //计算值
{
  stack<int>S3;
  for(int i=0; i <S1.length();i++)
  {
    char curChar=S1[i];
    int a,b,res;
    if(curChar=='+' || curChar=='-' || curChar =='*' || curChar=='/')
    {
      b=S3.top();  S3.pop();
      a=S3.top();  S3.pop();
      if(curChar=='+')
        res=a+b;
      else if(curChar=='-')
        res=a-b;
      else if(curChar=='*')
        res=a*b;
      else
        res=a/b;

      S3.push(res);
    }
    else
    {

      int temp;
      if(!S3.empty())
      {
        temp=S3.top();
        S3.pop();
        temp=temp*10+(curChar-'0');
        S3.push(temp);
      }
      else
      {

        S3.push(curChar-'0');
      }

    }
  }
  return S3.top();
}


int main()
{
  //  cout << "Hello world!" << endl;
  string  str;
  int c;
  cout<<"Input the expression:";
  cin>>str;
  string result=Polish(str);
  cout<<result<<endl;

  cout<<"Cal result:";
  c=cal(result);
  cout<<c<<endl;
  return 0;
}