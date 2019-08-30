/*
	一道复杂的逻辑题，注意每一个细节，一定要自己去写一遍。
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MaxP 6
#define MaxUser 10001
int N, K, M; //学生个数，考题个数，提交数
int Full_Score[MaxP];
/*定义一个学生节点*/
typedef struct Node
{
    int id;                                     //学生id
    int flag = 0;                               //判断该生成绩是否输出的标记
    int total_score = 0;                        //学生的总分
    int score[MaxP] = {-1, -1, -1, -1, -1, -1}; //每道题目的得分
    int total_number = 0;                       //答对正确的题目个数
} Student;
Student studentList[MaxUser]; //定于一个结构体数组存放学生信息
/*输入函数*/
void Input(Student List[])
{
    int i, j;
    int tmpid, tmp_problemid, tmpscore;
    //接收每道题的满分
    for (i = 1; i <= K; i++)
    {
        cin >> Full_Score[i];
    }
    //处理每一条记录
    for (i = 0; i < M; i++)
    {
        cin >> tmpid >> tmp_problemid >> tmpscore;
        List[tmpid].id = tmpid;
        //第一次提交之后，相应的题目分数值先变为0，便于之后计算
        if (List[tmpid].score[tmp_problemid] == -1)
        {
            List[tmpid].score[tmp_problemid] = 0;
        }
        //如果对应题目分数>=0.则说明是通过编译是通过的
        if (List[tmpid].score[tmp_problemid] <= tmpscore)
        {
            //设置该学生输出标记为1
            List[tmpid].flag = 1;
            //计算总分
            List[tmpid].total_score += (tmpscore - List[tmpid].score[tmp_problemid]);
            //如果某题目提交多次，则以最高成绩进行记录
            List[tmpid].score[tmp_problemid] = tmpscore;
        }
    }
}
/*计算每个学生完全答对的题目个数*/
void Calculate(Student studentList[])
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        if (studentList[i].total_score != 0)
        {
            for (j = 1; j <= K; j++)
            {
                if (studentList[i].score[j] == Full_Score[j])
                {
                    studentList[i].total_number++;
                }
            }
        }
    }
}
/*排序函数的依据*/
bool cmp(Student a, Student b)
{
    if (a.total_score > b.total_score ||                                       //按照分数高低排序
        (a.total_score == b.total_score && a.total_number > b.total_number) || //分数相同按照完全答对题目个数答对排序
        (a.total_score == b.total_score && a.total_number == b.total_number && a.id < b.id))
    { //前两者都相同的话，就按照id进行排序
        return true;
    }
    return false;
}
//输出函数
void output(Student studentList[])
{
    int i, j;
    int number = 1;
    for (i = 1; i <= N; i++)
    {
        //输出标记位1
        if (studentList[i].flag > 0)
        {
            cout << number << ' ';
            if (studentList[i + 1].total_score != studentList[i].total_score)
            {
                number = i + 1;
            }
            printf("%05d %d", studentList[i].id, studentList[i].total_score);
            for (j = 1; j <= K; j++)
            {
                if (studentList[i].score[j] == -1)
                {
                    printf(" -");
                }
                else
                {
                    printf(" %d", studentList[i].score[j]);
                }
            }

            printf("\n");
        }
    }
}
int main()
{
    cin >> N >> K >> M;
    Input(studentList);
    Calculate(studentList);
    sort(studentList + 1, studentList + N + 1, cmp);
    output(studentList);
    return 0;
}