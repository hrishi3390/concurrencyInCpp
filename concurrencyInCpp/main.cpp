//
//  main.cpp
//  concurrencyInCpp
//
//  Created by Hrishikesh Chaudhari on 04/03/19.
//  Copyright © 2019 Hrishikesh Chaudhari. All rights reserved.
//

#include <iostream>
#include <thread>

using namespace std;

class callable_class{
public:
    void operator()(){
        cout<<"Hello from functor having id: "<<this_thread::get_id()<<endl;
    }
};

void clean(){
    cout<< "cleaning the ship: "<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
}

void speed(){
    cout<< "speeding up the ship: "<<this_thread::get_id()<<endl;
     this_thread::sleep_for(chrono::milliseconds(5000));
}

void stop(){
    cout<< "stopping the ship: "<<this_thread::get_id()<<endl;
     this_thread::sleep_for(chrono::milliseconds(5000));
}

void run(int a){
    
    if(a==1)
    {
        thread t1(clean);
        t1.detach();
    }
    
    if(a == 2)
    {
        thread t2(speed);
        t2.join();
    }
    
    if(a==3){
        
        thread t3(stop);
        t3.join();
    }
        
    
}

int main(int argc, const char * argv[]) {
  
    int input;
    do{
        cout<<"Input following input \n 1. clean \n 2. full speed ahead\n 3. stop\n 100 exit program\n";
        cin>>input;
        
//        switch (input) {
//            case 1:
//                clean();
//                cout<<"clearning done!"<<endl;
//                break;
//            case 2:
//                speed();
//                cout<<"accelearated the ship"<<endl;
//                break;
//                
//            case 3:
//                stop();
//                cout<<"stopped the ship"<<endl;
//                break;
//            case 100:
//                break;
//            default:
//                cout<<"invalide order\n";
//                break;
//        }
        
        if(input==1)
        {
            thread t1(clean);
            t1.detach();
        }
        
        if(input == 2)
        {
            thread t2(speed);
            t2.join();
        }
        
        if(input==3){
            
            thread t3(stop);
            t3.join();
        }

        
    }while(input != 100);
   
    
    
    
    return 0;
}
