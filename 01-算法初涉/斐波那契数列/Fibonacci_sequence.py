#斐波那契数列数列


#使用递归求出斐波那契数列数列的第N个值
#时间复杂度为指数阶
def Fib_seq(n):
    if (n < 1):
        return -1;
    if n == 1 or n == 2 :
        return 1;
    return Fib_seq(n - 1) + Fib_seq(n - 2)

#设置一个长度为N的数组，初始化数组的每个值为-1
#设置下标为0及1的值为1
#使用循环，取数组数列的前俩项之和，赋值个当前项
#时间复杂度为O(n),相比Fib_seq时间负载度大大降低
#空间复杂度为O(n)
def Fib_seq1(n):
    if n < 1:
        return -1
    fib_list = [-1] * (n)
    print(fib_list)
    fib_list[0] = 1;
    fib_list[1] = 1;
    for i in range(2,n,1):
        fib_list[i] = fib_list[i - 1] + fib_list[i - 2]
    print(fib_list)
    return fib_list[-1];

#通过俩个变量记录数列的前俩项
#时间复杂度为O(n)
#空间复杂度降低为O(1)
def Fib_seq2(n):
    if n < 1:
        return -1
    if n == 1 or n == 2:
        return 1
    num1 = 1
    num2 = 1
    for i in range(2,n,1):
        num2 = num1 + num2
        num1 = num2 - num1;
    return num2;

#递归的变换方式
def Fib_seq3(a,b,n):
    if n == 0:
        return b
    return Fib_seq3(a + b, a,n - 1)

'''
 a = b*q + a*q + a*p
 b = b*p + a*q
 其中p=0,q=1
 把这种变换称为T变换，那么对于T的平方来说，有：
 a = (bp+aq)p+(bq+aq+ap)*q+(bq+aq+ap)*p = b(2pq+q^2)+a(p^2+2pq+3q^2)
 b = (bp+aq)p+(bq+aq+ap)q = b(p^2+q^2)+a(q^2+2pq)
 时间复杂度为O(logn)
'''
def Fib_seq4(a ,b ,p ,q , count):
    if (count == 0):
        return b
    else:
        if count % 2 == 0 :
            return Fib_seq4(a,b,(p*p+q*q),(2*p*q+q*q),(count/2));
        else:
            return Fib_seq4((b*q+a*q+a*p),(b*p+a*q),p,q,(count -1));

num = 34
print(Fib_seq(num))
print(Fib_seq1(num))
print(Fib_seq2(num))
print(Fib_seq3(1,0,num))
print(Fib_seq4(1,0,0,1,num))