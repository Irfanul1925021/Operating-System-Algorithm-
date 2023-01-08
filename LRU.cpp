




/*****************************************************************\
IN THE NAME OF ALLAH, MOST GRACIOUS AND MOST MERCIFUL

|     Author     : Irfanul Haque Nabil
|     Email      : irfanul2515@student.nstu.edu.bd
|     Department : Department of Software Engineering,
                   Institute of Information Technology(IIT)
|     University : Noakhali Science and Technology University,Bangladesh


\*****************************************************************/


/*...................................Data_Types............................................*/

#include<bits/stdc++.h>

using namespace std;
#define FastIO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define       ll                  long long int
#define       ull                  unsigned long long int
#define       veci                 vector<int>
#define       vecc                 vector<char>
#define       vecs                 vector<string>
#define       vecl                 vector<long long int>
#define       vecp                 vector<  pair<int,int> >
#define       mapstrint            map< string , int >
#define       mapstrstr            map< string , string >
#define       mapint               map< int, int >
#define       pb                   push_back
#define       newline cerr << endl
#define       pob                  pop_back
#define       mp                   make_pair
#define       pii                  pair<int, int>
#define       F                    first
#define       S                    second
#define       sc(x)                scanf("%d",&x)
#define       sc2(xx,zz)           scanf("%d %d",&xx,&zz)
#define       scl(x)               scanf("%lld",&x)
#define       scl2(xx,zz)          scanf("%lld %lld",&xx,&zz)
#define       pf                   printf
#define       nl                   "\n"
#define       min3(a,b,c)          min(a,b<c?b:c)
#define       max3(a,b,c)          max(a,b>c?b:c)
#define       all(v)               v.begin(), v.end()
///=============== Debugging ============================///
#define       debug(x) cerr << #x << " = " << x << endl
#define       debug2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
//#define f(x) (64 - __builtin_clzll(x))
///============ CONSTANT ===============///
#define mx9   1000000007
#define mx7   10000007
#define mx6   2000006
#define mx5   200005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   mx9
///==============================TEMPLATES===============================///

long double PI = acosl(-1);
bool compare_int(int a, int b){return (a>b);} //This function is use for descending order.
bool compare_string (string a, string b){return a.size()<b.size();}
bool compare_pair(const pair<int,int> &a,
                    const pair<int,int> &b){if(a.second==b.second)return a.first<b.first; else return (a.second > b.second);}
bool cmp(pair<string ,int > x , pair<string ,int > y){return (x.S < y.S);}
///=====================Graph Moves================///
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

///=====================Bitmask===================///
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}

///========================================FUNCTION=========================================///
//bool check(int n){if(n==1) return false; for(int i=2; i*i<=n; i++){if(n%i==0) return false;} return true;}
//ll bigmod(ll a, ll b, ll m){if(b==0) return 1%m;ll x=bigmod(a, b/2, m);x=(x*x)%m;if(b%2==1)x=(x*a)%m;return x;}
//bool flag[mx5];veci prime;
//void sieve(){prime.pb(2);for(ll i=3; i*i<=mx5; i+=2){if(flag[i]) continue;for(ll j=i*i; j<=mx5; j+=i+i) flag[j]=true;}for(ll i=3; i<=mx5; i+=2) if(!flag[i]) prime.pb(i);}
//ll fact(ll n){if(n==0 or n==1)return 1; else return n*fact(n-1);}
void NA(){printf("NO\n");exit(0);}
void YA(){printf("YES\n");exit(0);}

///=================START_FROM_HERE=====================///


class page_table
{
public:
    int no_of_pages,no_of_frames,page_fault=0,position=0,index=0,index1=0,count1=1;
    int frequency_array[100];
    int pages[100];
    int frames[100];
    page_table(int a,int b)
    {
        no_of_pages=a;
        no_of_frames=b;
        page_fault=no_of_frames;

        for(int i=0;i<no_of_frames;i++)
        {
            frames[i]=-1;
            frequency_array[i]=0;
        }
    }
    void get_pages()
    {
        cout<<"Enter the pages one after the another\n";
        for(int i=0;i<no_of_pages;i++)
        {
            cin>>pages[i];
        }
    }
    void intial_step()
    {
        for(int i=0;i<no_of_frames;i++)
        {
            frames[i]=pages[i];
            for(int j=0;j<=i;j++)
            {
                frequency_array[j]+=1;
            }
            print();
        }
    }
    bool check(int i1)
    {
        for(int i=0;i<no_of_frames;i++)
        {
            if(frames[i]==pages[i1])
            {

                index1=i;
                return true;
            }
        }
        return false;
    }
    void dead(int i1)
    {

        frequency_array[i1]=0;


    }
    int greatest()
    {
        int max1=frequency_array[0];
        for(int i=0;i<no_of_frames;i++)
        {
            if(max1<=frequency_array[i])
            {
                max1=frequency_array[i];
                index=i;
            }
        }

        return index;
    }
    void print()
    {
        cout<<"frames is\n";
        for(int i=0;i<no_of_frames;i++)
        {
            cout<<frames[i]<<"  ||  ";
        }
        cout<<"\n\n";
    }
    int lru()
    {
        for(int i=no_of_frames;i<no_of_pages;i++)
        {


            if(check(i)==true)
            {


                dead(index1);

                       for(int j=0;j<no_of_frames;j++)
            {
                if(index1==j)
                {
                    continue;
                }
                frequency_array[j]+=1;
            }
            print();
                continue;

            }
            else{
                position=greatest();


                frames[position]=pages[i];
                dead(position);
                 for(int j=0;j<no_of_frames;j++)
            {
                if(position==j)
                {
                    continue;
                }
                frequency_array[j]+=1;
            }
            page_fault++;



            }
            print();
        }

        return page_fault;
    }


};
int main()
{
    int a,b,c;
    cout<<"Enter the number of pages:\n";
    cin>>a;
    cout<<"Enter the number of frames:\n";
    cin>>b;
    page_table p(a,b);
    p.get_pages();
    p.intial_step();
    cout<<"page fault is "<<p.lru();

}
