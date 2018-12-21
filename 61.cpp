#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    void SerializeHelper(TreeNode* proot, string &s)
    {
        if(proot==NULL)
        {
            s.push_back('#');
            s.push_back(',');
            return;
        }
        s += to_string(proot->val);
        s.push_back(',');
        SerializeHelper(proot->left, s);
        SerializeHelper(proot->right, s);
    }
    char* Serialize(TreeNode *root) {
        if(root==NULL)
            return NULL;
        string s="";
        SerializeHelper(root, s);
        char *res = new char[s.size()];
        strcpy(res, s.c_str());

        return res;
    }
    TreeNode *deserializeHelper(string &s)
    {
        if (s.empty())
            return NULL;
        if (s[0] == '#')
        {
            s = s.substr(2);
            return NULL;
        }
        TreeNode *ret = new TreeNode(stoi(s));
        s = s.substr(s.find_first_of(',') + 1);
        ret->left = deserializeHelper(s);
        ret->right = deserializeHelper(s);
        return ret;
    }

    TreeNode* Deserialize(char *str) {
        if (str == NULL)
            return NULL;
        string s(str);
        return deserializeHelper(s);
    }
};
