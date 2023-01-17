#include <iostream>
using namespace std;

int main(){
    
    int nf,W;
    int no_tr = 0 ;

    cout<<"Enter no of frames : ";cin>>nf;
    cout<<"\nEnter the Window size : ";cin>>W;
    cout<<"\n\n";

    int i=1,j;
    while(i<=nf){
        int x=0 ;
        for(j=i; j<i+W && j<=nf ; j++,no_tr++)
            cout<<"Sent frame "<<j<<endl;
        
        for(j=i ; j<i+W && j<=nf ; j++ ){
            int flag = rand() % 2;

            if(!flag){
                cout<<"Acknowledgement for frame "<<j<<endl;
                x++;
            }
            else{
                cout<<"Frame "<<j<<" Not Received\n";
                cout<<"Retransmitting Window\n";
                break;
            }
        }
        cout<<endl;
        i+=x;
    }
    cout<<"Total number of transmission : "<<no_tr<<endl;

    return 0;
}