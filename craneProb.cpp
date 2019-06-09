#include <iostream>
#include<vector>
#include<bits/stdc++.h>
// #include<stdio.h>




int maxnum ;
std::vector<long long> initConfig;
std::vector<int> instructions;
bool picked_up = false;
long long* end;
long long* begin;
long long* ptrn;

void doOp(long long* &ptr,int op){

        // int* end = 
        // int * begin = 

        switch(op){
                case 1: // move left
                        if (ptr != begin){
                        ptr--;
                        }
                        break;
                case 2: //move right
                        if (ptr != end){
                        ptr++;
                        }
                        break;
                case 3: //pick up
                        if (*ptr>0 && !picked_up) {
                            
                            *ptr = *ptr -1;
                              picked_up = true; }
                        break;

                case 4: //pick
                        if (*ptr < maxnum  && picked_up) {
                            *ptr = *ptr +1;
                             picked_up = false;
                             }
                        break;
                // default:
                //         std::cout<<"lol";

        }
}


int main(){

    int n;
    long long maxheight;
    std::cin >> n >> maxheight;
    for (int i = 0; i< n; i++){
        int temp_ss ;
        std::cin >>temp_ss;
        initConfig.push_back(temp_ss);

    }
    maxnum = maxheight;
    while (1){
        int temp_s; 
        std::cin>>temp_s;

        if (temp_s==0){
            
            break;
            }
        else {
            instructions.push_back(temp_s);
            }
    }

    begin = &initConfig[0];
    end = &initConfig[initConfig.size()-1];
    ptrn = begin;
    for (int j = 0 ; j < instructions.size();j++){
        
         doOp(ptrn,instructions[j]);

    }
    for (int j = 0 ; j < initConfig.size();j++){

        std::cout << initConfig[j]<<" ";
    }
}