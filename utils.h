#ifndef UTILS_H_
#define UTILS_h_


#include <map>
#include <iostream>
#include <string>
#include <functional>
#include "listExceptions.h"

using namespace std;

#define ASSERT_ERROR(x, error) do{ \
    try{x; cout<<"Failed assertion at line "<<__LINE__<<" in "<<__func__<<\
    ": received no error while expecting "<<#error<<endl; return false;}\
    catch(error& e){}\
    catch(const listException& e){cout<<"Failed assertion at line "<<__LINE__<<" in "<<__func__<<\
    ": received error: "<<"\""<<e.what()<<"\" while expecting "<<"\""<<#error<<"\""<<endl; return false;}\
    } while(false);

#define ASSERT_TEST(x) do{if(!(x)){ \
    cout<<"Failed assertion at line "<<__LINE__<<" in "<<__func__<<endl;\
    return false; }} while(false);

#define ADD_TEST(x) tests[#x]=x;


bool run_test(std::function<bool()> test, std::string test_name){
    if(!test()){
        cout<<test_name<<" - FAILED."<<endl;
        return false;
    }
    cout<<test_name<<" - PASSED."<<endl;
    return true;
}
#endif
