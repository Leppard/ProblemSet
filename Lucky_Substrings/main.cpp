//
//  main.cpp
//  TestC++
//
//  Created by Leppard on 4/24/15.
//  Copyright (c) 2015 Leppard. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> makeFibonList(void){
    
    vector<int> list;
    
    int a=1,b=1;//设置两个初始值此时a=1,b=1
    
    list.push_back(a);

    for (int i=2;i<=100;i++){//循环计算输出第3-40个数
        b=b+a;//计算前两位之和放在b中第一轮a=1,b=2第二轮a=1,b=3
        
        a=b-a;//用b-a就是计算之前b的数，放入a中，第一轮a=1,b=2 第二轮a=2,b=3 以此类推
        list.push_back(a);
        
        if(i == 2){
            list.pop_back();
        }
        for(int k = 0; k<list.size();k++){
            if(a == list[i]){
                list.pop_back();
                break;
            }
            }
    }
    return list;
}

int main(int argc, const char * argv[]) {
    
    vector<int> list = makeFibonList();
    
    vector<string> result;
    string str;
    cin>>str;
    for(int i = 0;i<str.length();i++){
        int count = 0;
        int count_2;
        for(int j = i; j<str.length();j++){
            
            bool flag = false;
            int k =i;
            
            for (; k<j; k++) {

                if(str[j]==str[k])
                {
                    flag = true;
                }
            }
            if (flag == true) {
                count_2 = count;
            }
            else{
                count_2 = count+1;
            }
            
            for(int l=0;l<list.size();l++){
                if(count_2==list[l])
                {
                    string newStr = str.substr(i,j-i+1);
                    bool newFlag = false;
                    if(result.size()==0){
                        result.push_back(newStr);
                    }
                    else{
                    for(int g = 0;g<result.size();g++){
                        if(result[g] == newStr){
                            newFlag = true;
                        break;
                    }
                    if(newFlag == false)
                    {
                        result.push_back(newStr);
                        break;
                    }

                    }}
            }
            }
            count = count_2;
        }
        
    }
    
    for(int i = 0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    
    }
    return 0;
}
