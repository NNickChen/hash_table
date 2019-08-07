#include<iostream>
using namespace std;

int main()
{
    string s;
    while(1)
    {
	cin>>s;
	if(s[0]=='0') return 0;
	for(int i=0;i<s.size();i++)
	 printf("%x ",s[i]);
	cout<<"\n";
    }
}
