#include<iostream>
#include<fstream>
using namespace std;

string hash_table[1000][2];
string chaintable[1000][100][2];
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

int main(int argc , char * const argv[])
{
    string filename;
    if(argc<=1)
    {
        cout<<"Enter the filename:\n";
        cin>>filename;
    } else {
        filename = argv[1];
    }
    ifstream fin(filename);
    if(!fin)
    {
        cout<<"Cannot open the file.\n";
        return 0;
    }
    // int n;
    // fin>>n;
    // for(int i=0;i<n;i++)
    while(1)
    {
        string name;
        string number;
        fin>>name>>number;
        if(name[0]=='0') break;
        // cout<<name<<" "<<number<<"\n";
        int hash =calc_hash(name);
        if(hash_table[hash][0].size()==0)
        {
            hash_table[hash][0]=name;
            hash_table[hash][1]=number;
        }
        else
        {
            int i=0;
            while(chaintable[hash][i++][0].size()>0&&i<100);
            chaintable[hash][--i][0]=name;
            chaintable[hash][i][1]=number;
        }
    }
    // cout<<"1\n";
    fin.close();
    // cin>>n;
    while(1)
    {
        string name;
        string number;
        cin>>name;
        if(name[0]=='0') break;
        int hash = calc_hash(name);
        if(hash_table[hash][0]==name)
         number=hash_table[hash][1];
        else
        {
            int i=0;
            while(chaintable[hash][i++][0]!=name&&i<100);
            number=chaintable[hash][--i][1];
        }
        if(number.size()>0)
         cout<<number<<endl;
        else
         cout<<"Ignored\n";
    }
    return 0;
}
