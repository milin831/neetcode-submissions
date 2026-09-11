class Solution {
public:
    bool helper(vector<vector<char>>& board, string word,int x,int y,int index){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size()) return false;
        if(index>word.size()) return false;
        if(index==word.size()-1 && board[x][y]==word[index]) return true;
        if(board[x][y]==word[index]) return helper(board,word,x,y+1,index+1) ||
                                            helper(board,word,x+1,y,index+1) ||
                                            helper(board,word,x,y-1,index+1) ||
                                            helper(board,word,x-1,y,index+1);
        return false; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool istrue=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                istrue=helper(board,word,i,j,0); 
                if(istrue) return true;   
            }
        }
        return false;
    }
};
