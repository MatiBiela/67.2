#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class file
{
        ifstream inFile;
       	ofstream ofFile;
        public:
                file();
                ~file();
                void save();
};


file::file()
{		
		ofFile.open("wyniki.txt");

}

file::~file()
{
        inFile.close();
        ofFile.close();
}



unsigned long long fib(int n)
{
        if(n==0) return 0;
        if(n==1) return 1;
        long long temp1=0LL,temp2=1ll,temp3=0ll;
        for(int i=2;i<=n;i++)
        {
                temp3=temp1+temp2;
                temp1 = temp2;
                temp2 = temp3;
        }
        return temp2;
}

bool pierwsza(long long liczba)
{
	if(liczba <=1 ) return 0;
	for(long long i = 2; i<=liczba/2; i++)
	{
		if(liczba%i==0)
		{ 													// NA PAMIEC
			return false;
		}
	}
	return true;
}
void file::save(){
	for(long long i =2; i<=40; i++) {
		if(pierwsza(fib(i))) {
			ofFile << fib(i) << "\n";	
		}
	}
}
int main()
{
        file f;
		f.save();  
        for(long long i = 2; i<=40; i++){
        	if(pierwsza(fib(i)  )) 
        	{
               	cout << fib(i) << endl;
    			
			}

        
		}
        return 0;
}
