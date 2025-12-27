class Solution {
public:
    vector<vector<string>> ans={};
    vector<string> chessBoard={};

    bool isSafe(int r,int c,int n)
    {
        // check up down left right
        for(int i=0;i<n;i++)
        {
            if(chessBoard[r][i]=='Q' || chessBoard[i][c]=='Q')
            {
                return false;
            }
        }

        // diagonal
        int R=r;
        int C=c;

        // upward left
        while(R>=0 && C>=0)
        {
            if(chessBoard[R][C]=='Q')
            {
                return false;
            }
            R--;
            C--;
        }
        R=r;
        C=c;
        // upward right
        while(R>=0 && C<n)
        {
            if(chessBoard[R][C]=='Q')
            {
                return false;
            }
            R--;
            C++;
        }
        R=r;
        C=c;
        // downard right
        while(R<n && C<n)
        {
            if(chessBoard[R][C]=='Q')
            {
                return false;
            }
            R++;
            C++;
        }
        R=r;
        C=c;
        // downard left
        while(R<n && C>=0)
        {
            if(chessBoard[R][C]=='Q')
            {
                return false;
            }
            R++;
            C--;
        }

        return true;
    }

    void recursion(int row,int n)
    {
        // base case ~ put ans vector
        if(row==n)
        {
            // i have placed n queens
            ans.push_back(chessBoard);
            return ;
        }

        // recursive case ~ Option i have row and col based optionn
        for(int j=0;j<n;j++)
        {
            if(isSafe(row,j,n))
            {
                chessBoard[row][j]='Q';
                recursion(row+1,n);
                chessBoard[row][j]='.';//undo
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;i++)
        {   
            string row="";
            for(int j=0;j<n;j++)
            {
                row+=".";
            }
            chessBoard.push_back(row);
        }
        recursion(0,n);
        return ans;
    }
};