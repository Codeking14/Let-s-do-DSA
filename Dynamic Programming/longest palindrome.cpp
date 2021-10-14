#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int j=0,k=0;
        string odd="",even="",fodd="";
        int reso = 1,rese =0;
        for(int i=1;i<s.length();i++)
        {
            j=i-1;
            k=i+1;
            int temp = 1;
            while(j>=0 && k<s.length())
            {
                if(s[j] == s[k])
                {
                    temp+=2;
                    odd = s.substr(j,temp);
                    reso = odd.length();
                    j--;
                    k++;
                }
                else
                {
                    break;
                }
            }
            if(reso > fodd.length())
            {
                fodd = odd;
            }
        }
        cout<<fodd<<endl;
    }

	return 0;
}
