#include<iostream>
using namespace std;

class Solution {
public:
bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL || rows<=0 || cols<=0)
            return false;
        if(str==NULL)
            return true;
        bool *visited = new bool[rows*cols]();
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(pathJudge(matrix, rows, cols, str, visited, i, j))
                    return true;
        return false;
    }
    bool pathJudge(char *matrix, int rows, int cols, char* str, bool* visited, int curx, int cury)
    {
        int index = curx*cols+cury;
        if(*str=='\0')
            return true;
        if(cury==cols)
      {
           curx++;
           cury=0;
      }
      if(cury==-1)
      {
           curx--;
           cury=cols-1;
      }
        if(curx<0||curx>=rows)
            return false;
        if(visited[index] || *str!=matrix[index])
            return false;
        visited[index] = true;
        bool res = pathJudge(matrix, rows, cols, str+1, visited, curx, cury+1) ||
        pathJudge(matrix, rows, cols, str+1, visited, curx+1, cury)||
        pathJudge(matrix, rows, cols, str+1, visited, curx-1, cury)||
        pathJudge(matrix, rows, cols, str+1, visited, curx, cury-1);
        visited[index] = false;

        return res;
    }


};
