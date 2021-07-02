#include<iostream>
#include<list>

using namespace std;

#define ll long long
#define endl "\n"


class Graph{
    ll V;
    list<pair<ll,ll> > *l;

public:
    Graph(ll V){
        this->V = V;
        l = new list<pair<ll,ll>>[V+1];
    }

    void addEdge(ll x, ll y, ll cost){
        l[x].push_back({y,cost});
        l[y].push_back({x,cost});
    }

    ll dfsHelper(ll src, bool *visited, ll *count, ll &ans){
        count[src] = 1;
        visited[src] = 1;

        for(auto nbr_pair : l[src]){
            ll nbr = nbr_pair.first;
            ll wt = nbr_pair.second;

            if(!visited[nbr]){
                count[src] += dfsHelper(nbr,visited,count,ans);

                ll nx = count[nbr];
                ll ny = V - nx;

                ans += 2 * wt * min(nx,ny);
            }
        }


        return count[src];
    }

    ll dfs(){
        ll *count = new ll[V+1];
        bool *visited = new bool[V+1];

        for(ll i = 1; i <= V; i++){
            count[i] = 0;
            visited[i] = 0;
        }
        ll ans = 0;
        ll cnt = dfsHelper(1,visited,count,ans);
        return ans;
    }
    

};

int main(){
    ll t;
    cin >> t;
    for(ll tt = 1; tt <= t; tt++){
        ll n;
        cin >> n;

        Graph g(n);
        n--;
        while(n--){
            ll x, y, cost;
            cin >> x >> y >> cost;
            g.addEdge(x,y,cost);
        }

        ll ans = g.dfs();


        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
}

