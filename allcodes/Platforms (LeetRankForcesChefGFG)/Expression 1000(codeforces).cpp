/*
A. Expression
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

Petya studies in a school and he adores Maths. His class has been studying arithmetic expressions. On the last class the teacher wrote three positive integers a, b, c on the blackboard. The task was to insert signs of operations '+' and '*', and probably brackets between the numbers so that the value of the resulting expression is as large as possible. Let's consider an example: assume that the teacher wrote numbers 1, 2 and 3 on the blackboard. Here are some ways of placing signs and brackets:

    1+2*3=7
    1*(2+3)=5
    1*2*3=6
    (1+2)*3=9 

Note that you can insert operation signs only between a and b, and between b and c, that is, you cannot swap integers. For instance, in the given sample you cannot get expression (1+3)*2.

It's easy to see that the maximum value that you can obtain is 9.

Your task is: given a, b and c print the maximum value that you can get.
Input

The input contains three integers a, b and c, each on a single line (1 ≤ a, b, c ≤ 10).
Output

Print the maximum value of the expression that you can obtain.
Examples
Input
1
2
3

Output
9

Input
2
10
3

Output
60
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    if(a==1 || b== 1|| c== 1){
        if((a == 1&& b!=1 && c!=1)||(b == 1&& a!=1 && c!=1)||(c == 1&& b!=1 && a!=1)){
            cout<<((a == 1)?((a+b)*c):((b==1)?((min(a,c)+1)*max(a,c)):(a*(b+c))));
        }
        else{
            if(a!=1)
            cout<<a*(b+c);
            else if(b!=1)
            cout<<a+b+c;
            else if(c!=1)
            cout<<(a+b)*c;
            else
            cout<<3;
        }
    }
    else
    cout<<a*b*c;
}