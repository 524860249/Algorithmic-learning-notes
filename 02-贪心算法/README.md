# 什么是贪心算法
贪心算法又称为贪婪算法，意为在对问题求解时，总是在当前做出最优的选择，也就是说不从整体最优上加以考虑，他所做的在某种意义上是局部最优解。  
贪心算法得到的结果可能不是全局最优解，而是全局最优解的近似解。

### 算法基本要素

#### 贪心选择
贪心选择是指所求的问题的全局最优解可由一系列局部最优的选择，即贪心选择达到   
应用同一种规则，将原来的问题变为相似的但规模更小子问题，然后每一步都都是当前最佳的选择

#### 最优子结构
当一个问题的最优解包含其子问题的最优解时，称此问题具有最优子结构性质。问题的最优子结构性质是该问题是否可用贪心算法求解的关键。

### 算法攻略
> 1.算法策略   
根据不同的要求选取贪心策略，选择当前看上去最优的方案   
<font color="red">
比如从一堆古董中挑选10个最好的古董，你认为古董贵的最好，那么你就每次都从一堆古董中挑选最贵的那个，作为局部最优。如果你认为古董时间久的最好，那么你每次都从一堆古董中挑选时间最久的。   
根据不同求解的目的，贪心策略的选择也不同   
</font>
> 2.局部最优   
根据贪心策略，每一步都得到局部最优解  
<font color="red"> 
比如第一次挑到最大的古董放起来，记录为a1，第二次挑到最大的放起来记录为a2,以此类推   
</font>
> 3.全局最优   
汇总所有的局部最优，即可得到全局最优   
<font color="red"> 
每次挑选最好的古董都放在一起，那么这10次挑选的古董就是这一堆古董中最好的
</font>

### 加勒比海盗-最优装载问题
加勒比海盗抢劫了一艘拉有古董的船，没见古董都价值不菲，一旦打碎久失去了价值，海盗想带走古董，但海盗船的载重固定，不能全部带走，所以海盗想带着更多数量的古董。
#### 算法设计
>1 当海盗船载重固定为W时，古董的重量越小，船上可装载的古董数量就越多，只要依次拿重量最小的古董，直到不能再装为止   
>2 把所有的古董按照重量从小到大排序，然后根据贪心算法，每次只拿重量最小的古董，直到不能再装为止即可得到最优的装载方案   
#### 程序实现   
	#include <stdio.h>
	#include <iostream>
	#include <algorithm>
	using namespace std;

	const int N = 10000;
	int main()
	{
	    double weights[N];  //记录所有古董的重量
	    double loadNum; //海盗船的载重
	    int antiqueNum; //古董的数量
	    cout << "请输入海盗船的载重" << endl;
	    cin >> loadNum;
	    cout << "请输入古董的个数" << endl;
	    cin >> antiqueNum;
	    for (int i = 0; i < antiqueNum; i++) {
	        cout << "请输入第" << i + 1 << "个古董的重量" << endl;
	        cin >> weights[i];
	    }
	    //古董重量排序，从小到大
	    sort(weights, weights + antiqueNum);
	    //记录已经选择的古董的重量
	    double temp = 0.0;
	    //记录已经选择的古董的数量
	    int takeNum = 0;
	    for (int i = 0; i < antiqueNum; i++) {
	        if (temp + weights[i] > loadNum) {
	            break;
	        }
	        temp += weights[i];
	        takeNum += 1;
	    }
	    cout << "可以装载" << takeNum << "个古董，总重量共" << temp << endl;
	    return 0;
	}
#### 运行结果
	请输入海盗船的载重
	100
	请输入古董的个数
	10
	请输入第1个古董的重量
	1
	请输入第2个古董的重量
	3
	请输入第3个古董的重量
	4
	请输入第4个古董的重量
	12
	请输入第5个古董的重量
	23
	请输入第6个古董的重量
	34
	请输入第7个古董的重量
	45
	请输入第8个古董的重量
	56
	请输入第9个古董的重量
	67
	请输入第10个古董的重量
	78
	可以装载6个古董，总重量共77

### 阿里巴巴与四十大盗-背包问题
阿里巴巴赶着小毛驴发现了四十大盗的宝库，宝库中有着无数的金银财宝，阿里巴巴想将财宝每样带回去一个，给乡亲们看看，如果太重，就用锤子砸开。但是毛驴的运输能力有限，阿里巴巴通过什么方式可以运走最大价值的财宝？
#### 算法设计
>1 数据结构的设计和数据初始化，将n种宝物的重量和价值保存在结构体(包含重量、价格、性价比三个属性)，同时求出每种宝物的性价比保存在结构体中，然后按照性价比由高到低排序。   
>2 按照贪心策略，每次从宝物中找出性价比最高的宝物，连同已经选择的宝物一起计算重量，判断如果重量小于驴子可承受的重量，则继续选择宝物，如果当前重量大于驴子则将新选择的宝物拆分出刚好驴子可以负载的重量。   

