
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



int present(int table_frame[], int nf, int page)
{
	for(int i=0; i<nf; i++)
		if(page == table_frame[i])
			return 1;
	return 0;
}

void printtable(int table_frame[], int nf)
{
	for(int i=0; i<nf; i++)
	{
		if(table_frame[i] == -1)
			printf("-- ");
		else
			printf("%2d ", table_frame[i]);
	}
	printf("||");
}


int findpos(int table_frame[],int nf,int pages[],int curr,int np)
{
    int i,j;
    for(i=0;i<nf;i++)
    {
        if(table_frame[i] == -1)
            return i;
    }

    int pos[nf]={0};
    for(i=0;i<nf;i++)
    {
        pos[i]=1e9;
        for(j=curr+1;j<np;j++)
        {
            if(pages[j]==table_frame[i])
            {
                pos[i]=j;
                break;
            }
        }
    }

    int max1=-1;
    int returnpos=-1;
    for(i=0;i<nf;i++)
    {
        if(pos[i]>max1)
        {
            max1=pos[i];
            returnpos=i;
        }
    }

    return returnpos;
}

int main()
{
    //nf-number of frames
    int n,nf,i,pos=0;

    printf("enter number of frames\n");
    scanf("%d",&nf);
    int table_frame[nf];
    for(i=0;i<nf;i++)
    {
        table_frame[i]=-1;
    }

    printf("enter total number of page requests\n");
    scanf("%d",&n);
    int pages[n];
    printf("enter pages\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }

    int count1=0;
    printf("position of frame table after each request\n");
    for(i=0;i<n;i++)
    {
        printf("page table after request from %2d || ",pages[i]);
        if(!present(table_frame,nf,pages[i]))
        {
             int pos = findpos(table_frame,nf,pages,i,n);
             table_frame[pos]=pages[i];

             printtable(table_frame,nf);
             printf("page fault\n");
             count1++;
             continue;
        }
        printtable(table_frame,nf);
		printf("\n");

    }
    printf("\nNumber of page faults : %d\n\n", count1);
}
