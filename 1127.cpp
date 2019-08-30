/*
	本来是一道简单的题，但是自己在暴力建树，和使用层序记录这两种方法不是很熟练，所以在这个地方出错了

    以后可以多练习一下
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int in[35],post[35];
int n,x;
vector<int>level[35];
int Max = -1;

void buildTree (int lin,int rin,int lpost,int rpost,int index) {
    
    if(lin > rin) return ;
    int i = lin;
    for (; i <= rin; i++) {
        if (in[i] == post[rpost]) break;
    }
    Max = max(index,Max);
    //记住 层序遍历的话 就这样将其存入到每一层中去
    level[index].push_back(post[rpost]);
    buildTree(lin,i - 1,lpost,lpost + (i - lin - 1),index + 1);
    buildTree(i + 1,rin,lpost + i - lin,rpost - 1,index + 1);
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in[i];
    for (int i = 1; i <= n; i++) cin >> post[i];
    
    buildTree(1,n,1,n,1);
    cout << level[1][0];
    for (int i = 2; i <= Max; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < level[i].size(); j++) {
                cout << " " << level[i][j];
            }
        }
        else {
            for (int j = level[i].size() - 1; j >= 0; j--) {
                cout << " " << level[i][j];
            }
        }
    }
    cout << endl;
    
    return 0;
}

/*
	node *Create(int postL, int postR, int inL, int inR) {
	if ( postL > postR ) return NULL;
	node *root = new node();
	root->data = post[postR];
	int index;
	for ( index = inL; index <= inR; index++ ) {
		if ( in[index] == post[postR] ) break;
	}
	int numLeft = index - inL;
	root->lchild = Create(postL, postL+numLeft-1, inL, index-1);
	root->rchild = Create(postL+numLeft, postR-1, index+1, inR);
	return root;
}

 有一种蠢办法 可以像这样直接建树  我先开始想这个办法 没有怎么想通该怎么写，但是现在知道该怎么写。
*/