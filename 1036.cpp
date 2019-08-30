/*
	简单的送分题
    使用的是结构体直接进行排列
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
    char name[15],id[15],gender;
    int grade;
}node[110];
bool cmp(Node a,Node b){
    if(a.gender !=b.gender )
        return a.gender <b.gender;
    else 
        return a.grade >b.grade ;
}

int main(){
    int n;
    bool flag=true;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s %c %s %d",node[i].name ,&node[i].gender ,node[i].id ,&node[i].grade );
    }
    sort(node,node+n,cmp);
    if(node[0].gender =='F'){
        printf("%s %s\n",node[0].name ,node[0].id );
    }else{
        printf("Absent\n");
        flag=false;
    }
    if(node[n-1].gender =='M'){
        printf("%s %s\n",node[n-1].name ,node[n-1].id );
    }else{
        printf("Absent\n");
        flag=false;
    }
    if(flag==true){
        printf("%d\n",node[0].grade -node[n-1].grade );
    }else{
        printf("NA\n");
    }
    return 0;
}