/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    //JZ78 ����һ����־����

    vector<vector<int> > vc;
    void Level_order(TreeNode* root)
    {
        if (root == nullptr)
            return;
        vector<int> vvc;
        queue<TreeNode*> qroot;
        qroot.push(root);
        //size ���Լ�¼ÿ��Ԫ�ظ���
        int size = 1;
        int flag = 1;
        while (!qroot.empty())
        {
            //count ������¼�����ڵ���Ŀ
            int count = 0;
            while (size)
            {
                //ÿ��Ԫ����vector��ͬʱ������һ��ڵ�
                if (qroot.front()->left)
                {
                    qroot.push(qroot.front()->left);
                    count++;
                }
                if (qroot.front()->right)
                {
                    qroot.push(qroot.front()->right);
                    count++;
                }
                vvc.push_back(qroot.front()->val);
                qroot.pop();
                size--;
            }
            if (flag % 2 == 0)
            {
                auto it1 = vvc.begin();
                auto it2 = vvc.end() - 1;
                while (it1 < it2)
                {
                    std::swap(*it1, *it2);
                    it1++;
                    it2--;
                }
            }
            //ÿ����һ����ά����
            vc.push_back(vvc);
            //�ÿգ��Ա�����һ��
            vvc.resize(0);
            //size ������һ��ڵ���
            size += count;
            flag++;
        }
    }
    vector<vector<int> > Print(TreeNode* pRoot) {
        Level_order(pRoot);
        return vc;
    }

};