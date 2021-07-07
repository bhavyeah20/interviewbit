/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

#define graph UndirectedGraphNode

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {

    if(!node) return NULL
    queue<pair<graph *,graph *>> q; //original,copy
    unordered_map<graph *,graph *> mp; //orignal,copy 

    graph *head = new graph(node->label);
    mp[node] = head;
    q.push({node,head});

    while(!q.empty()){
        auto [temp,tempCopy] = q.front();
        q.pop();

        for(auto nbr : temp->neighbors){
            if(mp.find(nbr) != mp.end()){
                (tempCopy->neighbors).push_back(mp[nbr]);
            }

            else{
                graph *newNbr = new graph(nbr->label);
                (tempCopy->neighbors).push_back(newNbr);
                q.push({nbr,newNbr});
                mp[nbr] = newNbr;
            }
        }

    }

    return head;
}