|宝物|重量|价值|
|  ----  | ----  | ----  |
|1|5|25|
|2|2|7|
|3|6|9|
|4|3|6|
|5|8|20|
|6|7|7|
|7|5|7|
|8|4|16|
|9|6|18|

计算宝物的性价比，按照性价比从高到低排序

|宝物|重量|价值|性价比|	|宝物|重量|价值|性价比|
|  ----  | ----  | ----  | ----  | ----  |  ----  | ----  | ----  | ----  |
|1|5|25|5|	|1|5|25|5|
|2|2|7|3.5|	|8|4|16|4|
|3|6|9|1.5|	|2|2|7|3.5|
|4|3|6|2|	|9|6|18|3|
|5|8|20|2.5|	|5|8|20|2.5|
|6|7|7|1|	|4|3|6|2|
|7|5|7|1.4|	|3|6|9|1.5|
|8|4|16|4|	|7|5|7|1.4|
|9|6|18|3|	|6|7|7|1|

假如毛驴的运载能力为30，按照贪心策略每次选择性价比最高的宝物让驴子运载：   
第一次选择宝物1，驴子的运载重量为5，总价值为25   
第二次选择宝物8，驴子的运载重量为9，总价值为41   
第三次选择宝物2，驴子的运载重量为11，总价值为48   
第四次选择宝物9，驴子的运载重量为17，总价值为66   
第五次选择宝物5，驴子的运载重量为25，总价值为86   
第六次选择宝物4，驴子的运载重量为28，总价值为92   
第七次选择宝物3，驴子的运载重量为34，此时已经超过驴子的运载能力，那么阿里巴巴就需要将宝物3拆分，拆分出重量为2的部分，此部分价值为9*(2/6) = 3。总价值为95   
此时，驴子运载了宝物1,8,2,9,5,4,3，那么最优解即为（1,8,2,9,5,4,3），驴子运载的宝物的最大价值为95

#### 程序实现
	#include <stdio.h>
	#include <iostream>
	#include <algorithm>
	using namespace std;

	const int N = 10000;

	struct treasure{
	    double weight;
	    double price;
	    double quality;
	} t[N];

	bool cmp(treasure first,treasure second)
	{
	    return first.quality > second.quality;
	}

	int main()
	{
	    int treasureNum;  //宝物的数量
	    double loadNum;    //驴子的画运载能力
	    
	    cout << "请输入驴子的载重能力" << endl;
	    cin >> loadNum;
	    cout << "请输入宝物的数量" << endl;
	    cin >> treasureNum;
	    for (int i = 0; i < treasureNum; i++) {
	        cout << "请输入第" << i + 1 << "个宝物的重量及价格，以空格分隔：" << endl;
	        cin >> t[i].weight >> t[i].price;
	        t[i].quality = t[i].price / t[i].weight;
	    }
	    
	    sort(t, t + treasureNum, cmp);
	    for (int i = 0; i < treasureNum; i++) {
	        cout << "重量:" << t[i].weight << " 价格:" << t[i].price << " 性价比:" << t[i].quality << endl;
	    }
	    
	    double totalValue = 0.0;
	    for (int i = 0; i < treasureNum; i++) {
	        if (loadNum > t[i].weight) {
	            totalValue += t[i].price;
	            loadNum -= t[i].weight;
	            cout << "宝物重量:" << t[i].weight << " 宝物价格：" << t[i].price << " 宝物性价比:" << t[i].quality << " 已经装载重量:" << totalValue << " 剩余空间:" << loadNum <<  endl;
	        } else {
	            totalValue += t[i].price * (loadNum / t[i].weight);
	            cout << "宝物重量:" << t[i].weight << " 宝物价格：" << t[i].price << " 宝物性价比:" << t[i].quality << " 已经装载重量:" << totalValue << " 剩余空间:" << loadNum << " 拆分当前宝物，取重量为" << loadNum << "的，其价值为" << t[i].price * (loadNum / t[i].weight) << endl;
	            break;
	        }
	    }
	    cout << "阿里巴巴运走的财宝的总价值为" << totalValue << endl;
	    return 0;
	}
