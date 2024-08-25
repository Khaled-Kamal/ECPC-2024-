#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    
        string s;
        cin >> s;
 
        int H_h = stoi(s.substr(0, 2));
        int M_m = stoi(s.substr(3, 2));
        int M = 0, H = 0;
        if (H_h == 1)
        {
            M = 5;
        }
        else if (H_h == 2)
        {
            M = 10;
        }
        else if (H_h == 3)
        {
            M = 15;
        }
        else if (H_h == 4)
        {
            M = 20;
        }
        else if (H_h == 5)
        {
            M = 25;
        }
        else if (H_h == 6)
        {
            M = 30;
        }
        else if (H_h == 7)
        {
            M = 35;
        }
        else if (H_h == 8)
        {
            M = 40;
        }
        else if (H_h == 9)
        {
            M = 45;
        }
        else if (H_h == 10)
        {
            M = 50;
        }
        else if (H_h == 11)
        {
            M = 55;
        }
 
        if (M_m == 00)
        {
            H = 12;
        }
        else if (M_m == 05)
        {
            H = 1;
        }
        else if (M_m == 10)
        {
            H = 2;
        }
        else if (M_m == 15)
        {
            H = 3;
        }
        else if (M_m == 20)
        {
            H = 4;
        }
        else if (M_m == 25)
        {
            H = 5;
        }
        else if (M_m == 30)
        {
            H = 6;
        }
        else if (M_m == 35)
        {
            H = 7;
        }
        else if (M_m == 40)
        {
            H = 8;
        }
        else if (M_m == 45)
        {
            H = 9;
        }
        else if (M_m == 50)
        {
            H = 10;
        }
        else if (M_m == 55)
        {
            H = 11;
        }
        cout << setw(2) << setfill('0') << H << ":"
             << setw(2) << setfill('0') << M << '\n';
    }

signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int tc = 1 ;
    cin >> tc ;
    for(int i = 1 ; i <= tc ; i++)
    {
       solve();
    }
   
}