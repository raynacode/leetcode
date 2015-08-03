class Solution {
public:
    UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& visited) {
    	UndirectedGraphNode* nd = new UndirectedGraphNode(node->label);
    	visited[node->label] = nd;
    	for (int i = 0; i < (node->neighbors).size(); i++) {
    		if (visited[(node->neighbors)[i]->label])
    			nd->neighbors.push_back(visited[(node->neighbors)[i]->label]);
    		else
    			nd->neighbors.push_back(dfs((node->neighbors)[i], visited));
    	}
    	return nd;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode* node) {
    	if (!node)
    		return NULL;
    	unordered_map<int, UndirectedGraphNode*> visited;
    	UndirectedGraphNode* res = dfs(node, visited);
    	return res;
    }
};