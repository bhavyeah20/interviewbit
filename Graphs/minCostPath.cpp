//instead of pq we use 0-1 as weights 
//push 0 in front and 1 at back, no need to sort using pq

int Solution::solve(int A, int B, vector<string> &C) {
    deque<pair<int,int>> q; 
    q.push_front({0,0});

    vector<vector<int>> dist(A,vector<int> (B,1e9));
    dist[0][0] = 0;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop_front();
        
        int b = y, a = x;
        if(C[y][x] == 'R') a++;
        if(C[y][x] == 'D') b++;
        if(C[y][x] == 'L') a--;
        if(C[y][x] == 'U') b--;

        if(b >= 0 && a >= 0 && b < A && a < B){
        	if(dist[b][a] > dist[y][x]){
        		q.push_front({b,a});
        		dist[b][a] = dist[y][x];
        	}
        }
      
        if(x+1 < B && dist[y][x+1] > dist[y][x]+1){

            q.push_back({y,x+1}), dist[y][x+1] =  dist[y][x]+1;
        }
        


        if(y+1 < A && dist[y+1][x] > dist[y][x]+1){

            q.push_back({y+1,x}), dist[y+1][x] =  dist[y][x]+1;
        }


     
        if(x-1 >= 0 && dist[y][x-1] >dist[y][x]+1){

            q.push_back({y,x-1}), dist[y][x-1] =  dist[y][x]+1;
        }

     

        if(y-1 >= 0 && dist[y-1][x] > dist[y][x]+1){

            q.push_back({y-1,x}), dist[y-1][x] =  dist[y][x]+1;
        }

        
    }

    return dist[A-1][B-1];
}
