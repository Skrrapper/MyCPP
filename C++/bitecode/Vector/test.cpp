#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void vector_for()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void test_vector1()
{
    vector<int> v1(10,1);
    vector<string> v2(10,"***");

    for(auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;

    for(auto e : v2)
    {
        cout << e << " ";
    }
    cout << endl;

    string str("hello world");
    vector<char> v3(str.begin(),str.end());
    for(auto e : v3)
    {
        cout << e << " ";
    }
    cout << endl;

    int a[] = {2,34,21,57};
    vector<int> v4(a,a+4);
    for(auto e : v4)
    {
        cout << e << " ";
    }
    cout << endl;
    
    //默认升序排列
    // sort(v4.begin(),v4.end());
    // for(auto e : v4)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    // 降序排列
    greater<int> gt;
    sort(v4.begin(),v4.end(),gt);
    // sort(v4.begin(),v4.end(),greater<int>());
    for(auto e : v4)
    {
        cout << e << " "; 
    }
    cout << endl;
}

int  main()
{
    test_vector1();

    return 0;
}