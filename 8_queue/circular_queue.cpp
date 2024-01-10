     #include <bits/stdc++.h> 
class CircularQueue{
     int *A, F, R, S;

    public:

    CircularQueue(int n){
    S =n;
    A = new int[S];
    F = -1;
    R = -1;

    }

    bool enqueue(int value){
        if((F==0 && R==S-1)||(R==(F-1)%(S-1))){
        return false;
        }
        else if(F==-1){
            F=0;
            R=0;
        }
        else if(F!=0 && R==S-1){
            R=0;
        }
        else{
            R=R+1; 
         
        }
           A[R]=value;
        return true;
    } 

    int dequeue(){
        if(F==-1){
            return -1;
        }
        int flag=A[F];
        A[F]=-1;
        if(F==R){
            F=R=-1;
        }
        else if(F==S-1){
           F=0;
        }
        else{
            F++;
        }
        return flag;
    }

};
