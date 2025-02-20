#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define p2 pair<ll, ll>
#define p3 vi
#define p4 vi
#define vp2 vector<p2>
#define vp3 vector<p3>
#define inf 2e9
#define linf 1e17

#define read(a) cin >> a
#define dread(type, a) type a; cin >> a
#define dread2(type, a, b) dread(type, a); dread(type, b)
#define write(a) cout << (a) << endl
#ifdef _DEBUG
#define deb __debugbreak();
#else
#define deb ;
#endif

#define readpush(type,a) {type temp; read(temp); a.push_back(temp);}
#define readinsert(type,a) {type temp; read(temp); a.insert(temp);}
#define setcontains(set, x) (set.find(x) != set.end())
#define stringcontains(str, x) (str.find(x) != string::npos)
#define all(a) begin(a),end(a)

#define rep(i, high) for (ll i = 0; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (ll i = high; i >= 0; i--)

#define ceildiv(x,y) ((x + y - 1) / y)
#define fract(a) (a-floor(a))


inline void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector<double> sqrtlookup(256 * 256 * 3, -1);
inline float coldist(tuple<int, int, int> a, tuple<int, int, int> b)
{
    int d1 = get<0>(a) - get<0>(b);
    int d2 = get<1>(a) - get<1>(b);
    int d3 = get<2>(a) - get<2>(b);
    int index = d1 * d1 + d2 * d2 + d3 * d3;
    if (sqrtlookup[index] != -1)
    {
        return sqrtlookup[index];
    }
    else
    {
        sqrtlookup[index] = sqrt(index);
        return sqrtlookup[index];
    }
}

int main()
{
    fast();

#if 0
    //ifstream cin("C:\\Users\\Matis\\source\\repos\\Comp prog\\x64\\Debug\\in.txt");
    ifstream cin("C:\\Users\\Matis\\Downloads\\pixel\\examples\\sample03.in");
#endif

    dread(int, n);
    vector<tuple<int, int, int>> cols;
    rep(i, n * 3)
    {
        dread(int, r);
        dread(int, g);
        dread(int, b);
        cols.push_back({ r,g,b });
    }




    int bestX = -1;
    int best = inf;
    for (int guessWidth = 20; guessWidth < 1000; guessWidth++)
    {

        int score = 0;
        int j = 0;
        while (true)
        {
            if (guessWidth * j + 1 + guessWidth - 1 >= n)
            {
                break;
            }
            rep(k, guessWidth)
            {
                score += coldist(cols[guessWidth * j + k], cols[(guessWidth * (j + 1)) + k]);
            }

            j++;
        }

        if (score < best)
        {
            best = score;
            bestX = guessWidth;
        }
    }

    write(bestX);

    return 0;
}