class Solution {
public:
    int minDistance(string word1, string word2) {
    	int len1 = word1.size();
    	int len2 = word2.size();
    	vector<vector<int> > dist(len1 + 1, vector<int>(len2 + 1, 0));
    	for (int i = 1; i <= len2; i++)
    		dist[0][i] = i;
    
    	for (int i = 1; i <= len1; i++) {
    		dist[i][0] = i;
    		for (int j = 1; j <= len2; j++) {
    			if (word1[i - 1] == word2[j - 1])
    				dist[i][j] = min(min(dist[i - 1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1]);
    			else
    				dist[i][j] = min(min(dist[i - 1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1] + 1);
    		}
    	}
    	return dist[len1][len2];
    }
};