#### 运行结果
	请输入驴子的载重能力   
	30   
	请输入的数量   
	9   
	请输入第1个宝物的重量及价格，以空格分隔：   
	5 25   
	请输入第2个宝物的重量及价格，以空格分隔：   
	2 7   
	请输入第3个宝物的重量及价格，以空格分隔：   
	6 9   
	请输入第4个宝物的重量及价格，以空格分隔：   
	3 6   
	请输入第5个宝物的重量及价格，以空格分隔：   
	8 20   
	请输入第6个宝物的重量及价格，以空格分隔：   
	7 7   
	请输入第7个宝物的重量及价格，以空格分隔：   
	5 7   
	请输入第8个宝物的重量及价格，以空格分隔：   
	4 16   
	请输入第9个宝物的重量及价格，以空格分隔：   
	6 18   
	重量:5 价格:25 性价比:5   
	重量:4 价格:16 性价比:4   
	重量:2 价格:7 性价比:3.5   
	重量:6 价格:18 性价比:3   
	重量:8 价格:20 性价比:2.5   
	重量:3 价格:6 性价比:2   
	重量:6 价格:9 性价比:1.5   
	重量:5 价格:7 性价比:1.4   
	重量:7 价格:7 性价比:1   
	宝物重量:5 宝物价格：25 宝物性价比:5 已经装载重量:25 剩余空间:25   
	宝物重量:4 宝物价格：16 宝物性价比:4 已经装载重量:41 剩余空间:21   
	宝物重量:2 宝物价格：7 宝物性价比:3.5 已经装载重量:48 剩余空间:19   
	宝物重量:6 宝物价格：18 宝物性价比:3 已经装载重量:66 剩余空间:13   
	宝物重量:8 宝物价格：20 宝物性价比:2.5 已经装载重量:86 剩余空间:5   
	宝物重量:3 宝物价格：6 宝物性价比:2 已经装载重量:92 剩余空间:2   
	宝物重量:6 宝物价格：9 宝物性价比:1.5 已经装载重量:95 剩余空间:2 拆分当前宝物，取重量为2的，其价值为3   
	阿里巴巴运走的财宝的总价值为95    

#### 算法分析
上面的算法中的宝物可以做拆分，那么我们就可以用贪心算法，从局部最优解中得到全局最优解。但是在很多情况下物体无法拆分，此时再使用贪心算法可能就无法得到最优解，如

|宝物|重量|价值|性价比|
|  ----  | ----  | ----  | ----  |
|1|3|15|5|
|2|4|16|4|
|3|6|18|3|
|4|10|25|2.5|
|5|7|14|2|

如果驴子可运载的重量为10，那么使用贪心算法我们选择的宝物为1和2，总价值为31。但如果我们选择的是3和4 ，总价值将会变为34。显然此处使用贪心算法就无法得到全局最优解。   
那么针对这俩中物品是否可拆分可分为俩个问题，物体可拆分被称为**背包问题**，不可拆分则被称为**0-1背包问题**   
显然在不可拆分的问题中，全局最优解并非可以通过局部最优解获得（不具有贪心选择性质），但是如果问题中不需要全局最优解，而需要一个**接近全局最优解近似解**，则依然可使用贪心算法。   


### 会议安排
会议室每天都有很多会议要开，而每个会议的时间又不固定，那么如何安排会议可以让一个会议室每天开最多次的会议呢？
#### 算法设计
> 1. 为了方便识别各个会议，我们需要给会议一个编号。会议有开始时间和结束时间。那么我们就需要一个可以存储这三个属性的结构体(编号、开始时间、结束时间)   
> 2. 贪心策略选取   
   a. 每次从剩余会议中找出开始时间最早且与已经选择的会议时间不冲突的会议，如 已经选择的结束时间为12点，则下一个选择的会议开始时间必须上12点或之后的会议。  
   b. 每次从剩余会议中找出时间最短的会议且与已经选择的会议时间不冲突的会议，如 已经选择的结束时间为12点，剩余的会议中有 12点至15点，和14点至15点，则选择13至14点的会议    
   c. 每次从剩余会议中找出结束时间最早且与已经选择的会有时间不冲突的会议，如 以极高选择的结束时间为12点，剩余会议中有12点至15点，和13点至14点，则选择13点至14点    
   **针对不同的需求，我们选择不同的贪心策略，然后通过选择的贪心策略用程序实现，根据我们的问题需求，显然c需求更合适。**   

|编号|1|2|3|4|5|6|7|8|9|10|
|  ----  | ----  | ----  |  ----  | ----  | ----  |  ----  | ----  | ----  | ----  | ----  |
|开始时间|9|10|11|12|13|14|16|15|19|17|20|
|结束时间|12|11|13|15|16|18|18|21|21|22|

