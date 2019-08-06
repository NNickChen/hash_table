#include<iostream>
using namespace std;

static int sosu_table[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int calc_hash(string s)
{
    int hash=0;
    for(int i =0; i < s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
         hash += sosu_table[s[i] - 'a'];
        else
         hash += sosu_table[s[i] - 'A'];
    }
    return hash;
}

int main()
{
	while(1)
	{
		string name;
		cin>>name;
		if(name[0]=='0') break;
		cout<<calc_hash(name)<<endl;
	}
}
