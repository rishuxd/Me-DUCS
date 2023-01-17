#include<iostream>
using namespace std;

string xorFun(string encoded, string crc){
    int crclen = crc.length();
    int enlen = encoded.length();

    for (int i = 0; i <= enlen-crclen;)
    {
        for (int j = 0; j < crclen; j++)
        {
            if(encoded[i+j] == crc[j]){
                encoded[i+j] = '0';
            }
            else{
                encoded[i+j] = '1';
            }
        }
    for( ; i< encoded.length() && encoded[i] != '1' ; i++) ;
    }
    return encoded;
}

int main()
{
    cout<<endl<<"----------Sender Side----------"<<endl;
    
    string data, crc, encoded = "";
    cout<<"Enter Data Bits: "<<endl;
    cin>>data;

    cout<<"Enter Generator: "<<endl;
    cin>>crc;

    encoded += data;
    
    int datalem = data.length();
    int crclen = crc.length();

    for(int i=1; i<=crclen-1; i++){
        encoded += '0';
    }
    
    cout<<"Data Bits: "<<data<<endl;
    cout<<"CRC Bits: "<<crc<<endl;
    cout<<"Encoded Bits: "<<encoded<<endl;

    encoded = xorFun(encoded, crc);

    cout<<"Encoded Bits after XOR: "<<encoded<<endl;

    cout<<"Checksum is generated: ";
    cout<<encoded.substr(encoded.length()-crclen+1)<<endl;
    cout<<"Message to be Transmitted over network: ";
	cout<<data + encoded.substr(encoded.length() - crclen + 1)<<endl; 

    cout<<endl<<"---------------Reciever Side-----------------"<<endl;

    cout<<"Enter the message received: ";
    string msg;
    cin>>msg;

    msg = xorFun(msg, crc);

    for(char i: msg){
        if(i != '0'){
            cout<<"Messege is incorrect."<<endl;
            return 0;
        }
    }
    cout<<"No error found."<<endl;
    return 0;
}