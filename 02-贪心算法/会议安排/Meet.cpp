//
//  Meet.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/14.
//  Copyright © 2019 jay. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Meet
{
    int NO;    //会议编号
    int start;  //会议开始时间
    int end;    //会议结束时间
} meet_arr[100];

class setMeet
{
public:
    void init();
    void solve();
private:
    int meet_num, arrange_meet_num; //meet_num 会议总数   arrange_meet_num 最多可以安排的回忆数量
};

void setMeet::init()
{
    int start,end;
    cout << "请输入会议的总数" << endl;
    cin >> meet_num;
    for (int i = 0; i < meet_num; i++) {
        cout << "请输入第" << i + 1 << "场会议的开始时间和结束时间，以空格分隔"<< endl;
        cin >> start >> end;
        meet_arr[i].start = start;
        meet_arr[i].end = end;
        meet_arr[i].NO = i + 1;
    }
}

bool comp(Meet a,Meet b)
{
    if (a.end == b.end) {
        return a.start > b.start;
    }
    return a.end < b.end;
}

void setMeet::solve()
{
    sort(meet_arr, meet_arr + meet_num, comp);
    cout << "对会议进行排序" << endl;
    cout << "会议编号" << " 开始时间" << "  结束时间" << endl;
    for (int i = 0; i < meet_num; i ++) {
        cout << meet_arr[i].NO << " " << meet_arr[i].start << " " << meet_arr[i].end << endl;
    }
    
    cout << "---选择会议---" << endl;
    cout << "选择第1个会议，编号：" << meet_arr[0].NO << " 开始时间：" << meet_arr[0].start << " 结束时间：" << meet_arr[0].end << endl;
    arrange_meet_num = 1;
    int last = meet_arr[0].end;
    
    for (int i = 1; i < meet_num; i++) {
        if (meet_arr[i].start >= last) {
            //选择当前会议
            arrange_meet_num++;
            last = meet_arr[i].end;
            cout << "选择第" << i + 1 << "个会议，编号：" << meet_arr[i].NO << " 开始时间：" << meet_arr[i].start << " 结束时间：" << meet_arr[i].end << endl;
        }
    }
    cout << "最多可以安排" << arrange_meet_num << "个会议" << endl;
}

int main()
{
    setMeet sm;
    sm.init();
    sm.solve();
    return 0;
}
