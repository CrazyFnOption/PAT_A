/*
	我还以为是要用什么复杂的算法，就是排序之后直接遍历，一个一个去找，感觉弱爆了...

    我发现 如果使用不到printf 或者 scanf的时候 就不要使用 cin.tie(0) 这样也会耗尽时间

    总的来说 这道题有点丢失 25分题目的水准，算是一道特别简单的题目了。
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct Person
{
    string name;
    int age;
    int worth;

    bool operator<(const Person p) const
    {
        if (worth > p.worth)
            return true;
        else if (worth < p.worth)
            return false;
        else
        { // 财富相等，比较年龄，年龄小的优先
            if (age < p.age)
                return true;
            else if (age > p.age)
                return false;
            else
            { // 年龄相等，比较名字，按照字典顺序
                for (int i = 0; i < 9; i++)
                {
                    if (name[i] < p.name[i])
                        return true;
                    else if (name[i] > p.name[i])
                        return false;
                }
                return true;
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(NULL);
    vector<Person> persons;
    int N, K;
    cin >> N >> K;
    persons.resize(N);
    for (int i = 0; i < N; i++)
    {
        char *name = new char[9];
        cin >> persons[i].name >> persons[i].age >> persons[i].worth;
       
    }
    sort(persons.begin(), persons.end());
    int maxCnt, age_begin, age_end;
    int outputCnt = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> maxCnt >> age_begin >> age_end;
        outputCnt = 0;
        cout << "Case #" << i + 1 << ":" << endl;
        for (int i = 0; i < N; i++)
        {
            if (persons[i].age >= age_begin && persons[i].age <= age_end)
            {
                cout << persons[i].name << " " << persons[i].age << " " << persons[i].worth << endl;
                outputCnt++;
                if (outputCnt >= maxCnt)
                    break;
            }
        }
        if (outputCnt == 0)
            cout << "None" << endl;
    }
    return 0;
}