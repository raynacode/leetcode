class Solution {
public:
    RandomListNode* copyListHelper(RandomListNode* node, unordered_map<RandomListNode*, RandomListNode*>& visited) {
        RandomListNode* nd;
        if (!visited[node]) {
            nd = new RandomListNode(node->label);
            visited[node] = nd;
        }
        else
            nd = visited[node];
        if (node->random) {
            if (!visited[node->random]) {
                nd->random = new RandomListNode(node->random->label);
                visited[node->random] = nd->random;
            }
            else
                nd->random = visited[node->random];
        }
        if (!node->next)
            return nd;
        else
            nd->next = copyListHelper(node->next, visited);
    }
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (!head)
            return NULL;
        RandomListNode* res;
        unordered_map<RandomListNode*, RandomListNode*> visited;
        return copyListHelper(head, visited);
    }
};