排序后的列表为   

|编号|2|1|3|4|5|6|7|8|9|10|
|  ----  | ----  | ----  |  ----  | ----  | ----  |  ----  | ----  | ----  | ----  | ----  |
|开始时间|10|9|11|13|14|16|15|19|17|20|
|结束时间|11|12|13|15|16|18|18|21|21|22|

按照我们选定的贪心策略   
第一次选择编号为2，其结束时间为11   
第二次选择编号为3，其开始时间为11，结束时间为13   
第三次选择编号为4，其开始时间为13，结束时间为15   
第四次选择编号为6，其开始时间为16，结束时间为18   
第五次选择编号为8，其开始时间为19，结束时间为21   
至此，再无合适会议，选择结束，共可安排5场会议   

#### 程序实现

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
		//如果结束时间相同，则优先选择开始时间晚的会议。此处可根据具体需求调整
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
	        if (meet_arr[i].start > last) {
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

#### 运行结果   
	请输入会议的总数
	10
	请输入第1场会议的开始时间和结束时间，以空格分隔
	9 12
	请输入第2场会议的开始时间和结束时间，以空格分隔
	10 11
	请输入第3场会议的开始时间和结束时间，以空格分隔
	11 13
	请输入第4场会议的开始时间和结束时间，以空格分隔
	13 15
	请输入第5场会议的开始时间和结束时间，以空格分隔
	14 16
	请输入第6场会议的开始时间和结束时间，以空格分隔
	16 18
	请输入第7场会议的开始时间和结束时间，以空格分隔
	15 18
	请输入第8场会议的开始时间和结束时间，以空格分隔
	19 21
	请输入第9场会议的开始时间和结束时间，以空格分隔
	17 21
	请输入第10场会议的开始时间和结束时间，以空格分隔
	20 22
	对会议进行排序
	会议编号 开始时间  结束时间
	2 10 11
	1 9 12
	3 11 13
	4 13 15
	5 14 16
	6 16 18
	7 15 18
	8 19 21
	9 17 21
	10 20 22
	---选择会议---
	选择第1个会议，编号：2 开始时间：10 结束时间：11
	选择第3个会议，编号：3 开始时间：11 结束时间：13
	选择第4个会议，编号：4 开始时间：13 结束时间：15
	选择第6个会议，编号：6 开始时间：16 结束时间：18
	选择第8个会议，编号：8 开始时间：19 结束时间：21
	最多可以安排5个会议


### 哈夫曼编码
哈夫曼编码(Huffman Coding)，又称霍夫曼编码，是一种编码方式，可变字长编码(VLC)的一种。Huffman于1952年提出一种编码方法，该方法完全依据字符出现概率来构造异字头的平均长度最短的码字，有时称之为最佳编码。哈夫曼编码算法是基于二叉树构建编码压缩结构的，是数据压缩中的一种经典算法，算法根据文本字符出现的频率，重新对字符进行编码。

#### 算法设计   
> 1. 我们需要一个包含权重、父节点、左节点、右节点、字符信息的数据结构   
> 2. 使用贪心策略每次从没有没有父节点的节点列表中找出权重最小的俩个节点，权重小的放置于左节点，权重大的放置于右节点   
> 3. 通过左右节点生成一个新的节点，并将该节点设置为左右节点的父节点   
> 4. 便利哈夫曼树，得到每个字符对应的编码   
#### 程序实现   
	#include <stdio.h>
	#include <algorithm>
	#include <cstring>
	#include <cstdlib>
	#include <iostream>
	#include <vector>

	using namespace std;

	#define MAXVALUE 10000

	typedef struct
	{
	    double weight;
	    int parent;
	    int lchild;
	    int rchild;
	    char value;
	} HNodeType;

	typedef struct
	{
	    vector<int> bit;
	} HCodeType;
	/**
	 哈夫曼树
	 */
	void HuffmanTree(vector<HNodeType> &node_vector,int n)
	{
	    int i, j;   //循环使用
	    int left, right;    //每次需从数组中找出的俩个节点的数组下标
	    double left_weight, right_wieght;
	    for (i = 0 ; i < n; i++) {
	        cout << "请输入" << i + 1 << "个节点及对应的权重，以空格分隔" << endl;
	        HNodeType huffNode;
	        huffNode.weight = 0;
	        huffNode.parent = -1;
	        huffNode.lchild = -1;
	        huffNode.rchild = -1;
	        
	        cin >> huffNode.value >> huffNode.weight;
	        node_vector.push_back(huffNode);
	    }
	    //构造哈夫曼树
	    //i < n-1 循环完毕后，最终剩余的为根节点
	    for (i = 0; i < n-1; i++) {
	        left_weight = right_wieght = MAXVALUE;
	        left = right = -1;
	        /**
	         使用贪心策略每次找出还没有父节点的俩个权重最小的节点
	         将权重略小的节点置于左侧节点，权重略大的节点置于右侧节点
	         使用当前俩个节点生成一个新的节点，放置于列表的最后，以便下次循环使用
	         */
	        for (j = 0; j < node_vector.size(); j++) {
	            if (node_vector.at(j).weight < left_weight && node_vector.at(j).parent == -1) {
	                right_wieght = left_weight;
	                right = left;
	                left_weight = node_vector.at(j).weight;
	                left = j;
	            } else if (node_vector.at(j).weight < right_wieght && node_vector.at(j).parent == -1){
	                right_wieght = node_vector.at(j).weight;
	                right = j;
	            }
	        }
	        node_vector.at(left).parent = n + i;
	        node_vector.at(right).parent = n + i;
	        
	        HNodeType huffNode;
	        huffNode.weight = left_weight + right_wieght;
	        huffNode.lchild = left;
	        huffNode.rchild = right;
	        huffNode.parent = -1;
	        
	        node_vector.push_back(huffNode);
	        cout << "第" << i + 1 << "次循环：" << node_vector.at(left).weight << " " << node_vector.at(right).weight  << endl;
	    }
	    
	    for (i = 0; i < node_vector.size(); i++) {
	        cout << "parent:" << node_vector.at(i).parent << "    lchild:" <<node_vector.at(i).lchild << " rchild:" << node_vector.at(i).rchild
	        << "    weight:" << node_vector.at(i).weight  << "    value:" << node_vector.at(i).value << endl;
	    }
	}
	/**
	 哈夫曼编码转换
	 */
	void HuffmanCode(vector<HCodeType> &code_vector,vector<HNodeType> node_vector,int n)
	{
	    int i, c, p;
	    for (i = 0; i < n; i++) {
	        HCodeType cd;
	        c = i;
	        p = node_vector.at(c).parent;
	        while (p != -1) {
	            if(node_vector.at(p).lchild == c){
	                cd.bit.push_back(0);
	            } else {
	                cd.bit.push_back(1);
	            }
	            c = p;
	            p = node_vector.at(c).parent;
	        }
	        code_vector.push_back(cd);
	    }
	}
	int main()
	{
	    int i, j, n;
	    cout << "请输入节点数量"<< endl;
	    cin >> n;
	    
	    vector<HNodeType> Node_vector;
	    vector<HCodeType> Code_vector;

	    HuffmanTree(Node_vector, n);
	    HuffmanCode(Code_vector,Node_vector,n);
	    
	    for (i = 0; i < n; i++) {
	        cout << Node_vector.at(i).value << ": Huffman code is: ";
	        for (j = Code_vector.at(i).bit.size() - 1; j > -1 ; j--) {
	            cout << Code_vector.at(i).bit.at(j);
	        }
	        cout << endl;
	    }
	    return 0;
	}

#### 运行结果   
	请输入节点数量
	6
	请输入1个节点及对应的权重，以空格分隔
	a 0.02
	请输入2个节点及对应的权重，以空格分隔
	b 0.13
	请输入3个节点及对应的权重，以空格分隔
	c 0.2
	请输入4个节点及对应的权重，以空格分隔
	d 0.24
	请输入5个节点及对应的权重，以空格分隔
	e 0.36
	请输入6个节点及对应的权重，以空格分隔
	f 0.05
	第1次循环：0.02 0.05
	第2次循环：0.07 0.13
	第3次循环：0.2 0.2
	第4次循环：0.24 0.36
	第5次循环：0.4 0.6
	parent:6    lchild:-1 rchild:-1    weight:0.02    value:a
	parent:7    lchild:-1 rchild:-1    weight:0.13    value:b
	parent:8    lchild:-1 rchild:-1    weight:0.2    value:c
	parent:9    lchild:-1 rchild:-1    weight:0.24    value:d
	parent:9    lchild:-1 rchild:-1    weight:0.36    value:e
	parent:6    lchild:-1 rchild:-1    weight:0.05    value:f
	parent:7    lchild:0 rchild:5    weight:0.07    value:
#### 算法分析    
我们通过信息的使用频率作为权重，构建哈夫曼树，继而通过遍历哈夫曼树的出每个字母的哈夫曼编码。哈夫曼编码是一种无前缀编码，解码时不会混淆，主要应用在数据压缩，加密解密等场合。




















