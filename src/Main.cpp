#include <iostream>

int main(){
    return 0;
}

void menu(){

    int option = 0;
    while(1){
        std::cout<<std::endl<<"choose the graph representation:"<<std::endl
                            <<" [1] Incidence matrix"<<std::endl
                            <<" [2] Adjacency list"<<std::endl
                            <<"\n[3] exit";
        std::cin>>option;
        switch(option){
            case 1:{
                

                break;
            }

            case 2:{


                break;
            }

            case 3:{
                return;
            }

            default:{
                std::cout<<"\nWrong input! Try again";
                break;
            }
        }
    }
}